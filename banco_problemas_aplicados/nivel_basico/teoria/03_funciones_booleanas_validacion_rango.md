# 03 · Funciones booleanas y validación de rango

Los problemas 12 (rango seguro) y 18 (comparar canales) devuelven un **booleano**: `true` o
`false`. Es el patrón de "verificar una propiedad de todo el arreglo".

## 1. El patrón "¿todos cumplen?" con salida temprana

Para responder "¿**todos** los elementos cumplen X?", lo eficiente es recorrer y **salir en
cuanto uno falle**:

```
funcion bool todosCumplen(...){
    for (i = 0; i < tam; i++){
        if ( ! (elemento i cumple X) ){
            return false      // un contraejemplo basta para decir "no"
        }
    }
    return true               // nadie falló => todos cumplen
}
```

- **P12:** ¿todas las mediciones están dentro de `[3.3, 5.0]`? Si una se sale → `false`.
- **P18:** ¿son idénticos A y B? Si un par `A[i] != B[i]` → `false`.

El `return true` va **fuera** del bucle: solo se llega ahí si el `for` terminó sin encontrar
ningún fallo. Ponerlo dentro del bucle sería un error clásico (devolvería en la primera vuelta).

## 2. La trampa del rango: `3.3 <= val <= 5.0` NO se escribe así

En matemáticas escribimos `3.3 ≤ val ≤ 5.0`. En **C, C++ y Java eso NO funciona** como uno
espera:

```c
if (3.3 <= val <= 5.0)   // ❌ NO hace lo que crees
```

El compilador lo evalúa de izquierda a derecha:
1. Primero `3.3 <= val` → da un booleano (`true`/`false`, que vale `1` o `0`).
2. Luego compara ese `1` o `0` contra `5.0`: `(0 o 1) <= 5.0` → **siempre `true`**.

Resultado: la condición se cumpliría **siempre**, y el chequeo de rango sería inútil (en Java
ni siquiera compila, porque `boolean <= double` es un error de tipos).

**La forma correcta** es partir el rango en **dos** comparaciones unidas con `&&` (Y lógico):

```c
if (val >= 3.3 && val <= 5.0)   // ✅ "val es mayor o igual que 3.3 Y menor o igual que 5.0"
```

Y para detectar el que se **sale** del rango, se niega con `!`:

```c
if ( !(val >= 3.3 && val <= 5.0) ) {
    return false;   // esta fuera del rango
}
```
> Por las leyes de De Morgan, `!(a && b)` equivale a `(!a || !b)`, es decir
> `(val < 3.3 || val > 5.0)`. Las dos formas son válidas; usa la que leas más claro.

## 3. El tipo booleano en cada lenguaje

| | Tipo | Valores | Nota |
|---|---|---|---|
| **C** | `bool` | `true`/`false` | requiere `#include <stdbool.h>` |
| **C++** | `bool` | `true`/`false` | nativo |
| **Java** | `boolean` | `true`/`false` | se escribe `boolean` |

## 4. Usar el resultado sin `== true`

Como la función ya devuelve un booleano, se puede usar directo en el `if`:

```c
if (enRango(arr, tam)) { ... }          // preferible
if (enRango(arr, tam) == true) { ... }  // válido, pero redundante
```
En el pseudocódigo se dejó `== true` por claridad didáctica; en el código real se usa la forma
directa.

## 5. Operadores lógicos que aparecen aquí

| Operador | Significado | Ejemplo |
|---|---|---|
| `&&` | Y (ambas verdaderas) | `val >= 3.3 && val <= 5.0` |
| `\|\|` | O (al menos una) | `val < 3.3 \|\| val > 5.0` |
| `!` | NO (niega) | `!(val >= 3.3 && val <= 5.0)` |
