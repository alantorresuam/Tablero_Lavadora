#include <stdbool.h>
#include <carga.h>
#include "pico/stdlib.h"


#define LIGERA 0
#define MEDIA 1
#define PESADA 2

#define LED_1_PIN 19
#define LED_2_PIN 20
#define BOTON_PIN 34


void seleccionar_carga(int estado_carga) {
    estado_carga = (estado_carga + 1) % 3;
    switch(estado_carga) {
        case LIGERA:
        encender_led1();
        apagar_led2();
        break;
        case MEDIA:
        apagar_led1();
        encender_led2();
        break;
        case PESADA:
        encender_led1();
        encender_led2();
        break;
    }
}

void encender_led1() {
    gpio_put(LED_1_PIN, 1);
}

void encender_led2() {
    gpio_put(LED_2_PIN, 1);
}

void apagar_led1() {
    gpio_put(LED_1_PIN, 0);
}

void apagar_led2() {
    gpio_put(LED_2_PIN, 0);
}


bool verificar_boton_presionado() {
    return !gpio_get(BOTON_PIN);
}

int main() {
    gpio_init(LED_1_PIN);
    gpio_init(LED_2_PIN);
    gpio_init(BOTON_PIN);
    gpio_set_dir(LED_1_PIN, GPIO_OUT);
    gpio_set_dir(LED_2_PIN, GPIO_OUT);
    gpio_set_dir(BOTON_PIN, GPIO_IN);
    int estado_carga = LIGERA;
    
    while(true) {
        if(verificar_boton_presionado()) {
            sleep_ms(1500); 
            if(verificar_boton_presionado()) {
                seleccionar_carga();
            }
        }
    }
    return 0;
}