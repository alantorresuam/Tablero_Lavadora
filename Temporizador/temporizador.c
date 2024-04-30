#include "hardware/gpio.h"
#include "temporizador.h"
#include "pico/stdlib.h"
#include <stdlib.h>
#include <stdio.h>

// Prepara el temporizador para su uso
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

// Inicializa los pines GPIO necesarios
void time_init(){
    for (int i = 0; i < PINS_SIZE_TIME; i++) { 
    gpio_init(pins[i]);
    gpio_set_dir(pins[i], GPIO_OUT);
    }
}



int decrementar(){
    // Se decrementa contador que sea multiplo de 10
    if(digito_unidades == 0 && digito_decenas > 0){
        digito_decenas -= 1;
        digito_unidades = 9;
    }
    // Una vez que se llegué a 0 se mantiene así
    else if(digito_decenas == 0 && digito_unidades == 0){
        return 0;
    } 
    // Se decrementan unidades en general
    else{
        digito_unidades -=1;
    }

    return (digito_decenas * 10) + digito_unidades;
}


void actualizar(int decenas, int unidades){
    digito_decenas = decenas;
    digito_unidades = unidades;

    // Calculamos la máscara para el dígito de decenas
    uint32_t mask_decenas = 0;
    for(int i = 0; i < PINS_SIZE_TIME-2; i++){
        uint32_t shift_mask = digits[decenas] >> i;
        shift_mask = shift_mask & 1;
        mask_decenas = mask_decenas | (shift_mask << pins[i]);
    }
    // Activamos los pines correspondientes al dígito de decenas
    gpio_set_mask(mask_decenas);
    gpio_put(digito1, 0);
    gpio_put(digito2, 1);
    sleep_ms(time_delay);
    gpio_clr_mask(mask_decenas);
    
    // Calculamos la máscara para el dígito de unidades
    uint32_t mask_unidades = 0;
    for(int i = 0; i < PINS_SIZE_TIME-2; i++){
        uint32_t shift_mask = digits[unidades] >> i;
        shift_mask = shift_mask & 1;
        mask_unidades = mask_unidades | (shift_mask << pins[i]); 
    }
    // Activamos los pines correspondientes al dígito de unidades
    gpio_set_mask(mask_unidades);
    gpio_put(digito1, 1);
    gpio_put(digito2, 0);
    sleep_ms(time_delay);
    gpio_clr_mask(mask_unidades);

}
