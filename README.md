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

---
##  Funcionalidad
### Funcionalidad de Enjuague
Esta funcionalidad forma parte de un sistema de control para activar el modo de enjuague de una lavadora. Se encarga de activar el modo de enjuague mediante el control de un LED a una placa Raspberry Pi Pico W.

### Descripción
La función enjuagar() proporciona la capacidad de activar el modo de enjuague en la lavadora. Cuando se llama a esta función, se enciende un LED conectado al pin GPIO especificado en el código, indicando así que el proceso de enjuague está en curso.

### Uso
- Se importa el archivo de cabecera Enjuagar.h en su código principal.

#include "Enjuagar.h"

- Se llama a la función enjuagar() en el programa para activar el modo de enjuague.

enjuagar();

### Configuración
- Se debe tener la biblioteca pico/stdlib.h incluida en el entorno de desarrollo.

- Se conecta un LED al pin GPIO especificado en la constante PIN_ENJUAGAR 16.
---
### Funcionalidad de Lavado
Esta funcionalidad forma parte de un sistema de control para activar el modo de lavado de una lavadora. Se encarga de activar el modo de lavado mediante el control de un LED a una placa Raspberry Pi Pico W.

### Descripción
La función lavar() proporciona la capacidad de activar el modo de lavado en la lavadora. Cuando se llama a esta función, se enciende un LED conectado al pin GPIO especificado en el código, indicando así que el proceso de lavado está en curso.

### Uso
- Se importa el archivo de cabecera Lavar.h en su código principal.

#include "Lavar.h"

- Se llama a la función lavar() en el programa para activar el modo de enjuague.

lavar();

### Configuración
- Se debe tener la biblioteca pico/stdlib.h incluida en el entorno de desarrollo.

- Se conecta un LED al pin GPIO especificado en la constante PIN_LAVAR 17.
  
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
### Funcionalidad de Pausa/Play
Esta funcionalidad forma parte de un sistema de control para pausar y reanudar una lavadora. Se encarga de activar el modo pausado o en play mediante el control de un LED a una placa Raspberry Pi Pico W.

### Descripción
La función pausa_play(bool pausado) proporciona la capacidad de pausar y reanudar la lavadora. Cuando se llama a esta función y el botón conectado al pin GPIO BUTTON_PIN1 se detecta como presionado, se ejecuta una acción dependiendo del estado actual de pausa:

Si el estado de pausa es verdadero (pausado), se espera 1500 milisegundos y se verifica nuevamente si el botón sigue presionado. Si es así, se reanuda la operación llamando a la función play() y se devuelve false, indicando que la operación no está pausada.
Si el estado de pausa es falso (no pausado), se llama a la función pausa() para pausar la operación y se devuelve true, indicando que la operación está pausada.

### Uso
- Se importa el archivo de cabecera Pausa_play.h en el programa principal.

#include "Pausa_play.h"

- Se llama a la función pausa_play() en el programa para pausar y reanudar la operación.

bool estado_pausa = false; // Estado inicial: no pausado 
estado_pausa = pausa_play(estado_pausa); // Pausar o reanudar la operación

### Configuración
- Se debe tener la biblioteca pico/stdlib.h incluida en el entorno de desarrollo.
- Se conecta un LED al pin GPIO especificado en la constante PIN_PAUSA_PLAY  23.
---
## LEDS
Como usuario de una lavadora, quiero  que los leds me muestren la información correspondiente a la funcionalidad de la lavadora para poder monitorear el estado de esta.

### Tareas
- Diseñar e implementar un periférico a los leds de la lavadora.
- Integrar los leds como indicador visual que muestren claramente si una funcionalidad de la lavadora está en progreso.
- Adquirir los materiales necesarios para la implementación de los leds.
- Cablear el prototipo según las especificaciones de diseño, asegurando su compatibilidad con el sistema de control de la lavadora.
- Realizar pruebas exhaustivas para garantizar el correcto funcionamiento de los leds.
- Documentar el funcionamiento del periférico leds y su integración con el ciclo de lavado.
- Realizar cualquier ajuste necesario basado en los resultados de las pruebas.

### Definición de hecho:
Los leds como indicador visual están disponibles como un periférico de la lavadora, lo que permite al usuario visualizar el estado de las funcionalidades de esta. 
Cuando una funcionalidad está en progreso, la lavadora enciende el led correspondiente a esta funcionalidad, con lo que se verifica que dicha funcionalidad funciona correctamente.

---
##  Funcionalidad
### Funcionalidad de Enjuague
Esta funcionalidad forma parte de un sistema de control para una lavadora. Utilizando una placa Raspberry Pi Pico W se diseñó un periférico para el control de los leds.
### Descripción
El periférico leds proporciona la capacidad de controlar diferentes aspectos de una lavadora utilizando leds para indicar el estado actual de las opciones seleccionadas. Las funciones proporcionadas permiten encender y apagar los diferentes componentes de la lavadora y seleccionar diferentes modos y opciones. Cuando se usa este periférico, se enciende un LED correspondiente a una funcionalidad conectada al pin GPIO especificado en el código, indicando así que está en proceso.
### Uso
- construct_leds(int a[]): Esta función es un método para inicializar los pines GPIO utilizados para los leds de la lavadora. Recibe como argumento un arreglo de enteros que contiene los pines GPIO correspondientes a cada LED. Luego, copia estos pines al arreglo leds[].
- leds_init(): Esta función inicializa los pines GPIO de los LEDs. Itera sobre el arreglo leds[], inicializa cada pin GPIO y establece su dirección como salida (OUTPUT).
- apagar(): Apaga el LED correspondiente a la función de apagar la lavadora.
- encender(): Enciende el LED correspondiente a la función de encender la lavadora.
- play(): Enciende el LED correspondiente a la función de iniciar el ciclo de lavado.
- pausa(): Apaga el LED correspondiente a la función de pausar el ciclo de lavado.
- lavar(): Enciende el LED correspondiente a la función de lavar.
- enjuagar(): Enciende el LED correspondiente a la función de enjuagar.
- centrifugado(): Enciende el LED correspondiente a la función de centrifugado.
- fria(), tibia(), caliente(): Estas funciones encienden los LEDs correspondientes a las opciones de temperatura del agua (fría, tibia, caliente) y también imprimen un mensaje indicando la temperatura seleccionada en la consola.
- delicado(), normal(), fuerte(): Estas funciones encienden los LEDs correspondientes a los modos de lavado (delicado, normal, fuerte) y también imprimen un mensaje indicando el modo de lavado seleccionado en la consola.
- liviana(), media(), pesada(): Estas funciones encienden los LEDs correspondientes a las opciones de carga (liviana, media, pesada) y también imprimen un mensaje indicando la carga seleccionada en la consola.
### Configuración
