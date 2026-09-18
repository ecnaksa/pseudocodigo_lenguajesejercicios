# 04 · Recorrer pares adyacentes y detección de flanco

El Problema 16 (primer flanco de subida) introduce un patrón nuevo: mirar **dos elementos
vecinos a la vez**, `Arr[i]` y `Arr[i+1]`. Aparece también, de otra forma, en la burbuja (P14).

## 1. Comparar cada elemento con el siguiente

A veces la información no está en un solo elemento, sino en **la relación entre dos vecinos**:
si sube, si baja, si cambia de signo. Para eso se usa la pareja `Arr[i]` y `Arr[i+1]`.

**Flanco de subida (P16):** el punto donde la señal cruza de negativo a positivo.

```
Arr:   -3   -1    2    5   (cruza el cero entre i=1 y i=2)
i:      0    1    2    3
                ^
        Arr[1] = -1 < 0  Y  Arr[2] = 2 >= 0   -> flanco en i = 1
```

```c
int buscaFlanco(double arr[], int tam) {
    for (int i = 0; i < tam - 1; i++) {        // ojo: hasta tam-2
        if (arr[i] < 0 && arr[i + 1] >= 0) {
            return i;                           // primer flanco encontrado
        }
    }
    return -1;                                  // no hubo cruce ascendente
}
```

## 2. El límite del bucle: `i < tam - 1`

Como dentro se usa `Arr[i+1]`, en la última vuelta válida `i` vale `tam-2`, de modo que
`i+1` llegue justo a `tam-1` (el último elemento) y **no se pase**.

- Si el bucle fuera `i < tam`, en la última vuelta `i = tam-1` y `Arr[i+1] = Arr[tam]` **se
  sale del arreglo**: en C/C++ es comportamiento indefinido (basura o caída); en Java lanza
  `ArrayIndexOutOfBoundsException`.

**Regla general:** cuando en el cuerpo del bucle uses `Arr[i+1]`, el bucle debe llegar solo
hasta `tam-2`, es decir `for (i = 0; i < tam - 1; i++)`.

## 3. "Primer" flanco = salida temprana

El enunciado pide el **primer** flanco, así que se hace `return i` en cuanto se encuentra
(no se sigue buscando). Si no hay ninguno, se devuelve `-1`, la misma convención de "no
encontrado" del Problema 4.

## 4. El mismo patrón en la burbuja (P14)

El ordenamiento por intercambio también compara vecinos `Arr[f]` y `Arr[f+1]`, pero en lugar de
solo detectar, los **intercambia** si están en el orden equivocado:

```c
if (arr[f] > arr[f + 1]) {     // el de la izquierda es mayor: desordenado
    double aux = arr[f];
    arr[f] = arr[f + 1];
    arr[f + 1] = aux;          // intercambio con variable auxiliar
}
```
Por eso su bucle interno también respeta el límite `f < tam - 1 - i`: usa `Arr[f+1]` y además
evita re-comparar la parte ya ordenada al final.

## 5. Idea general: "ventana de tamaño 2"

Mirar `Arr[i]` y `Arr[i+1]` es una **ventana deslizante** de dos elementos que recorre el
arreglo. Sirve para detectar cambios: flancos (subida/bajada), diferencias, tendencias. Si un
día necesitas mirar tres vecinos (`Arr[i-1]`, `Arr[i]`, `Arr[i+1]`), el bucle iría de `1` a
`tam-2` para no salirte por ninguno de los dos lados.
