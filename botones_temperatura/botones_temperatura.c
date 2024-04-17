#include "botones_temperatura.h"
#include "pico/stdlib.h"

#define BOTON_PIN          2
#define LED_FRIO_PIN       14
#define LED_TIBIO_PIN      15
#define LED_CALIENTE_PIN   16

int contador = 0;

void inicializar_botones_temperatura() {
    gpio_init(BOTON_PIN);
    gpio_set_dir(BOTON_PIN, GPIO_IN);
    gpio_pull_up(BOTON_PIN);

    gpio_init(LED_FRIO_PIN);
    gpio_set_dir(LED_FRIO_PIN, GPIO_OUT);

    gpio_init(LED_TIBIO_PIN);
    gpio_set_dir(LED_TIBIO_PIN, GPIO_OUT);

    gpio_init(LED_CALIENTE_PIN);
    gpio_set_dir(LED_CALIENTE_PIN, GPIO_OUT);
}

void verificar_botones_temperatura() {
    if (!gpio_get(BOTON_PIN)) {
        sleep_ms(20); // Debounce
        if (!gpio_get(BOTON_PIN)) {
            contador++;
            if (contador == 1) {
                gpio_put(LED_FRIO_PIN, 1);
            } else if (contador == 2) {
                gpio_put(LED_TIBIO_PIN, 1);
            } else if (contador == 3) {
                gpio_put(LED_CALIENTE_PIN, 1);
            } else if (contador == 4) {
                gpio_put(LED_FRIO_PIN, 0);
                gpio_put(LED_TIBIO_PIN, 0);
                gpio_put(LED_CALIENTE_PIN, 0);
                contador = 0;
            }
            while (!gpio_get(BOTON_PIN)) {
                sleep_ms(20); // Espera hasta que se suelte el botón
            }
        }
    }
}
