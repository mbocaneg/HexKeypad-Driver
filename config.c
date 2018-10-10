
#include "config.h"

/*
 * Function that returns the number of milliseconds elapsed after boot. Most MCUs offer
 * this functionality, e.g. Arduino's millis() or STM32's HAL_GetTick(), but it could
 * just as easily be implemented using a timer.
 * */
uint32_t _get_ms_tick(void) {
	return 0;
}

/*
 * Function that simply sets/resets a keypad row. Again, this will vary from MCU to MCU, but
 * this would usually be done by toggling a GPIO pin.
 * */
void _write_row(uint8_t idx, uint8_t pinstate){
	return;
}

/*
 * Function that reads in a keypad row. This will usually be implemented by reading in a
 * GPIO pin. MAKE SURE SAID GPIO IS CONFIGURED WITH A PULLUP, EITHER INTERNALLY OR
 * WITH AN EXTERNAL RESISTOR.
 * */
bool _read_col(uint8_t idx){
	return false;
}
