# Lección 09 — Punteros

Los **punteros** son la característica más poderosa (y temida) de C. Son la razón de que C sea tan
eficiente y de "bajo nivel". Tómate esta lección con calma: entender punteros es entender cómo
funciona la memoria.

## La idea: memoria y direcciones

La memoria de la computadora es como una **calle larguísima de casillas numeradas**. Cada casilla
tiene una **dirección** (su número). Cuando declaras una variable, el sistema le asigna una o
varias casillas:

```c
int edad = 25;
```
`edad` vive en alguna dirección, por ejemplo la `0x7ffe...`. Ahí están guardados los bytes que
representan el `25`.

Un **puntero** es una variable que, en vez de guardar un valor normal, guarda **una dirección**:
"dónde vive" otra variable.

## Dos operadores: `&` y `*`

- **`&` (dirección de):** te da la **dirección** de una variable.
- **`*` (contenido de / desreferencia):** te da el **valor** que hay en una dirección.

Son operaciones **inversas**.

```c
int edad = 25;
int *p = &edad;      // p guarda la DIRECCION de edad

printf("%d\n", edad);   // 25   (el valor)
printf("%p\n", (void*)&edad);  // 0x...  (la direccion, con %p)
printf("%p\n", (void*)p);      // la misma direccion (p apunta a edad)
printf("%d\n", *p);     // 25   (*p = "el valor donde apunta p" = edad)
```

### Declarar un puntero

```c
int *p;      // p es un puntero a int
double *q;   // q es un puntero a double
char *c;     // c es un puntero a char
```
El `*` en la declaración dice "esto es un puntero". El **tipo** importa: un `int *` apunta a un
`int`, un `double *` a un `double`.

## Modificar la variable a través del puntero

Si tienes la dirección de una variable, puedes **cambiar su valor** con `*`:

```c
int edad = 25;
int *p = &edad;
*p = 30;              // cambia el valor que hay en esa direccion...
printf("%d\n", edad); // 30   ...que es 'edad'
```

Esto es la clave: `*p` es un **alias** de `edad`. Escribir en `*p` es escribir en `edad`.

## El puntero nulo (`NULL`)

Un puntero que **no apunta a nada válido** debe valer `NULL` (definido en `<stddef.h>`,
`<stdio.h>`, etc.). Desreferenciar un puntero `NULL` (o sin inicializar) **rompe el programa**.

```c
int *p = NULL;      // "de momento no apunta a nada"
if (p != NULL) {    // comprobar antes de usar
    printf("%d\n", *p);
}
```
Un puntero **sin inicializar** apunta a una dirección **basura**: nunca lo desreferencies hasta
darle una dirección válida o `NULL`.

## ¿Para qué sirven los punteros?

### 1. Que una función modifique variables del que la llama

Recuerda (lección 07): los argumentos van **por valor** (copia). Si quieres que una función
**cambie** una variable original, le pasas su **dirección** y la función usa `*`:

```c
void duplicar(int *n) {
    *n = *n * 2;          // modifica la variable original
}
int main(void) {
    int x = 5;
    duplicar(&x);         // le pasamos la DIRECCION de x
    printf("%d\n", x);    // 10
}
```
**Esto es exactamente por qué `scanf` lleva `&`:** necesita la dirección de tu variable para poder
guardar ahí lo que lee.

Un ejemplo clásico: **intercambiar** dos variables (imposible por valor, fácil con punteros):

```c
void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// ...
int x = 1, y = 2;
intercambiar(&x, &y);   // ahora x=2, y=1
```

### 2. Trabajar con arreglos y memoria dinámica

Los arreglos y los punteros están muy relacionados (siguiente sección), y la memoria dinámica
(lección 10) se maneja **enteramente** con punteros.

## Punteros y arreglos

En C, el **nombre de un arreglo** actúa como un **puntero a su primer elemento**. Por eso al
pasar un arreglo a una función se pasa realmente su dirección (y la función puede modificarlo).

```c
int a[3] = {10, 20, 30};
int *p = a;           // p apunta a a[0] (no hace falta &)
printf("%d\n", *p);   // 10  (== a[0])
printf("%d\n", a[0]); // 10
```

### Aritmética de punteros

Sumar 1 a un puntero **no** avanza 1 byte, sino **un elemento** (el compilador sabe el tamaño del
tipo). Así, `p + 1` apunta al siguiente elemento:

```c
int a[3] = {10, 20, 30};
int *p = a;
printf("%d\n", *(p + 1));   // 20   (== a[1])
printf("%d\n", *(p + 2));   // 30   (== a[2])
```
De hecho, **`a[i]` es azúcar sintáctico de `*(a + i)`**: las dos formas son equivalentes. Al
principio usa la notación con corchetes `a[i]`, que es más clara.

## `const` y punteros

Puedes prometer que **no** modificarás lo apuntado, útil para parámetros de solo lectura:

```c
void imprimir(const int *arr, int n) {   // no modificara arr
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
}
```

## Errores típicos (¡peligrosos!)

- **Desreferenciar `NULL` o un puntero sin inicializar** → *segmentation fault* (crash).
- **Confundir `*p` con `p`**: `p` es la dirección, `*p` es el valor.
- **Devolver la dirección de una variable local** desde una función (deja de existir al salir).
- **Olvidar el `&`** al pasar la dirección a una función que la espera.

## Resumen

- Un puntero guarda una **dirección**. Se declara con `tipo *p`.
- `&x` = dirección de `x`; `*p` = valor en la dirección `p` (desreferencia).
- `*p = v` modifica la variable a la que apunta `p`.
- Pasa punteros para que una función **modifique** tus variables (como `scanf`).
- El nombre de un arreglo es un puntero a su primer elemento; `a[i] == *(a+i)`.
- Inicializa punteros (a `NULL` si aún no apuntan a nada) y comprueba antes de usar.

## Ejemplos

- [`ejemplos/basico_punteros.c`](ejemplos/basico_punteros.c)
- [`ejemplos/intercambiar.c`](ejemplos/intercambiar.c)
- [`ejemplos/punteros_arreglos.c`](ejemplos/punteros_arreglos.c)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **K&R**, cap. 5 ("Pointers and Arrays") — el capítulo de referencia.
- **King**, cap. 11 ("Pointers") y cap. 12 ("Pointers and Arrays").
- **Beej's Guide to C**, "Pointers". https://beej.us/guide/bgc/html/split/pointers.html
