/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"
#include "alt_types.h"
#include "system.h"

#define delay 200000

const alt_u8 NUMBERS[] = {

	 0b11000000, // 0
	 0b11111001, // 1
	 0b10100100, // 2
	 0b10110000, // 3
	 0b10011001, // 4
	 0b10010010, // 5
	 0b10000010, // 6
	 0b11111000, // 7
	 0b10000000, // 8
	 0b10010000,  // 9
	 0b11111111, // Blank
	 0b10111111 // Minus
};

const alt_u8 LETTERS[] = {
	//ABCDEFG
		0b11101110, // a
		0b00111110, // b
		0b10011100, // c
		0b01111010, // d
		0b10011110, // e
		0b10001110, // f
		0b10111100, // g
		0b01101110, // h
		0b00001100, // i
		0b01111000, // j
		0b10101110, // k
		0b00011100, // l
		0b11101100, // m
		0b00101010, // n
		0b00111010, // o
		0b11001110, // p
		0b11100110, // q
		0b10001100, // r
		0b10110110, // s
		0b00011110, // t
		0b00111000, // u
		0b01111100, // v
		0b01111110, // w
		0b01101100, // x
		0b01110110, // y
		0b11011010, // z
		0b00000000 // Blank
};

void off_hex(){

	IOWR(HEX_0_BASE, 0, 127);
	IOWR(HEX_1_BASE, 0, 127);
	IOWR(HEX_2_BASE, 0, 127);
	IOWR(HEX_3_BASE, 0, 127);
	IOWR(HEX_4_BASE, 0, 127);
	IOWR(HEX_5_BASE, 0, 127);

}
void on_hex(){

	IOWR(HEX_0_BASE, 0, 0);
	IOWR(HEX_1_BASE, 0, 0);
	IOWR(HEX_2_BASE, 0, 0);
	IOWR(HEX_3_BASE, 0, 0);
	IOWR(HEX_4_BASE, 0, 0);
	IOWR(HEX_5_BASE, 0, 0);

}

void display_msg_left(char *msg, int *command){
	int l = (int)strlen(msg);
	int counters[6] = {0,1,2,3,4,5};

	while(1){
		get_sw(SW_BASE, command);
		if(*command == 0)
		{
			while(*command == 0)
			{
				get_sw(SW_BASE, command);
				usleep(10);
				if(*command == 3){	break;}

			}

		}
		if(*command == 3){	break;}


		if(counters[0] == l){counters[0]=0;}
		if(counters[1] == l){counters[1]=0;}
		if(counters[2] == l){counters[2]=0;}
		if(counters[3] == l){counters[3]=0;}
		if(counters[4] == l){counters[4]=0;}
		if(counters[5] == l){counters[5]=0;}

		IOWR(HEX_0_BASE, 0, NUMBERS[msg[counters[5]]-'0']);
		IOWR(HEX_1_BASE, 0, NUMBERS[msg[counters[4]]-'0']);
		IOWR(HEX_2_BASE, 0, NUMBERS[msg[counters[3]]-'0']);
		IOWR(HEX_3_BASE, 0, NUMBERS[msg[counters[2]]-'0']);
		IOWR(HEX_4_BASE, 0, NUMBERS[msg[counters[1]]-'0']);
		IOWR(HEX_5_BASE, 0, NUMBERS[msg[counters[0]]-'0']);
		counters[0]++;
		counters[1]++;
		counters[2]++;
		counters[3]++;
		counters[4]++;
		counters[5]++;

		usleep(delay*2);
	}

}
void display_msg_rigth(char *msg, int *command){
	int l = (int)strlen(msg);
	int counters[6] = {0,1,2,3,4,5};

	while(1){
		get_sw(SW_BASE, command);
		if(*command == 1)
		{
			while(*command == 1)
			{
				get_sw(SW_BASE, command);
				usleep(10);
				if(*command == 2){	break;}

			}

		}
		if(*command == 2){	break;}		if(counters[0] == l){counters[0]=0;}
		if(counters[1] == l){counters[1]=0;}
		if(counters[2] == l){counters[2]=0;}
		if(counters[3] == l){counters[3]=0;}
		if(counters[4] == l){counters[4]=0;}
		if(counters[5] == l){counters[5]=0;}

		IOWR(HEX_5_BASE, 0, NUMBERS[msg[counters[5]]-'0']);
		IOWR(HEX_4_BASE, 0, NUMBERS[msg[counters[4]]-'0']);
		IOWR(HEX_3_BASE, 0, NUMBERS[msg[counters[3]]-'0']);
		IOWR(HEX_2_BASE, 0, NUMBERS[msg[counters[2]]-'0']);
		IOWR(HEX_1_BASE, 0, NUMBERS[msg[counters[1]]-'0']);
		IOWR(HEX_0_BASE, 0, NUMBERS[msg[counters[0]]-'0']);
		counters[0]++;
		counters[1]++;
		counters[2]++;
		counters[3]++;
		counters[4]++;
		counters[5]++;

		usleep(delay*2);
	}

}
void display_status(alt_u32 sw_base, int *hex_status[], int *command){
		IOWR(HEX_0_BASE, 0, hex_status[0]);
		IOWR(HEX_1_BASE, 0, hex_status[1]);
		IOWR(HEX_2_BASE, 0, hex_status[2]);
		IOWR(HEX_3_BASE, 0, hex_status[3]);
		IOWR(HEX_4_BASE, 0, hex_status[4]);
		IOWR(HEX_5_BASE, 0, hex_status[5]);

}
void get_sw(alt_u32 sw_base, int *command){
	*command = IORD(sw_base,0);

}
int main()
{
	 int command;
	// int hex_status[6];
	 char *msg ="0123456789";
	 while(1){
		 get_sw(SW_BASE, &command);

		 switch(command){
		 case 2:
			 display_msg_left(msg, &command);
			 break;
		 case 3:
			 display_msg_rigth(msg, &command);
			 break;
		 case 0:
			 break;
//			 display_status(SW_BASE, &hex_status);


		 }

}

  return 0;
}
