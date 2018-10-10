# HexKeypad-Driver
A platform agnostic driver for 4X4 hex keypads, such as the one found here: https://www.ebay.com/itm/4x4-Matrix-Array-16-Key-Membrane-Switch-Keypad-Keyboard-Arduino-AVR-Raspberry-Pi/232362364509?hash=item3619e04e5d:g:HN4AAOSwFnFV~NSx:rk:2:pf:0

# Usage
The driver consists of 4 files; config.c/.h, and Keypad.c/h. In order to properly use the driver, 3 functions must be implemented. Said functions can be found in config.c. These are:
```c
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
```

Next, you must provide a desired keymap. The standard keymap for this keypad is provided in config.h as follows:
```c
static char keymap[4][4] = { { '1', '2', '3', 'A' }, { '4', '5', '6', 'B' }, { '7', '8',
		'9', 'C' }, { '*', '0', '#', 'D' } };
```
But you may change this to your liking. You can add the driver to your project as follows:
```c
#include "keypad/Keypad.h"
#include "keypad/config.h"

int main(){
    ...
    Keypad keypad;
    keypad._write_row = _write_row;
    keypad._read_col = _read_col;
    keypad._get_ms_tick = _get_ms_tick;
    keypad_init(&keypad, keymap);

    while(1){
        ...
        if(keypad_getchar(&keypad)){
            printf(str_buf, "Key pressed: %c\r\n", keypad.keypress);
        }
    }
}
```
An example STM32 CUBEMX project for an STM32F103C8 MCU is provided for your conveniance.