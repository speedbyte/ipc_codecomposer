/*
 ============================================================================
 Name        : IPC_Test.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>   /* Posix 1003.1c threads */
#include "IPC.h"

#define MODEM_DEVICE "/dev/ttyS1"

void *thread(void *arg);
void *thread2(void *arg);

int fd = 0; // file description for the serial port

int open_port(void)
{
	fd = open(MODEM_DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);

	if(fd == -1) // if open is unsucessful
	{
		printf("open_port: Unable to open %s \n", MODEM_DEVICE);
	}
	else
	{
		fcntl(fd, F_SETFL, 0);
		printf("open_port: Port %s is open.\n", MODEM_DEVICE);
	}

	return(fd);
} //open_port

int configure_port(int fd)      // configure the port
{
	struct termios options;
	tcgetattr(fd, &options);

	cfmakeraw(&options);

	cfsetispeed(&options, B115200); //Typical way of setting baud rate. Actual baud rate are contained in the c_ispeed and c_ospeed members
	cfsetospeed(&options, B115200);
	options.c_cflag |= (CLOCAL|CREAD);

	options.c_cflag &= ~CSIZE;
	options.c_cflag &= ~CSTOPB;
	options.c_cflag &= ~PARENB;
	options.c_cflag |= CS8;     //No parity, 8bits, 1 stop bit (8N1)

	tcsetattr (fd, TCSANOW, &options); //Make changes now without waiting for data to complete.
	return(fd);

} //configure_port


void *thread_mon(void *arg)
{
	int i = 0;
	while (1)
	{
		if(i == 20)
		{
			IPC_vMonitorCommunication(fd);
//			printf("MonitorCommunication\n");
			i = 0;
		}
		else
		{
			i++;
		}
		IPC_vWriteManager(fd);
		usleep(50000);
	}
	return(0);
}

void *thread(void *arg)
{
	int retval;
	struct timeval tv;
	fd_set readfds;
	fd = open_port();
	printf("fd = %d\n", fd);
	FD_ZERO(&readfds);
	FD_SET(fd, &readfds);
	tv.tv_sec = 0;
	tv.tv_usec = 1000;
	configure_port(fd);
	while (1)
	{
		//sleep(1);
		retval = select(fd+1, &readfds, NULL, NULL, &tv);
		if (-1 == retval )
		{
			perror("select()");
		}
		else
		{
			IPC_vProcessCommands(fd, retval);
		}
		tv.tv_sec = 0;
		tv.tv_usec = 1000;
		FD_SET(fd, &readfds);
	}
	return(0);
}



int main(void)
{
	char* strings[] = {"hello ", "world\n"};
	char* strings2[] = {"hello ", "world2\n"};
	IPC_sfInit(enIpcChannelCtrlCommands);
	pthread_t thread1;
	pthread_t thread2;
	//pthread_init();
	pthread_create(&thread1, NULL, thread, strings);
	pthread_create(&thread2, NULL, thread_mon, strings2);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);


	printf("!!!Start Programm!!!\n");

	while(1)
	{
		sleep(1);
	}
}

