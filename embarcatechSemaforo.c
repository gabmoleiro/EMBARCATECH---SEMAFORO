#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/gpio.h"

#define LED_VERMELHO 11
#define LED_AMARELO 12
#define LED_VERDE 13

typedef enum {
    VERMELHO,
    AMARELO,
    VERDE
} EstadoSemaforo;

EstadoSemaforo estado = VERMELHO; // Estado inicial do semáforo

const char *nomes_estados[] = {"Vermelho", "Amarelo", "Verde"};

// Callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    switch (estado) {
        case VERMELHO:
            gpio_put(LED_VERMELHO, 1);
            gpio_put(LED_AMARELO, 0);
            gpio_put(LED_VERDE, 0);
            estado = AMARELO;
            break;
        case AMARELO:
            gpio_put(LED_VERMELHO, 0);
            gpio_put(LED_AMARELO, 1);
            gpio_put(LED_VERDE, 0);
            estado = VERDE;
            break;
        case VERDE:
            gpio_put(LED_VERMELHO, 0);
            gpio_put(LED_AMARELO, 0);
            gpio_put(LED_VERDE, 1);
            estado = VERMELHO;
            break;
    }
    return true; // Mantém o timer rodando
}

int main() {
    stdio_init_all(); // Inicializa a comunicação serial

    EstadoSemaforo estado_anterior = estado;

    gpio_init(LED_VERMELHO);
    gpio_init(LED_AMARELO);
    gpio_init(LED_VERDE);

    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    // Define o estado inicial do semáforo (vermelho)
    gpio_put(LED_VERMELHO, 1);
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer); // Timer de 3 segundos

    while (1) {
        if (estado != estado_anterior) {
            printf("Próximo estado: %s\n", nomes_estados[estado]);
            estado_anterior = estado;
        }
        sleep_ms(1000);
    }

    return 0;
}
