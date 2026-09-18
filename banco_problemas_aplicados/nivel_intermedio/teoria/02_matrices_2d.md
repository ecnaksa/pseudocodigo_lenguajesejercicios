# 02 · Matrices (arreglos bidimensionales)

Los Problemas 29–32 introducen las **matrices**: arreglos de **dos dimensiones**, con filas y
columnas. Es el salto conceptual más grande de este bloque. Un arreglo 1D es una fila de
casillas; una matriz 2D es una **tabla** (rejilla) de casillas.

## 1. La idea

```
Mat (3 filas x 4 columnas):
            col0  col1  col2  col3
   fila0 [   5     2     8     1  ]
   fila1 [   3     9     0     7  ]
   fila2 [   4     4     6     2  ]
```

Cada celda se identifica con **dos** índices: `Mat[i][j]` = fila `i`, columna `j`. Por ejemplo
`Mat[1][2] = 0`. Se recorre con **dos bucles anidados**: el externo para las filas, el interno
para las columnas.

```
for (i = 0; i < n; i++){        // n filas
    for (j = 0; j < m; j++){    // m columnas
        ... Mat[i][j] ...
    }
}
```

## 2. Declaración en cada lenguaje

### C — arreglo 2D de longitud variable (VLA)

```c
int n = 3, m = 4;
double mat[n][m];               // n filas, m columnas
```
En memoria, C guarda la matriz **por filas** (row-major): primero toda la fila 0, luego la 1…
Por eso, para pasar una matriz a una función, C **necesita saber el número de columnas** (M);
si no, no sabría dónde empieza cada fila.

### C++ — `vector<vector<double>>` (lo idiomático)

```cpp
#include <vector>
int n = 3, m = 4;
vector<vector<double>> mat(n, vector<double>(m));   // n filas, cada una un vector de m
```
Es un "vector de vectores". Cada fila conoce su tamaño (`mat.size()` filas, `mat[i].size()`
columnas), así que las funciones no necesitan que le pasen N y M por separado.

### Java — arreglo de arreglos (`double[][]`)

```java
int n = 3, m = 4;
double[][] mat = new double[n][m];   // conoce mat.length (filas) y mat[i].length (columnas)
```
Igual que en Java 1D, la matriz es un objeto que **guarda sus dimensiones**.

## 3. El punto más delicado: pasar una matriz a una función

Aquí es donde más difieren los tres lenguajes.

**C** — hay que llevar las dimensiones y declarar la columna en el parámetro:

```c
void sumaFilas(int n, int m, double mat[n][m], double res[]) { ... }
//              ^^^^^^^^^^^^  se pasan N y M; el [m] es OBLIGATORIO
```
Sin el `[m]` (o `[][m]`), el compilador no puede calcular la dirección de `mat[i][j]`.
La fórmula que usa por dentro es: `mat[i][j]` está en `base + (i*m + j)` posiciones.

**C++** — se pasa el `vector<vector<double>>` (por referencia constante para no copiarlo):

```cpp
vector<double> sumaFilas(const vector<vector<double>>& mat) {
    // mat.size() = filas, mat[i].size() = columnas
}
```

**Java** — se pasa el `double[][]`, que ya trae sus dimensiones:

```java
static double[] sumaFilas(double[][] mat) {
    // mat.length = filas, mat[i].length = columnas
}
```

## 4. Los cuatro problemas, en una idea cada uno

| P | Qué hace | Núcleo |
|---|---|---|
| **29** Suma por filas | por cada fila, sumar sus columnas | `res[i] += mat[i][j]` (interno sobre j) |
| **30** Transponer | reflejar filas↔columnas | `trans[j][i] = mat[i][j]` |
| **31** Fila de mayor consumo | comparar la suma de cada fila | acumular por fila, guardar el índice de la mayor |
| **32** Nodos críticos | contar celdas sobre un umbral | `if (mat[i][j] > umbral) cont++` |

La **transposición** (P30) es la que mejor muestra el manejo de índices: la celda `(i, j)` del
original va a la `(j, i)` de la transpuesta, y la matriz cambia de forma **N×M → M×N**:

```
Mat (2x3)        Trans (3x2)
[1 2 3]           [1 4]
[4 5 6]    -->    [2 5]
                  [3 6]
```

## 5. Errores típicos con matrices

- **Confundir filas y columnas.** `Mat[i][j]`: el **primer** índice es la fila, el **segundo**
  la columna. En la transpuesta hay que crear la matriz destino con las dimensiones invertidas
  (`Trans[m][n]`).
- **Olvidar M al pasar la matriz en C.** `void f(int mat[][])` no compila; debe ser
  `void f(int n, int m, double mat[n][m])`.
- **Salirse de rango.** Los índices válidos son fila `0..n-1` y columna `0..m-1`.
- **Recorrer en el orden equivocado.** Para eficiencia en C conviene recorrer fila por fila
  (índice de columna en el bucle interno), porque así se accede a memoria consecutiva.

## 6. Resumen

| | Declarar N×M | Filas | Columnas | Pasar a función |
|---|---|---|---|---|
| **C** | `double mat[n][m];` | `n` (aparte) | `m` (aparte) | `f(int n, int m, double mat[n][m], ...)` |
| **C++** | `vector<vector<double>> mat(n, vector<double>(m));` | `mat.size()` | `mat[i].size()` | `f(const vector<vector<double>>& mat)` |
| **Java** | `double[][] mat = new double[n][m];` | `mat.length` | `mat[i].length` | `f(double[][] mat)` |

Todo lo demás (recorridos, condiciones, acumuladores) es **lo mismo** que con arreglos 1D, solo
que con **un bucle más** y **dos índices**.
