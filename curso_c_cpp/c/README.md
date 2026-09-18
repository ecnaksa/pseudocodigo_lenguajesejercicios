# Pista 1 — Lenguaje C

Bienvenido a la pista de **C**, el lenguaje que está en la base de casi todo: sistemas
operativos, drivers, microcontroladores, y de otros lenguajes (incluido C++). Aprender C te
enseña **cómo funciona la máquina por dentro**: memoria, direcciones, tipos, bytes.

Sigue las lecciones **en orden**; cada una asume la anterior.

| # | Lección | Contenido |
|---|---------|-----------|
| 01 | [Introducción y primer programa](01_introduccion) | Qué es C, el compilador, `hola mundo`, anatomía de un programa |
| 02 | [Variables, tipos y constantes](02_variables_y_tipos) | `int`, `double`, `char`, tamaños y rangos, `const` |
| 03 | [Entrada y salida](03_entrada_salida) | `printf`, `scanf`, especificadores de formato |
| 04 | [Operadores](04_operadores) | Aritméticos, relacionales, lógicos, bit a bit, precedencia |
| 05 | [Condicionales](05_condicionales) | `if`, `else if`, `else`, `switch`, ternario |
| 06 | [Bucles](06_bucles) | `while`, `do-while`, `for`, `break`, `continue` |
| 07 | [Funciones](07_funciones) | Parámetros, retorno, ámbito, recursión, prototipos |
| 08 | [Arreglos y cadenas](08_arreglos_y_cadenas) | Vectores, matrices, cadenas y `<string.h>` |
| 09 | [Punteros](09_punteros) | Direcciones, `*` y `&`, punteros y arreglos |
| 10 | [Memoria dinámica](10_memoria_dinamica) | `malloc`, `free`, arreglos dinámicos, fugas |
| 11 | [Estructuras y tipos compuestos](11_estructuras) | `struct`, `enum`, `union`, `typedef` |
| 12 | [Archivos](12_archivos) | `fopen`, leer/escribir texto y binario |
| 13 | [Preprocesador y varios archivos](13_preprocesador_y_multiarchivo) | Macros, `.h`, compilación separada, `make` |
| 14 | [Proyecto final](14_proyecto_final) | Agenda de contactos por consola |

## Cómo trabajar cada lección

1. Lee el `README.md` de la lección.
2. Compila y ejecuta los programas de `ejemplos/` **tú mismo**:
   ```bash
   gcc -std=c11 -Wall -Wextra ejemplos/nombre.c -o prog && ./prog
   ```
3. Haz los `ejercicios/` **antes** de mirar `ejercicios/soluciones/`.

Cuando termines, continúa con la [pista de C++](../cpp).
