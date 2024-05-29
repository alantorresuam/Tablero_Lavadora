#include "Teclado.h"
#include "temporizador.h"
#include "Leds.h"
#include "pin_list_leds.h"
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

bool temporizador = false;
int time = 0;
int segundo = 0;

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

    // Inicializa temporizador
    int pinsTime[] = {PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G, PIN_DIGITO1, PIN_DIGITO2};
    time_construct(pinsTime);

    int pinsled[] = { PIN_ENCENDIDO_APAGADO, PIN_PAUSA_PLAY, PIN_LAVAR, PIN_ENJUAGAR, PIN_CENTRIFUGAR};
    construct_leds(pinsled);

    time_init();
    apagarTemporizador();
    leds_init();

    while (true){
        char opcion = read_keypad();
        if(opcion != '\0'){
            uart_putc_raw(UART_ID, 'K'); // notificacion de entrada del teclado
            uart_putc_raw(UART_ID, opcion); // enviar entrada para cambio de estado
        }

        if (uart_is_readable(UART_ID)) {
            char command = uart_getc(UART_ID);
            if (command == 'I') // iniciar contador
            { 
                time = 8;
                temporizador = true;
            }
            if (command == 'P') // pause
            {
                temporizador = false;
                pausa();
            }
            if (command == 'p') // play
            {
                temporizador = true;
                play();
            }
            if(command == 'O') // apagar
            {
                apagar_todos_los_leds();
                temporizador = false;
                time = 0;
            }
            if(command == 'H') // apagar procesos
            {
                apagar_procesos();
            }
            if(command == 'N') // encender
            {
                encender();
            }
            if(command == 'L') // lavar
            {
                lavar();
            }
            if(command == 'E') // enjuagar
            {
                enjuagar();
            }
            if(command == 'C') // centrifugar
            {
                centrifugado();
            }
        }

        if(temporizador){
            printf("%d\n", time);
            if(time > 0){
                int decena = time / 10;
                int unidad = time % 10;
                actualizar(decena, unidad);
                segundo += 20;
                if (segundo == 1000){
                    time = decrementar();
                    segundo = 0;
                }
            }else if (time == 0){
                uart_putc_raw(UART_ID, 'T'); 
                apagar();
                temporizador = false;
            }
            
        }

        
    }

    
}
