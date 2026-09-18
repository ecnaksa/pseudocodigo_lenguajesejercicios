# 05 · Verificaciones booleanas: orden, simetría e histéresis (estricto vs. inclusivo)

Tres problemas devuelven `bool` recorriendo el vector y saliendo en cuanto algo falla: orden
estricto (P34), simetría (P39) e histéresis estricta (P24). Comparten el patrón de "salida
temprana" y, sobre todo, obligan a distinguir **estricto** (`<`, `>`) de **inclusivo**
(`<=`, `>=`).

## 1. El patrón "¿todos cumplen?" (repaso)

```
funcion bool propiedad(...){
    for (recorrido){
        if ( ! (se cumple aqui) ){
            return false      // un contraejemplo basta
        }
    }
    return true               // nadie fallo
}
```
El `return true` va **fuera** del bucle. Lo vimos en el nivel básico (rango seguro, comparar
canales); aquí se repite en tres variantes.

## 2. Orden estricto creciente (P34)

"Estrictamente creciente" significa que **cada** elemento es **menor** que el siguiente:
`Arr[i] < Arr[i+1]`. Si dos son **iguales**, ya **no** es estrictamente creciente.

```c
for (int i = 0; i < tam - 1; i++) {   // hasta tam-2, porque se usa Arr[i+1]
    if (!(arr[i] < arr[i + 1])) {      // estricto: <
        return false;
    }
}
return true;
```

- Con `<` (estricto): `[1, 2, 2, 4]` → **falla** (el 2 repetido).
- Con `<=` (no decreciente): `[1, 2, 2, 4]` → pasaría.

El enunciado pide "sin saltos anómalos" / estrictamente ascendente, así que es `<`.

## 3. Simetría / palíndromo espectral (P39)

Comprobar que la primera mitad coincide "de forma inversa" con la segunda es exactamente
comprobar `Arr[i] == Arr[n-1-i]` recorriendo solo hasta la mitad (`i < n/2`):

```c
for (int i = 0; i < n / 2; i++) {
    if (arr[i] != arr[n - 1 - i]) {
        return false;
    }
}
return true;
```
- Con `n` par, se comparan todas las parejas espejo.
- Con `n` impar, el elemento central no necesita compararse consigo mismo (`n/2` lo deja fuera),
  que es lo correcto.

Es el mismo "palíndromo" del primer set, aquí en clave de simetría espectral.

## 4. Histéresis estricta (P24): `<` vs `<=`

"Dentro de manera **estricta**" del intervalo `(vmin, vmax)` significa que los **extremos NO se
permiten**: hay que usar `>` y `<` (no `>=` ni `<=`).

```c
if (!(arr[i] > vmin && arr[i] < vmax)) {   // estricto: extremos excluidos
    return false;
}
```

Compáralo con el "rango seguro" del nivel básico (P12), que era **inclusivo** (`>= 3.3 && <= 5.0`,
los extremos sí valían). La diferencia entre ambos:

| Lectura | Rango **inclusivo** `[vmin, vmax]` | Rango **estricto** `(vmin, vmax)` |
|---|---|---|
| `val == vmin` | dentro ✓ | **fuera** ✗ |
| `vmin < val < vmax` | dentro ✓ | dentro ✓ |
| `val == vmax` | dentro ✓ | **fuera** ✗ |

Por ejemplo, con `vmin = 5`, `vmax = 8` y una lectura `= 5`: el rango **inclusivo** la acepta,
pero el **estricto** la rechaza (toca el límite).

> **Recuerda además** (del nivel básico): un rango **nunca** se escribe `vmin < val < vmax` en
> C/C++/Java; siempre son **dos** comparaciones unidas con `&&`.

## 5. ¿Por qué `!(condición)` en lugar de la condición negada "a mano"?

Escribir `if (!(arr[i] > vmin && arr[i] < vmax))` es equivalente, por las **leyes de De Morgan**,
a `if (arr[i] <= vmin || arr[i] >= vmax)`. Las dos formas detectan "está fuera". Usar `!(dentro)`
tiene la ventaja de que defines **una sola vez** qué es "estar dentro" y lo niegas, evitando
equivocarte al invertir cada comparación por separado.

## 6. Resumen

| Problema | Propiedad | Comparación clave | Estricto/Inclusivo |
|---|---|---|---|
| P34 orden | `Arr[i] < Arr[i+1]` | `<` | estricto (iguales fallan) |
| P39 simetría | `Arr[i] == Arr[n-1-i]` | `==` / `!=` | — |
| P24 histéresis | `Arr[i] > vmin && Arr[i] < vmax` | `>` y `<` | estricto (extremos fuera) |
| P12 (básico) rango seguro | `Arr[i] >= 3.3 && Arr[i] <= 5.0` | `>=` y `<=` | inclusivo (extremos dentro) |
