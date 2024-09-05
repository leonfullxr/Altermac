/* altermac. */
#include <sys/socket.h>
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <stdbool.h>
#include <sys/ioctl.h>  // for the ioctl function
#include <net/if.h>     // for the ifreq struct
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/if_arp.h>

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long int64;

struct s_mac {
    int64 address:48; // 48bits MAC addr
};
typedef struct s_mac MAC;

bool changeMac(int8*, MAC);
MAC generateMac(void);
int main(int,char**);

MAC generateMac() {
    int64 number1, number2;
    MAC mac;

    number1 = (long)rand();
    number2 = (long)rand();
    mac.address = ((number1 * number2) % 281474976710656); //2^48

    return mac;
}

bool changeMac(int8 *If, MAC mac) {
    struct ifreq ir;
    int filedescriptor, ret;

    filedescriptor = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
    assert(filedescriptor > 0);

    strncpy(ir.ifr_ifrn.ifrn_name, (char *)If, (IFNAMSIZ-1));
    ir.ifr_ifru.ifru_hwaddr.sa_family = ARPHRD_ETHER;
    memcpy(ir.ifr_ifru.ifru_hwaddr.sa_data, &mac, 6);

    ret = ioctl(filedescriptor, SIOCSIFHWADDR, &ir);
    close(filedescriptor);

    return (!ret) ?
        true :
        false;
}

int main(int argc,char *argv[]) {
    MAC mac;
    int8 *If;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s INTERFACE\n", *argv);
        return -1;
    } else {
        If = (int8 *)argv[1];
    }

    srand(getpid());
    mac = generateMac();
    if (changeMac(If, mac)) {
        printf("0x%llx\n", (long long)mac.address);
    } else {
        printf(stderr);
    }

    return 0;
}
