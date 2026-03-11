add_executable(pisca-led-tempo-botao
        main.c
)

target_link_libraries(pisca-led-tempo-botao
                     pico_stdlib )
pico_add_extra_outputs(pisca-led-tempo-botao)
