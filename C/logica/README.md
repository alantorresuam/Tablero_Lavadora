<<<<<<< HEAD
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


Documentación del Código: Controlador de Lavadora
Descripción
Este programa implementa el controlador para un tablero de lavadora utilizando una Raspberry Pi Pico W D. El controlador interactúa con los usuarios a través de un teclado matricial y muestra información en un display de 7 segmentos. El sistema permite seleccionar diferentes opciones de ciclo de lavado, tipo de carga, temperatura del agua y controla el tiempo del ciclo.

Bibliotecas Utilizadas
"Teclado.h": Proporciona funciones para la interacción con el teclado matricial.
"temporizador.h": Contiene funciones para la gestión del temporizador del ciclo de lavado.
"pin_list_display.h": Define los pines para el display de 7 segmentos.
"pin_list.h": Define los pines utilizados en la Raspberry Pi Pico.
<stdio.h>: Biblioteca estándar de entrada/salida.
"pico/stdlib.h": Biblioteca estándar de la Pi Pico para configuración de E/S.
<string.h>: Biblioteca estándar para manipulación de cadenas de caracteres.
Funcionalidades Principales
Encendido y Apagado: El sistema puede ser encendido y apagado con el botón dedicado.
Selección de Ciclo de Lavado: Permite al usuario seleccionar entre diferentes ciclos de lavado como "Lavar", "Enjuagar" y "Centrifugar".
Selección de Tipo de Lavado: Proporciona opciones para el tipo de lavado, como "Delicado", "Normal" y "Fuerte".
Selección de Tipo de Carga: Permite al usuario elegir entre diferentes tipos de carga, como "Ligera", "Mediana" y "Pesada".
Control de Temperatura: Permite al usuario seleccionar la temperatura del agua entre "Agua fría", "Agua tibia" y "Agua caliente".
Temporizador del Ciclo de Lavado: Gestiona el tiempo del ciclo de lavado y muestra la cuenta regresiva en el display de 7 segmentos.
Inicio y Pausa del Ciclo de Lavado: Permite iniciar y pausar el ciclo de lavado según la elección del usuario.
Finalización del Ciclo de Lavado: Indica al usuario cuando el ciclo de lavado ha sido completado.
Diagrama de Flujo del Programa
El código sigue el flujo de actividades definido en la documentación del proyecto. Se incluyen condiciones para cada paso del proceso, como la selección de opciones y la gestión del temporizador del ciclo de lavado.

Prototipo de Alambrado del Circuito
Se hace referencia al prototipo de alambrado en su primera versión para la disposición de los componentes y la asignación de pines de la Raspberry Pi Pico W.

logica/Tablero.jpg

Uso de Pines de la Raspberry Pi Pico W 
Se detalla la asignación de pines de la Raspberry Pi Pico W D para cada componente del sistema, como el teclado matricial, el display de 7 segmentos y los botones de control de la lavadora.

Display
#define PIN_A 10
#define PIN_B 11
#define PIN_C 12
#define PIN_D 13
#define PIN_E 14
#define PIN_F 15
#define PIN_G 16
#define PIN_DIGITO1 17
#define PIN_DIGITO2 18
Teclado matricial
#define PIN_L1 2
#define PIN_L2 3
#define PIN_L3 4
#define PIN_L4 5
#define PIN_C1 6
#define PIN_C2 7
#define PIN_C3 8
#define PIN_C4 9
//#define PIN_TEMPERATURA_CALIENTE 15	// Temperatura caliente
//#define PIN_ENJUAGAR 16				// Enjuagar
//#define PIN_LAVAR 17					// Lavar
//#define PIN_ENCENDIDO_APAGADO 18		// Encendido/Apagado
//// #define PIN_LAVADO_DELICADO 19		// Lavado delicado
//// #define PIN_LAVADO_NORMAL 20			// Lavado normal
//// #define PIN_LAVADO_FUERTE 21			// Lavado fuerte
//#define PIN_CENTRIFUGAR 22			// Centrifugar
//#define PIN_PAUSA_PLAY 23				// Pausa/Play
=======
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


Documentación del Código: Controlador de Lavadora
Descripción
Este programa implementa el controlador para un tablero de lavadora utilizando una Raspberry Pi Pico W D. El controlador interactúa con los usuarios a través de un teclado matricial y muestra información en un display de 7 segmentos. El sistema permite seleccionar diferentes opciones de ciclo de lavado, tipo de carga, temperatura del agua y controla el tiempo del ciclo.

Bibliotecas Utilizadas
"Teclado.h": Proporciona funciones para la interacción con el teclado matricial.
"temporizador.h": Contiene funciones para la gestión del temporizador del ciclo de lavado.
"pin_list_display.h": Define los pines para el display de 7 segmentos.
"pin_list.h": Define los pines utilizados en la Raspberry Pi Pico.
<stdio.h>: Biblioteca estándar de entrada/salida.
"pico/stdlib.h": Biblioteca estándar de la Pi Pico para configuración de E/S.
<string.h>: Biblioteca estándar para manipulación de cadenas de caracteres.
Funcionalidades Principales
Encendido y Apagado: El sistema puede ser encendido y apagado con el botón dedicado.
Selección de Ciclo de Lavado: Permite al usuario seleccionar entre diferentes ciclos de lavado como "Lavar", "Enjuagar" y "Centrifugar".
Selección de Tipo de Lavado: Proporciona opciones para el tipo de lavado, como "Delicado", "Normal" y "Fuerte".
Selección de Tipo de Carga: Permite al usuario elegir entre diferentes tipos de carga, como "Ligera", "Mediana" y "Pesada".
Control de Temperatura: Permite al usuario seleccionar la temperatura del agua entre "Agua fría", "Agua tibia" y "Agua caliente".
Temporizador del Ciclo de Lavado: Gestiona el tiempo del ciclo de lavado y muestra la cuenta regresiva en el display de 7 segmentos.
Inicio y Pausa del Ciclo de Lavado: Permite iniciar y pausar el ciclo de lavado según la elección del usuario.
Finalización del Ciclo de Lavado: Indica al usuario cuando el ciclo de lavado ha sido completado.
Diagrama de Flujo del Programa
El código sigue el flujo de actividades definido en la documentación del proyecto. Se incluyen condiciones para cada paso del proceso, como la selección de opciones y la gestión del temporizador del ciclo de lavado.

Prototipo de Alambrado del Circuito
Se hace referencia al prototipo de alambrado en su primera versión para la disposición de los componentes y la asignación de pines de la Raspberry Pi Pico W.

![alt text](Tablero.jpg)

Uso de Pines de la Raspberry Pi Pico W 
Se detalla la asignación de pines de la Raspberry Pi Pico W D para cada componente del sistema, como el teclado matricial, el display de 7 segmentos y los botones de control de la lavadora.

Display
#define PIN_A 10
#define PIN_B 11
#define PIN_C 12
#define PIN_D 13
#define PIN_E 14
#define PIN_F 15
#define PIN_G 16
#define PIN_DIGITO1 17
#define PIN_DIGITO2 18
Teclado matricial
#define PIN_L1 2
#define PIN_L2 3
#define PIN_L3 4
#define PIN_L4 5
#define PIN_C1 6
#define PIN_C2 7
#define PIN_C3 8
#define PIN_C4 9
//#define PIN_TEMPERATURA_CALIENTE 15	// Temperatura caliente
//#define PIN_ENJUAGAR 16				// Enjuagar
//#define PIN_LAVAR 17					// Lavar
//#define PIN_ENCENDIDO_APAGADO 18		// Encendido/Apagado
//// #define PIN_LAVADO_DELICADO 19		// Lavado delicado
//// #define PIN_LAVADO_NORMAL 20			// Lavado normal
//// #define PIN_LAVADO_FUERTE 21			// Lavado fuerte
//#define PIN_CENTRIFUGAR 22			// Centrifugar
//#define PIN_PAUSA_PLAY 23				// Pausa/Play
>>>>>>> cbe73a759d0bb9c9704b2620b41caa57489ee00e

---

# Lavadora con Conexión WiFi

Este proyecto consiste en una lavadora que cuenta con conectividad WiFi, lo que permite a los usuarios monitorear y controlar remotamente los niveles y la temperatura a través de una aplicación móvil o plataforma en línea.

## Características principales:
- *Conexión WiFi:* La lavadora está equipada con un módulo WiFi que le permite conectarse a una red inalámbrica doméstica.
- *Monitoreo Remoto:* Los usuarios pueden ver los niveles de agua y la temperatura en tiempo real a través de una aplicación móvil o plataforma en línea.
- *Control Remoto:* Los usuarios tienen la capacidad de encender y apagar la lavadora de forma remota desde la aplicación.

## Subtareas:
1. *Configuración de la Conexión WiFi:*
    - Configurar la lavadora para que se conecte a una red WiFi doméstica.
    - Implementar el protocolo Blink para la configuración y autenticación de la conexión WiFi.

2. *Desarrollo de la Aplicación:*
    - Diseñar la interfaz de usuario de la aplicación móvil o plataforma en línea.
    - Desarrollar la funcionalidad para acceder a los niveles y la temperatura de la lavadora a través de la API de Blink.
    - Implementar la capacidad de encender y apagar la lavadora remotamente desde la aplicación.

3. *Pruebas de Integración:*
    - Verificar la estabilidad de la conexión WiFi y la comunicación entre la lavadora y la aplicación.
    - Realizar pruebas de extremo a extremo para asegurar que la información proporcionada por la aplicación sea precisa y en tiempo real.
    - Probar la funcionalidad de encendido y apagado remoto para garantizar su fiabilidad y seguridad.

## Definición de Listo:
La conexión WiFi está configurada y operativa. La lavadora se conecta sin problemas a la red WiFi y es accesible a través de la aplicación móvil o plataforma en línea. Los usuarios pueden ver los niveles y la temperatura de la lavadora. Además, pueden encender y apagar la lavadora remotamente sin problemas. Se ha verificado que todas estas funciones operen sin errores, ofreciendo una experiencia de usuario eficiente.

---

¡Espero que esto sea útil! Si necesitas más detalles o ajustes, no dudes en decírmelo.
