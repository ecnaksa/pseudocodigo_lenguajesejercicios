# 01 · Cómo devolver más de un valor desde una función

El Problema 21 pide una función que entregue **dos** cosas a la vez: el valor pico máximo **y**
su índice. Pero `return` solo puede devolver **un** valor. ¿Cómo se resuelve? Con **parámetros
de salida** (paso por referencia). Es un concepto clave que cambia bastante entre C, C++ y Java.

## 1. El problema

```
funcion double picoMaximo(...){
    ...
    return mayor;      // aqui solo cabe UN valor: el maximo
}
```
El índice se queda sin poder salir por el `return`. La solución es **pasar una variable
"vacía"** desde `main` y que la función **la rellene**.

## 2. Solución en C: puntero (`int *pos`)

En C se pasa la **dirección** de la variable con `&`, y la función escribe en ella con `*`
(desreferencia):

```c
double picoMaximo(double arr[], int tam, int *pos) {
    double mayor = arr[0];
    *pos = 0;                 // *pos = "el entero que vive en esa direccion"
    for (int i = 1; i < tam; i++) {
        if (arr[i] > mayor) {
            mayor = arr[i];
            *pos = i;         // escribe en la variable de main
        }
    }
    return mayor;
}

int main(void) {
    int posicion;
    double v = picoMaximo(arr, tam, &posicion);   // &posicion = su direccion
    // aqui 'posicion' ya trae el indice, y 'v' el valor
}
```

- `&posicion` significa **"la dirección de posicion"**.
- `*pos` dentro de la función significa **"la variable que está en esa dirección"**.
- Así la función tiene una "vía directa" a la variable de `main` y puede modificarla.

## 3. Solución en C++: referencia (`int &pos`)

C++ ofrece algo más simple: la **referencia**. Se pone `&` en el parámetro y dentro se usa como
una variable normal (sin `*`):

```cpp
double picoMaximo(double arr[], int tam, int &pos) {
    double mayor = arr[0];
    pos = 0;                  // se usa directamente, sin '*'
    for (int i = 1; i < tam; i++) {
        if (arr[i] > mayor) { mayor = arr[i]; pos = i; }
    }
    return mayor;
}

int main() {
    int posicion;
    double v = picoMaximo(arr, tam, posicion);   // sin '&' en la llamada
}
```
Una **referencia** es "otro nombre" para la misma variable: `pos` y `posicion` son la misma
casilla de memoria. Es más legible que los punteros y hace lo mismo.

## 4. Solución en Java: no hay punteros → arreglo de un elemento

Java **no tiene** punteros ni referencias a variables sueltas: los `int`, `double`, etc. se
pasan **siempre por valor** (copia), así que modificar el parámetro **no** afecta a `main`.
El truco estándar es envolver el valor en un **arreglo de un elemento** (los arreglos sí se
pasan por referencia):

```java
static double picoMaximo(double[] arr, int tam, int[] pos) {
    double mayor = arr[0];
    pos[0] = 0;               // se escribe en pos[0]
    for (int i = 1; i < tam; i++) {
        if (arr[i] > mayor) { mayor = arr[i]; pos[0] = i; }
    }
    return mayor;
}

public static void main(String[] args) {
    int[] posicion = new int[1];                 // "caja" de un solo entero
    double v = picoMaximo(arr, tam, posicion);
    // posicion[0] trae el indice
}
```

## 5. Otras dos alternativas (para conocerlas)

1. **Devolver una estructura/objeto** con los dos campos:
   - C/C++: un `struct { double valor; int indice; };`
   - Java: una clase pequeña, o `double[] {valor, indice}`.
2. **Devolver un arreglo** de 2 posiciones `[valor, indice]` (menos claro si los tipos difieren).

Para este ejercicio, el paso por referencia es lo más directo y lo que pide la "función modular
con paso de parámetros".

## 6. Resumen

| | Mecanismo | En la función | En la llamada |
|---|---|---|---|
| **C** | puntero `int *pos` | `*pos = i;` | `picoMaximo(arr, tam, &posicion)` |
| **C++** | referencia `int &pos` | `pos = i;` | `picoMaximo(arr, tam, posicion)` |
| **Java** | arreglo `int[] pos` | `pos[0] = i;` | `picoMaximo(arr, tam, posicion)` (con `new int[1]`) |

> Detalle: en los tres lenguajes, **los arreglos ya viajan por referencia**. Por eso funciones
> como `invertirBuffer`, `rotaDerecha` o `normaliza` pueden modificar el arreglo recibido sin
> necesidad de `return`. Lo especial del Problema 21 es querer sacar **un dato suelto** (el
> índice) además del `return`.
