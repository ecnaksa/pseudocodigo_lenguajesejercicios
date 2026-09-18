# 02 · Condición sobre el ÍNDICE vs. sobre el VALOR

Este es el concepto que más se presta a confusión en este bloque, porque los problemas 3 y 5
se **parecen** a los del primer set pero preguntan algo distinto.

## 1. Las dos cosas que se pueden mirar en un `for`

Dentro de `for (i = 0; i < tam; i++)` conviven **dos** números en cada vuelta:

- **`i`** → la **posición** (el índice): 0, 1, 2, 3, …
- **`Arr[i]`** → el **valor** guardado en esa posición.

Una condición puede mirar **cualquiera de los dos**, y el resultado es completamente diferente.

```
Arr:     [ 50 ][ 51 ][ 52 ][ 53 ][ 54 ]
i:          0     1     2     3     4
```

- `if (i % 2 != 0)`  → mira el **índice**: se cumple en i = 1, 3  → posiciones impares.
- `if (Arr[i] % 2 != 0)` → mira el **valor**: se cumple en 51, 53 → valores impares.

En este ejemplo coinciden por casualidad, pero con `Arr = [50, 80, 52, 90, 54]` cambian:
por índice sigue siendo i = 1, 3; por valor **ninguno** es impar.

## 2. Lo que piden los problemas de este bloque

| Problema | Enunciado (Identifica) | Condición | Mira… |
|---|---|---|---|
| **3** cuentaImpares | "muestras ubicadas en índices impares" — `i % 2 != 0` | `i % 2 != 0` | el **índice** |
| **5** sumaPares | "valores situados en índices pares" — `i % 2 == 0` | `i % 2 == 0` | el **índice** |
| 6 cuentaRepeticiones | "incrementar si `Arr[i] == x`" | `Arr[i] == x` | el **valor** |
| 15 cuentaSaturadas | "contar si `Arr[i] == 1023`" | `Arr[i] == 1023` | el **valor** |

> **Comparación con el primer set:** allí `cuentaImpares` y `sumaPares` miraban el **valor**
> (`Arr[i] % 2`). Aquí, por el contexto (posiciones/fases pares e impares del multiplexor,
> índices de muestreo), miran el **índice** (`i % 2`). Mismo nombre, condición distinta: hay
> que leer siempre la especificación.

## 3. Consecuencia curiosa del P3 y P5

Como la condición del P3 depende **solo del índice**, el resultado **no depende de los valores**
del arreglo: para `tam` elementos siempre hay `tam/2` (división entera) índices impares. Por eso
en el código la función recibe el arreglo (porque la firma lo pide) pero **no lee su contenido**:

```c
int cuentaImpares(int arr[], int tam) {
    (void) arr;                 // se recibe por la firma, pero no se usa su contenido
    int contador = 0;
    for (int i = 0; i < tam; i++) {
        if (i % 2 != 0) contador++;   // solo importa la posicion
    }
    return contador;
}
```
El P5 sí usa el valor (`suma += arr[i]`), pero **elige cuáles** sumar según el índice.

## 4. Cómo no equivocarse

Pregúntate siempre: **"¿la condición habla de dónde está (posición) o de qué es (valor)?"**

- "en índices pares/impares", "en posiciones…", "cada dos elementos" → **índice** (`i`).
- "los números pares", "los negativos", "los que valen 1023", "iguales a x" → **valor** (`Arr[i]`).
