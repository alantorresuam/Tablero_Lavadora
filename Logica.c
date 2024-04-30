#include "Teclado.h"
#include "temporizador.h"
#include "pin_list_display.h"
#include "pin_list.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include <string.h>

int main()
{
    stdio_init_all();
    int pinsTeclado[]= {PIN_L1, PIN_L2, PIN_L3, PIN_L4, PIN_C1, PIN_C2, PIN_C3, PIN_C4};
    keypad_construct(pinsTeclado);


    int pinsTime[] = {PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G, PIN_DIGITO1, PIN_DIGITO2};
    time_construct(pinsTime);


    keypad_init();
    time_init();

    int tiempo = 0;
    int segundo = 0;

    bool encendido = false;
    bool pausa = true;
    bool lavar = false;
    bool enjuagar = false;
    bool centrifugar = false;
    bool enproceso = false;

    bool lavado_seleccionado = false;
    bool carga_seleccionada = false;
    bool temperatura_seleccionada = false;

    char proceso[50];
    char temperatura[50];

    char tipo_carga[50];
    char tipo_lavado[50];

    char char_enjuagar[50];
    char char_centrifugar[50];

    int tiempo_lavar = 0;
    int tiempo_enjuagar = 0;
    int tiempo_centrifugar = 0;

     
    char opcion = '\0';
    while(true){
        if(encendido){
            char opcion = read_keypad();
            if (pausa){
                if(!enproceso){
                    //leer opciones del ciclo
                    if(opcion == '7'){ //lavar
                        lavar = true;
                        tiempo_lavar = 30;
                    }
                    if(opcion == '8'){ //enjuagar
                        enjuagar = true;
                        tiempo_enjuagar = 30;
                    }
                    if(opcion == '9'){ //centrifugar
                        centrifugar = true;
                        tiempo_centrifugar = 30;
                    }

                    //Tipo lavado
                    if(!lavado_seleccionado){
