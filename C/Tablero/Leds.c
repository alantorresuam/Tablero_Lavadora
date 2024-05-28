#include "hardware/gpio.h"
#include "leds.h"
#include "pico/stdlib.h"
#include <stdlib.h>
#include <stdio.h>

void construct_leds(int a[]){
    for(int i = 0; i < PINS_SIZE_LEDS; i++){
        leds[i] = a[i];
    }
}

void leds_init(){
    for (int i = 0; i < PINS_SIZE_LEDS; i++) { 
        gpio_init(leds[i]);
        gpio_set_dir(leds[i], GPIO_OUT);
    }
}

// INICIO ENCENDER_APAGAR
/**
 * @brief Turns off the washing machine.
 */
void apagar(){
    gpio_put(leds[0], 0);
}

/**
 * @brief Turns on the washing machine.
 */
void encender(){
    gpio_put(leds[0], 1);
}
// FIN ENCENDER_APAGAR


// INICIO PLAY_PAUSA
/**
 * @brief Turns in play the washing machine.
 */
void play(){
    gpio_put(leds[1], 1);
}

/**
 * @brief Turns in pausa the washing machine.
 */
void pausa(){
    gpio_put(leds[1], 0);
}
// FIN PLAY_PAUSA


//  INICIO LAVAR
void lavar(){
    gpio_put(leds[2], 1);
}
//  FIN LAVAR


//  INICIO ENJUAGAR
void enjuagar(){
    gpio_put(leds[3], 1);
}
//  FIN ENJUAGAR


// INICIO CENTRIFUGADO
void centrifugado(){
    gpio_put(leds[4], 1);
}
// FIN CENTRIFUGADO


//  INICIO TEMPERATURA (Agua caliente/tibia/fría)
/**
 * @brief ENCENDER LED DE AGUA FRIA.
 */
void fria(){
    printf("Agua fria\n");
}

/**
 * @brief ENCENDER LED DE AGUA TIBIA.
 */
void tibia(){
    printf("Agua tibia\n");

}

/**
 * @brief ENCENDER LED DE AGUA CALIENTE.
 */
void caliente(){
    printf("Agua caliente\n");

}
//  FIN TEMPERATURA (Agua caliente/tibia/fría)


// INICIO TIPO_LAVADO (normal/fuerte/ropa delicada)
/**
 * @brief Turns on the delicate washing mode LED.
 */
void delicado(){
    printf("Lavado delicado\n");
}

/**
 * @brief Turns on the normal washing mode LED.
 */
void normal(){
    printf("Lavado normal\n");
}

/**
 * @brief Turns on the strong washing mode LED.
 */
void fuerte(){
    printf("Lavado fuerte\n");
}
// FIN TIPO_LAVADO (normal/fuerte/ropa delicada)


// INCIO CARGA (liviana/media/pesada)
/**
 * @brief Turns on the light load LED.
 */
void liviana(){
    printf("Carga liviana\n");
}

/**
 * @brief Turns on the medium load LED.
 */
void media(){
    printf("Carga media\n");
}

/**
 * @brief Turns on the heavy load LED.
 */
void pesada(){
    printf("Carga pesada\n");
}
// FIN CARGA (liviana/media/pesada)