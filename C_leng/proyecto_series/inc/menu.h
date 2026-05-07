#ifndef MENU_H
#define MENU_H

#include "series.h"

#define OPCION_PARES 1
#define OPCION_FIBONACCI 2
#define OPCION_SUMATORIA 3
#define OPCION_SALIR 0
#define VALOR_INICIAL 0

void mostrar_menu();
void ejecutar_opcion(int opcion);
void solicitar_datos_serie(Serie *s);

#endif
