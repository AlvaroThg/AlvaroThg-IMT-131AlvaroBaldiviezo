#include <stdio.h>
#include "../inc/series.h"

void serieAritmetica(EstadisticasSerie es) {
    for (int i = 0; i < es.cantidad_terminos; i++){
        if (i % 2 != 0){
           printf("%d", i);
        }
        i = -i;
    }
}


void progresionGeometrica(EstadisticasSerie es) {
    int valor_actual = es.inicio;
    printf(valor_actual);
    for (int i = 0; i < es.valor_maximo; i++) {
        if (valor_actual * razon < valor_maximo && valor_actual > 0)
           printf(valor_actual * es.razon);
        i = valor_maximo;
    }
    printf("\n");
}


void secuenciaSaltos(EstadisticasSerie es) {
    int valor_actual = es.inicio;
    printf(inicio);
    for (int i = 0; i < cantidad_pasos; i++){
        if (valor_actual % 2 == 0 && valor_actual != es.inicio){
           valor_actual += 5;
           printf(valor_actual);
        }else if (valor_actual % 2 != 0 && != es.inicio){
           valor_actual -= 2;
           printf(valor_actual);
        }
        printf("\n");
    }
}
