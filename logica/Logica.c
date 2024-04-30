#include "Teclado.h"
#include "temporizador.h"
#include "leds.h"
#include "pin_list_display.h"
#include "pin_list_keypad.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include <string.h>
#include "pin_list_leds.h"

int main()
{
    stdio_init_all();
    int pinsTeclado[]= {PIN_L1, PIN_L2, PIN_L3, PIN_L4, PIN_C1, PIN_C2, PIN_C3, PIN_C4};
    keypad_construct(pinsTeclado);


    int pinsTime[] = {PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G, PIN_DIGITO1, PIN_DIGITO2};
    time_construct(pinsTime);

    int pinsled[] = { PIN_ENCENDIDO_APAGADO, PIN_PAUSA_PLAY, PIN_LAVAR, PIN_ENJUAGAR, PIN_CENTRIFUGAR};
    construct_leds(pinsled);

    keypad_init();
    time_init();
    leds_init();

    int tiempo = 0;
    int segundo = 0;

    bool seleccion_encendido = false;
    bool seleccion_pausa = true;
    bool seleccion_lavar = false;
    bool seleccion_enjuagar = false;
    bool seleccion_centrifugar = false;
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
        if(seleccion_encendido){
            char opcion = read_keypad();
            if (seleccion_pausa){
                if(!enproceso){
                    //leer opciones del ciclo
                    if(opcion == '7'){ //seleccion_lavar
                        seleccion_lavar = true;
                        lavar();
                        tiempo_lavar = 30;
                    }
                    if(opcion == '8'){ //seleccion_enjuagar
                        seleccion_enjuagar = true;
                        enjuagar();
                        tiempo_enjuagar = 30;
                    }
                    if(opcion == '9'){ //seleccion_centrifugar
                        seleccion_centrifugar = true;
                        tiempo_centrifugar = 30;
                        centrifugado();
                    }

                    //Tipo lavado
                    if(!lavado_seleccionado){

                        if(seleccion_lavar){
                            if (opcion == '1')
                            {
                                lavado_seleccionado = true;
                                strcpy(tipo_lavado, "\nLavado: delicado\t");
                                delicado();
                            }
                            if (opcion == '2')
                            {
                                lavado_seleccionado = true;
                                strcpy(tipo_lavado, "\nLavado: normal\t");
                                normal();
                            }
                            if (opcion == '3')
                            {
                                lavado_seleccionado = true;
                                strcpy(tipo_lavado, "\nLavado: fuerte\t");
                                fuerte();
                            }
                            
                        }
                    }

                    //Enjuagar y seleccion_centrifugar 
                    if(seleccion_enjuagar){
                        strcpy(char_enjuagar, "//\tEnjuagar\t");   
                    }
                    if(seleccion_centrifugar){
                        strcpy(char_centrifugar, "//\tCentrifugar\t");
                    }

                    //Tipo de carga
                    if(!carga_seleccionada){
                        if (opcion == '4')
                        {
                            strcpy(tipo_carga, "\nCarga: ligera\t");
                            carga_seleccionada = true;
                            liviana();
                        }
                        if (opcion == '5')
                        {
                            strcpy(tipo_carga, "\nCarga: mediana\t");
                            carga_seleccionada = true;
                            media();
                        }
                        if (opcion == '6')
                        {
                            strcpy(tipo_carga, "\nCarga: pesada\t");
                            carga_seleccionada = true;
                            pesada();
                        }

                    }
                    
                    //Temperatura
                    if(!temperatura_seleccionada){

                        if(seleccion_lavar){
                            if (opcion == 'A')
                            {
                                strcpy(temperatura, "\nAgua fria\t");
                                temperatura_seleccionada = true;
                                fria();
                            }
                            if (opcion == 'B')
                            {
                                strcpy(temperatura, "\nAgua tibia\t");
                                temperatura_seleccionada = true;
                                tibia();
                            }
                            if (opcion == 'C')
                            {
                                strcpy(temperatura, "\nAgua caliente\t");
                                temperatura_seleccionada = true;
                                caliente();
                            }
                        }
                    }

                    //Presionar play
                    if(seleccion_lavar || seleccion_enjuagar || seleccion_centrifugar){
                        if(lavado_seleccionado && carga_seleccionada){
                            if(opcion == '*'){
                                seleccion_pausa = false;
                                play();
                                enproceso = true;
                                sleep_ms(1000);
                                tiempo = tiempo + tiempo_lavar + tiempo_enjuagar + tiempo_centrifugar;
                            }
                        }
                    }  
                }else{
                    if(opcion == '*'){
                        seleccion_pausa = false;
                    }
                }
                int decena = tiempo / 10;
                int unidad = tiempo % 10;
                actualizar(decena, unidad);
                    
            }else{ //Play
                int decena = tiempo / 10;
                int unidad = tiempo % 10;
                actualizar(decena, unidad);
                segundo += 20;
                if (segundo == 1000){
                    tiempo = decrementar();
                    segundo = 0;
                }
                if(tiempo == 0){
                    printf("Ciclo de lavado terminado :) \n Apagando...\n");
                    sleep_ms(2000);
                    printf("Apagado\n");
                    seleccion_encendido = false;
                    break;
                }
                if(opcion == '0'){
                    pausa();
                    seleccion_pausa = true;
                }
            }
            
            if(opcion == '#'){
                seleccion_encendido = false;
                printf("Apagando...\n");
                apagar();
                sleep_ms(2000);
                printf("Apagado\n");
            }
        }else{
            char opcion = read_keypad();
            if(opcion == 'D'){
                seleccion_encendido = true;
                printf("Encendido \n");
                encender();
                sleep_ms(500);
            }
        }

    }
    return 0;
}
