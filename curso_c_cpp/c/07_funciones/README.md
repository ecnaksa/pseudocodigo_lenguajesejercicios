# Lección 07 — Funciones

Una **función** es un bloque de código con **nombre** que realiza una tarea, puede **recibir
datos** (parámetros) y puede **devolver** un resultado. Ya usas una función especial en todo
programa: `main`. Ahora aprenderás a crear las tuyas.

## Por qué usar funciones

- **No repetir código** (DRY: *Don't Repeat Yourself*): escribes la lógica una vez y la reutilizas.
- **Dividir el problema** en piezas pequeñas y manejables.
- **Legibilidad**: `double area = areaCirculo(5);` se lee mejor que la fórmula repetida.
- **Probar y depurar** cada pieza por separado.

## Anatomía de una función

```c
tipo_de_retorno  nombre(parametros) {
    // cuerpo
    return valor;   // si el tipo no es void
}
```

Ejemplo: una función que suma dos enteros.

```c
int sumar(int a, int b) {
    int resultado = a + b;
    return resultado;
}
```

- `int` (antes del nombre) es el **tipo que devuelve**.
- `sumar` es el nombre.
- `(int a, int b)` son los **parámetros**: variables locales que reciben los valores al llamarla.
- `return resultado;` **entrega** el valor y termina la función.

**Llamarla** (usarla):

```c
int total = sumar(3, 4);   // total = 7
printf("%d\n", total);
```
Los valores `3` y `4` (los **argumentos**) se copian en `a` y `b`.

## Funciones `void` (no devuelven nada)

Si la función solo **hace** algo (imprimir, por ejemplo) y no entrega un valor, su tipo es
**`void`**:

```c
void saludar(void) {
    printf("Hola!\n");
}
// ...
saludar();   // se llama sin usar su valor
```

## Prototipos: declarar antes de usar

C lee el archivo **de arriba abajo**. Si llamas a una función **antes** de definirla, el
compilador no la conoce todavía. Hay dos soluciones:

1. **Definir la función antes de `main`.**
2. **Poner un *prototipo* (declaración) arriba**, y la definición después. Un prototipo es la
   primera línea de la función seguida de `;`:

```c
#include <stdio.h>

int sumar(int a, int b);      // PROTOTIPO: "existe una funcion sumar que devuelve int"

int main(void) {
    printf("%d\n", sumar(3, 4));   // se puede usar aunque se defina abajo
    return 0;
}

int sumar(int a, int b) {     // DEFINICION
    return a + b;
}
```
Los prototipos son la base para organizar el código en varios archivos (lección 13).

## Paso de argumentos: **por valor**

En C, los argumentos se pasan **por valor**: la función recibe una **copia**. Modificar el
parámetro **no** afecta a la variable original:

```c
void intentarCambiar(int x) {
    x = 100;              // cambia solo la COPIA local
}
int main(void) {
    int n = 5;
    intentarCambiar(n);
    printf("%d\n", n);    // sigue siendo 5
}
```

Para que una función **sí** modifique una variable del que la llama, hay que pasar su
**dirección** (un puntero). Eso lo verás en la lección 09; por eso `scanf` lleva `&`. Los
**arreglos**, en cambio, se pasan de forma que sí se pueden modificar (lección 08).

## Ámbito (scope) de las variables

- Las variables declaradas **dentro** de una función (incluidos sus parámetros) son **locales**:
  solo existen ahí. Dos funciones pueden usar `i` sin interferir.
- Las variables declaradas **fuera** de toda función son **globales**: visibles desde todas. Úsalas
  con moderación (dificultan seguir el flujo); es mejor pasar datos por parámetros.

## Recursión: una función que se llama a sí misma

Una función puede llamarse a sí misma para resolver un problema en términos de una versión más
pequeña. Necesita un **caso base** que detenga la recursión:

```c
long long factorial(int n) {
    if (n <= 1) return 1;             // caso base
    return n * factorial(n - 1);      // caso recursivo
}
```
`factorial(4)` = `4 * factorial(3)` = `4 * 3 * factorial(2)` = ... = `24`. **Sin** caso base, la
recursión sería infinita (y agotaría la memoria). Muchos problemas recursivos también se pueden
resolver con bucles; usa el que sea más claro.

## Buenas prácticas

- **Una función, una tarea.** Si hace demasiado, divídela.
- **Nombres que digan qué hace** (`calcularPromedio`, no `f`).
- Mantenlas **cortas**; si una función no cabe en la pantalla, probablemente hace de más.
- Documenta con un comentario **qué** hace, **qué** recibe y **qué** devuelve.

## Errores típicos

- Llamar a una función sin declararla/definirla antes → error o advertencia.
- Olvidar el `return` en una función que no es `void`.
- Esperar que la función modifique una variable pasada por valor (no lo hará).
- Recursión sin caso base → desbordamiento de pila (*stack overflow*).

## Resumen

- `tipo nombre(parametros){ ... return valor; }`.
- `void` si no devuelve nada; los argumentos se pasan **por copia**.
- Usa **prototipos** para llamar antes de definir.
- Variables **locales** vs **globales** (prefiere locales + parámetros).
- **Recursión**: caso base + caso recursivo.

## Ejemplos

- [`ejemplos/sumar.c`](ejemplos/sumar.c)
- [`ejemplos/por_valor.c`](ejemplos/por_valor.c)
- [`ejemplos/recursion.c`](ejemplos/recursion.c)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **K&R**, cap. 4 ("Functions and Program Structure").
- **King**, cap. 9 ("Functions").
- **cppreference**, "Functions". https://en.cppreference.com/w/c/language/functions
