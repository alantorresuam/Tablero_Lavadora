add_executable(Temporizador
        temporizador.c
        )

# Pull in common dependencies
target_link_libraries(Temporizador pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(Temporizador 1)
pico_enable_stdio_uart(Temporizador 0)

# Create map/bin/hex file etc.
pico_add_extra_outputs(Temporizador)