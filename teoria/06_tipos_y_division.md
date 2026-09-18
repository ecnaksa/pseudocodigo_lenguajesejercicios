# 06 · Tipos de dato, división entera vs. real, y el tipo `bool`

## 1. Tipos de dato básicos

Cada variable tiene un **tipo** que define qué puede guardar y cuánta memoria ocupa. Los que
aparecen en los ejercicios:

| Concepto | Pseudocódigo | C | C++ | Java |
|---|---|---|---|---|
| Entero | `entero` | `int` | `int` | `int` |
| Real (con decimales) | `real` | `float` / `double` | `float` / `double` | `float` / `double` |
| Lógico (V/F) | `bool` | `bool` (con `<stdbool.h>`) | `bool` | `boolean` |
| Carácter | `caracter` | `char` | `char` | `char` |

Para los ejercicios basta `int` (enteros) y, en el Ejercicio 08, `double` para el promedio.

## 2. División entera vs. división real (Ejercicio 08)

Este es un punto que causa errores silenciosos. En C, C++ y Java, **si divides dos enteros,
el resultado es entero** (se **trunca**, se tira la parte decimal):

```c
int suma = 150, tam = 4;
suma / tam;        // ¡da 37, no 37.5!  (división ENTERA)
```

Para obtener el promedio **con decimales** hay que hacer que **al menos uno** de los operandos
sea real. Eso se logra con un **casteo** (conversión de tipo):

```c
/* C */
double promedio = (double) suma / tam;   // suma se convierte a double → división real → 37.5
```
```cpp
// C++
double promedio = static_cast<double>(suma) / tam;   // (double)suma también es válido
```
```java
// Java
double promedio = (double) suma / tam;
```

> Cuidado con el orden: `(double)(suma / tam)` **primero** hace la división entera (37) y
> **luego** convierte a `37.0`. Hay que convertir **antes** de dividir:
> `(double) suma / tam`. También sirve declarar `suma` como `double` desde el inicio.

En el pseudocódigo esto se refleja declarando `promedio` como **real**:

```
Definir promedio como real
promedio = suma / tam        // se entiende como división real
```

Al traducir, **no olvidar el casteo**, o el "promedio" saldría sin decimales.

## 3. El tipo lógico `bool` (Ejercicio 13)

Un `bool` solo puede valer **verdadero** o **falso**. Es el tipo que devuelve `esPalindromo`.

| | Tipo | Valores | Nota |
|---|---|---|---|
| **C** | `bool` | `true` / `false` | Hay que incluir `#include <stdbool.h>` |
| **C++** | `bool` | `true` / `false` | Nativo, no requiere include |
| **Java** | `boolean` | `true` / `false` | Se escribe `boolean`, no `bool` |

Uso típico:

```c
bool esPalindromo(int arr[], int tam) {
    for (int i = 0; i < tam / 2; i++) {
        if (arr[i] != arr[tam - 1 - i]) {
            return false;      // en cuanto falla la simetría
        }
    }
    return true;               // sobrevivió todas las comparaciones
}
```

Y al usarlo, el resultado ya es una condición; **no hace falta** `== true`:

```c
if (esPalindromo(arr, tam)) { ... }        // preferible
if (esPalindromo(arr, tam) == true) { ... } // válido, pero redundante
```

## 4. Desbordamiento (nota breve)

Un `int` tiene un rango limitado (en C/C++/Java típicamente hasta `2 147 483 647`). Sumar
valores muy grandes puede **desbordar** y dar resultados extraños. Para los tamaños de estos
ejercicios (5, 8, 10, 20 elementos con valores normales) no hay problema, pero conviene saber
que existe: si algún día sumas millones de números grandes, se usa un tipo más ancho como
`long` (C/C++/Java) o `long long` (C/C++).

## 5. Resumen

- Divide enteros → obtienes **entero** (se pierde el decimal). Castea a `double` para el
  promedio real (Ej. 08).
- `bool`/`boolean` para verdadero/falso (Ej. 13); en C recuerda `<stdbool.h>`.
- Elige el tipo según lo que guardas: contar → `int`; promediar → `double`; sí/no → `bool`.
