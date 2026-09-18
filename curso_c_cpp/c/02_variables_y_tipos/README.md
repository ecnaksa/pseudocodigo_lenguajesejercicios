# Lección 02 — Variables, tipos de datos y constantes

## Qué es una variable

Una **variable** es un espacio en la **memoria** con un **nombre**, donde guardas un valor que
puede **cambiar** mientras el programa corre. Piensa en una caja etiquetada: la etiqueta es el
nombre, y dentro está el valor.

En C, **antes de usar una variable debes declararla**, indicando su **tipo** (qué clase de dato
guardará) y su nombre:

```c
int edad;        // declara una variable entera llamada 'edad'
edad = 25;       // le asigna el valor 25
```

O todo en una línea (declaración con inicialización):

```c
int edad = 25;
double precio = 19.99;
char inicial = 'A';
```

> **Regla importante:** en C una variable **no inicializada** contiene **basura** (un valor
> indeterminado). Siempre que puedas, **inicialízala** al declararla.

## Los tipos de datos básicos

C es un lenguaje de **tipado estático**: el tipo de cada variable se fija al declararla y no
cambia. Los tipos fundamentales son:

| Tipo | Guarda | Ejemplo de literal | `printf` |
|---|---|---|---|
| `int` | enteros | `42`, `-7`, `0` | `%d` |
| `float` | reales (precisión simple) | `3.14f` | `%f` |
| `double` | reales (precisión doble) | `3.14159` | `%f` (o `%lf` al leer) |
| `char` | un carácter | `'A'`, `'5'`, `'\n'` | `%c` |

Ejemplo mostrando cada uno:

```c
#include <stdio.h>

int main(void) {
    int cantidad = 5;
    double precio = 2.50;
    char letra = 'C';

    printf("Cantidad: %d\n", cantidad);
    printf("Precio: %f\n", precio);
    printf("Letra: %c\n", letra);
    return 0;
}
```

### El tipo `char` guarda números

Un `char` guarda **un** carácter, pero por dentro es un **número entero pequeño** (1 byte): el
**código ASCII** del carácter. Por eso `'A'` es en realidad el número `65`.

```c
char c = 'A';
printf("%c\n", c);   // A
printf("%d\n", c);   // 65  (el mismo dato, mostrado como numero)
```

## Modificadores de tipo

Los enteros admiten **modificadores** que cambian su tamaño o si permiten negativos:

- **`short`** y **`long`** (y `long long`): enteros más pequeños o más grandes.
- **`unsigned`**: solo valores **no negativos** (0 en adelante), a cambio de llegar al doble por
  el lado positivo.

```c
unsigned int poblacion = 4000000000u;   // muchos positivos, ningun negativo
long long distancia = 9000000000LL;     // enteros muy grandes
short pequeno = 100;
```

## Tamaños y rangos: `sizeof` y `<limits.h>`

Cada tipo ocupa cierto número de **bytes** en memoria, y por eso tiene un **rango** de valores
que puede representar. El operador `sizeof` te dice cuántos bytes ocupa un tipo:

```c
#include <stdio.h>

int main(void) {
    printf("int:    %zu bytes\n", sizeof(int));
    printf("double: %zu bytes\n", sizeof(double));
    printf("char:   %zu byte\n",  sizeof(char));
    return 0;
}
```

> `%zu` es el especificador para el tipo que devuelve `sizeof` (`size_t`).

En una PC típica: `int` = 4 bytes, `double` = 8, `char` = 1. **No lo des por seguro**: el estándar
solo garantiza mínimos. Los **rangos exactos** están en `<limits.h>` (enteros) y `<float.h>`
(reales): por ejemplo `INT_MAX` es el mayor `int`.

**El desbordamiento (overflow)** ocurre si guardas un valor fuera del rango: el resultado "da la
vuelta" y produce números erróneos. Elige un tipo con rango suficiente.

## Nombres de variables (identificadores)

Reglas para nombrar variables:

- Pueden llevar **letras, dígitos y guion bajo** `_`, pero **no** empezar con un dígito.
- **Distinguen mayúsculas**: `edad`, `Edad` y `EDAD` son tres variables distintas.
- No pueden ser **palabras reservadas** (`int`, `return`, `if`, `while`, …).
- Elige nombres **descriptivos**: `precioTotal` es mejor que `x`.

## Constantes: valores que no cambian

A veces quieres un valor con nombre que **no** deba cambiar (una tasa, Pi, un límite). Dos formas:

**1. `const`** — una variable de solo lectura (con tipo, la forma recomendada):

```c
const double PI = 3.14159;
const int MAX_INTENTOS = 3;
// PI = 4;   // ERROR de compilacion: no se puede modificar una const
```

**2. `#define`** — una macro del preprocesador (sustitución de texto, sin tipo):

```c
#define PI 3.14159
#define MAX_INTENTOS 3
```

Por convención, las constantes se escriben en **MAYÚSCULAS**. Hoy suele preferirse `const` porque
respeta los tipos y da mejores errores; `#define` sigue siendo común para valores simples.

## Conversión de tipos (casting)

Cuando mezclas tipos, C hace **conversiones**. Ojo con la **división entera**: si divides dos
`int`, el resultado es `int` (se pierde la parte decimal):

```c
int a = 7, b = 2;
printf("%d\n", a / b);            // 3  (division entera, se trunca)

double r = (double) a / b;        // (double) convierte 'a' a real ANTES de dividir
printf("%f\n", r);                // 3.500000
```

`(double) a` es un **casting** (conversión explícita): "trata `a` como `double`". Al hacer real
uno de los operandos, la división pasa a ser real. Recuerda ponerlo **antes** de dividir:
`(double) a / b`, no `(double)(a / b)`.

## Errores típicos

- **Usar una variable sin inicializar** → valor basura.
- **División entera inesperada** (`1/2` da `0`, no `0.5`).
- **Elegir un tipo demasiado pequeño** → desbordamiento.
- **Confundir `=` (asignar) con `==` (comparar)** — lo veremos en condicionales.

## Resumen

- Declara variables con `tipo nombre;` e inicialízalas.
- Tipos base: `int`, `float`, `double`, `char`; modificadores `short/long/unsigned`.
- `sizeof` da el tamaño en bytes; los rangos están en `<limits.h>`/`<float.h>`.
- Constantes con `const` (recomendado) o `#define`.
- Cuidado con la división entera; usa `(double)` para forzar división real.

## Ejemplos de esta lección

- [`ejemplos/tipos_basicos.c`](ejemplos/tipos_basicos.c)
- [`ejemplos/tamanos.c`](ejemplos/tamanos.c)
- [`ejemplos/division_y_cast.c`](ejemplos/division_y_cast.c)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **K&R**, cap. 2 ("Types, Operators and Expressions").
- **King**, *C Programming: A Modern Approach*, cap. 7 ("Basic Types").
- **cppreference**, "C" → "Basic concepts" → "Types" y "Objects and alignment".
  https://en.cppreference.com/w/c/language/type
