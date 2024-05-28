# Agrega los ejecutables para el emisor y receptor
add_executable(Lavadora main.c
        temporizador.c
        Teclado.c
)

# Vincula las bibliotecas necesarias
target_link_libraries(Lavadora pico_stdlib hardware_uart)

# enable usb output, disable uart output
pico_enable_stdio_usb(Lavadora 1)
pico_enable_stdio_uart(Lavadora 0)

# Crea los archivos de configuración para la Raspberry Pi Pico
pico_add_extra_outputs(Lavadora)
