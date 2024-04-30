#include "hardware/gpio.h"
#include "temporizador.h"
#include "pico/stdlib.h"
#include <stdlib.h>
#include <stdio.h>

void time_construct(int a[]){
    for(int i = 0; i < PINS_SIZE_TIME; i++){
        pins[i] = a[i];
    }

    int bits[10] = {
        0x3f,  // 0
        0x06,  // 1
        0x5b,  // 2
        0x4f,  // 3
        0x66,  // 4
        0x6d,  // 5
        0x7d,  // 6
        0x07,  // 7
        0x7f,  // 8
        0x67   // 9
    };

    for(int i = 0; i < DIGIT_SIZE; i++){
        digits[i] = bits[i];
    }

    digito_decenas = 0;
    digito_unidades = 0;
    digito1 = a[PINS_SIZE_TIME-2];
    digito2 = a[PINS_SIZE_TIME-1];
    mask = 0;

}

void time_init(){
    for (int i = 0; i < PINS_SIZE_TIME; i++) { 
    gpio_init(pins[i]);
    gpio_set_dir(pins[i], GPIO_OUT);
    }
}



int decrementar(){

}


void actualizar(int decenas, int unidades){

}