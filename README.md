# Ejercicios de Arreglos — Pseudocódigo → C, C++ y Java

Este repositorio parte de un conjunto de **15 ejercicios de arreglos** (niveles básico,
intermedio y avanzado) resueltos en un **"pseudocódigo híbrido"** (mezcla el vocabulario de
PSeInt con la estructura de C/C++/Java). Aquí se hacen tres cosas:

1. **Se corrigen** los errores del pseudocódigo original, **conservando su esencia**.
2. **Se explica la teoría** en detalle: cómo funciona cada componente en C, C++ y Java.
3. **Se dan las soluciones correctas y compilables** en **C, C++ y Java**.

## Estructura

```
pseudocodigo_lenguajesejercicios/
├── README.md                    ← este archivo
├── pseudocodigo_corregido/      ← 1) pseudocódigo híbrido corregido, con notas de qué se arregló
│   ├── nivel_1_basico.md            (ejercicios 01–04)
│   ├── nivel_2_intermedio.md        (ejercicios 05–11)
│   └── nivel_3_avanzado.md          (ejercicios 12–15)
├── teoria/                      ← 2) explicación detallada, lenguaje por lenguaje
│   ├── 00_introduccion.md
│   ├── 01_estructura_de_un_programa.md
│   ├── 02_arreglos.md
│   ├── 03_paso_de_arreglos_a_funciones.md
│   ├── 04_entrada_y_salida.md
│   ├── 05_control_de_flujo.md
│   └── 06_tipos_y_division.md
├── soluciones/                  ← 3) código correcto y probado
│   ├── c/     ejercicio01.c   … ejercicio15.c
│   ├── cpp/   ejercicio01.cpp … ejercicio15.cpp
│   └── java/  Ejercicio01.java … Ejercicio15.java
├── banco_problemas_aplicados/   ← 4) problemas NUEVOS aplicados a ingeniería (por sets)
│   ├── nivel_basico/                20 problemas de electrónica (pseudocódigo + teoría + C/C++/Java)
│   └── nivel_intermedio/            19 problemas: señales, buffers y MATRICES (misma estructura)
├── curso_c_cpp/                 ← 5) curso DESDE CERO de C y C++ (teoría + práctica, por temas)
│   ├── c/     14 lecciones: de "hola mundo" a punteros, structs, archivos y un proyecto final
│   └── cpp/   13 lecciones: de C a C++, POO, plantillas, STL, RAII y un proyecto final
└── curso_java/                  ← 6) curso DESDE CERO de Java (teoría + práctica, por temas)
    └── 01…17   de "hola mundo" a POO, colecciones, excepciones, streams y un proyecto final
```

> **Cuatro partes.** El repositorio tiene:
> - (a) los **15 ejercicios originales** corregidos (`pseudocodigo_corregido/`, `teoria/`,
>   `soluciones/`);
> - (b) el **[`banco_problemas_aplicados/`](banco_problemas_aplicados)**, una carpeta contenedora
>   de problemas nuevos aplicados a ingeniería, organizada por sets:
>   [`nivel_basico/`](banco_problemas_aplicados/nivel_basico) (20 problemas) y
>   [`nivel_intermedio/`](banco_problemas_aplicados/nivel_intermedio) (19 problemas, incluye
>   matrices); se agregarán más sets en subcarpetas hermanas;
> - (c) el **[`curso_c_cpp/`](curso_c_cpp)**, un curso **desde cero** de C y C++, y
> - (d) el **[`curso_java/`](curso_java)**, un curso **desde cero** de Java.
>
> Los dos cursos están organizados por **temas con progresión** (al estilo de *30-Days-Of-Python*,
> pero por temas y no por días), con **teoría y práctica** en cada lección y las **fuentes**
> (libros, páginas) citadas en su `FUENTES.md`.

## Los 15 ejercicios

| # | Nivel | Función / tarea | Idea |
|---|-------|-----------------|------|
| 01 | Básico | `int sumaElementos(int Arr[], int tam)` | Sumar todos los elementos. |
| 02 | Básico | `int buscaMinimo(int Arr[], int tam)` | Valor mínimo del arreglo. |
| 03 | Básico | `int cuentaImpares(int Arr[], int tam)` | Cuántos impares hay. |
| 04 | Básico | `int buscaElemento(int Arr[], int x, int tam)` | Posición de `x`, o `-1`. |
| 05 | Intermedio | `int sumaPares(int Arr[], int tam)` | Sumar solo los pares. |
| 06 | Intermedio | `int cuentaRepeticiones(int Arr[], int x, int tam)` | Veces que se repite `x`. |
| 07 | Intermedio | Análisis de 10 números | Ceros/positivos/negativos y sus sumas. |
| 08 | Intermedio | Promedio de 5 y mayores | Promedio y valores mayores a él. |
| 09 | Intermedio | Suma de vectores | `C[i] = A[i] + B[i]`. |
| 10 | Intermedio | Multiplicación cruzada | `C[i] = A[i] * B[tam-1-i]`. |
| 11 | Intermedio | Mayor de 20 | Valor y posición del mayor. |
| 12 | Avanzado | `void invierteArreglo(int Arr[], int tam)` | Invertir el orden. |
| 13 | Avanzado | `bool esPalindromo(int Arr[], int tam)` | ¿Es simétrico? |
| 14 | Avanzado | `void ordenaBurbuja(int Arr[], int tam)` | Ordenar ascendente (burbuja). |
| 15 | Avanzado | `int eliminaDuplicados(int Arr[], int tam)` | Quitar repetidos, devolver nuevo tamaño. |

## Resumen de los errores corregidos

Muchos ejercicios del pseudocódigo original tenían fallos que impedirían ejecutarlos. Los más
frecuentes (detallados ejercicio por ejercicio en [`pseudocodigo_corregido/`](pseudocodigo_corregido)):

- **Sintaxis general:** `for` con comas en vez de `;`; `=` en lugar de `==` en comparaciones;
  tipos (`int`, `int[]`) dentro de las **llamadas** a funciones; `if else` en lugar de `else`.
- **Nombres que no coinciden:** la llamada usaba un nombre y la definición otro
  (`CalcularPromedio`/`Promedio`, `encontrar mayor`/`encontrar_mayor`), o con espacios
  (`sumar vectores`), o con acentos inconsistentes (`minimo`/`mínimo`).
- **Bugs de lógica** (los importantes):
  - **Ej. 02:** inicializaba `min = 0` y comparaba fuera de rango → mínimo incorrecto.
  - **Ej. 03:** contaba **pares** en vez de impares (`% 2 == 0`).
  - **Ej. 13:** la función `esPalindromo` **invertía** el arreglo en lugar de **comparar**, y
    no devolvía `bool`. (Reescrita por completo.)
  - **Ej. 14:** el intercambio de la burbuja usaba `Arr[i]` en vez de `Arr[f]` → no ordenaba.
  - **Ej. 15:** el bucle interno usaba `i` en vez de `j` en la condición/incremento.
- **Datos que no se leían:** faltaba `Leer tam` (Ej. 04, 13) o `Leer Arr[i]` (Ej. 08); `x`
  nunca se leía (Ej. 06).
- **Casos "especiales" que se conservaron a propósito** (son pseudocódigo legítimo, no
  errores):
  - **Ej. 12:** el bloque `Algoritmo` haciendo de `main` (estilo PSeInt puro).
  - **Ej. 14 y 15:** `Escribir sin saltar` = imprimir sin salto de línea.

## Cursos desde cero (C, C++ y Java)

Además de los ejercicios, el repositorio incluye **dos cursos completos** para aprender los
lenguajes **desde cero**, con teoría detallada, ejemplos ejecutables y ejercicios con solución en
cada lección. Todo el código fue **compilado y probado** (JDK 21, `gcc -std=c11`,
`g++ -std=c++17`).

- **[`curso_c_cpp/`](curso_c_cpp)** — C y C++ en dos pistas:
  - `c/`: 14 lecciones, de "hola mundo", tipos y control de flujo a **funciones, arreglos,
    cadenas, punteros, memoria dinámica, structs, archivos y compilación multiarchivo**, con un
    **proyecto final** (agenda de contactos con persistencia).
  - `cpp/`: 13 lecciones, de **C a C++**, `iostream`, referencias, **POO** (clases,
    herencia/polimorfismo), **sobrecarga de operadores**, **plantillas**, la **STL**
    (`vector`, `map`, algoritmos, lambdas), **RAII/punteros inteligentes** y **excepciones**, con
    un **proyecto final** (biblioteca).
- **[`curso_java/`](curso_java)** — Java en 17 lecciones: de la **JVM** y "hola mundo" a tipos y
  `Scanner`, control de flujo, métodos, arreglos y cadenas, **POO** (clases, herencia, interfaces,
  polimorfismo), **colecciones** (`ArrayList`, `HashMap`), **excepciones** y **lambdas/streams**,
  con un **proyecto final** (gestor de tareas). Empieza por su
  [`README.md`](curso_java/README.md) y [`CONFIGURACION.md`](curso_java/CONFIGURACION.md).

Cada curso cita sus fuentes en `FUENTES.md`
([C/C++](curso_c_cpp/FUENTES.md) · [Java](curso_java/FUENTES.md)).

## Por dónde empezar

1. Lee [`teoria/00_introduccion.md`](teoria/00_introduccion.md) para entender el estilo y cómo
   compilar.
2. Toma un ejercicio en [`pseudocodigo_corregido/`](pseudocodigo_corregido) y compáralo con su
   versión en [`soluciones/`](soluciones).
3. Cuando una parte no te cuadre (arreglos, funciones, división real…), busca el tema en
   [`teoria/`](teoria).

Todas las soluciones fueron **compiladas** (`gcc -std=c11`, `g++ -std=c++17`, `javac 21`) y
**probadas** con datos de ejemplo; los tres lenguajes producen los mismos resultados.
