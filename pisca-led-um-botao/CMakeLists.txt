add_executable(pisca-led-um-botao
        main.c
)

target_link_libraries(pisca-led-um-botao
                     hardware_adc
                     pico_stdlib )
pico_add_extra_outputs(pisca-led-um-botao)
