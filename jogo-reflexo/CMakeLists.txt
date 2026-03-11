add_executable(jogo-reflexo
        main.c
)

target_link_libraries(jogo-reflexo pico_stdlib)
pico_add_extra_outputs(jogo-reflexo)
