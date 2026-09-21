# Lección 13 — Preprocesador y varios archivos

Un programa real no cabe cómodamente en **un solo archivo**. Esta lección te enseña a **dividir**
tu código en varios archivos y a entender el **preprocesador**, la primera fase de la compilación.

## El preprocesador

Antes de compilar, el **preprocesador** procesa las líneas que empiezan con `#`. Es una fase de
**sustitución de texto**.

### `#include`

Ya lo usas: pega el contenido de un archivo de cabecera.

```c
#include <stdio.h>      // cabecera del sistema: entre < >
#include "mimodulo.h"   // cabecera tuya: entre comillas
```
- `< >` busca en los directorios del sistema (bibliotecas estándar).
- `" "` busca **primero** en tu carpeta (tus propios archivos).

### `#define`: macros

Define una **sustitución de texto**. Para constantes:

```c
#define PI 3.14159
#define MAX 100
double area = PI * r * r;    // el preprocesador reemplaza PI por 3.14159
```

También **macros con parámetros** (parecen funciones, pero son sustitución):

```c
#define CUADRADO(x) ((x) * (x))
int y = CUADRADO(5);         // se convierte en ((5) * (5)) = 25
```
> **Cuidado:** rodea los parámetros y el todo con paréntesis. Sin ellos, `CUADRADO(1+2)` sería
> `1+2*1+2 = 5` en vez de `9`. Por eso hoy suele preferirse `const` y funciones `inline` para
> valores y cálculos; las macros con parámetros son delicadas.

### Compilación condicional e *include guards*

`#ifndef` / `#define` / `#endif` evitan que una cabecera se incluya **dos veces** (lo que causaría
errores de redefinición). Es el patrón estándar en todo archivo `.h`:

```c
#ifndef MIMODULO_H      // "si NO se ha definido MIMODULO_H..."
#define MIMODULO_H      // ...definelo (para que la proxima vez se salte)

// ... contenido de la cabecera ...

#endif                  // fin del guard
```
(La alternativa moderna, no estándar pero muy soportada, es una sola línea al inicio: `#pragma
once`.)

## Compilación separada: dividir en varios archivos

La idea: separar las **declaraciones** (qué existe) de las **definiciones** (cómo funciona).

- Un archivo **`.h`** (cabecera): **declara** funciones, tipos y constantes (los *prototipos*).
- Un archivo **`.c`**: **define** (implementa) esas funciones.
- Otros `.c` que quieran usarlas hacen `#include "modulo.h"`.

### Ejemplo de tres archivos

**`mathutils.h`** (la interfaz — qué ofrece el módulo):
```c
#ifndef MATHUTILS_H
#define MATHUTILS_H

int sumar(int a, int b);
int factorial(int n);

#endif
```

**`mathutils.c`** (la implementación):
```c
#include "mathutils.h"

int sumar(int a, int b) {
    return a + b;
}
int factorial(int n) {
    int r = 1;
    for (int i = 2; i <= n; i++) r *= i;
    return r;
}
```

**`main.c`** (usa el módulo):
```c
#include <stdio.h>
#include "mathutils.h"

int main(void) {
    printf("%d\n", sumar(3, 4));
    printf("%d\n", factorial(5));
    return 0;
}
```

### Compilar varios archivos

Le pasas **todos** los `.c` al compilador (la cabecera **no** se compila; se incluye):

```bash
gcc -std=c11 -Wall main.c mathutils.c -o programa
./programa
```

Por dentro, cada `.c` se compila por separado a un `.o` (código objeto) y luego el **enlazador**
(*linker*) los junta. En proyectos grandes esto permite **recompilar solo lo que cambió**.

## `make`: automatizar la compilación

Escribir el comando completo cada vez es tedioso. **`make`** lee un archivo **`Makefile`** con
**reglas** y compila lo necesario:

```make
programa: main.c mathutils.c mathutils.h
	gcc -std=c11 -Wall main.c mathutils.c -o programa

clean:
	rm -f programa
```
- La primera línea: "para crear `programa`, que depende de estos archivos, ejecuta el comando de
  abajo".
- **Importante:** la línea del comando debe empezar con un **TAB** (tabulación), no espacios.
- Se usa así:
  ```bash
  make          # compila
  make clean    # borra el ejecutable
  ```
`make` solo recompila si algún archivo cambió, ahorrando tiempo en proyectos grandes. (Existen
herramientas más modernas como **CMake** para proyectos complejos.)

## `static` y `extern` (breve)

- Una función o variable global marcada **`static`** solo es visible **dentro de su archivo**
  (encapsulamiento a nivel de archivo).
- **`extern`** declara una variable global definida en **otro** archivo.

## Errores típicos

- **Olvidar los *include guards*** en un `.h` → errores de "redefinición".
- **No pasar todos los `.c`** al compilar → error de "referencia indefinida" (*undefined
  reference*) en el enlazado.
- **Poner definiciones en el `.h`** (deben ir en el `.c`; el `.h` declara).
- En el `Makefile`, usar **espacios** en vez de **TAB** en la línea del comando.

## Resumen

- El preprocesador (`#`) hace sustitución de texto: `#include`, `#define`, `#ifndef`.
- Divide el código: `.h` **declara**, `.c` **define**; incluye el `.h` con `#include "..."`.
- Protege las cabeceras con *include guards*.
- Compila pasando **todos** los `.c`; automatiza con un `Makefile` (TAB en los comandos).

## Ejemplo de esta lección

Un proyecto de tres archivos con Makefile en [`ejemplos/proyecto/`](ejemplos/proyecto/):

```bash
cd ejemplos/proyecto
make
./programa
```

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **K&R**, cap. 4 (§4.11 "The C Preprocessor").
- **King**, cap. 14 ("The Preprocessor") y cap. 15 ("Writing Large Programs").
- **cppreference**, "Preprocessor". https://en.cppreference.com/w/c/preprocessor
- **GNU Make manual**: https://www.gnu.org/software/make/manual/
