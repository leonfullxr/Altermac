# Altermac
A program written in C to be able to change the MAC address.

The whole purpose was to deeply learn what are MAC addresses and what is their purpose.
Some ethical hacking videos recommend changing this address to remain anonymous and/or private.

## Challenges
The more simple approach would be to run the following command:

> ifconfig "your_network" hw ether "your_MACaddress"

But surely it's better to understand **how** the command works and what it does.
So for that reason, it's recommended to run:

> strace -f ifconfig "your_network" hw ether "your_MACaddress" 2> ouput.txt

Now, with this output, we can ensure **what** functions are being called
and what's the process behind it.

We want to look for something like the following:

> ioctl(4, SIOCSIFHWADDR, {ifr_name="ens192", ifr_hwaddr={sa_family=ARPHRD_ETHER, sa_data=00:0c:29:9f:80:dd}}) = 0

Now bare in mind, the output might be slightly different, as the MAC address, ifr_name and ether have a high chance to change.
The important thing is to recognize the parameters and the 'ioctl' function.

Now, we have to look at the file:

> vi /usr/include/x86_64-linux-gnu/bits/ioctls.h

Note: I'm using a 64bit ARM, the 'x86_64'-linux-gnu might differ depending on your system's arquitechture..

Now in this file, we can search for '#define SIOCSIFHWADDR', which was the 2º argument in the ioctl function.

Now we want to search for 3º argument in the 'ioctl' function. For that, we will want to find the file
that contains the ifr_name:

> grep -r ifr_name

A bunch of files have it included, but we want the definition, which in my case, is in the
/usr/include/net/if.h

> vi /usr/include/net/if.h

Here we can see that there is a struct defined, called 'ifreq', that's what we're interested in.
