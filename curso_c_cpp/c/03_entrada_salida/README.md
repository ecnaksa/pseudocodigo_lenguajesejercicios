# Lección 03 — Entrada y salida (`printf` y `scanf`)

Hasta ahora solo **mostramos** texto. Un programa útil también **recibe datos**. En C, la
entrada/salida por consola se hace con dos funciones de `<stdio.h>`: **`printf`** (mostrar) y
**`scanf`** (leer).

## `printf`: mostrar con formato

`printf` imprime texto y **valores de variables**. Dentro de la cadena pones **especificadores de
formato** (empiezan con `%`), y después, separados por comas, los valores que rellenan esos
huecos, en orden:

```c
int edad = 25;
double altura = 1.72;
printf("Tengo %d anios y mido %.2f m\n", edad, altura);
// Tengo 25 anios y mido 1.72 m
```

### Especificadores más usados

| Especificador | Para el tipo | Ejemplo |
|---|---|---|
| `%d` | `int` | `printf("%d", 42)` → `42` |
| `%f` | `double`/`float` | `printf("%f", 3.5)` → `3.500000` |
| `%c` | `char` | `printf("%c", 'A')` → `A` |
| `%s` | cadena de texto | `printf("%s", "hola")` → `hola` |
| `%zu` | `size_t` (de `sizeof`) | `printf("%zu", sizeof(int))` |
| `%%` | un `%` literal | `printf("50%%")` → `50%` |

### Controlar el formato de los números

- **Decimales:** `%.2f` muestra 2 decimales → `3.14`. `%.0f` ninguno.
- **Ancho:** `%5d` reserva al menos 5 espacios (alinea a la derecha) → `   42`.
- Combinados: `%8.2f` → ancho 8, 2 decimales.

```c
printf("[%5d]\n", 42);      // [   42]
printf("[%-5d]\n", 42);     // [42   ]   (el - alinea a la izquierda)
printf("%.3f\n", 3.14159);  // 3.142     (redondea a 3 decimales)
```

## `scanf`: leer del teclado

`scanf` lee datos que el usuario escribe y los **guarda en variables**. Su forma se parece a
`printf`, pero con una diferencia crucial: hay que pasarle **la dirección** de la variable, con el
operador **`&`**.

```c
int edad;
printf("Ingresa tu edad: ");
scanf("%d", &edad);          // el & es OBLIGATORIO con tipos basicos
printf("El proximo anio tendras %d\n", edad + 1);
```

### ¿Por qué el `&`?

`scanf` necesita saber **dónde** guardar el dato que lee. `&edad` significa "la **dirección en
memoria** de `edad`". Sin el `&`, `scanf` recibiría el *valor* (basura) en vez del *lugar*, y el
programa fallaría. (Los punteros de la lección 09 explican esto a fondo; por ahora: **`scanf`
lleva `&`**.)

### Especificadores de `scanf` (¡ojo con `double`!)

| Leer un… | Especificador |
|---|---|
| `int` | `%d` |
| `float` | `%f` |
| **`double`** | **`%lf`** ← distinto de `printf` |
| `char` | `%c` |

> Detalle que confunde: para **imprimir** un `double` usas `%f`, pero para **leerlo** con `scanf`
> usas **`%lf`**. Es una peculiaridad histórica de C.

### Leer varios valores

```c
int a, b;
printf("Ingresa dos numeros: ");
scanf("%d %d", &a, &b);      // lee dos enteros separados por espacio o salto de linea
printf("Suma: %d\n", a + b);
```

`scanf` con `%d`/`%f` **salta automáticamente** los espacios y saltos de línea previos, así que el
usuario puede separar los números con espacios o Enter.

## El caso especial de `%c` y el "Enter pendiente"

Al leer un número con `scanf("%d", ...)`, el **Enter** (`\n`) que el usuario pulsó **queda en el
buffer**. Si justo después lees un `char` con `%c`, capturará ese `\n` en vez del carácter que
esperabas. La solución habitual es poner un **espacio antes de `%c`**, que le dice a `scanf`
"ignora los espacios/saltos pendientes":

```c
int edad;
char inicial;
scanf("%d", &edad);
scanf(" %c", &inicial);   // el espacio antes de %c evita capturar el '\n' pendiente
```

## Comprobar que la lectura funcionó (buena práctica)

`scanf` **devuelve** cuántos valores logró leer. Puedes verificarlo:

```c
int n;
if (scanf("%d", &n) != 1) {
    printf("Entrada invalida\n");
    return 1;
}
```
Al principio puedes omitir esta comprobación para no complicarte, pero es una buena costumbre
para programas robustos.

## Ejemplo completo

```c
#include <stdio.h>

int main(void) {
    int edad;
    double sueldo;

    printf("Edad: ");
    scanf("%d", &edad);

    printf("Sueldo por hora: ");
    scanf("%lf", &sueldo);        // %lf para leer double

    printf("En %d anios ganaras aprox. %.2f por hora tras subidas\n",
           5, sueldo * 1.1);
    return 0;
}
```

## Errores típicos

- **Olvidar el `&`** en `scanf` → el programa se rompe (crash) o guarda mal el dato.
- **Usar `%f` en vez de `%lf`** al leer un `double` con `scanf`.
- **El `\n` pendiente** al mezclar `%d`/`%f` con `%c` (usa `" %c"`).
- **Orden o número de argumentos** que no coincide con los `%` → salida rara.

## Resumen

- `printf("...%d...", valor)` muestra; los `%` son especificadores.
- `%.2f` controla decimales, `%5d` el ancho.
- `scanf("%d", &var)` lee; **siempre `&`** con tipos básicos.
- `double` se **lee** con `%lf` y se **imprime** con `%f`.
- Usa `" %c"` (con espacio) al leer caracteres tras un número.

## Ejemplos de esta lección

- [`ejemplos/leer_entero.c`](ejemplos/leer_entero.c)
- [`ejemplos/formato_printf.c`](ejemplos/formato_printf.c)
- [`ejemplos/leer_varios.c`](ejemplos/leer_varios.c)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **King**, cap. 3 ("Formatted Input/Output").
- **cppreference**, `printf`/`scanf`. https://en.cppreference.com/w/c/io/fprintf
