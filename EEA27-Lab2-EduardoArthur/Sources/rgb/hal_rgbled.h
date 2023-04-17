/*
 * hal_rgbled.h
 *
 *  Created on: 11/04/2023
 *      Author: edusi
 */

#ifndef HAL_RGBLED_H_
#define HAL_RGBLED_H_

#include "fsl_device_registers.h"

/*************************************************/
/* Constants for setting registers               */
/*************************************************/
// Convert system ticks to seconds
#define TO_SECONDS 1000000

// System Clock Gating Control
#define SCGC_PORT_VALUE 1

// Pin Control Register n
#define PCR_MUX_VALUE 0x001

// Port Data Direction Register
#define PDD_OUTPUT 0x1
#define PDD_SHIFT_RED 18
#define PDD_SHIFT_GREEN 19
#define PDD_SHIFT_BLUE 1

/*************************************************/
/* Functions to set the LEDs                     */
/*************************************************/
// LED setup function
void hal_rgbled__setupRgbLed();

// LED colors function
// Turn on the respective LED
void hal_rgbled__setLedRed();
void hal_rgbled__setLedGreen();
void hal_rgbled__setLedBlue();

// Turn off the respective LED
void hal_rgbled__clearLedRed();
void hal_rgbled__clearLedGreen();
void hal_rgbled__clearLedBlue();

#endif /* HAL_RGBLED_H_ */



