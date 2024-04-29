#include "temporizador.h"
#include "pico/stdlib.h"
#include <stdlib.h>
#include "pin_list_display.h"

void time_construct(int a[]){
    for(int i = 0; i < PINS_SIZE; i++){
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
    digito1 = PIN_DIGITO1;
    digito2 = PIN_DIGITO2;
    mask = 0;

}

void time_init(){
    for (int i = 0; i < PINS_SIZE-2; i++) { // Corrección del rango
        gpio_init(pins[i]);
        gpio_set_dir(pins[i], GPIO_OUT);
    }
    gpio_init(digito1); // Configurar como salida
    gpio_set_dir(digito1, GPIO_OUT);
    gpio_init(digito2); // Configurar como salida
    gpio_set_dir(digito2, GPIO_OUT);
}



int decrementar(){
    if(digito_unidades == 0 && digito_decenas > 0){
        digito_decenas -= 1;
        digito_unidades = 9;
    }
    else if(digito_decenas == 0 && digito_unidades == 0){
        return 0;
    } else{
        digito_unidades -=1;
    }

    return (digito_decenas * 10) + digito_unidades;
}

void actualizar(int decenas, int unidades){
    digito_decenas = decenas;
    digito_unidades = unidades;

    // Calculamos la máscara para el dígito de decenas
    uint32_t mask_decenas = 0;
    for(int i = 0; i < PINS_SIZE-2; i++){
        uint32_t shift_mask = digits[decenas] >> i;
        printf("decena: %d\t", decenas);
        shift_mask = shift_mask & 1;
        printf("shift_mask 1: %d\t", shift_mask);
        mask_decenas = mask_decenas | (shift_mask << pins[i]); // Utilizamos el array pins para configurar los pines
        printf("mascara 1: %d \n", mask_decenas);
    }
    

    // Activamos los pines correspondientes al dígito de decenas
    gpio_set_mask(mask_decenas);
    gpio_put(digito1, 1);
    gpio_put(digito2, 0);
    sleep_ms(time_delay);
    gpio_clr_mask(mask_decenas);
    

    // Calculamos la máscara para el dígito de unidades
    uint32_t mask_unidades = 0;
    for(int i = 0; i < PINS_SIZE-2; i++){
        uint32_t shift_mask = digits[unidades] >> i;
        printf("unidad: %d\t", unidades);
        shift_mask = shift_mask & 1;
        printf("shift_mask 2: %d\n", shift_mask);
        mask_unidades = mask_unidades | (shift_mask << pins[i]); // Utilizamos el array pins para configurar los pines
        printf("mascara 2: %d\n", mask_unidades);
    }

    // Activamos los pines correspondientes al dígito de unidades
    gpio_set_mask(mask_unidades);
    gpio_put(digito1, 0);
    gpio_put(digito2, 1);
    sleep_ms(time_delay);
    gpio_clr_mask(mask_unidades);

    printf("tiempo: %d%d", decenas, unidades);
}
