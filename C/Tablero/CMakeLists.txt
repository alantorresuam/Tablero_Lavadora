# Agrega los ejecutables para el emisor y receptor
add_executable(Tablero main.c
        temporizador.c
        Teclado.c
        Leds.c
)

# Vincula las bibliotecas necesarias
target_link_libraries(Tablero pico_stdlib hardware_uart)

# enable usb output, disable uart output
pico_enable_stdio_usb(Tablero 1)
pico_enable_stdio_uart(Tablero 0)

# Crea los archivos de configuración para la Raspberry Pi Pico
pico_add_extra_outputs(Tablero)
