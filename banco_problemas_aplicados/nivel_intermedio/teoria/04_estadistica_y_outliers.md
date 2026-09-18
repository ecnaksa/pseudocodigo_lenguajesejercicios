# 04 · Estadística: media, desviación estándar y outliers

El Problema 35 es el más "matemático" del bloque: para decidir qué lecturas son anómalas hay
que calcular la **media** y la **desviación estándar**, y usar la raíz cuadrada.

## 1. La media (promedio)

Ya la conoces: sumar todo y dividir entre la cantidad.

```c
double suma = 0.0;
for (int i = 0; i < n; i++) suma += arr[i];
double media = suma / n;
```

## 2. La varianza y la desviación estándar

La **desviación estándar** (σ) mide cuánto se "dispersan" los datos alrededor de la media. Se
calcula en dos pasos:

1. **Varianza** = promedio de las diferencias al cuadrado respecto a la media:

   σ² = ( Σ (xᵢ − media)² ) / n

2. **Desviación estándar** = raíz cuadrada de la varianza: σ = √(σ²)

```c
double sumaCuad = 0.0;
for (int i = 0; i < n; i++)
    sumaCuad += (arr[i] - media) * (arr[i] - media);   // diferencia al cuadrado
double desv = sqrt(sumaCuad / n);                      // raiz cuadrada
```

- Se eleva al cuadrado para que las diferencias negativas y positivas **no se cancelen** (y para
  penalizar más las lejanas).
- La **raíz cuadrada** deja σ en las mismas unidades que los datos.
- `sqrt` está en `<math.h>` (C) / `<cmath>` (C++) / `Math.sqrt` (Java). En C hay que **enlazar
  la librería matemática**: `gcc archivo.c -o prog -lm` (la `-lm` va al final).

> Nota: aquí se usa la varianza **poblacional** (dividir entre `n`). En estadística inferencial
> a veces se divide entre `n-1` (varianza muestral); para este ejercicio, `n` es suficiente.

## 3. ¿Qué es un outlier y cómo se detecta?

Un **outlier** (valor atípico) es una lectura que se aleja "demasiado" de lo normal. Un criterio
muy común es: **más de 2 desviaciones estándar** de distancia respecto a la media.

```c
if (fabs(arr[i] - media) > 2.0 * desv) {
    // arr[i] es un outlier
}
```
`fabs(arr[i] - media)` es la distancia (siempre positiva) del valor a la media. Si supera `2σ`,
se considera anómalo. (Con datos normales, cerca del 95 % cae dentro de ±2σ, así que salirse es
"raro".)

## 4. Reemplazar por la "media local"

En vez de borrar el outlier (lo que cambiaría el tamaño), se **sustituye** por el promedio de
sus vecinos inmediatos, suavizando la señal:

```c
if (i == 0)          res[i] = arr[i + 1];              // extremo izquierdo: unico vecino
else if (i == n - 1) res[i] = arr[i - 1];              // extremo derecho: unico vecino
else                 res[i] = (arr[i - 1] + arr[i + 1]) / 2.0;   // promedio de ambos vecinos
```
Los valores **no** anómalos se copian tal cual (`res[i] = arr[i]`).

> **Detalle de implementación:** los reemplazos se calculan usando los valores **originales**
> (`arr`) y se escriben en un vector **de salida** (`res`). Si se modificara el mismo arreglo
> mientras se recorre, un vecino ya "arreglado" contaminaría el cálculo del siguiente. Trabajar
> sobre `arr` (lectura) → `res` (escritura) evita ese efecto en cadena.

## 5. Un matiz importante del criterio 2σ

Con **pocos** datos y **un** pico muy grande, ese pico **infla** la propia desviación estándar,
y puede que ni siquiera supere su propio umbral de 2σ. Por ejemplo, `[0 0 0 100 0]`: la media es
20 y σ = 40, así que 2σ = 80; y `|100 − 20| = 80`, que **no** es *mayor* que 80. Resultado: el
100 queda justo en el borde y no se marca. No es un error del programa: es cómo se comporta la
estadística con muestras chicas. Con más datos "normales" alrededor, el pico sí sobresale y se
corrige (por eso `[5 5 5 … 5 50]` sí detecta y reemplaza el 50).

## 6. Resumen de funciones matemáticas

| Necesito | C (`<math.h>`) | C++ (`<cmath>`) | Java |
|---|---|---|---|
| Valor absoluto (double) | `fabs(x)` | `fabs(x)` / `abs(x)` | `Math.abs(x)` |
| Raíz cuadrada | `sqrt(x)` | `sqrt(x)` | `Math.sqrt(x)` |
| Potencia | `pow(x, y)` | `pow(x, y)` | `Math.pow(x, y)` |

> En C, recuerda enlazar con `-lm` (al final del comando) cuando uses `sqrt`, `pow`, etc.
