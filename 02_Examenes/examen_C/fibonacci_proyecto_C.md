# Proyecto Fibonacci — Modular en C

## Estructura del proyecto

```
proyecto_fibonacci/
├── inc/
│   ├── fibonacci.h
│   └── menu.h
└── src/
    ├── main.c
    ├── fibonacci.c
    └── menu.c
```

## Funciones principales

- `generarFibonacci(ConfigFib cfg)`
- `esFibonacci(int numero)` → int
- `sumaFibonacci(cfg, long *suma, float *prom, int *cant)` — usa punteros

## Puntos clave

- **struct**: `ConfigFib` con `cantidad` + `desde`
- **punteros**: `sumaFibonacci` usa `long*`, `float*`, `int*`
- **-lm**: `math.h` necesita este flag al compilar
- **VALOR_INICIAL**: macro usada como 0 inicial

---

## inc/fibonacci.h — Struct + macros + prototipos

```c
#ifndef FIBONACCI_H
#define FIBONACCI_H

/* ── MACROS ─────────────────────────────── */
#define OPCION_GENERAR    1
#define OPCION_VERIFICAR  2
#define OPCION_SUMA       3
#define OPCION_SALIR      0

#define VALOR_INICIAL     0

/* ── STRUCT ──────────────────────────────── */
typedef struct {
    int cantidad;   /* cuántos elementos generar  */
    int desde;      /* desde qué índice mostrar   */
} ConfigFib;

/* ── PROTOTIPOS ──────────────────────────── */
void  generarFibonacci(ConfigFib cfg);
int   esFibonacci(int numero);
void  sumaFibonacci(ConfigFib cfg, long *suma, float *promedio, int *cantidad);

#endif /* FIBONACCI_H */
```

---

## inc/menu.h — Include guard obligatorio

```c
#ifndef MENU_H
#define MENU_H

void mostrarMenu();
int  leerOpcion();

#endif /* MENU_H */
```

---

## src/main.c — Solo llamadas, sin lógica aquí

```c
#include <stdio.h>
#include "../inc/fibonacci.h"
#include "../inc/menu.h"

int main() {
    int opcion;
    ConfigFib cfg;
    int    numero, esFib, cantidad;
    long   suma;
    float  promedio;

    while (1) {
        mostrarMenu();
        opcion = leerOpcion();

        switch (opcion) {

            case OPCION_GENERAR:
                printf("Ingrese cantidad de elementos: ");
                scanf("%d", &cfg.cantidad);
                printf("Ingrese desde que indice (0 = desde el inicio): ");
                scanf("%d", &cfg.desde);
                generarFibonacci(cfg);
                break;

            case OPCION_VERIFICAR:
                printf("Ingrese un numero: ");
                scanf("%d", &numero);
                esFib = esFibonacci(numero);
                if (esFib)
                    printf("%d SI es un numero Fibonacci.\n", numero);
                else
                    printf("%d NO es un numero Fibonacci.\n", numero);
                break;

            case OPCION_SUMA:
                printf("Ingrese cantidad de elementos: ");
                scanf("%d", &cfg.cantidad);
                cfg.desde = VALOR_INICIAL;
                sumaFibonacci(cfg, &suma, &promedio, &cantidad);
                printf("Suma total       : %ld\n", suma);
                printf("Promedio         : %.2f\n", promedio);
                printf("Cantidad         : %d\n",  cantidad);
                break;

            case OPCION_SALIR:
                printf("Saliendo...\n");
                return 0;

            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }

        printf("\n");
    }
}
```

---

## src/menu.c — Solo imprime y lee

```c
#include <stdio.h>
#include "../inc/menu.h"

void mostrarMenu() {
    printf("===== MENU FIBONACCI =====\n");
    printf("1. Generar serie Fibonacci\n");
    printf("2. Verificar si un numero es Fibonacci\n");
    printf("3. Calcular suma y promedio\n");
    printf("0. Salir\n");
    printf("Seleccione una opcion: ");
}

int leerOpcion() {
    int op;
    scanf("%d", &op);
    return op;
}
```

---

## src/fibonacci.c — TODA la lógica, incluye función con punteros

```c
#include <stdio.h>
#include <math.h>        /* sqrt(), floor() — para esFibonacci */
#include "../inc/fibonacci.h"

/* ── Opción 1: Generar Fibonacci ─────────── */
void generarFibonacci(ConfigFib cfg) {
    if (cfg.cantidad <= 0) {
        printf("Error: la cantidad debe ser mayor a 0.\n");
        return;
    }
    if (cfg.desde < 0) {
        printf("Error: el indice inicial no puede ser negativo.\n");
        return;
    }
    if (cfg.desde >= cfg.cantidad) {
        printf("Error: el indice debe ser menor que la cantidad.\n");
        return;
    }

    int a = 0, b = 1, temp;
    printf("Serie: ");

    for (int i = 0; i < cfg.cantidad; i++) {
        if (i >= cfg.desde)        /* solo imprime desde el índice indicado */
            printf("%d ", a);
        temp = a + b;
        a    = b;
        b    = temp;
    }
    printf("\n");
}

/* ── Opción 2: Verificar si es Fibonacci ──── */
/* Truco: n es Fibonacci si (5*n*n + 4) o (5*n*n - 4) es cuadrado perfecto */
int esFibonacci(int numero) {
    if (numero < 0) return 0;

    int check1 = 5 * numero * numero + 4;
    int check2 = 5 * numero * numero - 4;

    int raiz1 = (int) sqrt((double) check1);
    int raiz2 = (int) sqrt((double) check2);

    return (raiz1 * raiz1 == check1) || (raiz2 * raiz2 == check2);
}

/* ── Opción 3: Suma — usa PUNTEROS ───────── */
void sumaFibonacci(ConfigFib cfg, long *suma, float *promedio, int *cantidad) {
    if (cfg.cantidad <= 0) {
        printf("Error: la cantidad debe ser mayor a 0.\n");
        return;
    }

    int a = 0, b = 1, temp;
    *suma     = VALOR_INICIAL;
    *cantidad = 0;

    printf("Serie: ");
    for (int i = 0; i < cfg.cantidad; i++) {
        printf("%d ", a);
        *suma     += a;
        *cantidad += 1;
        temp = a + b;
        a    = b;
        b    = temp;
    }
    printf("\n");

    *promedio = (*cantidad > 0) ? (float)(*suma) / (*cantidad) : 0;
}
```

---

## Compilar

```bash
# Compilar (con -lm porque usamos math.h en fibonacci.c)
gcc src/main.c src/fibonacci.c src/menu.c -o fibonacci -I inc -lm

# Ejecutar
./fibonacci

# Con warnings activados (buena práctica)
gcc -Wall -Wextra src/main.c src/fibonacci.c src/menu.c -o fibonacci -I inc -lm
```
