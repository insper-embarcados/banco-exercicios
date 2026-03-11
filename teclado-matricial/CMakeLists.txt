add_executable(teclado-matricial
        main.c
)

target_link_libraries(teclado-matricial pico_stdlib)
pico_add_extra_outputs(teclado-matricial)
