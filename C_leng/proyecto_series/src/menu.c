#include <stdio.h>
#include "../inc/menu.h"
#include "../inc/series.h"

void mostrar_menu() {
    printf("=====\nMENU SERIES =====\n");
    printf("1. Mostrar numeros pares\n");
    printf("2. Generar serie Fibonacci\n");
    printf("3. Calcular sumatoria\n");
    printf("0. Salir\n");
    printf("Seleccione una opcion: ");
}

void solicitar_datos_serie(Serie *s) {
    do {
        printf("Ingrese inicio: ");
        scanf("%d", &s->inicio);
        printf("Ingrese fin: ");
        scanf("%d", &s->fin);
        printf("Ingrese incremento: ");
        scanf("%d", &s->incremento);
        
        if (s->incremento <= 0 || s->fin < s->inicio) {
            printf("Error: el incremento debe ser mayor a 0 y el fin mayor o igual al inicio.\n");
        }
    } while (s->incremento <= 0 || s->fin < s->inicio);
}

void ejecutar_opcion(int opcion) {
    Serie s;
    int n, sumatoria, cantidad;
    float promedio;

    switch (opcion) {
        case OPCION_PARES:
            solicitar_datos_serie(&s);
            mostrar_pares(&s);
            break;
        case OPCION_FIBONACCI:
            printf("Ingrese la cantidad de elementos: ");
            scanf("%d", &n);
            if (n > 0) {
                generar_fibonacci(n);
            }
            break;
        case OPCION_SUMATORIA:
            solicitar_datos_serie(&s);
            calcular_sumatoria(&s, &sumatoria, &promedio, &cantidad);
            printf("Sumatoria total: %d\n", sumatoria);
            printf("Promedio: %.2f\n", promedio);
            printf("Cantidad de elementos: %d\n", cantidad);
            break;
        case OPCION_SALIR:
            break;
        default:
            printf("Opcion invalida.\n");
    }
}
