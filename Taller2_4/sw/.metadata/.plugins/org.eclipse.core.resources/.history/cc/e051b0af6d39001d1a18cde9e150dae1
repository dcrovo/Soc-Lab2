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

const alt_u8 NUMBERS[] = {
	//ABCDEFG
	 0b11111100, // 0
	 0b01100000, // 1
	 0b11011010, // 2
	 0b11110010, // 3
	 0b01100110, // 4
	 0b10110110, // 5
	 0b10111110, // 6
	 0b11100000, // 7
	 0b11111110, // 8
	 0b11100110,  // 9
	 0b00000000, // Blank
	 0b00000010 // Minus
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
int main()
{
	 off_hex();

	IOWR(HEX_0_BASE, 0, LETTERS[0]);


  return 0;
}
