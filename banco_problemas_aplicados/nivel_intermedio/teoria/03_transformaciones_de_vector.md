# 03 · Transformaciones de vector (producir un vector a partir de otro)

Varios problemas de este bloque **producen un vector nuevo** (o modifican el de entrada) en vez
de calcular un solo número. Conviene distinguir tres subtipos según el **tamaño** del resultado.

## 1. Resultado del MISMO tamaño

El vector de salida tiene tantas casillas como el de entrada.

- **P28 Normalización:** `Arr[i] = Arr[i] / maxVal` (se modifica en el sitio).
- **P38 Rectificación:** `if (Arr[i] < 0) Arr[i] = -Arr[i]` (se modifica en el sitio).
- **P25 Partición:** se reordena a otro vector auxiliar, misma cantidad de elementos.

### Normalización (P28) — dividir entre el máximo absoluto

Primero se busca el **máximo valor absoluto** (`|x|`), luego se divide todo entre él:

```c
double maxVal = fabs(arr[0]);
for (int i = 1; i < n; i++)
    if (fabs(arr[i]) > maxVal) maxVal = fabs(arr[i]);
if (maxVal == 0.0) return;              // proteccion: no dividir por cero
for (int i = 0; i < n; i++)
    arr[i] = arr[i] / maxVal;
```
- `fabs` (C/C++, de `<math.h>`/`<cmath>`) y `Math.abs` (Java) dan el valor absoluto.
- Si los datos son ≥ 0, el resultado cae en `[0, 1]`; si hay negativos, en `[-1, 1]`.
- La protección `if (maxVal == 0)` evita la **división por cero** (todos ceros).

### Partición pares/impares (P25) — reordenar a un auxiliar

Se copia a un vector `res` primero lo de índices pares y luego lo de índices impares, con un
único contador `k` que avanza en el destino:

```c
int k = 0;
for (int i = 0; i < tam; i++) if (i % 2 == 0) res[k++] = arr[i];
for (int i = 0; i < tam; i++) if (i % 2 != 0) res[k++] = arr[i];
```
(Condición sobre el **índice** `i`, como en el nivel básico.)

## 2. Resultado MÁS PEQUEÑO

El vector de salida tiene **menos** casillas; hay que llevar un contador y/o devolver el nuevo
tamaño.

- **P27 Derivada discreta:** `dv[i] = v[i+1] - v[i]` → tamaño **n-1** (una diferencia menos que
  elementos). El bucle llega a `n-2` porque usa `v[i+1]`.
- **P33 Submuestreo:** se toman los índices `0, K, 2K, …` → tamaño ≈ `n/K`. Se devuelve cuántos
  quedaron.

```c
// Derivada (P27): salida de tamano n-1
for (int i = 0; i < n - 1; i++) dv[i] = v[i + 1] - v[i];

// Submuestreo (P33): salta de K en K y devuelve el nuevo tamano
int j = 0;
for (int i = 0; i < n; i += k) res[j++] = arr[i];
return j;
```

## 3. Resultado MÁS GRANDE o REORDENADO

- **P36 Concatenación:** el resultado mide `nA + nB`; se copian A y luego B con un contador `k`
  que avanza en C.
- **P26 Rotación circular:** mismo tamaño, pero cada elemento va a una posición desplazada de
  forma **cíclica**.

### Rotación circular a la derecha (P26) — el módulo da "la vuelta"

El elemento de la posición `i` va a la `(i + k) % tam`. El `% tam` hace que, al pasarse del
final, el índice reaparezca por el principio:

```c
k = k % tam;                 // si k >= tam, la rotacion equivale a k modulo tam
double aux[tam];
for (int i = 0; i < tam; i++) aux[(i + k) % tam] = arr[i];
for (int i = 0; i < tam; i++) arr[i] = aux[i];   // copiar de vuelta
```

Ejemplo con `[1 2 3 4 5]` y `k = 1`: cada uno se corre una posición a la derecha y el último da
la vuelta → `[5 1 2 3 4]`.

> **Con vector auxiliar** (como aquí) es lo más claro. Existe un método **in-place** con tres
> inversiones (invertir todo, invertir los primeros k, invertir el resto), que ahorra memoria
> pero es menos intuitivo; para aprender, el auxiliar es preferible.

## 4. El producto punto (P37): de dos vectores a UN número

Aunque su entrada son dos vectores, su salida es un **escalar** (no un vector): acumula
`A[i]*B[i]`. Es el mismo patrón "multiplicar y acumular" del nivel básico (potencia), pero sin
promediar:

```c
double suma = 0.0;
for (int i = 0; i < n; i++) suma += A[i] * B[i];
return suma;
```

## 5. Regla mental

Antes de escribir el bucle, decide **cuánto mide la salida**:

- ¿Igual que la entrada? → recorres `0..n-1` y escribes en la misma posición (o en otra igual).
- ¿Más pequeña? → contador aparte y, a menudo, devolver el nuevo tamaño; cuidado con `n-1` si
  usas `arr[i+1]`.
- ¿Más grande / reordenada? → contador que avanza en el destino, o índice cíclico con `%`.
