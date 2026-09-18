# Configuración del entorno

Antes de empezar necesitas un **compilador** (que traduce tu código a un ejecutable) y un
**editor de texto**. Aquí tienes lo mínimo para C y C++.

## 1. El compilador

Usaremos **GCC** (para C, comando `gcc`) y **G++** (para C++, comando `g++`), el compilador
libre más usado. Alternativas válidas: **Clang** (`clang`/`clang++`) y **MSVC** (en Windows).

### Linux (Debian/Ubuntu)

```bash
sudo apt update
sudo apt install build-essential   # incluye gcc, g++, make
```

### macOS

```bash
xcode-select --install             # instala las herramientas de linea de comandos (clang)
# opcional, para tener gcc/g++ "de verdad": brew install gcc
```

### Windows

- **Opción A (recomendada para principiantes):** instala **MSYS2** (https://www.msys2.org) y
  luego, en su terminal: `pacman -S mingw-w64-ucrt-x86_64-gcc`.
- **Opción B:** usa **WSL** (Windows Subsystem for Linux) y sigue las instrucciones de Linux.
- **Opción C:** instala **Visual Studio Community** (trae el compilador MSVC y un IDE completo).

### Comprobar que funciona

```bash
gcc --version
g++ --version
```

## 2. El editor

Cualquiera sirve, pero para empezar bien:

- **Visual Studio Code** (https://code.visualstudio.com) + extensión oficial **C/C++** de
  Microsoft. Gratuito y multiplataforma.
- Alternativas: **Code::Blocks**, **CLion** (de pago), **Vim/Neovim**, o incluso el Bloc de notas
  para los primeros programas.

## 3. Compilar y ejecutar

Un programa en C/C++ pasa por dos pasos: **compilar** (crear el ejecutable) y **ejecutar**.

### C

```bash
gcc -std=c11 -Wall -Wextra hola.c -o hola   # compila hola.c y crea el ejecutable "hola"
./hola                                       # lo ejecuta (en Windows: hola.exe)
```

### C++

```bash
g++ -std=c++17 -Wall -Wextra hola.cpp -o hola
./hola
```

### Qué significan las banderas (flags)

| Bandera | Para qué sirve |
|---|---|
| `-std=c11` / `-std=c++17` | Elige la **versión del lenguaje** (estándar). |
| `-Wall` | Activa **advertencias** comunes. **Úsala siempre**: te avisa de errores probables. |
| `-Wextra` | Advertencias adicionales, aún más estrictas. |
| `-o nombre` | Nombre del ejecutable de salida (si lo omites, se llama `a.out`). |
| `-g` | Incluye información para el **depurador** (ver abajo). |
| `-O2` | Optimiza el código (para versiones "de producción"). |
| `-lm` | Enlaza la **librería matemática** en C (necesaria para `sqrt`, `pow`… ; va al final). |

> **Consejo:** compila **siempre** con `-Wall -Wextra`. Las advertencias son tu primer detector
> de errores. Un programa que compila "limpio" tiene muchos menos problemas.

## 4. Dar entrada al programa sin teclear (útil para probar)

Si un programa pide datos por teclado, puedes "alimentárselos" con `printf ... | ./programa`:

```bash
printf "5\n3\n" | ./suma     # le pasa 5 y luego 3 como si los teclearas
```

## 5. Depurar (cuando algo falla)

Un **depurador** te deja ejecutar el programa paso a paso y ver el valor de las variables. El
más común con GCC es **GDB**:

```bash
gcc -std=c11 -g programa.c -o programa   # -g incluye simbolos de depuracion
gdb ./programa
# dentro de gdb: break main (pone un punto de parada), run, next, print variable, continue, quit
```

En VS Code puedes depurar con botones (F5) tras configurar la extensión C/C++; es más cómodo al
principio.

Para detectar **errores de memoria** (fugas, accesos inválidos) en C/C++, la herramienta clásica
es **Valgrind** (Linux):

```bash
valgrind ./programa
```

## 6. Cómo trabajar con este curso

1. Crea una carpeta de trabajo tuya (aparte del repo) para experimentar.
2. Copia o reescribe los ejemplos, compílalos y ejecútalos. **Cambia cosas** y observa qué pasa:
   así se aprende.
3. Compila con `-Wall -Wextra` y lee las advertencias.
4. Resuelve los ejercicios tú antes de ver la solución.

Ya con esto listo, ve a [`c/`](c/) y empieza por la lección 01.
