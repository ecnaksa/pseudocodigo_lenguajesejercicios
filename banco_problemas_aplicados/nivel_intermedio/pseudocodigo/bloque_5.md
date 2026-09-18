# Bloque 5/5 — Cierre de Bloque Intermedio (Problemas 37 a 39)

---

## Problema 37 — Cálculo del Producto Punto de Vectores

**Contexto:** operación fundamental para filtros FIR y cálculo vectorial en campos
electromagnéticos discretos. `double productoPunto(double A[], double B[], int n)` acumula
`A[i] * B[i]` y devuelve un **escalar** (un solo número).
**E/P/S:** vectores A y B → acumulador de productos `A[i]*B[i]` → escalar resultante.

```
Algoritmo ProductoPunto

int main(){
    Definir A[], B[] como reales
    Definir n, i como enteros
    Escribir "Ingrese el tamano de los vectores"
    Leer n
    Dimension A[n], B[n]
    for (i = 0; i < n; i++){
        Escribir "A[", i, "]"
        Leer A[i]
        Escribir "B[", i, "]"
        Leer B[i]
    }
    Escribir "Producto punto A . B = ", productoPunto(A, B, n)
    return 0
}

funcion double productoPunto(double A[], double B[], int n){
    Definir i como entero
    Definir suma como real
    suma = 0
    for (i = 0; i < n; i++){
        suma = suma + A[i] * B[i]
    }
    return suma
}
```

---

## Problema 38 — Inversión Condicional de Negativos

**Contexto:** rectificación digital por software de una señal bipolar. Aplicar valor absoluto
solo donde `Arr[i] < 0` (los positivos quedan igual).
**E/P/S:** vector bipolar → aplicar valor absoluto si `Arr[i] < 0` → vector rectificado.

```
Algoritmo Rectificacion

int main(){
    Definir Arr[] como real
    Definir n, i como enteros
    Escribir "Ingrese el numero de mediciones"
    Leer n
    Dimension Arr[n]
    for (i = 0; i < n; i++){
        Escribir "Medicion ", i
        Leer Arr[i]
    }
    rectifica(Arr, n)
    Escribir "Senal rectificada:"
    for (i = 0; i < n; i++){
        Escribir sin saltar Arr[i], " "
    }
    return 0
}

funcion void rectifica(double Arr[], int n){
    Definir i como entero
    for (i = 0; i < n; i++){
        if (Arr[i] < 0){
            Arr[i] = -Arr[i]              // convertir el negativo en positivo
        }
    }
}
```

---

## Problema 39 — Análisis de Simetría Espectral Básica

**Contexto:** comprobar si los primeros `N/2` elementos coinciden de forma inversa con los
últimos `N/2`, es decir, si el vector es simétrico (palíndromo): `Arr[i] == Arr[N-1-i]`.
**E/P/S:** vector de tamaño N → comparar mitades opuestas → booleano de simetría.

```
Algoritmo SimetriaEspectral

int main(){
    Definir Arr[] como real
    Definir n, i como enteros
    Escribir "Ingrese el tamano del vector"
    Leer n
    Dimension Arr[n]
    for (i = 0; i < n; i++){
        Escribir "Elemento ", i
        Leer Arr[i]
    }
    if (esSimetrico(Arr, n) == true){
        Escribir "El vector es simetrico (mitades opuestas coinciden)"
    } else {
        Escribir "El vector NO es simetrico"
    }
    return 0
}

funcion bool esSimetrico(double Arr[], int n){
    Definir i como entero
    for (i = 0; i < int(n / 2); i++){
        if (Arr[i] != Arr[n - 1 - i]){
            return false
        }
    }
    return true
}
```

> Código real en [`../soluciones`](../soluciones).
