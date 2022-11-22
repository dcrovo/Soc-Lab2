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
#include "io.h"
#include "alt_types.h"
#include "system.h"

#define delay 10000

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
void light_up_square(alt_u32 hex_base){
	off_hex();
	static alt_u8 upsquare_data = 0b00011100;
	IOWR(hex_base, 0, upsquare_data);
}
void light_down_square(alt_u32 hex_base){
	off_hex();
	static alt_u8 upsquare_data = 0b00100011;
	IOWR(hex_base, 0, upsquare_data);
}

void get_command(alt_u32 sw_base, int *command, int *freq){
	int sw_read = IORD(sw_base,0);
	int	sw_freq = sw_read;
	int sw_5 = ((sw_read >> 5) & 1);
	int sw_6 = ((sw_read >> 6) & 1);
	*command = 0;
	*command |= sw_5 << 5;
	*command |= sw_6 << 6;

	sw_freq &= ~(1 << 5);
	sw_freq &= ~(1 << 6);
	*freq = (sw_freq + 1)*delay;

}


void rotate_right(alt_32 switch_base, alt_u32 hex_base[], int *freq, int *command){

	for(int i=5;i>=0;i--){
		get_command(switch_base, command, freq);
		if(*command == 0 || *command ==32 || *command == 96){break;}
		light_up_square(hex_base[i]);
		usleep(*freq);
	}
	for(int i=0;i<=5;i++){
			get_command(switch_base, command, freq);
			if(*command == 0 || *command ==32 || *command == 96){break;}
			light_down_square(hex_base[i]);
			usleep(*freq);
		}
}

void rotate_left(alt_32 switch_base, alt_u32 hex_base[], int *freq, int *command){

	for(int i=0;i<=5;i++){
		get_command(switch_base, command, freq);
		if(*command == 0 || *command ==32 || *command == 64){break;}
		light_up_square(hex_base[i]);
		usleep(*freq);
	}
	for(int i=5;i>=0;i--){

		get_command(switch_base, command, freq);
		if(*command == 0 || *command ==32 || *command == 64){break;}
		light_down_square(hex_base[i]);
		usleep(*freq);
	}
}
int main()
{
	int command;
	int freq;
	alt_u32 HEX_BASE[]={HEX_0_BASE, HEX_1_BASE, HEX_2_BASE, HEX_3_BASE, HEX_4_BASE, HEX_5_BASE};
	while(1){

		get_command(SWITCH_BASE, &command, &freq);

		switch(command){
		case 0:
			off_hex();
			break;
		case 32:
			off_hex();
			break;
		case 64: //  ON CASE and Right Direction
			rotate_right(SWITCH_BASE, HEX_BASE, &freq, &command);
			break;
		case 96: // Left direction
			rotate_left(SWITCH_BASE, HEX_BASE, &freq, &command);
			break;
		default:
			on_hex();

		}
	}



  return 0;
}
