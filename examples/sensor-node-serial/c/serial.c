#include <stdio.h>
#include <fcntl.h>   /* File Control Definitions           */
#include <termios.h> /* POSIX Terminal Control Definitions */
#include <unistd.h>  /* UNIX Standard Definitions          */
#include <errno.h>   /* ERROR Number Definitions           */
#include "serial.h"

int init_serial(char *port)
{
    int fd = -1; // File Descriptor

    /* Opening the Serial Port */
    /* ttyS00 is the FT232 based USB2SERIAL Converter   */
    /* O_RDWR   - Read/Write access to serial port       */
    /* O_NOCTTY - No terminal will control the process   */
    /* Open in blocking mode,read will wait              */
    fd = open(port, O_RDWR | O_NOCTTY);

    /* Error Checking */
    if(fd == -1)
    {
        printf("Error: Opening serial port failed\n");
        return fd;
    }
    else
    {
        printf("-- Port [%s] Opened Successfully\n", port);
    }

    /* Setting the Attributes of the serial port using termios structure */
    struct termios SerialPortSettings;
    tcgetattr(fd, &SerialPortSettings);

    /* Setting the Baud rate (9600bps) */
    cfsetispeed(&SerialPortSettings,B9600);
    cfsetospeed(&SerialPortSettings,B9600);

    /* 8N1 Mode */
    SerialPortSettings.c_cflag &= ~PARENB; /* No Parity */
    SerialPortSettings.c_cflag &= ~CSTOPB; /* 1 Stop bit */
    SerialPortSettings.c_cflag &= ~CSIZE;  /* Clears the mask for setting the data size */
    SerialPortSettings.c_cflag |=  CS8;    /* Set the data bits = 8 */
    SerialPortSettings.c_cflag &= ~CRTSCTS; /* No Hardware flow Control */
    SerialPortSettings.c_cflag |= CREAD | CLOCAL; /* Enable receiver,Ignore Modem Control lines */
    SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY); /* Disable XON/XOFF flow control */
    SerialPortSettings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);  /* Non Cannonical mode */ 
    SerialPortSettings.c_oflag &= ~OPOST;/*No Output Processing*/

    /* Setting Time outs */
    SerialPortSettings.c_cc[VMIN] = 10; /* Read at least 10 characters */
    SerialPortSettings.c_cc[VTIME] = 0; /* Wait indefinetly   */

    if((tcsetattr(fd,TCSANOW,&SerialPortSettings)) != 0) /* Set the attributes to the termios structure*/
    {
        printf("Error: Setting attributes failed\n");
        /* Close file and return error */
        close(fd);
        return -1;
    }
    else
    {
        printf("-- Port configured\n");
    }

    return fd;
}

int read_serial(int fd, char *buf, int max_size)
{
    tcflush(fd, TCIFLUSH);
    return read(fd, buf, max_size);
}

void close_serial(int fd)
{
    close(fd); /* Close the serial port */
}
