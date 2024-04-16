#include <stdbool.h>
#include "pico/stdlib.h"

#define LAVAR_PIN 14
#define LED_PIN 10

#define APAGADO 0
#define ENCENDIDO 1

int estado_led = APAGADO;

void controlar_led(int estado) {
    gpio_put(LED_PIN, estado);
}

bool verificar_lavar_presionado() {
    return !gpio_get(LAVAR_PIN);
}

int main() {
    gpio_init(LAVAR_PIN);
    gpio_init(LED_PIN);
    gpio_set_dir(LAVAR_PIN, GPIO_IN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        if (verificar_lavar_presionado()) {
            sleep_ms(50);
            if (verificar_lavar_presionado()) {
                estado_led = (estado_led == APAGADO) ? ENCENDIDO : APAGADO;
                controlar_led(estado_led);
                while (verificar_lavar_presionado()) {
                    sleep_ms(50);
                }
            }
        }
    }

    return 0;
}