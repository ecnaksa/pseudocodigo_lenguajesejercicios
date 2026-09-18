# 05 · Control de flujo: `for`, `if/else` y operadores

## 1. El bucle `for`

El `for` repite un bloque un número **contado** de veces. Tiene **tres partes** separadas por
**punto y coma** (`;`):

```
for ( inicialización ; condición ; incremento ){
    ... cuerpo ...
}
```

- **Inicialización:** se ejecuta **una vez** al empezar (`i = 0`).
- **Condición:** se evalúa **antes de cada vuelta**; si es verdadera, se entra al cuerpo
  (`i < tam`).
- **Incremento:** se ejecuta **al final de cada vuelta** (`i++`, que es `i = i + 1`).

```
for (i = 0; i < tam; i++){
    ... Arr[i] ...
}
```

> **Error del JSON original:** venía `for (i=0, i<tam, i++)` con **comas**. Las tres partes
> del `for` se separan con **`;`** en C, C++ y Java. Con comas el programa ni siquiera
> compila (o hace algo distinto). Esta fue una de las correcciones globales.

En los tres lenguajes el `for` se escribe **igual**. Además es común declarar la `i` dentro:

```c
for (int i = 0; i < tam; i++) { ... }   // C, C++ y Java
```

### Bucles anidados

Un `for` dentro de otro. Se usan en la **burbuja** (Ej. 14) y en **eliminar duplicados**
(Ej. 15). El de adentro completa **todas** sus vueltas por **cada** vuelta del de afuera:

```
for (i = 0; i < tam; i++){          // externo
    for (f = 0; f < tam-1-i; f++){  // interno
        ...
    }
}
```
En la burbuja, el interno llega solo hasta `tam-1-i` porque tras cada pasada el mayor ya
quedó "hundido" al final y no hace falta volver a compararlo.

## 2. El condicional `if / else`

```
if ( condición ){
    ... se ejecuta si la condición es verdadera ...
} else {
    ... se ejecuta si es falsa ...
}
```

> **Error del JSON original:** venía `if else { }`. La palabra correcta es **`else`** (sin
> `if` delante). Para encadenar tres o más casos se usa `else { if (...) { } else { } }` o,
> más limpio, `else if`:

```c
if (arr[i] == 0) {
    ceros++;
} else if (arr[i] < 0) {   // "si no, y además es negativo"
    neg++;
} else {                   // "si no (es positivo)"
    pos++;
}
```
Este es exactamente el reparto en tres categorías del **Ejercicio 07**.

## 3. Operadores relacionales (comparación)

Devuelven verdadero/falso. **Iguales en los tres lenguajes:**

| Operador | Significado | Ejemplo |
|---|---|---|
| `==` | igual a | `Arr[i] == x` |
| `!=` | distinto de | `Arr[i] != Arr[tam-1-i]` |
| `<`  | menor que | `Arr[i] < min` |
| `>`  | mayor que | `Arr[i] > mayor` |
| `<=` | menor o igual | `i <= n` |
| `>=` | mayor o igual | `x >= 0` |

> **Error clásico y del JSON original:** usar `=` (que es **asignación**) donde se quería `==`
> (**comparación**). `if (arr[i] % 2 = 0)` está mal; lo correcto es `if (arr[i] % 2 == 0)`.

## 4. El operador `%` (residuo o módulo)

`a % b` es el **residuo** de dividir `a` entre `b`. Es la herramienta para saber si un número
es par o impar:

- **Par:** `x % 2 == 0` (residuo 0). → Ejercicio 05.
- **Impar:** `x % 2 != 0` (residuo distinto de 0). → Ejercicio 03.

```
12 % 2 = 0   → par
 7 % 2 = 1   → impar
```

> Detalle con negativos en C/C++/Java: `-7 % 2` da `-1` (no `1`). No importa para par/impar,
> porque lo que se comprueba es si es `0` o **distinto** de `0`, y `-1 != 0` sigue siendo cierto,
> así que `-7` se cuenta correctamente como impar.

## 5. Operadores lógicos (combinar condiciones)

Iguales en los tres lenguajes; útiles cuando una decisión depende de varias cosas:

| Operador | Significado | Ejemplo |
|---|---|---|
| `&&` | Y (ambas verdaderas) | `x > 0 && x < 100` |
| `\|\|` | O (al menos una) | `x == 1 \|\| x == 2` |
| `!` | NO (niega) | `!esPalindromo(arr, n)` |

## 6. `while` (mención)

Aunque los ejercicios usan `for`, conviene conocer `while`, que repite **mientras** una
condición sea verdadera (útil cuando no se sabe de antemano cuántas vueltas serán):

```c
while (condición) {
    ...
}
```
Un `for (i=0; i<n; i++){…}` equivale a `i=0; while (i<n){ … i++; }`.
