Proyecto Tablero de Lavadora
Descripción del Proyecto
El proyecto se enfoca en el desarrollo de un controlador de lavadora usando una Raspberry Pi Pico W. Este controlador permite a los usuarios seleccionar diferentes opciones de lavado a través de un teclado matricial, mostrando la información relevante en un display de 7 segmentos. El sistema también cuenta con conectividad WiFi, permitiendo el monitoreo y control remoto del dispositivo.

Estructura del Proyecto
El proyecto está organizado en diferentes módulos, cada uno encargado de manejar aspectos específicos de la funcionalidad de la lavadora. A continuación, se detalla cada módulo y su propósito:

1. Botón de Encendido y Apagado
Descripción: Un botón dedicado para encender y apagar la lavadora, acompañado de un LED que indica el estado actual (encendido/apagado).
Detalles de Implementación:
Pin del Botón: El botón está conectado a un pin digital de la Raspberry Pi Pico.
Pin del LED: El LED indicador está conectado a otro pin digital.
Funcionamiento: Al presionar el botón, si la lavadora está apagada, el sistema se enciende y el LED se ilumina. Si el botón se presiona nuevamente, la lavadora se apaga y el LED se apaga.
2. Selección de Temperatura (Agua Caliente/Tibia/Fría)
Descripción: Permite a los usuarios seleccionar la temperatura del agua para el ciclo de lavado.
Detalles de Implementación:
Opciones de Temperatura: Agua caliente, tibia y fría.
Indicadores LED: Cada opción de temperatura tiene un LED asociado que se ilumina cuando se selecciona.
Funcionamiento: Al seleccionar una opción, el sistema ajusta los parámetros del ciclo de lavado para mantener la temperatura adecuada.
3. Ciclos de Lavado (Normal/Fuerte/Delicada)
Descripción: Ofrece diferentes modos de lavado para adaptarse a diferentes tipos de tejidos y suciedades.
Detalles de Implementación:
Opciones de Ciclo: Normal, fuerte y delicada.
Configuración de Parámetros: Cada ciclo ajusta la duración y la intensidad del lavado según la opción seleccionada.
Indicadores LED: Los LEDs indican el ciclo seleccionado.
4. Enjuagar
Descripción: Proporciona una opción adicional de enjuague para eliminar residuos de detergente.
Detalles de Implementación:
Activación del Enjuague: El usuario puede seleccionar la opción de enjuague adicional.
Configuración del Ciclo: Se llena el tambor con agua limpia y se agita para realizar el enjuague.
Indicadores LED: Se ilumina un LED para indicar que la función de enjuague está activada.
5. Selección de Carga (Liviana/Media/Pesada)
Descripción: Permite al usuario seleccionar la cantidad de ropa a lavar, ajustando los parámetros del ciclo en consecuencia.
Detalles de Implementación:
Opciones de Carga: Liviana, media y pesada.
Ajuste Automático: La selección de carga ajusta la duración del ciclo, la cantidad de agua y la intensidad del lavado.
Indicadores LED: Los LEDs indican la opción de carga seleccionada.
6. Temporizador del Ciclo de Lavado
Descripción: Muestra el tiempo restante del ciclo de lavado en un display de 7 segmentos.
Detalles de Implementación:
Display de 7 Segmentos: Conectado a los pines de la Raspberry Pi Pico para mostrar el tiempo restante.
Actualización en Tiempo Real: El temporizador se actualiza en tiempo real para reflejar el tiempo restante del ciclo.
7. Inicio y Pausa del Ciclo de Lavado
Descripción: Permite al usuario iniciar y pausar el ciclo de lavado según sea necesario.
Detalles de Implementación:
Botón de Inicio/Pausa: Un botón dedicado para iniciar y pausar el ciclo.
Indicadores LED: Indican el estado actual del ciclo (en progreso o pausado).
8. Finalización del Ciclo de Lavado
Descripción: Indica al usuario cuando el ciclo de lavado ha terminado.
Detalles de Implementación:
Notificación: Mediante un indicador visual y/o sonoro para informar al usuario que el ciclo ha finalizado.
Reset del Sistema: Prepara la lavadora para un nuevo ciclo después de la finalización.
9. Conectividad WiFi
Descripción: Permite el monitoreo y control remoto de la lavadora a través de una red WiFi.
Detalles de Implementación:
Configuración WiFi: La Raspberry Pi Pico W se conecta a la red WiFi doméstica.
Monitoreo en Tiempo Real: Permite ver el estado actual de la lavadora, incluyendo niveles de agua y temperatura.
Control Remoto: Encender/apagar la lavadora y ajustar los parámetros del ciclo de lavado a través de una aplicación móvil o plataforma en línea.
Documentación del Código
El código fuente está organizado en varios archivos y módulos, cada uno responsable de diferentes aspectos del funcionamiento del sistema. A continuación se presenta una descripción detallada de cada archivo y su propósito:

Archivos y Bibliotecas Utilizadas
Teclado.h: Maneja la interacción con el teclado matricial.
temporizador.h: Gestión del temporizador del ciclo de lavado.
pin_list_display.h: Define los pines para el display de 7 segmentos.
pin_list.h: Define los pines utilizados en la Raspberry Pi Pico.
stdio.h: Biblioteca estándar de entrada/salida.
pico/stdlib.h: Biblioteca estándar de la Pi Pico para configuración de E/S.
string.h: Biblioteca estándar para manipulación de cadenas de caracteres.
Prototipo de Alambrado del Circuito
El prototipo del circuito incluye la conexión de varios componentes a la Raspberry Pi Pico, asegurando que cada funcionalidad esté correctamente conectada y operativa.

Display de 7 Segmentos
Pines Utilizados: PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G, PIN_DIGITO1, PIN_DIGITO2
Conexión: Cada segmento del display está conectado a un pin digital de la Raspberry Pi Pico.
Teclado Matricial
Pines Utilizados: PIN_L1, PIN_L2, PIN_L3, PIN_L4, PIN_C1, PIN_C2, PIN_C3, PIN_C4
Conexión: Las filas y columnas del teclado matricial están conectadas a pines digitales de la Raspberry Pi Pico.
Diagrama de Flujo del Programa
El programa sigue un flujo lógico de operaciones, desde la selección de opciones por parte del usuario hasta la ejecución del ciclo de lavado y la finalización del mismo. A continuación se describe el flujo principal del programa:

Inicio del Sistema

Verifica el estado inicial de todos los componentes.
Espera la interacción del usuario.
Selección de Opciones

El usuario selecciona la temperatura, el ciclo de lavado y la carga.
Las selecciones se muestran en el display y se confirman mediante LEDs.
Inicio del Ciclo

Al presionar el botón de inicio, se comienza el ciclo de lavado.
El temporizador se inicia y se muestra el tiempo restante en el display.
Ejecución del Ciclo

La lavadora ejecuta el ciclo seleccionado, ajustando los parámetros según las opciones elegidas.
Monitoreo y ajuste continuo del ciclo basado en sensores (si aplicable).
Pausa del Ciclo

El usuario puede pausar el ciclo en cualquier momento.
El estado se guarda y se muestra una indicación de pausa.
Finalización del Ciclo

Al completar el ciclo, se notifica al usuario mediante un indicador visual y/o sonoro.
El sistema se prepara para un nuevo ciclo.
Definición de Listo
El proyecto se considera completo y listo para su uso cuando se cumplen los siguientes criterios:

Conectividad WiFi: El sistema está configurado y operando correctamente, permitiendo la conexión a una red WiFi y el control remoto a través de una aplicación o plataforma.
Display: El display de 7 segmentos muestra la información del ciclo de manera clara y precisa.
Selector de Carga: Funciona adecuadamente, permitiendo la selección de la carga y ajustando los parámetros del ciclo en consecuencia.
Historias de Usuario
Las historias de usuario son esenciales para entender las necesidades y expectativas de los usuarios finales. A continuación, se presentan las principales historias de usuario para este proyecto:

1. Carga Liviana/Media/Pesada
Funcionalidad: Selección del tipo de carga, ajustando el ciclo de lavado automáticamente según la selección.
Tareas:
Implementación del selector de carga.
Pruebas exhaustivas para asegurar el correcto ajuste de parámetros.
Documentación de la funcionalidad y pruebas.
Definición de Hecho:
El selector está integrado y funcionando correctamente.
El LED correspondiente se enciende al seleccionar la carga.
Los parámetros del ciclo se ajustan automáticamente según la selección.
2. Temporizador
Funcionalidad: Display que muestra el tiempo restante del ciclo de lavado.
Tareas:
Selección e integración del display de 7 segmentos.
Programación de la lógica de temporización.
Pruebas exhaustivas para asegurar la precisión del temporizador.
Documentación de la funcionalidad y pruebas.
Definición de Hecho:
El display muestra la información del temporizador correctamente.
El temporizador ha sido probado en diferentes escenarios.
La funcionalidad está documentada adecuadamente.
