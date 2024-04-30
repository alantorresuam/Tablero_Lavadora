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

// Inicializar los puestos del teclado
void keypad_init() {
    for (int i = 0; i < ROWS; i++) {
        gpio_init(ROWS_PINS[i]);
        gpio_set_dir(ROWS_PINS[i], GPIO_OUT);
    }

    for (int i = 0; i < COLS; i++) {
        gpio_init(COLS_PINS[i]);
        gpio_set_dir(COLS_PINS[i], GPIO_IN);
        gpio_pull_down(COLS_PINS[i]);
    }
}

char read_keypad() {
    // Escanear las filas
    for (int i = 0; i < ROWS; i++) {
        gpio_put(ROWS_PINS[i], 1);

        // Leer las columnas
        for (int j = 0; j < COLS; j++) {
            if (gpio_get(COLS_PINS[j]) == 1) {
                gpio_put(ROWS_PINS[i], 0); 
                return KEYS[i][j]; 
            }
        }

        gpio_put(ROWS_PINS[i], 0); 
    }

    return '\0'; 
}
