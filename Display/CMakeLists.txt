add_executable(display
        display.c
        #../common/sdk_inclines.S
        )

# pull in common dependencies
target_link_libraries(display pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(display)

# add url via pico_set_program_url
# example_auto_set_url(display)