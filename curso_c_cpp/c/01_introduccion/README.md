# Lección 01 — Introducción y primer programa

## Qué es C

**C** es un lenguaje de programación creado por **Dennis Ritchie** en los Laboratorios Bell entre
1969 y 1973, para escribir el sistema operativo **UNIX**. Es un lenguaje:

- **Compilado:** tu código de texto se traduce a **lenguaje máquina** (instrucciones que la CPU
  ejecuta directamente) antes de correr. Eso lo hace muy **rápido**.
- **De propósito general y "de bajo nivel":** te da control fino sobre la **memoria** y el
  hardware, más cerca de la máquina que lenguajes como Python o Java.
- **Pequeño:** el lenguaje en sí tiene pocas palabras clave (unas 30). La potencia viene de
  combinarlas y de la **biblioteca estándar**.

C sigue siendo fundamental hoy: sistemas operativos (Linux, Windows), bases de datos,
microcontroladores, y es la base de la que nacieron C++, Java, C#, entre otros. Aprender C te
enseña **cómo funciona la computadora por dentro**.

## Qué necesitas

Un **compilador** (usaremos `gcc`) y un **editor de texto**. Si aún no lo tienes, revisa
[`../../CONFIGURACION.md`](../../CONFIGURACION.md).

## Tu primer programa: "Hola, mundo"

Por tradición, el primer programa en cualquier lenguaje imprime "Hola, mundo". Crea un archivo
`hola.c` con este contenido:

```c
#include <stdio.h>

int main(void) {
    printf("Hola, mundo\n");
    return 0;
}
```

Compílalo y ejecútalo:

```bash
gcc -std=c11 -Wall -Wextra hola.c -o hola
./hola
```

Salida:

```
Hola, mundo
```

¡Felicidades, ya programaste en C! Ahora vamos a entender **cada línea**, porque en este programa
tan corto están varias ideas centrales.

## Anatomía del programa, línea por línea

```c
#include <stdio.h>
```
- Es una **directiva del preprocesador** (empieza con `#`). Le dice al compilador: "incluye aquí
  el contenido de `stdio.h`".
- `stdio.h` = *standard input/output header* (cabecera de entrada/salida estándar). Contiene la
  **declaración** de `printf` (y de `scanf`, que veremos luego). Sin este `#include`, el
  compilador no sabría qué es `printf`.

```c
int main(void) {
```
- `main` es la **función principal**: el punto por donde **empieza** a ejecutarse todo programa
  en C. Si no hay `main`, no hay programa.
- `int` a la izquierda indica que `main` **devuelve un entero** al sistema operativo al terminar.
- `(void)` significa que `main` **no recibe parámetros** (más adelante veremos una forma que sí
  recibe argumentos de la línea de comandos).
- La llave `{` abre el **cuerpo** de la función: las instrucciones que se ejecutarán.

```c
    printf("Hola, mundo\n");
```
- `printf` (*print formatted*) es una **función de la biblioteca** que **imprime texto** en la
  pantalla (la salida estándar).
- Entre comillas dobles va una **cadena de texto** (*string*): `"Hola, mundo\n"`.
- `\n` es un **carácter especial**: el **salto de línea** (*newline*). Hace que el cursor baje al
  siguiente renglón. Sin él, la siguiente impresión quedaría pegada.
- El **punto y coma `;`** termina la instrucción. En C, casi toda instrucción acaba en `;`.
  Olvidarlo es el error de principiante número uno.

```c
    return 0;
```
- `main` devuelve `0` al sistema operativo. Por convención, **`0` significa "el programa terminó
  correctamente"**. Un valor distinto de 0 suele indicar un error.

```c
}
```
- La llave `}` **cierra** el cuerpo de `main`. Toda `{` debe tener su `}`.

## Sobre los caracteres de escape

Dentro de una cadena, la barra invertida `\` empieza una **secuencia de escape**, que representa
un carácter especial:

| Secuencia | Significado |
|---|---|
| `\n` | Salto de línea (newline) |
| `\t` | Tabulación (tab) |
| `\\` | Una barra invertida literal `\` |
| `\"` | Una comilla doble literal `"` (dentro de la cadena) |
| `\0` | Carácter nulo (marca el fin de una cadena; lo veremos en la lección 08) |

Ejemplo:

```c
printf("Linea 1\nLinea 2\n");
printf("Col1\tCol2\n");
```
Imprime:
```
Linea 1
Linea 2
Col1	Col2
```

## Comentarios

Los **comentarios** son texto que el compilador **ignora**; sirven para explicar el código a los
humanos.

```c
// Comentario de una linea (desde // hasta el fin de linea)

/* Comentario
   de varias
   lineas */
```

Usa comentarios para explicar el **por qué** de algo no obvio, no para repetir lo que el código
ya dice.

## Qué pasa al compilar (visión general)

Cuando ejecutas `gcc hola.c -o hola`, ocurren varias fases:

1. **Preprocesado:** se resuelven las directivas `#` (por ejemplo, se pega el contenido de
   `stdio.h`).
2. **Compilación:** el código C se traduce a **código ensamblador** y luego a **código objeto**
   (binario, `.o`).
3. **Enlazado (*linking*):** se junta tu código objeto con el de las bibliotecas (por ejemplo, la
   implementación real de `printf`) para producir el **ejecutable** final (`hola`).

Por ahora no necesitas dominar esto; basta saber que "compilar" convierte tu texto en un programa
ejecutable.

## Errores típicos al empezar

- **Olvidar el `;`** al final de una instrucción → error de compilación.
- **Olvidar `#include <stdio.h>`** → advertencia/error sobre `printf`.
- **Descuadrar las llaves `{ }`** → errores confusos; revisa que cada `{` tenga su `}`.
- **Nombre de archivo o mayúsculas** (`Printf` no es `printf`): C **distingue mayúsculas de
  minúsculas**.

## Resumen

- Todo programa C empieza en `main`.
- `#include` trae funciones de la biblioteca (como `printf` desde `stdio.h`).
- Las instrucciones terminan en `;`.
- `\n` es el salto de línea.
- Se compila con `gcc` y se ejecuta el archivo resultante.

## Ejemplos de esta lección

- [`ejemplos/hola.c`](ejemplos/hola.c) — el clásico "Hola, mundo".
- [`ejemplos/varias_lineas.c`](ejemplos/varias_lineas.c) — varios `printf`, escapes `\n` y `\t`.
- [`ejemplos/comentarios.c`](ejemplos/comentarios.c) — uso de comentarios.

## Ejercicios

Ve a [`ejercicios/`](ejercicios/). Intenta resolverlos antes de mirar las soluciones.

## Para profundizar

- **K&R**, *The C Programming Language*, cap. 1 (§1.1 "Getting Started").
- **King**, *C Programming: A Modern Approach*, cap. 1–2.
- **Beej's Guide to C**, "Hello, World!". https://beej.us/guide/bgc/
- **cppreference**, "C language" → "Basic concepts". https://en.cppreference.com/w/c/language
