# Nivel Avanzado — Ejercicios 12 a 15 (corregidos)

> Recuerda las **correcciones globales** (for con `;`, `==`/`!=` en comparaciones y
> quitar los tipos de las llamadas) del [README](README.md).

---

## Ejercicio 12 — `void invierteArreglo(int Arr[], int tam)`

**Enunciado:** modifica el orden de los elementos de manera que queden invertidos.

**Sobre el "no tiene `int main`":** tu observación es correcta y es un buen ejemplo para
mostrar la equivalencia. En **PSeInt puro** un programa **no tiene `main`**: el bloque
`Algoritmo … FinAlgoritmo` **es** el programa principal. El original abría `Algoritmo Invertir`
pero luego cerraba con una `}` (como si hubiera un `main`), dejando una **llave
desbalanceada**. Aquí se deja en estilo PSeInt puro para ilustrarlo: el bloque `Algoritmo`
hace el papel de `main`. En C/C++/Java ese **mismo** bloque se escribe como
`int main(){ … return 0; }` (ver [`../soluciones/c/ejercicio12.c`](../soluciones/c/ejercicio12.c)).

**Correcciones aplicadas**
- Llave `}` desbalanceada (bloque `Algoritmo` sin `int main` de apertura): resuelto con
  `Algoritmo … FinAlgoritmo`.
- `Dimension Arr[tam]` estaba **antes** de `Leer tam`; se movió después.
- La firma era `invertir(int tam, int arr[])` pero la llamada pasaba `(arr, tam)`: **orden
  invertido**. Se unificó a `invierteArreglo(int Arr[], int tam)` / `invierteArreglo(Arr, tam)`.
- Se renombró el temporal `a` a `aux` por claridad. `int(tam/2)` = división entera (la mitad).

```
Algoritmo Invertir
    Definir Arr[], i, tam como enteros
    Escribir "Ingrese el tamaño del arreglo:"
    Leer tam
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Ingrese el elemento ", i
        Leer Arr[i]
    }
    invierteArreglo(Arr, tam)
    Escribir "El nuevo arreglo es:"
    for (i = 0; i < tam; i++){
        Escribir Arr[i]
    }
FinAlgoritmo

funcion void invierteArreglo(int Arr[], int tam){
    Definir i, aux como enteros
    for (i = 0; i < int(tam / 2); i++){
        aux = Arr[i]
        Arr[i] = Arr[tam - 1 - i]
        Arr[tam - 1 - i] = aux
    }
}
```

---

## Ejercicio 13 — `bool esPalindromo(int Arr[], int tam)`

**Enunciado:** determina si un arreglo es **simétrico** (se lee igual de izquierda a derecha
que de derecha a izquierda).

**Correcciones aplicadas — la más importante de todo el conjunto**
- **La función no hacía lo que pide el enunciado.** El original **copió el código del
  Ejercicio 12** (invertía el arreglo) y **no devolvía nada**, a pesar de que la firma es
  `bool`. Se reescribió por completo para **COMPARAR** los extremos hacia el centro: si algún
  par `Arr[i]` y `Arr[tam-1-i]` **difiere**, devuelve `false`; si el recorrido termina sin
  diferencias, devuelve `true`. (Palíndromo = comparar, **no** modificar.)
- Usaba la variable `a` **sin declarar**.
- Faltaban `Leer tam` y el `return 0` del `main`.
- `if else` → `else`; `= true` → `== true` (o directamente `if (esPalindromo(Arr, tam))`).

```
Algoritmo Palindromo

int main(){
    Definir Arr[], tam, i como enteros
    Escribir "Ingrese el tamaño del arreglo:"
    Leer tam
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Ingrese el elemento ", i
        Leer Arr[i]
    }
    if (esPalindromo(Arr, tam) == true){
        Escribir "El arreglo es simétrico"
    } else {
        Escribir "El arreglo no es simétrico"
    }
    return 0
}

funcion bool esPalindromo(int Arr[], int tam){
    Definir i como entero
    for (i = 0; i < int(tam / 2); i++){
        if (Arr[i] != Arr[tam - 1 - i]){
            return false
        }
    }
    return true
}
```

---

## Ejercicio 14 — `void ordenaBurbuja(int Arr[], int tam)`

**Enunciado:** implementa el método de la burbuja para ordenar el arreglo de forma ascendente.

**Correcciones aplicadas**
- **Bug del intercambio.** El original hacía `Arr[i] = Arr[f+1]` usando `i` en vez de `f`.
  Como el intercambio trabaja sobre las posiciones adyacentes `f` y `f+1`, lo correcto es
  `Arr[f] = Arr[f+1]`. Con el error el arreglo **no quedaba ordenado** y se corrompían valores.
- **`Escribir sin saltar` se conserva a propósito:** significa imprimir **sin salto de línea**.
  (En C: `printf("%d ", Arr[i])`; en C++: `cout << Arr[i] << " "`; en Java: `System.out.print(Arr[i] + " ")`.)

```
Algoritmo Burbuja

int main(){
    Definir Arr[], tam, i como enteros
    tam = 5
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Ingrese el elemento ", i
        Leer Arr[i]
    }
    ordenaBurbuja(Arr, tam)
    Escribir "El arreglo ordenado:"
    for (i = 0; i < tam; i++){
        Escribir sin saltar Arr[i], " "
    }
    return 0
}

funcion void ordenaBurbuja(int Arr[], int tam){
    Definir i, f, aux como enteros
    for (i = 0; i < tam; i++){
        for (f = 0; f < tam - 1 - i; f++){
            if (Arr[f] > Arr[f + 1]){
                aux = Arr[f]
                Arr[f] = Arr[f + 1]
                Arr[f + 1] = aux
            }
        }
    }
}
```

---

## Ejercicio 15 — `int eliminaDuplicados(int Arr[], int tam)`

**Enunciado:** remueve todos los elementos duplicados y devuelve el **nuevo tamaño lógico**.

**Correcciones aplicadas**
- **Bug grave del bucle interno.** El original escribía `for (j = i+1, i<tam, i++)`: usaba
  **`i`** en la condición y en el incremento en lugar de **`j`**. Lo correcto es
  `for (j = i+1; j < tam; j++)`. Con el error, el bucle interno modificaba `i` y no recorría `j`.
- `Definir … f …` declaraba `f`, pero el código usaba `i` (**no declarada**). Se declaran `i, j, k`.
- Nombre `elimina duplicado` **con espacio** → `eliminaDuplicados`.
- `Returnar tam` → `return tam`; y sobraba una `}` al final.
- El original reajustaba con `i = i-1`; equivalente, pero aquí se usa `j = j-1` para volver a
  revisar la posición que acaba de ocupar el valor desplazado.

**Cómo funciona:** para cada `Arr[i]` se busca hacia adelante (`j = i+1 …`) alguna copia;
cuando aparece, se **desplazan a la izquierda** los elementos posteriores para "tapar el
hueco", se reduce el tamaño lógico (`tam = tam - 1`) y se retrocede `j`. Al final, `tam` es
la cantidad de posiciones válidas.

```
Algoritmo EliminarDuplicados

int main(){
    Definir Arr[], tam, ntam, i como enteros
    tam = 8
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Ingrese el elemento ", i
        Leer Arr[i]
    }
    ntam = eliminaDuplicados(Arr, tam)
    Escribir "Arreglo sin duplicados:"
    for (i = 0; i < ntam; i++){
        Escribir sin saltar Arr[i], " "
    }
    return 0
}

funcion int eliminaDuplicados(int Arr[], int tam){
    Definir i, j, k como enteros
    for (i = 0; i < tam; i++){
        for (j = i + 1; j < tam; j++){
            if (Arr[i] == Arr[j]){
                for (k = j; k < tam - 1; k++){
                    Arr[k] = Arr[k + 1]
                }
                tam = tam - 1
                j = j - 1
            }
        }
    }
    return tam
}
```

> Traducciones reales en [`../soluciones`](../soluciones). Nota: en Java el arreglo conserva
> su longitud física (`arr.length`); lo que cambia es el **tamaño lógico** devuelto.
