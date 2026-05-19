# Plantillas C — Examen General

> REEMPLAZA: nombres de variables, tipos de datos, lógica específica — la estructura es siempre la misma

---

## Funciones / Recursión

### Función básica

```c
#include <stdio.h>

// Declaración (prototipo)
int suma(int a, int b);

int main() {
    int resultado = suma(3, 4);
    printf("Resultado: %d\n", resultado);
    return 0;
}

// Definición
int suma(int a, int b) {
    return a + b;
}
```

### Recursión: Factorial

```c
#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1) return 1;  // caso base
    return n * factorial(n - 1);     // llamada recursiva
}

int main() {
    printf("5! = %d\n", factorial(5)); // 120
    return 0;
}
```

### Recursión: Fibonacci

```c
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 0) return 0;  // caso base
    if (n == 1) return 1;  // caso base
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    for (int i = 0; i < 8; i++)
        printf("%d ", fibonacci(i));  // 0 1 1 2 3 5 8 13
    return 0;
}
```

---

## Punteros / Memoria

### Punteros básicos

```c
#include <stdio.h>

int main() {
    int x = 10;
    int *p = &x;       // p apunta a x

    printf("Valor: %d\n", *p);    // 10  (desreferenciar)
    printf("Dirección: %p\n", p); // dirección de x

    *p = 20;           // modifica x a través del puntero
    printf("x ahora: %d\n", x);  // 20
    return 0;
}
```

### Pasar por referencia (con puntero)

```c
#include <stdio.h>

void duplicar(int *n) {
    *n = *n * 2;   // modifica el original
}

int main() {
    int x = 5;
    duplicar(&x);
    printf("x = %d\n", x);  // 10
    return 0;
}
```

### Memoria dinámica (malloc/free)

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int *arr = (int*) malloc(n * sizeof(int));  // reservar

    if (arr == NULL) {
        printf("Error de memoria\n");
        return 1;
    }

    for (int i = 0; i < n; i++) arr[i] = i * 10;
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    free(arr);  // SIEMPRE liberar
    return 0;
}
```

### Aritmética de punteros

```c
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40};
    int *p = arr;   // apunta al primer elemento

    printf("%d\n", *p);     // 10
    printf("%d\n", *(p+1)); // 20  (siguiente elemento)
    printf("%d\n", *(p+2)); // 30

    // Recorrer con puntero
    for (int i = 0; i < 4; i++)
        printf("%d ", *(p + i));
    return 0;
}
```

---

## Estructuras (struct)

### struct básico

```c
#include <stdio.h>
#include <string.h>

struct Persona {
    char nombre[50];
    int edad;
    float altura;
};

int main() {
    struct Persona p1;
    strcpy(p1.nombre, "Ana");
    p1.edad = 25;
    p1.altura = 1.65;

    printf("Nombre: %s\n", p1.nombre);
    printf("Edad: %d\n", p1.edad);
    return 0;
}
```

### typedef struct

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[50];
    int edad;
} Persona;  // ya no necesitas escribir "struct"

void mostrar(Persona p) {
    printf("%s tiene %d años\n", p.nombre, p.edad);
}

int main() {
    Persona p = {"Carlos", 30};
    mostrar(p);
    return 0;
}
```

### Arreglo de structs

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[50];
    float nota;
} Alumno;

int main() {
    Alumno alumnos[3] = {
        {"Ana", 85.5},
        {"Luis", 92.0},
        {"Maria", 78.3}
    };

    for (int i = 0; i < 3; i++) {
        printf("%s: %.1f\n", alumnos[i].nombre, alumnos[i].nota);
    }
    return 0;
}
```

### Puntero a struct (->)

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[50];
    int edad;
} Persona;

void cumpleanios(Persona *p) {
    p->edad++;  // flecha para acceder con puntero
}

int main() {
    Persona p = {"Pedro", 29};
    cumpleanios(&p);
    printf("Ahora tiene %d años\n", p.edad);  // 30
    return 0;
}
```

---

## Archivos (I/O)

### Escribir en archivo

```c
#include <stdio.h>

int main() {
    FILE *f = fopen("datos.txt", "w");  // "w" = escribir

    if (f == NULL) {
        printf("Error al abrir archivo\n");
        return 1;
    }

    fprintf(f, "Hola, archivo!\n");
    fprintf(f, "Número: %d\n", 42);

    fclose(f);  // SIEMPRE cerrar
    printf("Archivo escrito correctamente.\n");
    return 0;
}
```

### Leer de archivo (línea por línea)

```c
#include <stdio.h>

int main() {
    FILE *f = fopen("datos.txt", "r");  // "r" = leer
    char linea[200];

    if (f == NULL) {
        printf("Error al abrir archivo\n");
        return 1;
    }

    while (fgets(linea, sizeof(linea), f) != NULL) {
        printf("%s", linea);  // ya incluye '\n'
    }

    fclose(f);
    return 0;
}
```

### Escribir y leer structs en binario

```c
#include <stdio.h>
#include <string.h>

typedef struct { char nombre[50]; int edad; } Persona;

int main() {
    Persona p1 = {"Ana", 25};

    // ESCRIBIR binario
    FILE *fw = fopen("personas.bin", "wb");
    fwrite(&p1, sizeof(Persona), 1, fw);
    fclose(fw);

    // LEER binario
    Persona p2;
    FILE *fr = fopen("personas.bin", "rb");
    fread(&p2, sizeof(Persona), 1, fr);
    fclose(fr);

    printf("Leído: %s, %d\n", p2.nombre, p2.edad);
    return 0;
}
```

### Agregar al final del archivo (append)

```c
#include <stdio.h>

int main() {
    FILE *f = fopen("log.txt", "a");  // "a" = append

    if (f == NULL) return 1;

    fprintf(f, "Nueva línea agregada\n");
    fclose(f);
    return 0;
}
```

---

## Algoritmos de Ordenamiento

### Burbuja (Bubble Sort)

```c
#include <stdio.h>

void burbuja(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {         // comparar
                int temp = arr[j];            // intercambiar
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22};
    int n = 5;
    burbuja(arr, n);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
```

### Selección (Selection Sort)

```c
#include <stdio.h>

void seleccion(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Intercambiar mínimo con posición i
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;
    seleccion(arr, n);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
```

### Inserción (Insertion Sort)

```c
#include <stdio.h>

void insercion(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int clave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > clave) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = clave;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = 5;
    insercion(arr, n);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
```
