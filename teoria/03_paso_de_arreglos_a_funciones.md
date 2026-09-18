# 03 · Paso de arreglos a funciones (por valor vs. por referencia)

Esta es una de las ideas que **más confunde** al principio, y explica por qué funcionan
`invierteArreglo`, `ordenaBurbuja` y `sumarVectores`: **modifican el arreglo dentro de la
función y el cambio se ve afuera, en `main`.**

## 1. Dos formas de pasar datos

- **Por valor:** la función recibe una **copia**. Si la cambia, el original **no** se entera.
  Así se pasan los enteros sueltos (`int tam`, `int x`).
- **Por referencia:** la función recibe una **vía de acceso al original** (su dirección). Si
  lo cambia, el original **sí** cambia. Así se comportan los **arreglos** en los tres lenguajes.

## 2. Los enteros van por valor

```
funcion int eliminaDuplicados(int Arr[], int tam){
    ...
    tam = tam - 1     // modifica la COPIA de tam dentro de la función
    ...
    return tam
}
```

En el Ejercicio 15, la función hace `tam = tam - 1` muchas veces, pero la `tam` de `main`
**no** cambia por eso; por eso el nuevo tamaño se **devuelve** con `return tam` y en `main` se
guarda en otra variable (`ntam`). Si el arreglo se pasara por valor como los enteros, nada de
esto funcionaría.

## 3. Los arreglos van por referencia (de hecho)

### C y C++

Cuando escribes `int arr[]` como parámetro, en realidad la función recibe un **puntero** al
primer elemento (la *dirección* del arreglo). No se copia el arreglo completo, sino "dónde
está". Por eso, al hacer `arr[i] = ...` dentro de la función, estás tocando **la memoria
original**.

```c
void invierteArreglo(int arr[], int tam) {   // arr es en realidad un puntero int*
    for (int i = 0; i < tam / 2; i++) {
        int aux = arr[i];
        arr[i] = arr[tam - 1 - i];            // ¡esto cambia el arreglo de main!
        arr[tam - 1 - i] = aux;
    }
}
```
`void invierteArreglo(int arr[], int tam)` y `void invierteArreglo(int* arr, int tam)` son
equivalentes en C/C++.

### Java

En Java un arreglo es un **objeto**, y a los métodos se les pasa una **referencia** a ese
objeto. El resultado práctico es el mismo: modificar `arr[i]` dentro del método cambia el
arreglo original.

```java
static void invierteArreglo(int[] arr, int tam) {
    for (int i = 0; i < tam / 2; i++) {
        int aux = arr[i];
        arr[i] = arr[tam - 1 - i];   // cambia el arreglo de main
        arr[tam - 1 - i] = aux;
    }
}
```

> Matiz para Java: se pasa **la referencia por valor**. Puedes **modificar el contenido** del
> arreglo (`arr[i] = …`) y se ve afuera; pero si dentro del método haces
> `arr = new int[...]` (apuntar a un arreglo nuevo), eso **no** afecta a `main`. Para estos
> ejercicios siempre modificamos el contenido, así que el cambio sí se refleja.

## 4. Consecuencia práctica: dos estilos de función

Según lo anterior, hay dos maneras de "entregar el resultado":

1. **Devolver un valor** (`return`): cuando el resultado es **un solo dato**.
   - `sumaElementos` → devuelve un `int`.
   - `esPalindromo` → devuelve un `bool`.
   - `eliminaDuplicados` → devuelve el nuevo tamaño lógico (`int`).

2. **Modificar el arreglo recibido** (función `void`): cuando el resultado es **el arreglo
   entero** transformado.
   - `invierteArreglo` → deja el arreglo al revés.
   - `ordenaBurbuja` → deja el arreglo ordenado.
   - `sumarVectores` / `multiplicarVectores` → **llenan** el vector `C` que se les pasó.

En el caso de `sumarVectores`, fíjate que `C` se crea en `main` **vacío** y se pasa a la
función; la función lo **rellena** y, como va por referencia, `main` ya lo tiene lleno al
volver:

```c
int A[tam], B[tam], C[tam];     // C existe en main
sumarVectores(A, B, C, tam);    // la función escribe en C[i] = A[i] + B[i]
/* aquí C ya está lleno */
```

## 5. Cuadro resumen

| Dato | ¿Cómo se pasa? | Si lo modifico dentro, ¿se ve afuera? |
|---|---|---|
| `int`, `bool` (dato simple) | por valor (copia) | **No** → por eso se usa `return` |
| Arreglo en C/C++ (`int arr[]`) | por referencia (puntero) | **Sí** (al cambiar sus elementos) |
| Arreglo en Java (`int[] arr`) | referencia por valor | **Sí** al cambiar elementos; **No** si reapunta con `new` |
