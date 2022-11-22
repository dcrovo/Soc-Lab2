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

void sw_get_command(alt_u32 sw_base, int *prd)
{
	*prd = (IORD(sw_base, 0) + 2) ;
}

void read_key(alt_u32 button_base, int *status){

	*status = IORD(button_base,0);

}

void led_flash(alt_u32 led_base, alt_u32 button_base, int *prd, int *status)
{
	alt_u32 data = 0;
	for(int j=0;j<10;j++){
		read_key(button_base, status);
		if(!*status){
			break;
		}
		data = data & 0;
		data = data | 1 << j;
		data = data | 1 << (9-j);

		IOWR(LED_BASE,0,data);
		sw_get_command(SWITCH_BASE, prd);
		usleep(delay*(*prd));
	}


}

int main()
{
	int prd;
	int status;
	while(1)
	{
		read_key(BUTTON_BASE, &status);
		switch(status){
		case 0:
			IOWR(LED_BASE,0,1);
			IOWR(LED_BASE,0,512);
			break;
		default:
			sw_get_command(SWITCH_BASE, &prd);
			led_flash(LED_BASE, BUTTON_BASE, &prd, &status);
		}

	}
  return 0;
}
