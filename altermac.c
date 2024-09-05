/* altermac. */
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long int64;

struct s_mac {
    int64 address:48; // 48bits MAC addr
};
typedef struct s_mac MAC;

MAC generateMac(void);
int main(int,char**);

MAC generateMac() {
    int64 number1, number2;
    MAC mac;

    number1 = (long)random();
    number2 = (long)random();
    mac.address = ((number1 * number2) % 281474976710656); //2^48

    return mac;
}

int main(int argc,char *argv[]) {
    MAC mac;

    srand(getpid());
    mac = generateMac();
    printf("0x%llx\n", (long long)mac.address);

    return 0;
}
