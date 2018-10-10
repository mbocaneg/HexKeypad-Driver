/*
 * Keypad.c
 *
 *  Created on: Oct 7, 2018
 *      Author: Orion
 */

#include "Keypad.h"

/*
 * Keypad intialization routine. It simply configures the keymap
 * member of a Keypad struct(passed in as a ponter) to a 4X4
 * character keymap provided by the user, and sets the keypress
 * member to ' ' character.
 * */
void keypad_init(Keypad *keypad, char keymap[4][4]) {
	keypad->keymap = &keymap[0];
	keypad->keypress = ' ';
}

/*
 * Helpful function that sets all keypad rows HIGH. Declare it as static
 * as user really has no need to use it.
 * */
static void keypad_all_rows_set(Keypad *keypad) {
	if (keypad->_write_row != NULL) {
		keypad->_write_row(0, HIGH);
		keypad->_write_row(1, HIGH);
		keypad->_write_row(2, HIGH);
		keypad->_write_row(3, HIGH);
	}
}

/*
 * function that gets a single keypress from the keypad.
 * If one is detected, it returns true and said keypress
 * is stored in the keypress member of the keypad struct
 * passed into the function. If no keypress is found, then
 * the function simply returns false.
 * */
bool keypad_getchar(Keypad *keypad) {

	//set all keypad rows HIGH
	keypad_all_rows_set(keypad);

	//for all keypad rows...
	for (int i = 0; i < 4; i++) {

		keypad->_write_row(i, LOW);

		//..and for all keypad columns
		for (int j = 0; j < 4; j++) {

			//if a potential keypress is detected...
			if (!keypad->_read_col(j)) {
				//debounce the potential keypress by sampling it again after a DEBOUNCE period.
				uint32_t debounce_start = keypad->_get_ms_tick();
				while (keypad->_get_ms_tick() - debounce_start < DEBOUNCE) {}

				//if it really is a keypress...
				if (!keypad->_read_col(j)) {
					//get the current time in ms
					uint32_t now = keypad->_get_ms_tick();
					//get the keypress character by looking it up in the keymap array
					keypad->keypress = keypad->keymap[i][j];
					//deassert the keypad rows by setting them HIGH
					keypad_all_rows_set(keypad);
					//wait a while so as to not register multiple keypresses
					while (keypad->_get_ms_tick() - now < KEYDELAY) {
					}
					//...and return true
					return true;
				}

			}

		}
		//if no key was found to be pressed within the current row deassert the row
		keypad->_write_row(i, HIGH);
	}
	//if no keypress was found, return false.
	return false;
}
