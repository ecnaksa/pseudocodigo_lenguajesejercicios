# Nivel Intermedio — Ejercicios 05 a 11 (corregidos)

> Recuerda las **correcciones globales** (for con `;`, `==`/`!=` en comparaciones y
> quitar los tipos de las llamadas) del [README](README.md).

---

## Ejercicio 05 — `int sumaPares(int Arr[], int tam)`

**Enunciado:** regresa la suma de solo los números pares del arreglo.

**Correcciones aplicadas**
- Comparación `Arr[i] % 2 = 0` → `Arr[i] % 2 == 0` (un número es par si su residuo es 0).
- Nombre `spar` → `sumaPares`; tipos fuera de la llamada.

```
Algoritmo SumaPares

int main(){
    Definir Arr[], tam, i como enteros
    Escribir "Ingrese el tamaño del arreglo"
    Leer tam
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Ingrese el elemento ", i
        Leer Arr[i]
    }
    Escribir "La suma de los números pares es: ", sumaPares(Arr, tam)
    return 0
}

funcion int sumaPares(int Arr[], int tam){
    Definir i, suma como enteros
    suma = 0
    for (i = 0; i < tam; i++){
        if (Arr[i] % 2 == 0){
            suma = suma + Arr[i]
        }
    }
    return suma
}
```

---

## Ejercicio 06 — `int cuentaRepeticiones(int Arr[], int x, int tam)`

**Enunciado:** regresa el número de veces que se repite el valor `x` dentro del arreglo.

**Correcciones aplicadas**
- `Definir i, x, tam, arr[], tam …` declaraba **`tam` dos veces**; se deja una sola.
- **`x` nunca se leía**; se agregó `Leer x`.
- Había una **llamada suelta** (`Repeticiones(...)`) cuyo resultado se descartaba y luego
  otra dentro del `Escribir` con **distinto orden de parámetros** respecto a la firma
  (`(Arr, tam, x)` vs `(Arr, x, tam)`). Se deja **una sola** llamada, con el orden
  `(Arr, x, tam)` coherente con la firma, y faltaba la coma antes de ella.

```
Algoritmo ContarRepeticiones

int main(){
    Definir Arr[], tam, i, x como enteros
    Escribir "Ingrese el tamaño del arreglo"
    Leer tam
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Ingrese el elemento ", i
        Leer Arr[i]
    }
    Escribir "Ingrese el valor a contar (x):"
    Leer x
    Escribir "El valor ", x, " se repite: ", cuentaRepeticiones(Arr, x, tam)
    return 0
}

funcion int cuentaRepeticiones(int Arr[], int x, int tam){
    Definir i, contador como enteros
    contador = 0
    for (i = 0; i < tam; i++){
        if (Arr[i] == x){
            contador = contador + 1
        }
    }
    return contador
}
```

---

## Ejercicio 07 — Análisis de 10 números (ceros, positivos, negativos y sus sumas)

**Enunciado:** almacenar 10 enteros; imprimir cuántos son ceros, negativos y positivos,
y además la suma de los negativos y la suma de los positivos.

**Correcciones aplicadas**
- `Escribir suma negativos", sneg` tenía la **comilla de apertura faltante** → `Escribir "Suma de negativos: ", sneg`.
- `if else` → `else` (se usa `if / else` anidado para las tres categorías).
- La función no llevaba la palabra `funcion` ni tipo; como **no devuelve valor**, se marca `void`.

```
Algoritmo AnalisisNumeros

int main(){
    Definir Arr[], tam, i como enteros
    tam = 10
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Ingrese el elemento ", i
        Leer Arr[i]
    }
    analizarArreglo(Arr, tam)
    return 0
}

funcion void analizarArreglo(int Arr[], int tam){
    Definir i, ceros, pos, neg, spos, sneg como enteros
    ceros = 0
    pos = 0
    neg = 0
    spos = 0
    sneg = 0
    for (i = 0; i < tam; i++){
        if (Arr[i] == 0){
            ceros = ceros + 1
        } else {
            if (Arr[i] < 0){
                neg = neg + 1
                sneg = sneg + Arr[i]
            } else {
                pos = pos + 1
                spos = spos + Arr[i]
            }
        }
    }
    Escribir "Cantidad de ceros: ", ceros
    Escribir "Cantidad de positivos: ", pos
    Escribir "Cantidad de negativos: ", neg
    Escribir "Suma de positivos: ", spos
    Escribir "Suma de negativos: ", sneg
}
```

---

## Ejercicio 08 — Promedio de 5 números y valores mayores al promedio

**Enunciado:** almacenar 5 enteros, calcular y desplegar su promedio, y determinar/desplegar
cuántos y cuáles son mayores que el promedio.

**Correcciones aplicadas**
- **Faltaba `Leer Arr[i]`** en el bucle de lectura (el original solo escribía el mensaje,
  nunca guardaba el dato).
- La llamada era `CalcularPromedio(...)` pero la función se llamaba `Promedio`; se unificó
  a `promedioMayores`.
- `promedio` es **real**: en pseudocódigo `Definir promedio como real`. (En C/C++/Java hay
  que **forzar la división real**; ver [`../teoria/06_tipos_y_division.md`](../teoria/06_tipos_y_division.md).)

```
Algoritmo PromedioMayores

int main(){
    Definir Arr[], tam, i como enteros
    tam = 5
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Ingrese el elemento ", i
        Leer Arr[i]
    }
    promedioMayores(Arr, tam)
    return 0
}

funcion void promedioMayores(int Arr[], int tam){
    Definir i, mayores, suma como enteros
    Definir promedio como real
    suma = 0
    for (i = 0; i < tam; i++){
        suma = suma + Arr[i]
    }
    promedio = suma / tam
    Escribir "Promedio: ", promedio
    mayores = 0
    Escribir "Valores mayores al promedio:"
    for (i = 0; i < tam; i++){
        if (Arr[i] > promedio){
            mayores = mayores + 1
            Escribir Arr[i]
        }
    }
    Escribir "Cantidad de elementos mayores: ", mayores
}
```

---

## Ejercicio 09 — Suma de dos vectores A + B → C

**Enunciado:** llenar dos vectores A y B de 5 elementos, sumar elemento a elemento
(`C[i] = A[i] + B[i]`) e imprimir el vector C.

**Correcciones aplicadas**
- `Escribe` → `Escribir`.
- Nombre `sumar vectores` **con espacio** (identificador inválido) y llamada `sumarvectores`;
  se unificó a `sumarVectores`.
- `intC[]` (sin espacio) y tipos en la llamada; `;` final sobrante.

```
Algoritmo SumaVectores

int main(){
    Definir tam, i como enteros
    tam = 5
    Definir A[], B[], C[] como enteros
    Dimension A[tam], B[tam], C[tam]
    for (i = 0; i < tam; i++){
        Escribir "Ingrese el elemento ", i, " de A:"
        Leer A[i]
        Escribir "Ingrese el elemento ", i, " de B:"
        Leer B[i]
    }
    sumarVectores(A, B, C, tam)
    return 0
}

funcion void sumarVectores(int A[], int B[], int C[], int tam){
    Definir i como entero
    for (i = 0; i < tam; i++){
        C[i] = A[i] + B[i]
    }
    Escribir "Vector C:"
    for (i = 0; i < tam; i++){
        Escribir "C[", i, "] = ", C[i]
    }
}
```

---

## Ejercicio 10 — Multiplicación "cruzada" de A y B → C

**Enunciado:** dos vectores de 10 elementos. Multiplicar el 1.º de A por el último de B,
el 2.º de A por el penúltimo de B, …, y guardar en C **de izquierda a derecha**:
`C[i] = A[i] * B[tam-1-i]`.

**Correcciones aplicadas**
- Coma sobrante en `Definir … C[], como entero`.
- `intC[]`, `intB[]` (sin espacio) y tipos en la llamada.
- La lógica `C[i] = A[i] * B[tam-1-i]` **ya era correcta** (primer×último, segundo×penúltimo…);
  se conservó.

```
Algoritmo OperacionVectores

int main(){
    Definir tam, i como enteros
    tam = 10
    Definir A[], B[], C[] como enteros
    Dimension A[tam], B[tam], C[tam]
    for (i = 0; i < tam; i++){
        Escribir "Ingrese el elemento ", i, " de A:"
        Leer A[i]
        Escribir "Ingrese el elemento ", i, " de B:"
        Leer B[i]
    }
    multiplicarVectores(tam, A, B, C)
    return 0
}

funcion void multiplicarVectores(int tam, int A[], int B[], int C[]){
    Definir i como entero
    for (i = 0; i < tam; i++){
        C[i] = A[i] * B[tam - 1 - i]
    }
    Escribir "Vector C:"
    for (i = 0; i < tam; i++){
        Escribir "C[", i, "] = ", C[i]
    }
}
```

---

## Ejercicio 11 — Mayor de un vector de 20 (valor y posición)

**Enunciado:** llenar un vector de 20 elementos (todos diferentes) e imprimir la posición
y el valor del mayor.

**Correcciones aplicadas**
- Nombre `encontrar mayor` / `encontrar_mayor` con **espacio** en la llamada → `encontrarMayor`.
- Acento inconsistente: `posición = i` frente a la declaración `posicion`; se unificó a `posicion`.
- El bucle puede empezar en `i = 1` porque `Arr[0]` ya se tomó como mayor provisional
  (empezar en `0` también sería correcto).

```
Algoritmo ElementoMayor

int main(){
    Definir Arr[], tam, i como enteros
    tam = 20
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Ingrese el elemento ", i
        Leer Arr[i]
    }
    encontrarMayor(Arr, tam)
    return 0
}

funcion void encontrarMayor(int Arr[], int tam){
    Definir i, mayor, posicion como enteros
    mayor = Arr[0]
    posicion = 0
    for (i = 1; i < tam; i++){
        if (Arr[i] > mayor){
            mayor = Arr[i]
            posicion = i
        }
    }
    Escribir "El elemento mayor: ", mayor
    Escribir "Posición del mayor: ", posicion
}
```

> Traducciones reales en [`../soluciones`](../soluciones).
