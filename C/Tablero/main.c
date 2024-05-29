#include "Teclado.h"
#include "temporizador.h"
#include "pin_list_keypad.h"
#include "pin_list_display.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include <string.h>
#include "hardware/uart.h"

#define UART_ID uart0
#define BAUD_RATE 9600
#define UART_TX_PIN 12
#define UART_RX_PIN 13

char state = '\0';
int main(){

    // Inicializa UART
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    stdio_init_all();

    // Inicializa teclado
    int pinsTeclado[]= {PIN_L1, PIN_L2, PIN_L3, PIN_L4, PIN_C1, PIN_C2, PIN_C3, PIN_C4};
    keypad_construct(pinsTeclado);
    keypad_init();


    while (true){
        char opcion = read_keypad();
        if(opcion != '\0'){
            uart_putc_raw(UART_ID, 'K'); // notificacion de entrada del teclado
            uart_putc_raw(UART_ID, opcion); // enviar entrada para cambio de estado
        }

        uart_putc_raw(UART_ID, 'S'); // Solicita el nuevo estado de la FSM
        while (!uart_is_readable(UART_ID)) // esperando respuesta 
        {

        }
        char char_state = uart_getc(UART_ID); // obtener el nuevo estado
        state = atoi(&char_state);
    }
}
