/*
 * config.h
 *
 *  Created on: Oct 7, 2018
 *      Author: Orion
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_
#include "stm32f1xx_hal.h"
#include <stdbool.h>

#define HIGH 1
#define LOW 0

/*
 * header file for configuring platform specific functionalities. Three "abstract" functions must
 * be implemented for the driver to function properly, which are _get_ms_tick, _write_row, and
 * _read_col. Implementations will vary depending on the MCU you might be targeting.
 * */

static char keymap[4][4] = { { '1', '2', '3', 'A' }, { '4', '5', '6', 'B' }, { '7', '8',
		'9', 'C' }, { '*', '0', '#', 'D' } };

/*
 * These 3 "abstract" functions must be implemented for the platform you are targeting
 * */

/*
 * Function that returns the number of milliseconds elapsed after boot. Most MCUs offer
 * this functionality, e.g. Arduino's millis() or STM32's HAL_GetTick(), but it could
 * just as easily be implemented using a timer.
 * */
uint32_t _get_ms_tick(void);

/*
 * Function that simply sets/resets a keypad row. Again, this will vary from MCU to MCU, but
 * this would usually be done by toggling a GPIO pin.
 * */
void _write_row(uint8_t idx, uint8_t pinstate);

/*
 * Function that reads in a keypad row. This will usually be implemented by reading in a
 * GPIO pin. MAKE SURE SAID GPIO IS CONFIGURED WITH A PULLUP, EITHER INTERNALLY OR
 * WITH AN EXTERNAL RESISTOR.
 * */
bool _read_col(uint8_t idx);

#endif /* KEYPAD_CONFIG_H_ */
