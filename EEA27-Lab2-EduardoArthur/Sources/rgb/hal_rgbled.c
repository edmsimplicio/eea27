/*
 * hal_rgbled.c
 *
 *  Created on: 11/04/2023
 *      Author: edusi
 */

#include "hal_rgbled.h"

void hal_rgbled__setupRgbLed() {
	// Enable clock gating
	SIM_SCGC5 = SIM_SCGC5 | (SCGC_PORT_VALUE << SIM_SCGC5_PORTB_SHIFT);
	SIM_SCGC5 = SIM_SCGC5 | (SCGC_PORT_VALUE << SIM_SCGC5_PORTD_SHIFT);

	// Set up port MUX
	PORTB_PCR18 = PORTB_PCR18 | (PCR_MUX_VALUE << PORT_PCR_MUX_SHIFT);
	PORTB_PCR19 = PORTB_PCR19 | (PCR_MUX_VALUE << PORT_PCR_MUX_SHIFT);
	PORTD_PCR1 = PORTD_PCR1 | (PCR_MUX_VALUE << PORT_PCR_MUX_SHIFT);

	// Set up GPIO data direction
	GPIOB_PDDR = GPIOB_PDDR | (PDD_OUTPUT << PDD_SHIFT_RED);
	GPIOB_PDDR = GPIOB_PDDR | (PDD_OUTPUT << PDD_SHIFT_GREEN);
	GPIOD_PDDR = GPIOD_PDDR | (PDD_OUTPUT << PDD_SHIFT_BLUE);

	// Turn off all the LEDs
	hal_rgbled__clearLedRed();
	hal_rgbled__clearLedGreen();
	hal_rgbled__clearLedBlue();
}

void hal_rgbled__setLedRed(){
	GPIOB_PDOR = GPIOB_PDOR & ~(1 << PDD_SHIFT_RED);
}

void hal_rgbled__setLedGreen(){
	GPIOB_PDOR = GPIOB_PDOR & ~(1 << PDD_SHIFT_GREEN);
}

void hal_rgbled__setLedBlue(){
	GPIOD_PDOR = GPIOD_PDOR & ~(1 << PDD_SHIFT_BLUE);
}

void hal_rgbled__clearLedRed(){
	GPIOB_PDOR = GPIOB_PDOR | (1 << PDD_SHIFT_RED);
}

void hal_rgbled__clearLedGreen(){
	GPIOB_PDOR = GPIOB_PDOR | (1 << PDD_SHIFT_GREEN);
}

void hal_rgbled__clearLedBlue(){
	GPIOD_PDOR = GPIOD_PDOR | (1 << PDD_SHIFT_BLUE);
}
