#include "operaciones.h"
#include "inputs.h"

typedef struct {
    int x=0;
    int y=0;

}operaciones;

operaciones op;

#define MSG "Elija una opcion (suma = 1; resta = 2; multiplicacion = 3; division = 4; salir = 0): \n"

int main(void){
    
    scanf("%d", &op.x);
    scanf("%d", &op.y);
    printf("%d\n", (op.x+op.y));

    while (1) {
        menu(&op); 
        if(op == 1){

        }
    }

    return 0;
}

