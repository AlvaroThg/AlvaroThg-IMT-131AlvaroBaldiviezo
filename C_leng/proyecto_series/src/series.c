#include <stdio.h>
#include "../inc/series.h"
#include "../inc/menu.h"

void mostrar_pares(Serie *s) {
    for (int i = s->inicio; i <= s->fin; i += s->incremento) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void generar_fibonacci(int n) {
    int a = VALOR_INICIAL, b = 1, temp;
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        temp = a + b;
        a = b;
        b = temp;
    }
    printf("\n");
}

void calcular_sumatoria(Serie *s, int *sumatoria, float *promedio, int *cantidad) {
    *sumatoria = 0;
    *cantidad = 0;
    
    printf("Serie: ");
    for (int i = s->inicio; i <= s->fin; i += s->incremento) {
        printf("%d ", i);
        *sumatoria += i;
        (*cantidad)++;
    }
    printf("\n");
    
    if (*cantidad > 0) {
        *promedio = (float)(*sumatoria) / (*cantidad);
    } else {
        *promedio = 0.0;
    }
}
