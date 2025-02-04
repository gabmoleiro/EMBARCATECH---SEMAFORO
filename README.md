# Semáforo com Raspberry Pi Pico W

Este repositório contém a implementação de um semáforo utilizando a placa Raspberry Pi Pico W, programado em C com o Pico SDK. O sistema alterna entre os estados do semáforo (vermelho, amarelo e verde) a cada 3 segundos, utilizando a função `add_repeating_timer_ms()`. Além disso, uma mensagem é enviada via porta serial a cada segundo.

## Requisitos

Para executar este projeto, é necessário:
- Raspberry Pi Pico W (ou simulação no Wokwi)
- 3 LEDs (vermelho, amarelo e verde)
- 3 resistores de 330Ω
- Ambiente de desenvolvimento configurado com:
  - VS Code
  - Pico SDK
  - Simulador Wokwi

## Instalação e Execução

1. Clone este repositório:
   ```sh
   git clone https://github.com/gabmoleiro/EMBARCATECH---SEMAFORO.git
   cd EMBARCATECH---SEMAFORO
   ```

2. Configure o ambiente de desenvolvimento:
   - Instale o [Pico SDK](https://github.com/gabmoleiro/EMBARCATECH---SEMAFORO.git)
   - Configure o VS Code para compilar códigos C para o Raspberry Pi Pico
   - Integre o simulador Wokwi ao VS Code

## Funcionamento

- O LED vermelho acende primeiro.
- Após 3 segundos, o LED vermelho apaga e o LED amarelo acende.
- Após mais 3 segundos, o LED amarelo apaga e o LED verde acende.
- O ciclo se repete indefinidamente.
- A cada segundo, uma mensagem é impressa no terminal serial.

