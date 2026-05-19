#include <stdio.h>
#include "../inc/series.h"
#include "../inc/menu.h"

int main() {
    int opcion;
    EstadisticasSerie es;

    int total, cantidad;
    float promedio;

    while (1) {
        mostrarMenu();
        opcion = leerOpcion();

        switch (opcion) {
            case OPCION_ARITMETICA:
                printf("Ingrese la cantidad de terminos (N): ");     scanf("%d", &es.cantidad_terminos);

                serieAritmetica(es);
                break;

            case OPCION_GEOMETRICA:
                printf("Ingrese inicio: ");	scanf("%d", &es.inicio);
                printf("Ingrese multiplicador (razon): "); scanf("%d", &es.razon);
                printf("Ingrese el valor maximo: "); scanf("%d", &es.valor_maximo);

                progresionGeometrica(es);
                break;

            case OPCION_SALTOS:
                printf("Ingrese inicio: ");     scanf("%d", &es.inicio);
                printf("Ingrese cantidad de pasos: ");        scanf("%d", &es.cantidad_pasos);
                secuenciaSaltos(es);
                break;

            case OPCION_SALIR:
                printf("Saliendo...\n");
                return 0;

            default:
                printf("Opcion invalida.\n");
        }
        printf("\n");
    }
}
