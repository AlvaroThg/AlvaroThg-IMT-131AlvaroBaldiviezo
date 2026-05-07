#include "inputs.h"

void leerNumeros(int *a, int *b){
    printf(MSG1);
    if (scanf("%d", a) != 1) {
        *a = 0;
    }
    printf(MSG2);
    if (scanf("%d", b) != 1) {
        *b = 0;
    }
    return;
}
