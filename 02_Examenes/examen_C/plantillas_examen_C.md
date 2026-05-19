# Plantillas Examen C — Proyecto Modular (Series)

> ADVERTENCIA: Cambia el nombre del struct y sus campos según el problema

## Estructura del proyecto

```
proyecto/
├── inc/
│   ├── series.h
│   └── menu.h
└── src/
    ├── main.c
    ├── menu.c
    └── series.c
```

---

## inc/series.h — SIEMPRE cambia struct según el problema

```c
#ifndef SERIES_H   /* include guard — SIEMPRE en .h */
#define SERIES_H

/* ── MACROS ─────────────────────────────── */
#define OPCION_PARES      1
#define OPCION_FIBONACCI  2
#define OPCION_SUMATORIA  3
#define OPCION_SALIR      0
#define VALOR_INICIAL     0

/* ── STRUCT ──────────────────────────────── */
typedef struct {
    int inicio;
    int fin;
    int incremento;
} Serie;

/* ── PROTOTIPOS (declaraciones) ──────────── */
void mostrarPares(Serie s);
void generarFibonacci(int cantidad);
void calcularSumatoria(Serie s, int *total, float *promedio, int *cantidad);

#endif /* SERIES_H */
```

---

## inc/menu.h — Include guard igual que series.h

```c
#ifndef MENU_H
#define MENU_H

void mostrarMenu();
int leerOpcion();

#endif /* MENU_H */
```

---

## src/main.c — Solo llama funciones, NO lógica aquí

```c
#include <stdio.h>
#include "../inc/series.h"
#include "../inc/menu.h"

int main() {
    int opcion;
    Serie s;
    int total, cantidad;
    float promedio;

    while (1) {              /* bucle infinito obligatorio */
        mostrarMenu();
        opcion = leerOpcion();

        switch (opcion) {
            case OPCION_PARES:
                printf("Ingrese inicio: ");     scanf("%d", &s.inicio);
                printf("Ingrese fin: ");        scanf("%d", &s.fin);
                printf("Ingrese incremento: "); scanf("%d", &s.incremento);
                mostrarPares(s);
                break;

            case OPCION_FIBONACCI:
                printf("Ingrese la cantidad de elementos: ");
                scanf("%d", &cantidad);
                generarFibonacci(cantidad);
                break;

            case OPCION_SUMATORIA:
                printf("Ingrese inicio: ");     scanf("%d", &s.inicio);
                printf("Ingrese fin: ");        scanf("%d", &s.fin);
                printf("Ingrese incremento: "); scanf("%d", &s.incremento);
                calcularSumatoria(s, &total, &promedio, &cantidad);
                printf("Sumatoria total : %d\n", total);
                printf("Promedio        : %.2f\n", promedio);
                printf("Cantidad        : %d\n", cantidad);
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
```

---

## src/menu.c — Solo imprime el menú y lee la opción

```c
#include <stdio.h>
#include "../inc/menu.h"

void mostrarMenu() {
    printf("===== MENU SERIES =====\n");
    printf("1. Mostrar numeros pares\n");
    printf("2. Generar serie Fibonacci\n");
    printf("3. Calcular sumatoria\n");
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

## src/series.c — TODA la lógica, función con puntero obligatoria

```c
#include <stdio.h>
#include "../inc/series.h"

/* ── Opción 1: Pares ─────────────────────── */
void mostrarPares(Serie s) {
    if (s.incremento <= 0) {
        printf("Error: incremento debe ser mayor a 0.\n");
        return;
    }
    if (s.fin < s.inicio) {
        printf("Error: fin debe ser >= inicio.\n");
        return;
    }
    for (int i = s.inicio; i <= s.fin; i += s.incremento) {
        if (i % 2 == 0)
            printf("%d ", i);
    }
    printf("\n");
}

/* ── Opción 2: Fibonacci ─────────────────── */
void generarFibonacci(int cantidad) {
    int a = 0, b = 1, temp;
    for (int i = 0; i < cantidad; i++) {
        printf("%d ", a);
        temp = a + b;
        a = b;
        b = temp;
    }
    printf("\n");
}

/* ── Opción 3: Sumatoria — usa PUNTEROS ──── */
void calcularSumatoria(Serie s, int *total, float *promedio, int *cantidad) {
    if (s.incremento <= 0) { printf("Error: incremento > 0.\n"); return; }
    if (s.fin < s.inicio)  { printf("Error: fin >= inicio.\n");  return; }

    *total    = 0;
    *cantidad = 0;

    printf("Serie: ");
    for (int i = s.inicio; i <= s.fin; i += s.incremento) {
        printf("%d ", i);
        *total    += i;
        *cantidad += 1;
    }
    printf("\n");

    *promedio = (*cantidad > 0) ? (float)(*total) / (*cantidad) : 0;
}
```

---

## Compilar

```bash
# Compilar todos los archivos juntos
gcc src/main.c src/series.c src/menu.c -o programa -I inc

# Ejecutar
./programa

# Con warnings (recomendado)
gcc -Wall -Wextra src/main.c src/series.c src/menu.c -o programa -I inc
```

---

## Patrones clave

### Include guard — SIEMPRE en .h

```c
#ifndef NOMBRE_H
#define NOMBRE_H

/* contenido del .h */

#endif
```

### Función con puntero (modifica el original)

```c
/* declaración en .h */
void calcular(Struct s, int *resultado);

/* uso en main */
int res;
calcular(s, &res);
printf("%d", res);
```

### Patrón struct + validación

```c
typedef struct {
    int campo1;
    int campo2;
} MiStruct;

/* validar antes de operar */
if (s.incremento <= 0) { printf("Error\n"); return; }
if (s.fin < s.inicio)  { printf("Error\n"); return; }
```

### #include entre carpetas

```c
/* desde src/*.c hacia inc/*.h */
#include "../inc/series.h"
#include "../inc/menu.h"

/* desde inc/*.h (solo lo necesario) */
#include <stdio.h>
```

---

## Checklist — antes de entregar

- [ ] `typedef struct` definido en `.h`
- [ ] Macros `#define` en `.h`
- [ ] Include guards en TODOS los `.h`
- [ ] Al menos 1 función con puntero (`int *resultado`)
- [ ] `while(1)` con `switch` en `main.c`
- [ ] `main.c` NO tiene lógica — solo llamadas
- [ ] Validar: `incremento > 0` y `fin >= inicio`
- [ ] `#include "../inc/archivo.h"` en los `.c`
- [ ] `gcc src/main.c src/series.c src/menu.c -o prog -I inc`
