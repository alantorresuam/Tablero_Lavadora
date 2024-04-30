#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "Teclado.h"
#include "pico/stdlib.h"


void keypad_construct(const int a[]){
    for(int i=0; i<ROWS; i++)
        ROWS_PINS[i] = a[i];
    
    for(int i=0; i<COLS; i++)
        COLS_PINS[i] = a[i+ROWS];
    
    char keyValues[4][4] = {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}
    };

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            KEYS[i][j] = keyValues[i][j];
        }
    }
}