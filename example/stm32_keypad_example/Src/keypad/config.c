/*
 * config.c
 *
 *  Created on: Oct 7, 2018
 *      Author: Orion
 */
#include "config.h"

/*
 * Sample configuration file for an STM32 based MCU.
 * */

/*
 * Keypad rows and columns are implemented as parallel arrays. One array holds the GPIO
 * port for a row/column given by an array index. The other array holds the actual GPIO
 * pin number for a row/column given by an array index.
 * */

GPIO_TypeDef *r_port[] = {GPIOA, GPIOA, GPIOA, GPIOA};
uint16_t r_array[] = { GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3 };

GPIO_TypeDef *c_port[] = {GPIOA, GPIOA, GPIOA, GPIOA};
uint16_t c_array[] = { GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7 };

/*
 * _get_ms_tick is implemented by simply calling STM32's HAL_GetTick() function
 * */
uint32_t _get_ms_tick(void) {
	return HAL_GetTick();
}

/*
 * _write_row is implemented by setting/resetting a GPIO pin. This pin is located at
 * a GPIO port pointed to by r_port[idx], and pin number given by r_array[idx]
 * */
void _write_row(uint8_t idx, uint8_t pinstate){
	GPIO_PinState PinState = (pinstate == HIGH)? GPIO_PIN_SET:GPIO_PIN_RESET;
	HAL_GPIO_WritePin(r_port[idx], r_array[idx], PinState);
}

/*
 * _read_col is implemented by reading a GPIO pin at GPIO port c_port[idx], and
 * pin number given by c_array[idx]
 * */
bool _read_col(uint8_t idx){
	if(HAL_GPIO_ReadPin(c_port[idx], c_array[idx]))
		return true;
	else
		return false;
}
