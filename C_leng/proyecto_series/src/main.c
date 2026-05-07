#include <stdio.h>
#include "../inc/menu.h"

int main() {
    int opcion;
    
    while (1) {
        mostrar_menu();
        if (scanf("%d", &opcion) != 1) {
            while(getchar() != '\n'); // Limpiar buffer por si meten letras
            continue;
        }
        
        if (opcion == OPCION_SALIR) {
            break;
        }
        
        ejecutar_opcion(opcion);
        printf("\n");
    }
    
    return 0;
}
