# 06 · Multiplicar-y-acumular: producto punto y potencia promedio

El Problema 13 (potencia aparente promedio) combina tres patrones que ya conoces —multiplicar,
acumular y promediar— en uno solo, muy común en procesamiento de señales.

## 1. El patrón "multiplicar y acumular" (MAC)

En vez de sumar `Arr[i]` (como en P1), aquí se suma el **producto** de dos arreglos en la misma
posición: `V[i] * I[i]`. Eso es el **producto punto** de dos vectores:

```
V:  [ v0 ][ v1 ][ v2 ] ...
I:  [ i0 ][ i1 ][ i2 ] ...
suma = v0*i0 + v1*i1 + v2*i2 + ...
```

```c
double suma = 0.0;
for (int k = 0; k < n; k++) {
    suma = suma + V[k] * I[k];    // multiplicar y acumular en cada vuelta
}
```

Físicamente: potencia instantánea = voltaje × corriente. Sumar `V[i]*I[i]` acumula la potencia
de cada instante.

> "Multiplicar y acumular" (MAC) es una operación tan frecuente que los procesadores de señales
> (DSP) tienen instrucciones dedicadas para hacerla en un solo paso.

## 2. Del total al promedio

El enunciado pide el **promedio**, así que al final se divide la suma entre `n`:

```c
double potenciaPromedio(double V[], double I[], int n) {
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        suma = suma + V[i] * I[i];
    }
    return suma / n;              // promedio de las potencias instantaneas
}
```

Como `suma` es `double`, `suma / n` es **división real** (con decimales) aunque `n` sea `int`
—no hace falta castear, a diferencia del promedio con enteros del primer set.

## 3. Relación con la multiplicación cruzada (P10)

Compara las dos operaciones entre dos arreglos:

| | Fórmula | Qué produce |
|---|---|---|
| **P10 cruzada** | `C[i] = A[i] * B[tam-1-i]` | un **vector** C (guarda cada producto) |
| **P13 producto punto** | `suma += V[i] * I[i]` | un **escalar** (un solo número) |

- En P10, cada producto se **guarda** en su casilla → el resultado es otro arreglo.
- En P13, cada producto se **acumula** en una sola variable → el resultado es un número.
- Además P10 cruza los índices (`i` con `tam-1-i`, el espejo), mientras que P13 usa el **mismo**
  índice en ambos (`i` con `i`).

Reconocer si el resultado es "un arreglo nuevo" o "un solo número" te dice de inmediato si
necesitas un vector `C[]` o una variable `suma`.

## 4. Cuidado con el desbordamiento (nota)

Si multiplicas y acumulas **muchísimos** valores grandes, la suma puede crecer mucho. Con
`double` el rango es enorme (no suele haber problema), pero si algún día haces esto con `int`,
`V[i]*I[i]` podría desbordar el rango del entero. En ese caso se usa un tipo más ancho
(`long`/`long long`) para la acumulación.
