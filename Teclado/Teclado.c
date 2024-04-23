#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/gpio.h"

#define ROWS 4
#define COLS 4

const uint ROW_PINS[ROWS] = {2, 3, 4, 5}; 
const uint COL_PINS[COLS] = {6, 7, 8, 9}; 


void keypad_init() {
    for (int i = 0; i < ROWS; i++) {
        gpio_init(ROW_PINS[i]);
        gpio_set_dir(ROW_PINS[i], GPIO_OUT);
    }

    for (int i = 0; i < COLS; i++) {
        gpio_init(COL_PINS[i]);
        gpio_set_dir(COL_PINS[i], GPIO_IN);
        gpio_pull_down(COL_PINS[i]);
    }
}
