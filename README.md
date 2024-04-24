# Historias de usuario

## SPRINT 1

## Enjuagar
Como usuario de una lavadora, deseo poder realizar un ciclo de enjuague para asegurarme de que la ropa quede limpia y sin residuos de detergente después del lavado.

### Tareas
- Diseñar e implementar la opción de enjuague en la interfaz de la lavadora.
- Integrar el ciclo de enjuague en la secuencia de operaciones de la lavadora.
- Realizar pruebas para verificar que el ciclo de enjuague funcione correctamente.
- Documentar el proceso de enjuague y sus características en la documentación del usuario.
- Realizar ajustes según sea necesario en base a los resultados de las pruebas.

### Definición de hecho:
El ciclo de enjuague está disponible como una opción en la interfaz de la lavadora, lo que permite al usuario realizar un enjuague adicional después del ciclo de lavado principal. 
Durante el ciclo de enjuague, la lavadora llena el tambor con agua limpia y realiza un ciclo de agitación para eliminar los residuos de detergente de la ropa. 
Se verifica que el ciclo de enjuague funcione correctamente y cumpla con los estándares de limpieza esperados.

---
## Lavar
Como usuario de una lavadora, quiero poder seleccionar la opción de lavado para limpiar la ropa de manera efectiva.

### Tareas
- Diseñar e implementar un control de selección de lavado en la interfaz de la lavadora.
- Integrar el ciclo de lavado en la secuencia de operaciones de la lavadora.
- Realizar pruebas para verificar que el ciclo de lavado funcione correctamente.
- Documentar el proceso de lavado y sus características en la documentación del usuario.
- Realizar cualquier ajuste necesario basado en los resultados de las pruebas.
  
#### Definición de hecho:
El ciclo de lavado está disponible como una opción en la interfaz de la lavadora, lo que permite al usuario realizar un lavado adicional después del ciclo principal. Durante el ciclo de lavado, la lavadora llena el tambor con agua limpia y realiza un ciclo de agitación para eliminar los residuos de detergente de la ropa. Se verifica que el ciclo de lavado funcione correctamente y cumpla con los estándares de limpieza esperados.

## SPRINT 2

## Pausa/play
Como usuario de una lavadora, quiero tener la opción de pausar y reanudar el ciclo de lavado para poder agregar o quitar prendas durante el proceso de lavado según sea necesario.

### Tareas
- Diseñar e implementar un botón de pausa/play en la interfaz de la lavadora.
- Integrar un indicador visual que muestre claramente si el ciclo de lavado está en pausa o en curso.
- Adquirir los materiales necesarios para la implementación del botón y el indicador visual.
- Cablear el prototipo según las especificaciones de diseño, asegurando su compatibilidad con el sistema de control de la lavadora.
- Realizar pruebas exhaustivas para garantizar el correcto funcionamiento del botón de pausa/play y del indicador visual.
- Documentar el funcionamiento del botón de pausa/play y su integración con el ciclo de lavado.
- Realizar cualquier ajuste necesario basado en los resultados de las pruebas.
  
### Definición de hecho:
El botón de pausa/play se encuentra claramente visible en la interfaz de la lavadora y permite al usuario detener temporalmente el ciclo de lavado con un solo toque. Un indicador visual muestra
si el ciclo está pausado o en curso. Al presionar nuevamente el botón, el ciclo se reanuda desde el punto en que se detuvo.

---
##  Funcionalidad
### Funcionalidad de Enjuague
Esta funcionalidad forma parte de un sistema de control para activar el modo de enjuague de una lavadora. Se encarga de activar el modo de enjuague mediante el control de un LED a una placa Raspberry Pi Pico W.

### Descripción
La función enjuagar() proporciona la capacidad de activar el modo de enjuague en la lavadora. Cuando se llama a esta función, se enciende un LED conectado al pin GPIO especificado en el código, indicando así que el proceso de enjuague está en curso.

## Uso
- Se importa el archivo de cabecera Enjuagar.h en su código principal.

#include "Enjuagar.h"

- Se llama a la función enjuagar() en el programa para activar el modo de enjuague.

enjuagar();

## Configuración
- Se debe tener la biblioteca pico/stdlib.h incluida en el entorno de desarrollo.

- Se conecta un LED al pin GPIO especificado en la constante LED_PIN15.
---
### Funcionalidad de Lavado
Esta funcionalidad forma parte de un sistema de control para activar el modo de lavado de una lavadora. Se encarga de activar el modo de lavado mediante el control de un LED a una placa Raspberry Pi Pico W.

### Descripción
La función lavar() proporciona la capacidad de activar el modo de lavado en la lavadora. Cuando se llama a esta función, se enciende un LED conectado al pin GPIO especificado en el código, indicando así que el proceso de lavado está en curso.

## Uso
- Se importa el archivo de cabecera Lavar.h en su código principal.

#include "Lavar.h"

- Se llama a la función lavar() en el programa para activar el modo de enjuague.

lavar();

## Configuración
- Se debe tener la biblioteca pico/stdlib.h incluida en el entorno de desarrollo.

- Se conecta un LED al pin GPIO especificado en la constante LED_PIN15.

# Adicional
En el teclado matricial, los botones correspondientes a lavar y enjuagar son el 7 y 8 respectivamente.

# Tablero de Lavadora

Este proyecto consiste en el diseño e implementación de un tablero de control para una lavadora, que incluye funciones para diferentes tipos de lavado y un botón de encendido y apagado, cada uno controlando un LED correspondiente en el tablero.

## Funciones Implementadas

1. **Tipo de Lavado Delicado:** Esta función está diseñada para lavar prendas delicadas o de tejidos sensibles que requieren un tratamiento suave.

2. **Tipo de Lavado Normal:** Este modo de lavado es adecuado para prendas de uso diario y de tejidos comunes que no necesitan un lavado especial.

3. **Tipo de Lavado Fuerte:** Esta función está destinada a prendas con suciedad pesada o manchas difíciles que requieren un lavado más potente y prolongado.

## Botón de Encendido y Apagado

El tablero de control incluye un botón que permite encender y apagar la lavadora. Este botón proporciona la funcionalidad básica para encender la lavadora y apagarla.

## LED Indicador

Cada botón en el tablero de control está asociado con un LED indicador. Cuando presionas un botón, se enciende el LED correspondiente para indicar que la función asociada está activada.

## Uso del Tablero

Para utilizar el tablero de control de la lavadora, sigue estos pasos:

1. **Encendido de la Lavadora:** Presiona el botón de encendido para activar la lavadora. Esto encenderá el LED indicador correspondiente en el tablero.

2. **Selección del Tipo de Lavado:** Selecciona el tipo de lavado deseado utilizando los controles correspondientes en el tablero. Puedes elegir entre delicado, normal o fuerte, según el tipo de prendas y la cantidad de suciedad. Cada selección enciende el LED indicador respectivo en el tablero.


4. **Apagado de la Lavadora:** Una vez que el ciclo de lavado haya finalizado, presiona el botón de apagado para detener la lavadora y apagarla. Esto también apagará todos los LEDs indicadores en el tablero.


PROYECTO TEBLERO DE LAVADORA

Botón de encendido  y apagado:
El botón de encendido/apagado se encuentra en la interfaz de la lavadora y permite al usuario activar o desactivar la máquina. Cuando se enciende, el LED asociado permanece iluminado, indicando que la lavadora está en funcionamiento. Al presionar nuevamente el botón, la lavadora se apaga y el LED se apaga.

Temperatura(Agua caliente/tibia/fría):
El usuario puede seleccionar la temperatura del agua (caliente, tibia o fría) a través de la interfaz de la lavadora. La lavadora ajusta automáticamente el ciclo de lavado de acuerdo con la temperatura seleccionada. Se realizan pruebas para garantizar que la selección de temperatura funcione correctamente y sea precisa. 

Lavar :
El control de selección de lavado está presente en la interfaz de la lavadora, permitiendo al usuario elegir entre diferentes ciclos de lavado según sus necesidades. Cada ciclo de lavado está diseñado para proporcionar una limpieza efectiva de la ropa, con opciones que incluyen lavado normal, lavado fuerte y lavado delicado, entre otros. La duración y la intensidad de cada ciclo se ajustan automáticamente según la opción seleccionada. Las pruebas realizadas confirman que los ciclos de lavado cumplen con los estándares de limpieza establecidos.

Enjuagar:
El ciclo de enjuague está disponible como una opción en la interfaz de la lavadora, lo que permite al usuario realizar un enjuague adicional después del ciclo de lavado principal. Durante el ciclo de enjuague, la lavadora llena el tambor con agua limpia y realiza un ciclo de agitación para eliminar los residuos de detergente de la ropa. Se verifica que el ciclo de enjuague funcione correctamente y cumpla con los estándares de limpieza esperados.

Lavado: normal/fuerte/ropa delicada
La lavadora ofrece al usuario la posibilidad de seleccionar entre al menos tres modos de lavado: normal, fuerte y ropa delicada. Cada modo de lavado ajusta los parámetros de lavado, como la duración del ciclo, la velocidad de agitación, la temperatura del agua, etc., según las necesidades específicas de cada tipo de prenda. La selección de modo de lavado es clara y fácil de entender para el usuario a través de la interfaz de la lavadora.

Carga: liviana/media/pesada
El selector de opciones de carga se encuentra en la interfaz de la lavadora y permite al usuario elegir entre las opciones de carga liviana, media o pesada. Al seleccionar una opción, la lavadora ajusta automáticamente los parámetros del ciclo de lavado (como la duración, la velocidad de rotación y la cantidad de agua utilizada) para adaptarse a la carga seleccionada.

