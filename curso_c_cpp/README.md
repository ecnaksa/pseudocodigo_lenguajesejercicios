# Curso de C y C++ — de cero a fundamentos sólidos

Un curso **progresivo** para aprender **C** y **C++** desde cero, con **teoría a fondo** y
**práctica** (ejemplos compilables + ejercicios con solución). Inspirado en la forma de
[30-Days-Of-Python](https://github.com/Asabeneh/30-Days-Of-Python) —una lección por tema, cada
una con explicación completa y ejercicios—, pero organizado por **temas** en dificultad
creciente, no por días.

> **Por qué esto importa.** No se puede improvisar ("vibe-code") un programa serio sin entender
> los fundamentos: cómo funciona la memoria, los tipos, los punteros, la organización del código.
> C y C++ te obligan a entender esas cosas, y por eso son una base excelente para todo lo demás.

## Cómo está organizado

```
curso_c_cpp/
├── README.md            ← este archivo (plan del curso)
├── CONFIGURACION.md     ← instalar el compilador, compilar, ejecutar, depurar
├── FUENTES.md           ← bibliografía y fuentes usadas (libros, sitios, estándares)
├── c/                   ← PISTA 1: Lenguaje C (fundamentos)
│   ├── README.md
│   └── 01_.. 14_..      ← una carpeta por lección
└── cpp/                 ← PISTA 2: Lenguaje C++ (construye sobre C)
    ├── README.md
    └── 01_.. 13_..
```

Cada lección es una carpeta con:
- **`README.md`** — la teoría del tema, explicada en detalle y con ejemplos comentados.
- **`ejemplos/`** — programas cortos y **compilables** que ilustran cada idea.
- **`ejercicios/README.md`** — enunciados de práctica.
- **`ejercicios/soluciones/`** — soluciones compilables de esos ejercicios.

## Ruta de aprendizaje

### Pista 1 — C (empieza aquí)

| # | Lección | Aprendes a… |
|---|---------|-------------|
| 01 | Introducción y primer programa | Qué es C, el compilador, `hola mundo`, compilar y ejecutar |
| 02 | Variables, tipos de datos y constantes | `int`, `double`, `char`, rangos, `const`, conversiones |
| 03 | Entrada y salida (`printf`/`scanf`) | Especificadores de formato, leer del teclado |
| 04 | Operadores | Aritméticos, relacionales, lógicos, bit a bit, precedencia |
| 05 | Condicionales | `if/else`, `else if`, `switch`, operador ternario |
| 06 | Bucles | `while`, `do-while`, `for`, `break`, `continue` |
| 07 | Funciones | Parámetros, retorno, ámbito, recursión, cabeceras |
| 08 | Arreglos y cadenas | Vectores, matrices, cadenas C y `<string.h>` |
| 09 | Punteros | Direcciones, `*` y `&`, aritmética de punteros |
| 10 | Memoria dinámica | `malloc`/`calloc`/`realloc`/`free`, fugas de memoria |
| 11 | Estructuras y tipos compuestos | `struct`, `union`, `enum`, `typedef` |
| 12 | Archivos | Leer y escribir archivos de texto y binarios |
| 13 | Preprocesador y varios archivos | `#include`, macros, compilación separada, `make` |
| 14 | Proyecto final en C | Integrar todo: agenda de contactos por consola |

### Pista 2 — C++ (después de C)

| # | Lección | Aprendes a… |
|---|---------|-------------|
| 01 | De C a C++ | `iostream`, `namespace`, qué mejora respecto a C |
| 02 | Tipos, referencias y `const` | Referencias, `auto`, `nullptr`, `string`, `bool` |
| 03 | Funciones en C++ | Sobrecarga, parámetros por defecto, paso por referencia |
| 04 | Clases y objetos | Encapsulamiento, atributos y métodos, `public`/`private` |
| 05 | Constructores y destructores | Ciclo de vida de un objeto, `this`, miembros estáticos |
| 06 | Herencia y polimorfismo | Reutilizar y extender clases, funciones `virtual` |
| 07 | Sobrecarga de operadores | Hacer que tus tipos se usen como los nativos |
| 08 | Plantillas (templates) | Código genérico: funciones y clases plantilla |
| 09 | STL: contenedores | `vector`, `string`, `map`, `set`, iteradores |
| 10 | STL: algoritmos y lambdas | `<algorithm>`, `sort`, `find`, funciones lambda |
| 11 | Punteros inteligentes y RAII | `unique_ptr`, `shared_ptr`, gestión segura de recursos |
| 12 | Manejo de excepciones | `try`/`catch`/`throw`, errores en tiempo de ejecución |
| 13 | Proyecto final en C++ | Integrar POO + STL: sistema de biblioteca |

## Cómo usar este curso

1. Lee [`CONFIGURACION.md`](CONFIGURACION.md) e instala el compilador.
2. Empieza por [`c/`](c) en orden. Lee el `README.md` de cada lección, **escribe y ejecuta** tú
   mismo los ejemplos (no solo los leas), y luego resuelve los ejercicios **antes** de mirar la
   solución.
3. Cuando termines C, pasa a [`cpp/`](cpp).
4. Consulta [`FUENTES.md`](FUENTES.md) cuando quieras profundizar en un tema con material serio.

## Requisitos previos

Ninguno de programación, pero si vienes de este mismo repositorio ya conoces la lógica básica
(variables, bucles, condicionales, arreglos) en pseudocódigo, lo que te dará ventaja. Solo
necesitas una computadora, un editor de texto y ganas de practicar.

## Convenciones del curso

- El código está comentado en español y los mensajes en pantalla, sin acentos, para evitar
  problemas de codificación entre terminales.
- Cada ejemplo indica **cómo compilarlo** y **qué salida** produce.
- Los estándares usados: **C11** (`gcc -std=c11`) y **C++17** (`g++ -std=c++17`), ambos muy
  soportados y modernos sin ser exóticos.
