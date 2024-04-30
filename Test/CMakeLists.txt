add_executable(Test
        Test.c
        )

# Pull in common dependencies
target_link_libraries(Test pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(Test 1)
pico_enable_stdio_uart(Test 0)

# Create map/bin/hex file etc.
pico_add_extra_outputs(Test)
