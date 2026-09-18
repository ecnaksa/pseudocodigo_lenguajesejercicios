# 00 · Introducción: el "pseudocódigo híbrido"

## ¿Qué es?

El pseudocódigo de estos ejercicios es **híbrido**: mezcla dos mundos.

- **Del pseudocódigo / PSeInt** toma el **vocabulario en español** y la forma de *pensar*
  el algoritmo:
  - `Algoritmo Nombre` para dar nombre al programa.
  - `Definir x como entero` para declarar variables.
  - `Dimension Arr[tam]` para reservar un arreglo.
  - `Escribir …` para mostrar y `Leer …` para pedir datos.
  - `Escribir sin saltar …` para imprimir sin bajar de renglón.
- **De C / C++ / Java** toma la **estructura y la sintaxis**:
  - `int main(){ … return 0 }` como punto de entrada.
  - Funciones con **tipo de retorno**: `funcion int suma(int Arr[], int tam){ … }`.
  - `for (i = 0; i < tam; i++){ … }`, `if (…){ … } else { … }`.
  - Llaves `{ }` para delimitar bloques.

Este estilo es muy útil como **puente**: el mismo texto se puede traducir casi línea por
línea a C, a C++ o a Java. Esa es exactamente la meta de este repositorio.

> **PSeInt puro vs. híbrido.** En PSeInt "de verdad" un programa se escribe
> `Algoritmo … FinAlgoritmo`, los bucles son `Para i <- 0 Hasta n-1 Hacer … FinPara` y
> **no existe `main`**. El estilo híbrido de estos ejercicios ya adopta la forma de C
> (`main`, `for`, `{ }`), así que está a medio camino. El **Ejercicio 12** es el único que
> se dejó en estilo PSeInt puro (el bloque `Algoritmo` hace de `main`) justamente para que
> se vea la equivalencia.

## Los tres lenguajes de destino, en una frase cada uno

- **C** — lenguaje de bajo nivel, compilado. Los arreglos son bloques de memoria y las
  funciones reciben punteros. Entrada/salida con `printf`/`scanf`.
- **C++** — superconjunto de C orientado a objetos. Puede usar todo lo de C, pero además
  tiene `cin`/`cout`, `bool` nativo, `new`/`delete` y la biblioteca estándar (`vector`, etc.).
- **Java** — compilado a *bytecode* que corre sobre la JVM. Todo vive dentro de **clases**;
  los arreglos son **objetos** que conocen su propia longitud (`arr.length`). Entrada con
  `Scanner`, salida con `System.out`.

## Cómo compilar y ejecutar

Desde la raíz del repositorio:

```bash
# C  (gcc). El estándar c11 habilita los arreglos de tamaño variable "int arr[tam];".
gcc -std=c11 -Wall soluciones/c/ejercicio01.c -o ej01
./ej01

# C++ (g++)
g++ -std=c++17 -Wall soluciones/cpp/ejercicio01.cpp -o ej01
./ej01

# Java (javac + java). El archivo y la clase deben llamarse igual (Ejercicio01).
javac soluciones/java/Ejercicio01.java
java -cp soluciones/java Ejercicio01
```

Todos los programas piden los datos por teclado. Para probarlos sin escribir a mano se les
puede "alimentar" la entrada:

```bash
# Ejemplo: arreglo de 5 elementos [4 -2 9 -7 3] al programa del mínimo (Ejercicio 02)
printf "5\n4\n-2\n9\n-7\n3\n" | ./ej02
```

## Cómo está organizado el repositorio

```
pseudocodigo_lenguajesejercicios/
├── pseudocodigo_corregido/   ← el pseudocódigo híbrido corregido (por nivel)
├── soluciones/
│   ├── c/                    ← 15 programas en C   (ejercicio01.c … ejercicio15.c)
│   ├── cpp/                  ← 15 programas en C++  (ejercicio01.cpp … )
│   └── java/                 ← 15 programas en Java (Ejercicio01.java … )
└── teoria/                   ← esta carpeta: la explicación de cada componente
```
