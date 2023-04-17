/*
 * ksdk_hal_rgbled.c
 *
 *  Created on: 13/04/2023
 *      Author: edusi
 */

#include "rgb/ksdk_hal_rgbled.h"

void ksdk_hal_ledrgb_init (void) {
		CLOCK_SYS_EnablePortClock(PORT_B_INSTANCE);
		CLOCK_SYS_EnablePortClock(PORT_D_INSTANCE);

		PORT_HAL_SetMuxMode(PORTB, PIN_LED_RED, PORT_MUX_AS_GPIO);
		PORT_HAL_SetMuxMode(PORTB, PIN_LED_GREEN, PORT_MUX_AS_GPIO);
		PORT_HAL_SetMuxMode(PORTD, PIN_LED_BLUE, PORT_MUX_AS_GPIO);

		GPIO_HAL_SetPinDir(GPIOB, PIN_LED_RED, PIN_AS_OUTPUT);
		GPIO_HAL_SetPinDir(GPIOB, PIN_LED_GREEN, PIN_AS_OUTPUT);
		GPIO_HAL_SetPinDir(GPIOD, PIN_LED_BLUE, PIN_AS_OUTPUT);

		ksdk_hal_ledrgb_clearRedLed();
		ksdk_hal_ledrgb_clearGreenLed();
		ksdk_hal_ledrgb_clearBlueLed();
}

void ksdk_hal_ledrgb_clearRedLed (void) {
	GPIO_HAL_SetPinOutput(GPIOB, PIN_LED_RED);
}

void ksdk_hal_ledrgb_setRedLed (void) {
	GPIO_HAL_ClearPinOutput(GPIOB, PIN_LED_RED);
}

void ksdk_hal_ledrgb_clearGreenLed (void) {
	GPIO_HAL_SetPinOutput(GPIOB, PIN_LED_GREEN);
}

void ksdk_hal_ledrgb_setGreenLed (void) {
	GPIO_HAL_ClearPinOutput(GPIOB, PIN_LED_GREEN);
}

void ksdk_hal_ledrgb_clearBlueLed (void) {
	GPIO_HAL_SetPinOutput(GPIOD, PIN_LED_BLUE);
}

void ksdk_hal_ledrgb_setBlueLed (void) {
	GPIO_HAL_ClearPinOutput(GPIOD, PIN_LED_BLUE);
}

