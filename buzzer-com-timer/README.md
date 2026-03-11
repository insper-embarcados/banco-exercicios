# EXE2

> [!IMPORTANT]  
> Exercício com avaliação manual, não tem teste no wokwi! Mas possui testes de qualidade de código e de rubrica!

Usando timer, controle a frequência na qual o buzzer irá tocar, indo do agudo para o grave (de forma continua).

Você pode definir as frequências, não existe uma padrão.

## Regras de implementação do firmware:

- Baremetal (sem RTOS).
- Utilizar **timers** para o controle de tempo.
- **Proibido** o uso de funções de atraso como `sleep_ms()`, `sleep_us()` ou `get_absolute_time()`.

## Testes

O código deve passar em todos os testes para ser aceito:

- `embedded_check`
- `firmware_check`
- ~~`wokwi`~~