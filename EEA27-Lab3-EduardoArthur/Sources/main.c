/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


/* system includes */
#include "fsl_clock_manager.h"
#include "fsl_port_hal.h"
#include "fsl_gpio_hal.h"
#include "debug/print_scan.h"
#include "uart/ksdk_hal_debugUart.h"

#include "rgb/ksdk_hal_rgbled.h"

int main(void)
{
	// Initialize the RGB LED device
	ksdk_hal_ledrgb_init();

	ksdk_hal_ledrgb_clearGreenLed();
	ksdk_hal_ledrgb_setGreenLed();

	// Collected argument count
	int readArguments = 0;
	unsigned char readCommand[4];
	debugUart_init();

    /* Write your code here */
    while(1) {
    	debug_printf("Current Command: ");

    	// Read 4 arguments
    	while(readArguments < 4){
    		readCommand[readArguments] = debug_getchar();
        	debug_printf("%c", readCommand[readArguments]);
        	++readArguments;
    	}

    	// Reset the argument counter
    	readArguments = 0;
    	debug_printf("\n\r");

    	// Check if the command follows the specified structure.
    	if(readCommand[0] == 'L' &&
    			(readCommand[1] == '0' || readCommand[1] == '1') &&
    			(readCommand[2] == '0' || readCommand[2] == '1') &&
				(readCommand[3] == '0' || readCommand[3] == '1')){
    		// Set the Red LED
			if(readCommand[1] == '0')
				ksdk_hal_ledrgb_clearRedLed();
			else
				ksdk_hal_ledrgb_setRedLed();

    		// Set the Green LED
    		if(readCommand[2] == '0')
    			ksdk_hal_ledrgb_clearGreenLed();
    		else
    			ksdk_hal_ledrgb_setGreenLed();

    		// Set the Blue LED
			if(readCommand[3] == '0')
				ksdk_hal_ledrgb_clearBlueLed();
			else
				ksdk_hal_ledrgb_setBlueLed();
    	}
    	else
    		debug_printf("Please, follow the pattern: LRGB, with R, B and G as {0,1}.\n\r");


    }
    /* Never leave main */
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
