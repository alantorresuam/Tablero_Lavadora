#include <stdbool.h>
#include "pico/stdlib.h"

#define ENJUAGAR_PIN 15
#define LED_PIN 10

#define APAGADO 0
#define ENCENDIDO 1

int estado_led = APAGADO;

void controlar_led(int estado) {
    gpio_put(LED_PIN, estado);
}

bool verificar_enjuagar_presionado() {
    return !gpio_get(ENJUAGAR_PIN);
}

int main() {
    gpio_init(ENJUAGAR_PIN);
    gpio_init(LED_PIN);
    gpio_set_dir(ENJUAGAR_PIN, GPIO_IN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        if (verificar_enjuagar_presionado()) {
            // Espera un breve periodo de tiempo para evitar rebotes del botón
            sleep_ms(50);
            if (verificar_enjuagar_presionado()) {
                // Cambiar el estado del LED
                estado_led = (estado_led == APAGADO) ? ENCENDIDO : APAGADO;
                controlar_led(estado_led);
                // Esperar hasta que se suelte el botón
                while (verificar_enjuagar_presionado()) {
                    sleep_ms(50);
                }
            }
        }
    }

    return 0;
}