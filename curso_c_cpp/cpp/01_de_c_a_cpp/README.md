# Lección 01 — De C a C++

C++ empezó como "C con clases": es, en gran medida, un **superconjunto de C**. Casi todo tu
conocimiento de C sigue valiendo. Esta pista se centra en lo que C++ **añade**. Empecemos por lo
más visible: la entrada/salida y algunos cambios de estilo.

> **Requisito:** haber hecho la pista de C (al menos hasta punteros y estructuras).

## "Hola, mundo" en C++

```cpp
#include <iostream>

int main() {
    std::cout << "Hola, mundo" << std::endl;
    return 0;
}
```

Compilar y ejecutar (nota: `g++`, extensión `.cpp`):

```bash
g++ -std=c++17 -Wall -Wextra hola.cpp -o hola
./hola
```

Comparémoslo con C: donde C usaba `#include <stdio.h>` y `printf`, C++ usa `#include <iostream>`
y `std::cout`. Veamos las novedades.

## La biblioteca de flujos: `iostream`

C++ ofrece **flujos** (*streams*) para entrada/salida, más seguros y flexibles que `printf`:

- **`std::cout`** (*character output*): la salida estándar (pantalla).
- **`std::cin`** (*character input*): la entrada estándar (teclado).
- El operador **`<<`** "inserta" en la salida; **`>>`** "extrae" de la entrada.

```cpp
int edad;
std::cout << "Tu edad: ";
std::cin >> edad;                          // sin & y sin %d: cin sabe el tipo
std::cout << "El proximo anio: " << edad + 1 << std::endl;
```

**Ventajas frente a `printf`/`scanf`:**
- **No hay especificadores** (`%d`, `%f`…): `cout`/`cin` deducen el tipo automáticamente. Menos
  errores.
- Se **encadenan** varios valores con `<<`: `cout << "x=" << x << ", y=" << y;`.
- `cin >>` **no** necesita `&`.

`std::endl` inserta un salto de línea (como `"\n"`) y además **vacía el buffer**. Para muchas
impresiones seguidas, `"\n"` es un poco más eficiente; ambos sirven.

## Namespaces y `std::`

Todo lo de la biblioteca estándar de C++ vive en el **espacio de nombres** `std` (de *standard*).
Por eso escribes `std::cout`, `std::cin`, `std::endl`. Los **namespaces** evitan choques de
nombres entre bibliotecas.

Para no repetir `std::`, puedes escribir `using namespace std;` una vez:

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hola" << endl;    // ya no hace falta std::
    return 0;
}
```

> **Matiz:** `using namespace std;` es cómodo para aprender y programas pequeños, pero en
> proyectos grandes se **desaconseja** (puede provocar colisiones de nombres). Una alternativa es
> importar solo lo que usas: `using std::cout;`. En este curso lo usaremos por comodidad, pero
> tenlo presente.

## Otras diferencias cómodas respecto a C

### El tipo `bool` es nativo

En C necesitabas `<stdbool.h>`; en C++, `bool`, `true` y `false` son parte del lenguaje:

```cpp
bool activo = true;
if (activo) { /* ... */ }
```

### Comentarios y declaraciones

- Los comentarios `//` funcionan igual (C también los tiene desde C99).
- Puedes **declarar variables donde las necesites** (no solo al principio del bloque), algo que en
  C clásico no se permitía.

### `nullptr` en vez de `NULL`

Para punteros nulos, C++ prefiere **`nullptr`** (más seguro que `NULL`). Lo veremos con punteros.

### Constantes: `const` (y `constexpr`)

En C++ se prefiere `const` sobre `#define` para constantes con tipo. Además existe `constexpr`
para constantes evaluadas en compilación (avanzado).

## ¿Qué sigue siendo igual que en C?

**Mucho:** `if`, `else`, `switch`, `while`, `for`, funciones, operadores, arreglos, punteros,
`struct`, tipos básicos (`int`, `double`, `char`)... Todo eso lo aprendiste en la pista de C y
**funciona igual** en C++. Por eso esta pista se centra en lo nuevo (referencias, clases,
plantillas, STL...).

## Errores típicos al pasar de C a C++

- Seguir usando `printf`/`scanf` (funcionan en C++ vía `<cstdio>`, pero lo idiomático es
  `cout`/`cin`).
- Olvidar `std::` (o el `using namespace std;`) → error "cout was not declared".
- Compilar con `gcc` en vez de `g++` (o usar extensión `.c`).

## Resumen

- C++ es casi un superconjunto de C; casi todo lo de C sigue valiendo.
- E/S con flujos: `std::cout << ...` y `std::cin >> ...`, sin especificadores ni `&`.
- Todo lo estándar está en el namespace `std` (`std::` o `using namespace std;`).
- `bool`/`true`/`false` nativos; `nullptr` para punteros; `const`/`constexpr` para constantes.
- Compila con `g++ -std=c++17`.

## Ejemplos

- [`ejemplos/hola.cpp`](ejemplos/hola.cpp)
- [`ejemplos/entrada.cpp`](ejemplos/entrada.cpp)
- [`ejemplos/comparacion_printf.cpp`](ejemplos/comparacion_printf.cpp)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **Stroustrup**, *A Tour of C++*, cap. 1 ("The Basics").
- **learncpp.com**, secciones 1.x ("C++ Basics"). https://www.learncpp.com/
- **cppreference**, "iostream". https://en.cppreference.com/w/cpp/io
