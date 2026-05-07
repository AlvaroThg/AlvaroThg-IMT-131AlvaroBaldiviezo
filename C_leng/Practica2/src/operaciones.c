#include "operaciones.h"

int suma(int a, int b){
    return a + b;
}
int resta(int a, int b){
    return a-b;
}
int multiplicacion(int a, int b){
    return a*b;
}
float division(int a, int b){
    if (b == 0) {
        return 0.0f;
    }
    return (float)a/(float)b;
}
