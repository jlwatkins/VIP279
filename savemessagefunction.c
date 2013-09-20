#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
 
#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/time.h>
 
#include "../socketcan-isobus/patched/can.h"
#include "../socketcan-isobus/isobus.h"

//Altered version of print_message written by alex layton
void save_message(char interface[], struct timeval *ts, struct isobus_mesg *mes, char filename[]) 
{
	int i;

	/* Open file specified */
	fh = fopen(filename,"wt");

	/* Send CAN information into file */
	fprintf(fh, "%06d ", mes->pgn);
	for(i = 0; i < mes->dlen; i++) {
		fprintf(fh, " %02x", mes->data[i]);
	}
	fprintf(fh, "\t%ld.%06ld\t%s\n", ts->tv_sec, ts->tv_usec, interface);

	/* Flush output after each message */
	fflush(stdout);

	fclose(fh);
}

int main()
{
	//Open Socket CAN on windows/linux

	//Establish connection to sockets

	//See if messages are being received

	char file[] = "test1.txt";
	save_message(/* i have no idea */);
	
	return 0;
}