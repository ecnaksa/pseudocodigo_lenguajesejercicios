# Nivel Básico — Ejercicios 01 a 04 (corregidos)

> Recuerda las **correcciones globales** (for con `;`, `==`/`!=` en comparaciones y
> quitar los tipos de las llamadas) descritas en el [README](README.md); aquí solo se
> detallan los errores propios de cada ejercicio.

---

## Ejercicio 01 — `int sumaElementos(int Arr[], int tam)`

**Enunciado:** recibe un arreglo de enteros y regresa el resultado de sumar todos sus elementos.

**Correcciones aplicadas**
- `Dimension Arr[tam]` estaba **antes** de `Leer tam`; se movió **después** (no se puede
  dimensionar con un tamaño que todavía no se conoce).
- El cuerpo tenía `suma = suma + arr[]` **sin índice** → debe ser `Arr[i]`.
- La función se llamaba `suma`, chocando con su variable local `suma`; se renombró a
  `sumaElementos` (además coincide con el enunciado).

```
Algoritmo SumarElementos

int main(){
    Definir Arr[], tam, i como enteros
    Escribir "Ingrese el tamaño del arreglo"
    Leer tam
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Ingrese el elemento ", i
        Leer Arr[i]
    }
    Escribir "La suma de los elementos del arreglo es: ", sumaElementos(Arr, tam)
    return 0
}

funcion int sumaElementos(int Arr[], int tam){
    Definir suma, i como enteros
    suma = 0
    for (i = 0; i < tam; i++){
        suma = suma + Arr[i]
    }
    return suma
}
```

---

## Ejercicio 02 — `int buscaMinimo(int Arr[], int tam)`

**Enunciado:** recibe un arreglo de enteros y regresa el valor mínimo almacenado.

**Correcciones aplicadas**
- **Lógica incorrecta.** El original hacía `min = 0` y comparaba `Arr[i] < Arr[i+1]`
  (accediendo a `Arr[i+1]`, que se **sale del arreglo** en la última vuelta). Con `min = 0`
  un arreglo de puros positivos daría mínimo `0`, que ni siquiera está en el arreglo.
  Lo correcto es tomar `min = Arr[0]` y comparar **cada elemento contra el mínimo provisional**.
- Nombre con acento inconsistente (`mínimo` vs `minimo`) y llamada `minimo(int Arr[i], int tam)`
  con índice y tipos; se unificó a `buscaMinimo(Arr, tam)`.

```
Algoritmo BuscarMinimo

int main(){
    Definir Arr[], tam, i como enteros
    Escribir "Ingrese el tamaño del arreglo"
    Leer tam
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Ingrese el elemento ", i
        Leer Arr[i]
    }
    Escribir "El valor mínimo es: ", buscaMinimo(Arr, tam)
    return 0
}

funcion int buscaMinimo(int Arr[], int tam){
    Definir i, min como enteros
    min = Arr[0]
    for (i = 1; i < tam; i++){
        if (Arr[i] < min){
            min = Arr[i]
        }
    }
    return min
}
```

---

## Ejercicio 03 — `int cuentaImpares(int Arr[], int tam)`

**Enunciado:** regresa la cantidad total de números impares que contiene el arreglo.

**Correcciones aplicadas**
- **Contaba lo contrario.** La condición era `Arr[i] % 2 = 0`, que detecta **pares**,
  pero la variable se llama `nimpar`. Un número es **impar** cuando `Arr[i] % 2 != 0`.
- `return impar` usaba una variable **inexistente**; debe ser `return nimpar`.

```
Algoritmo CuentaImpares

int main(){
    Definir Arr[], tam, i como enteros
    Escribir "Ingrese el tamaño del arreglo"
    Leer tam
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Ingrese el elemento ", i
        Leer Arr[i]
    }
    Escribir "La cantidad de números impares es: ", cuentaImpares(Arr, tam)
    return 0
}

funcion int cuentaImpares(int Arr[], int tam){
    Definir i, nimpar como enteros
    nimpar = 0
    for (i = 0; i < tam; i++){
        if (Arr[i] % 2 != 0){
            nimpar = nimpar + 1
        }
    }
    return nimpar
}
```

---

## Ejercicio 04 — `int buscaElemento(int Arr[], int x, int tam)`

**Enunciado:** busca el valor `x` y regresa su posición, o un valor indicativo (`-1`) si no se encuentra.

**Correcciones aplicadas**
- **Nunca se leía `tam`.** Se agregó `Leer tam` (y `Dimension` después).
- **Lógica rota.** El original ponía `posición = -1` en el `else` en **cada** iteración
  que no coincidía, borrando un resultado ya encontrado, y dependía del orden del arreglo.
  Se reescribe para **devolver `i` en cuanto se encuentra** `x` y `-1` si el recorrido
  termina sin hallarlo.
- Se llamaba a la función **dos veces** y con los parámetros en **distinto orden**
  (`posición(Arr, tam, x)`); ahora se llama **una sola vez**, se guarda en `pos` y se
  respeta el orden `(Arr, x, tam)` de la firma.

```
Algoritmo BuscarElemento

int main(){
    Definir Arr[], tam, i, x, pos como enteros
    Escribir "Ingrese el tamaño del arreglo"
    Leer tam
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Ingrese el elemento ", i
        Leer Arr[i]
    }
    Escribir "Ingrese el elemento a buscar:"
    Leer x
    pos = buscaElemento(Arr, x, tam)
    if (pos < 0){
        Escribir "No existe elemento coincidente"
    } else {
        Escribir "La posición del elemento es: ", pos
    }
    return 0
}

funcion int buscaElemento(int Arr[], int x, int tam){
    Definir i como entero
    for (i = 0; i < tam; i++){
        if (Arr[i] == x){
            return i
        }
    }
    return -1
}
```

> Traducciones reales: [`../soluciones/c/ejercicio0X.c`](../soluciones/c),
> [`../soluciones/cpp/ejercicio0X.cpp`](../soluciones/cpp),
> [`../soluciones/java/Ejercicio0X.java`](../soluciones/java).
