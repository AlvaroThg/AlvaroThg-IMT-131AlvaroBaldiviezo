#ifndef SERIES_H
#define SERIES_H

typedef struct {
    int inicio;
    int fin;
    int incremento;
} Serie;

void mostrar_pares(Serie *s);
void generar_fibonacci(int n);
void calcular_sumatoria(Serie *s, int *sumatoria, float *promedio, int *cantidad);

#endif
