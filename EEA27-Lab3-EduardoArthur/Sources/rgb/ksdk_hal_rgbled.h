/*
 * ksdk_hal_rgbled.h
 *
 *  Created on: 13/04/2023
 *      Author: edusi
 */

#ifndef SOURCES_RGB_KSDK_HAL_RGBLED_H_
#define SOURCES_RGB_KSDK_HAL_RGBLED_H_

/* system includes */
#include "fsl_clock_manager.h"
#include "fsl_port_hal.h"
#include "fsl_gpio_hal.h"

#define PORT_B_INSTANCE 1
#define PORT_D_INSTANCE 3

#define PIN_LED_RED 18
#define PIN_LED_GREEN 19
#define PIN_LED_BLUE 1

#define PORT_MUX_AS_GPIO 1U
#define PIN_AS_OUTPUT 1U

/* ************************************************ */
/* Method name: ksdk_hal_ledrgb_init			    */
/* Method description: Initialize the RGB LED device*/
/* Input params: n/a 								*/
/* Output params: n/a 								*/
/* ************************************************ */
void ksdk_hal_ledrgb_init (void);


/* ************************************************ */
/* Method name: ksdk_hal_ledrgb_clearRedLed 		*/
/* Method description: Clear the "red" led from RGB	*/
/* Input params: n/a 								*/
/* Output params: n/a								*/
/* ************************************************ */
void ksdk_hal_ledrgb_clearRedLed (void);


/* ************************************************ */
/* Method name: ksdk_hal_ledrgb_setRedLed 			*/
/* Method description: Set the " red " led from RGB */
/* Input params: n/a								*/
/* Output params: n/a 								*/
/* ************************************************ */
void ksdk_hal_ledrgb_setRedLed (void);


/* ************************************************ */
/* Method name: ksdk_hal_ledrgb_clearGreenLed 		*/
/* Method description: Clear the"green"led from RGB */
/* Input params: n/a 								*/
/* Output params: n/a 								*/
/* ************************************************ */
void ksdk_hal_ledrgb_clearGreenLed (void);


/* ************************************************ */
/* Method name: ksdk_hal_ledrgb_setGreenLed 		*/
/* Method description: Set the "green" led from RGB */
/* Input params: n/a 								*/
/* Output params: n/a 								*/
/* ************************************************ */
void ksdk_hal_ledrgb_setGreenLed (void);


/* ************************************************ */
/* Method name: ksdk_hal_ledrgb_clearBlueLed		*/
/* Method description: Clear the "blue" led from RGB*/
/* Input params: n/a 								*/
/* Output params: n/a 								*/
/* ************************************************ */
void ksdk_hal_ledrgb_clearBlueLed (void);


/* ************************************************ */
/* Method name: ksdk_hal_ledrgb_setBlueLed			*/
/* Method description: Set the "blue" led from RGB  */
/* Input params: n/a 								*/
/* Output params: n/a								*/
/* ************************************************ */
void ksdk_hal_ledrgb_setBlueLed (void);

#endif /* SOURCES_RGB_KSDK_HAL_RGBLED_H_ */
