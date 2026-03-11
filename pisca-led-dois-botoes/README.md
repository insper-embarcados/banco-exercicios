# EXE2

Um sistema que controla o **piscar de dois LEDs** com frequências e tempos de atividade definidos:

- **LED Verde**: pisca a cada `200 ms`
- **LED Amarelo**: pisca a cada `500 ms`

Cada LED deve permanecer ativo (piscando) por um período fixo:

- **LED Verde**: `1000 ms`
- **LED Amarelo**: `2000 ms`

A ativação dos LEDs depende dos botões correspondentes:

- **Botão Verde** → inicia o piscar do **LED Verde**
- **Botão Amarelo** → inicia o piscar do **LED Amarelo**

> [!WARNING]  
> ⚠️ Regra especial:
>  Se **dois LEDs estiverem piscando simultaneamente**, quando o **tempo de um deles terminar**, **ambos devem parar imediatamente** e permanecer **apagados** até um dos botões serem pressionados novamente.

![](exemple.gif)

## Regras de implementação do firmware:

- Baremetal (sem RTOS).
- Utilizar **timers** para o controle de tempo.
- Os leds devem parar de piscar apagados.
- Deve trabalhar com interrupções nos botões.  
- **Proibido** o uso de funções de atraso como `sleep_ms()`, `sleep_us()` ou `get_absolute_time()`.
- Antes de testar, **remova ou comente qualquer `printf`**, pois pode interferir na temporização.

## Testes

O código deve passar em todos os testes para ser aceito:

- `embedded_check`
- `firmware_check`
- `wokwi`

Caso acredite que o seu código está funcionando, porém os testes estão falhando, preencha o forms:

[Google forms para revisão manual](https://docs.google.com/forms/d/e/1FAIpQLSdikhET4iqFwkOKmgD-G6Ri-2kCdhDLndlFWXdfdcuDfPnYHw/viewform?usp=dialog)
