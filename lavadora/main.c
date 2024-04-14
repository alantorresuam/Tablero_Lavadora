/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

/*
  Our 7 Segment display has pins as follows:

  --A--
  F   B
  --G--
  E   C
  --D--

  By default we are allocating GPIO 2 to segment A, 3 to B etc.
  So, connect GPIO 2 to pin A on the 7 segment LED display etc. Don't forget
  the appropriate resistors, best to use one for each segment!

  Connect button so that pressing the switch connects the GPIO 9 (default) to
  ground (pull down)
*/

#define FIRST_GPIO_OUT 2
#define BUTTON_GPIO_OUT (FIRST_GPIO+11)
#define FIRST_GPIO_IN 2
#define BUTTON_GPIO_IN (FIRST_GPIO+11)




/// \tag::hello_gpio[]
int main() {
    int bits[2] = {
        0xC0,  // 0
        0x79,  // 1
};

stdio_init_all();
printf("Hello, 7segment - press button to count down!\n");


// We could use gpio_set_dir_out_masked() here
// Configurar 19 puertos GPIO
for (int gpio = FIRST_GPIO; gpio < FIRST_GPIO + 19; gpio++) {
    gpio_init(gpio);
    gpio_set_dir(gpio, GPIO_OUT);
    // Nuestro mapa de bits tiene un bit establecido donde necesitamos un LED encendido, 
    // PERO, estamos bajando para encender la luz, así que invertimos nuestra salida
    gpio_set_outover(gpio, GPIO_OVERRIDE_INVERT);
}

// Configurar el botón
gpio_init(BUTTON_GPIO);
gpio_set_dir(BUTTON_GPIO, GPIO_IN);
// Estamos utilizando el botón para activar una bajada a 0V cuando se presiona,
// así que asegúrate de que cuando no está presionado, use resistencias de pull-up internas.
// De lo contrario, cuando no se presiona, la entrada estará flotando.
gpio_pull_up(BUTTON_GPIO);

int val = 0;
while (true) {
    // Contar hacia arriba o hacia abajo dependiendo de la entrada del botón
    // Estamos bajando en el interruptor activo, así que invertimos el valor para
    // hacer que una pulsación cuente hacia abajo
    if (!gpio_get(BUTTON_GPIO)) {
        if (val == 9) {
            val = 0;
        } else {
            val++;
        }
    } else if (val == 0) {
        val = 9;
    } else {
        val--;
    }
}
        // We are starting with GPIO 2, our bitmap starts at bit 0 so shift to start at 2.
        int32_t mask = bits[val] << FIRST_GPIO;

        // Set all our GPIOs in one go!
        // If something else is using GPIO, we might want to use gpio_put_masked()
        gpio_set_mask(mask);
        sleep_ms(1000);
        gpio_clr_mask(mask);
    }
}
/// \end::hello_gpio[]