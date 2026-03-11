add_executable(pisca-led-um-depois-o-outro
        main.c
)

target_link_libraries(pisca-led-um-depois-o-outro
                     hardware_adc
                     pico_stdlib )
pico_add_extra_outputs(pisca-led-um-depois-o-outro)
