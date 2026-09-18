# Nivel Intermedio Aplicado (señales, buffers y matrices) — 19 problemas

Segundo set del banco: problemas 21–39 ("Nivel Intermedio" en 5 bloques). Sube el nivel con
**matrices 2D**, **paso por referencia**, **estadística** (desviación estándar) y varias
**transformaciones de vector**. Cada problema trae **pseudocódigo híbrido**, **teoría** y
**solución en C, C++ y Java**.

## Contenido

```
nivel_intermedio/
├── pseudocodigo/     bloque_1.md … bloque_5.md   (problemas 21–39)
├── teoria/           devolver varios valores, matrices 2D, transformaciones de vector,
│                     estadistica/outliers, verificaciones (estricto vs inclusivo)
└── soluciones/
    ├── c/     problema21.c … problema39.c
    ├── cpp/   problema21.cpp … problema39.cpp
    └── java/  Problema21.java … Problema39.java
```

## Los 19 problemas

| # | Bloque | Problema | Firma / tarea |
|---|--------|----------|---------------|
| 21 | 1 Señales y buffers | Pico Máximo y Su Índice | `double picoMaximo(double[], int, &pos)` — valor + índice |
| 22 | 1 | Conteo de Códigos de Falla | `int contarFalla(int[], int, int codigo)` |
| 23 | 1 | Inversión In-Place | `void invertirBuffer(int[], int)` |
| 24 | 1 | Rango de Histéresis | `bool enHisteresis(double[], int, vmin, vmax)` — estricto |
| 25 | 2 Estructuras | Partición Pares/Impares | reordenar por índice a auxiliar |
| 26 | 2 | Desplazamiento Circular | rotar a la derecha K (módulo) |
| 27 | 2 | Derivada Discreta | `dv[i] = v[i+1] - v[i]` (salida n-1) |
| 28 | 2 | Normalización [0,1] | dividir entre el máximo absoluto |
| 29 | 3 Matrices | Suma por Filas | matriz N×M → vector de sumas |
| 30 | 3 | Transposición | `Trans[j][i] = Mat[i][j]` (M×N) |
| 31 | 3 | Fila de Mayor Consumo | índice de la fila con mayor suma |
| 32 | 3 | Nodos con Voltaje Crítico | contar celdas sobre un umbral |
| 33 | 4 Buffers | Submuestreo | tomar índices `i*K` |
| 34 | 4 | Orden Estricto Creciente | `bool` `Arr[i] < Arr[i+1]` |
| 35 | 4 | Remoción de Outliers | media ± 2σ → media local |
| 36 | 4 | Concatenación de Buffers | unir A y B en C |
| 37 | 5 Cierre | Producto Punto | escalar = Σ `A[i]*B[i]` |
| 38 | 5 | Inversión de Negativos | rectificar (valor absoluto si <0) |
| 39 | 5 | Simetría Espectral | `bool` palíndromo `Arr[i]==Arr[n-1-i]` |

## Compilar y ejecutar

```bash
# C  (para P35 y P28, que usan math, la -lm va AL FINAL)
gcc -std=c11 -Wall soluciones/c/problema29.c -o p29 && ./p29
gcc -std=c11 -Wall soluciones/c/problema35.c -o p35 -lm && ./p35
# C++
g++ -std=c++17 -Wall soluciones/cpp/problema29.cpp -o p29 && ./p29
# Java
javac soluciones/java/Problema29.java -d . && java Problema29
```

### Probar sin teclear

```bash
# P29 suma por filas (matriz 2x3: [1 2 3][4 5 6])
printf "2\n3\n1\n2\n3\n4\n5\n6\n" | ./p29        # -> fila 0 = 6.00 ; fila 1 = 15.00

# P26 rotación circular derecha K=1 sobre [1 2 3 4 5]
printf "5\n1\n2\n3\n4\n5\n1\n" | ./p26           # -> 5.00 1.00 2.00 3.00 4.00

# P37 producto punto A=[1 2 3] B=[4 5 6]
printf "3\n1\n4\n2\n5\n3\n6\n" | ./p37           # -> 32.00
```

> Tamaño fijo: solo P21 (20 muestras). Las matrices (P29–32) piden N y M; el resto pide el tamaño.

## Notas por lenguaje (lo nuevo de este nivel)

- **Devolver 2 valores (P21):** C usa puntero `int *pos`; C++ referencia `int &pos`; Java un
  arreglo `int[] pos` de un elemento. Ver [`teoria/01_devolver_varios_valores.md`](teoria/01_devolver_varios_valores.md).
- **Matrices (P29–32):** C usa `double mat[n][m]` (hay que pasar M); C++ `vector<vector<double>>`;
  Java `double[][]`. Ver [`teoria/02_matrices_2d.md`](teoria/02_matrices_2d.md).
- **Estadística (P35):** `sqrt`/`fabs`; en C enlazar con `-lm`. Ver [`teoria/04_estadistica_y_outliers.md`](teoria/04_estadistica_y_outliers.md).
