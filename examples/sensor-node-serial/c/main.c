#include <stdio.h>
#include <fcntl.h>   /* File Control Definitions           */
#include <termios.h> /* POSIX Terminal Control Definitions */
#include <unistd.h>  /* UNIX Standard Definitions          */
#include <errno.h>   /* ERROR Number Definitions           */
#include "serial.h"

int main(int argc, char **argv)
{
    int fd = init_serial("/dev/ttyS0");
    if (fd == -1)
    {
        printf("Error: failed init serial\n");
    }
    char buf[100];
    for (int i = 0; i < 10; ++i)
    {
        int n = read_serial(fd, buf, sizeof(buf));
        /* Ensure NUL terminated string */
        buf[n] = '\0';
        printf("Bytes Read: %d\n", n);
        printf("Data Read: %s\n", buf);
    }
    close_serial(fd);
}

