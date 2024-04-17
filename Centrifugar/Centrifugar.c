#include <stdbool.h>
#include "pico/stdlib.h"

#define LED_PIN  14 
#define CENTRIFUGADO_PIN 14 // Botón para activar el centrifugado

void centrifugar();

int main() {
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_init(CENTRIFUGADO_PIN);
    gpio_set_dir(CENTRIFUGADO_PIN, GPIO_IN);
    gpio_pull_up(CENTRIFUGADO_PIN);

    while (true) {
        if (gpio_get(CENTRIFUGADO_PIN)) {
            centrifugar();
        }

        sleep_ms(100);
    }

    return 0;
}

void centrifugar() {
    gpio_put(LED_PIN, 1); // Encender el LED para indicar que está en centrifugado
    sleep_ms(1800000); // Esperar 30 minutos (1800000 milisegundos)
    gpio_put(LED_PIN, 0); // Apagar el LED al finalizar el centrifugado
    printf("Centrifugado completo.\n");
}
