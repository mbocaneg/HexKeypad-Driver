/*
 * Keypad.h
 *
 *  Created on: Oct 7, 2018
 *      Author: Orion
 */

#ifndef KEYPAD_KEYPAD_H_
#define KEYPAD_KEYPAD_H_

#define HIGH 1
#define LOW 0

#define KEYDELAY 200
#define DEBOUNCE 30

#include <stdbool.h>
#include <string.h>
#include <inttypes.h>

/*
 * struct for representing a 4X4 Hex keypad.
 * */
typedef struct keypad_t{

	//char that represents a single keypress
	char keypress;

	//2d character array that represents the desired keymap for the keypad.
	char (*keymap)[4];

	/*
	 * "abstract" platform dependent functions represented a function pointers.
	 * These functions will assert a keypad row, read from a keypad column, and
	 * get the number of milliseconds elapsed. These must be implemented in config.c,
	 * and then pointed to during keypad initialization.
	 * */
	void (*_write_row)(uint8_t idx, uint8_t pinstate);
	bool (*_read_col)(uint8_t idx);
	uint32_t (*_get_ms_tick)(void);
}Keypad;

/*
 * functions for initializing the keypad and returning
 * keypresses.
 * */
void keypad_init(Keypad *keypad, char keymap[4][4]);
bool keypad_getchar(Keypad *keypad);

#endif /* KEYPAD_KEYPAD_H_ */
