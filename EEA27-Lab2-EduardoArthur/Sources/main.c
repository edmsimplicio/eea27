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

#include "rgb/hal_rgbled.h"
#include "semaphor.h"

static int i = 0;

int main(void)
{
	hal_rgbled__setupRgbLed();
	int timeCounter = 0;

	// Set the semaphor starting state
	SemaphorState currentState = RED;
	hal_rgbled__setLedRed();

    /* Write your code here */
    while(1) {
    	switch(currentState){
    	case RED:
			if(timeCounter < 3 * TO_SECONDS){
				break;
			}

    		// Switch from RED to GREEN
    		timeCounter = 0;
    		currentState = GREEN;

    		// Clear colors and set LED to Red
			hal_rgbled__clearLedRed();
			hal_rgbled__clearLedGreen();
			hal_rgbled__clearLedBlue();

			hal_rgbled__setLedGreen();
    		break;


    	case YELLOW:
			if(timeCounter < 2 * TO_SECONDS){
				break;
			}

    		// Switch from YELLOW to RED
			timeCounter = 0;
			currentState = RED;

			// Clear colors and set LED to Red
			hal_rgbled__clearLedRed();
			hal_rgbled__clearLedGreen();
			hal_rgbled__clearLedBlue();

			hal_rgbled__setLedRed();
			break;


    	case GREEN:
			if(timeCounter < 4 * TO_SECONDS){
				break;
			}

    		// Switch from GREEN to YELLOW
    		timeCounter = 0;
			currentState = YELLOW;

			// Clear colors and set LED to YELLOW
			hal_rgbled__clearLedRed();
			hal_rgbled__clearLedGreen();
			hal_rgbled__clearLedBlue();

			hal_rgbled__setLedRed();
			hal_rgbled__setLedGreen();
    		break;


    	default:
    		currentState = RED;

    		// Clear colors and set LED to Red
			hal_rgbled__clearLedRed();
			hal_rgbled__clearLedGreen();
			hal_rgbled__clearLedBlue();

			hal_rgbled__setLedGreen();

			timeCounter = 0;

    		break;
    	}


    	++timeCounter;
    }
    /* Never leave main */
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
