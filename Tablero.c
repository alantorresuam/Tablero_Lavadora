#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define FIRST_GPIO_OUT  2
#define BUTTON_GPIO     9

int main() {
    stdio_init_all();
    printf("Hello, 7segment - press button to count down!\n");

    gpio_init(BUTTON_GPIO);
    gpio_set_dir(BUTTON_GPIO, GPIO_IN);
    gpio_pull_up(BUTTON_GPIO);

    int val = 0;
    while (1) {
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

        gpio_put(FIRST_GPIO_OUT, val);
        sleep_ms(1000);
    }

    return 0;
}
