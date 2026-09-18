# Bloque 3/5 — Operaciones Matriciales (Problemas 29 a 32)

> **Novedad: matrices (arreglos 2D).** Una matriz se declara con dos dimensiones
> `Dimension Mat[n][m]` y se recorre con **dos** bucles anidados (`i` filas, `j` columnas):
> el elemento es `Mat[i][j]`. La traducción a C/C++/Java tiene diferencias importantes;
> se explican en [`../teoria/02_matrices_2d.md`](../teoria/02_matrices_2d.md).

---

## Problema 29 — Suma de Matriz de Nodos por Filas

**Contexto:** red de distribución mallada. Recibe una matriz N x M y devuelve un arreglo
unidimensional con la suma de cada fila.
**E/P/S:** matriz N x M → acumular por filas en bucle anidado → vector suma.

```
Algoritmo SumaFilas

int main(){
    Definir Mat[][] como real
    Definir Res[] como real
    Definir n, m, i, j como enteros
    Escribir "Numero de filas (N)"
    Leer n
    Escribir "Numero de columnas (M)"
    Leer m
    Dimension Mat[n][m], Res[n]
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            Escribir "Mat[", i, "][", j, "]"
            Leer Mat[i][j]
        }
    }
    sumaFilas(n, m, Mat, Res)
    Escribir "Suma por filas:"
    for (i = 0; i < n; i++){
        Escribir "  fila ", i, " = ", Res[i]
    }
    return 0
}

funcion void sumaFilas(int n, int m, double Mat[][], double Res[]){
    Definir i, j como enteros
    Definir suma como real
    for (i = 0; i < n; i++){
        suma = 0
        for (j = 0; j < m; j++){
            suma = suma + Mat[i][j]
        }
        Res[i] = suma
    }
}
```

---

## Problema 30 — Transposición de Matriz de Admitancias

**Contexto:** análisis matricial de circuitos. Recibe una matriz N x M y devuelve su
transpuesta M x N: `Trans[j][i] = Mat[i][j]`.

```
Algoritmo Transposicion

int main(){
    Definir Mat[][], Trans[][] como reales
    Definir n, m, i, j como enteros
    Escribir "Numero de filas (N)"
    Leer n
    Escribir "Numero de columnas (M)"
    Leer m
    Dimension Mat[n][m], Trans[m][n]
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            Escribir "Mat[", i, "][", j, "]"
            Leer Mat[i][j]
        }
    }
    transpone(n, m, Mat, Trans)
    Escribir "Matriz transpuesta (", m, " x ", n, "):"
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            Escribir sin saltar Trans[i][j], " "
        }
        Escribir ""                       // salto de linea al final de cada fila
    }
    return 0
}

funcion void transpone(int n, int m, double Mat[][], double Trans[][]){
    Definir i, j como enteros
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            Trans[j][i] = Mat[i][j]       // se intercambian los indices
        }
    }
}
```

---

## Problema 31 — Búsqueda de Fila con Mayor Consumo

**Contexto:** subestación representada por una matriz de consumos. Devuelve el índice de la
fila con mayor consumo acumulado (la de mayor suma).
**E/P/S:** matriz de consumos → comparar sumas de filas → índice de la fila máxima.

```
Algoritmo FilaMayorConsumo

int main(){
    Definir Mat[][] como real
    Definir n, m, i, j como enteros
    Escribir "Numero de buses/filas (N)"
    Leer n
    Escribir "Numero de columnas (M)"
    Leer m
    Dimension Mat[n][m]
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            Escribir "Mat[", i, "][", j, "]"
            Leer Mat[i][j]
        }
    }
    Escribir "La fila con mayor consumo es la ", filaMayorConsumo(n, m, Mat)
    return 0
}

funcion int filaMayorConsumo(int n, int m, double Mat[][]){
    Definir i, j, filaMax como enteros
    Definir suma, mayorSuma como reales
    mayorSuma = 0
    for (j = 0; j < m; j++){              // suma de la fila 0 como referencia
        mayorSuma = mayorSuma + Mat[0][j]
    }
    filaMax = 0
    for (i = 1; i < n; i++){
        suma = 0
        for (j = 0; j < m; j++){
            suma = suma + Mat[i][j]
        }
        if (suma > mayorSuma){
            mayorSuma = suma
            filaMax = i
        }
    }
    return filaMax
}
```

---

## Problema 32 — Conteo de Nodos con Voltaje Crítico

**Contexto:** matriz de tensiones. Contar cuántas celdas superan un umbral de sobretensión.
**E/P/S:** matriz y umbral crítico → contar celdas que superen el límite → cantidad entera.

```
Algoritmo NodosCriticos

int main(){
    Definir Mat[][] como real
    Definir n, m, i, j como enteros
    Definir umbral como real
    Escribir "Numero de filas (N)"
    Leer n
    Escribir "Numero de columnas (M)"
    Leer m
    Dimension Mat[n][m]
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            Escribir "Mat[", i, "][", j, "]"
            Leer Mat[i][j]
        }
    }
    Escribir "Umbral critico de sobretension:"
    Leer umbral
    Escribir "Nodos que superan el umbral: ", cuentaCriticos(n, m, Mat, umbral)
    return 0
}

funcion int cuentaCriticos(int n, int m, double Mat[][], double umbral){
    Definir i, j, contador como enteros
    contador = 0
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            if (Mat[i][j] > umbral){
                contador = contador + 1
            }
        }
    }
    return contador
}
```

> Código real en [`../soluciones`](../soluciones). Nota: en C la matriz se pasa como
> `Mat[n][m]` (indicando M); en C++ se usa `vector<vector<double>>`; en Java `double[][]`.
