# Lección 10 — Memoria dinámica

Hasta ahora, el tamaño de tus arreglos estaba **fijo** en el código (`int a[5];`). Pero muchas
veces **no sabes** cuántos datos habrá hasta que el programa corre (el usuario decide, lees de un
archivo…). La **memoria dinámica** te permite pedir memoria **en tiempo de ejecución**, con el
tamaño exacto que necesites.

## Memoria estática vs. dinámica (stack vs. heap)

Simplificando, tu programa usa dos zonas de memoria:

- **La pila (*stack*):** para variables locales y llamadas a funciones. Es rápida y automática:
  la memoria se libera sola al salir de la función. Su tamaño es limitado.
- **El montón (*heap*):** una zona grande que tú gestionas **manualmente** con `malloc`/`free`.
  Aquí pides memoria dinámica; **tú** eres responsable de devolverla.

## `malloc`: pedir memoria

`malloc` (*memory allocation*), de `<stdlib.h>`, reserva un bloque de bytes y devuelve un
**puntero** a su inicio (o `NULL` si falla):

```c
#include <stdlib.h>

int *arr = malloc(5 * sizeof(int));   // memoria para 5 enteros
if (arr == NULL) {                    // SIEMPRE comprobar
    printf("Sin memoria\n");
    return 1;
}
```

- `5 * sizeof(int)` calcula cuántos bytes hacen falta (5 enteros). Usar `sizeof(int)` en vez de
  "4" hace el código **portable** (funciona aunque el tamaño cambie).
- El puntero se usa **igual que un arreglo**: `arr[0]`, `arr[1]`, … `arr[4]`.

```c
for (int i = 0; i < 5; i++) {
    arr[i] = i * 10;                  // 0, 10, 20, 30, 40
}
```

## `free`: devolver la memoria

Cuando termines de usar la memoria, **debes** liberarla con `free`. Si no, se produce una **fuga
de memoria** (*memory leak*): el programa retiene memoria que ya no usa.

```c
free(arr);          // devuelve el bloque al sistema
arr = NULL;         // buena practica: evitar usar un puntero ya liberado
```

**Regla de oro:** por cada `malloc` debe haber **exactamente un** `free`.

## `calloc` y `realloc`

- **`calloc(n, tam)`** reserva memoria para `n` elementos de `tam` bytes **y la inicializa a
  cero**:
  ```c
  int *arr = calloc(5, sizeof(int));   // 5 enteros, todos en 0
  ```
- **`realloc(ptr, nuevoTam)`** **cambia el tamaño** de un bloque ya reservado (para crecer o
  encoger), conservando el contenido:
  ```c
  arr = realloc(arr, 10 * sizeof(int));  // ahora caben 10
  ```
  `realloc` puede mover el bloque a otra dirección, por eso se reasigna a `arr`. (Para código
  robusto, se usa un puntero temporal por si `realloc` devuelve `NULL`.)

## Ejemplo completo: arreglo de tamaño decidido por el usuario

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Cuantos numeros? ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));    // tamaño dinamico
    if (arr == NULL) return 1;

    for (int i = 0; i < n; i++) arr[i] = i * i;   // 0, 1, 4, 9, ...

    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    free(arr);     // liberar
    return 0;
}
```

## Errores típicos (los más peligrosos de C)

- **Fuga de memoria:** olvidar `free`. El programa consume cada vez más memoria.
- **Usar memoria ya liberada** (*use after free*) o **liberar dos veces** (*double free*) → crash
  o corrupción.
- **No comprobar si `malloc` devolvió `NULL`** y desreferenciarlo.
- **Escribir fuera del bloque reservado** (*buffer overflow*) → corrupción silenciosa.
- **Olvidar multiplicar por `sizeof`** (`malloc(5)` reserva 5 **bytes**, no 5 enteros).

> **Herramienta:** compila con `-g` y ejecuta con **Valgrind** (`valgrind ./prog`) para detectar
> fugas y accesos inválidos. Es casi imprescindible al trabajar con memoria dinámica.

## Un vistazo adelante

En C++ (pista 2) hay formas más seguras de manejar memoria: `new`/`delete`, y sobre todo
`std::vector` y los **punteros inteligentes**, que liberan la memoria automáticamente (RAII).
Pero entender `malloc`/`free` es la base de todo.

## Resumen

- `malloc(n * sizeof(tipo))` reserva memoria dinámica; devuelve un puntero (o `NULL`).
- Úsala como un arreglo; **comprueba** que no sea `NULL`.
- `free(ptr)` la devuelve: **un `free` por cada `malloc`**.
- `calloc` inicializa a cero; `realloc` cambia el tamaño.
- Cuidado con fugas, *use-after-free* y *double free*. Usa Valgrind.

## Ejemplos

- [`ejemplos/arreglo_dinamico.c`](ejemplos/arreglo_dinamico.c)
- [`ejemplos/realloc_crecer.c`](ejemplos/realloc_crecer.c)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **K&R**, cap. 5 (§5.6, §8.7 sobre `malloc`).
- **King**, cap. 17 ("Advanced Uses of Pointers"), sección de gestión dinámica.
- **cppreference**, `malloc`/`free`/`calloc`/`realloc`.
  https://en.cppreference.com/w/c/memory/malloc
