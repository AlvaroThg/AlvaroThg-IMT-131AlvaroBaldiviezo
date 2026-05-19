#include <stdio.h>
#include "../inc/menu.h"

void mostrarMenu() {
    printf("===== MENU SERIES =====\n");
    printf("1. Serie Aritmetica Alternada\n");
    printf("2. Progresion Geometrica con Limite\n");
    printf("3. Secuencia de Saltos Condicionales\n");
    printf("0. Salir\n");
    printf("Seleccione una opcion: ");
}

int leerOpcion() {
    int op;
    scanf("%d", &op);
    return op;
}
