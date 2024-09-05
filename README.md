# **Altermac: A MAC Address Changer Tool**

## **Overview**

Altermac is a lightweight, command-line tool designed to dynamically change the MAC address of network interfaces on Linux systems. This project provides an easy-to-use interface for developers and system administrators to modify MAC addresses, which can be useful in various scenarios such as testing network protocols or troubleshooting connectivity issues.

## **Features**

*   **MAC Address Generation**: Altermac includes a built-in random number generator that produces 48-bit MAC addresses suitable for use with most networking applications.
*   **Interface Selection**: Users can specify the network interface to modify using the command-line argument `INTERFACE`.
*   **Error Handling**: It includes error handling mechanisms to catch and report potential issues during MAC address modifications.

## **Run**

To run Altermac, follow these steps:

1.  Clone this repository: `git clone https://github.com/username/altermac.git`
2.  Navigate into the project directory: `cd altermac`
3.  Compile the source code (optional): `make` or `gcc -o altermac *.c`
4.  Run Altermac using your preferred interface name as an argument: `./altermac INTERFACE`

## **Example Usage**

To generate a new MAC address for the `wlan0` interface:

```bash
./altermac wlan0
```

## **Compiling and Installing**

If you want to compile Altermac from source or install it on your system, follow these steps:

1.  Clone this repository: `git clone https://github.com/leonfullxr/Altermac`
2.  Navigate into the project directory: `cd Altermac`
3.  Compile the source code: `make`
4.  Execute the program

## **Further improvements**
* Handle various interfaces at the same time.
* Change partially a MAC address (can select the changing bytes).
