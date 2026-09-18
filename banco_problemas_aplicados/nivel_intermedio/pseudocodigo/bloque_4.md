# Bloque 4/5 — Procesamiento de Buffers (Problemas 33 a 36)

---

## Problema 33 — Compresión de Datos por Submuestreo

**Contexto:** reducir la tasa de muestreo tomando únicamente las muestras en posiciones
múltiplos de un factor `K` (índices 0, K, 2K…). Devuelve el nuevo tamaño.
**E/P/S:** vector original y factor K → extraer elementos en índices `i*K` → vector comprimido.

```
Algoritmo Submuestreo

int main(){
    Definir Arr[], Res[] como reales
    Definir n, k, i, nuevo como enteros
    Escribir "Ingrese el numero de muestras"
    Leer n
    Dimension Arr[n], Res[n]
    for (i = 0; i < n; i++){
        Escribir "Muestra ", i
        Leer Arr[i]
    }
    Escribir "Ingrese el factor de compresion K:"
    Leer k
    nuevo = submuestrea(Arr, n, k, Res)
    Escribir "Vector comprimido (", nuevo, " muestras):"
    for (i = 0; i < nuevo; i++){
        Escribir sin saltar Res[i], " "
    }
    return 0
}

funcion int submuestrea(double Arr[], int n, int k, double Res[]){
    Definir i, j como enteros
    j = 0
    for (i = 0; i < n; i = i + k){        // i salta de K en K
        Res[j] = Arr[i]
        j = j + 1
    }
    return j                              // cantidad de muestras conservadas
}
```

---

## Problema 34 — Verificación de Orden Estricto Creciente

**Contexto:** validar si un vector de calibración está **estrictamente** ordenado de forma
ascendente, sin saltos anómalos.
**E/P/S:** vector de calibración → comprobar `Arr[i] < Arr[i+1]` → booleano de orden.

> "Estricto" ⇒ `<` (si dos elementos son iguales, **no** cumple). Ver
> [`../teoria/05_verificaciones_orden_y_simetria.md`](../teoria/05_verificaciones_orden_y_simetria.md).

```
Algoritmo OrdenEstricto

int main(){
    Definir Arr[] como real
    Definir tam, i como enteros
    Escribir "Ingrese el tamano del vector"
    Leer tam
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Calibracion ", i
        Leer Arr[i]
    }
    if (esCreciente(Arr, tam) == true){
        Escribir "El vector esta estrictamente ordenado de forma ascendente"
    } else {
        Escribir "El vector NO esta estrictamente ordenado"
    }
    return 0
}

funcion bool esCreciente(double Arr[], int tam){
    Definir i como entero
    for (i = 0; i < tam - 1; i++){        // hasta tam-2 porque se usa Arr[i+1]
        if (!(Arr[i] < Arr[i + 1])){
            return false
        }
    }
    return true
}
```

---

## Problema 35 — Remoción de Valores Anómalos (Outliers)

**Contexto:** identificar lecturas que excedan en más de **2 desviaciones estándar** el
promedio y reemplazarlas por el **valor medio local** (promedio de sus vecinos).
**E/P/S:** vector con ruido → filtrar y sustituir por media local → vector depurado.

> Requiere calcular media, varianza y desviación estándar (`raiz` = raíz cuadrada). Ver
> [`../teoria/04_estadistica_y_outliers.md`](../teoria/04_estadistica_y_outliers.md).

```
Algoritmo RemocionOutliers

int main(){
    Definir Arr[], Res[] como reales
    Definir n, i como enteros
    Escribir "Ingrese el numero de lecturas"
    Leer n
    Dimension Arr[n], Res[n]
    for (i = 0; i < n; i++){
        Escribir "Lectura ", i
        Leer Arr[i]
    }
    removeOutliers(Arr, n, Res)
    Escribir "Vector depurado:"
    for (i = 0; i < n; i++){
        Escribir sin saltar Res[i], " "
    }
    return 0
}

funcion void removeOutliers(double Arr[], int n, double Res[]){
    Definir i como entero
    Definir suma, media, sumaCuad, desv como reales
    suma = 0
    for (i = 0; i < n; i++){
        suma = suma + Arr[i]
    }
    media = suma / n
    sumaCuad = 0
    for (i = 0; i < n; i++){
        sumaCuad = sumaCuad + (Arr[i] - media) * (Arr[i] - media)
    }
    desv = raiz(sumaCuad / n)              // desviacion estandar
    for (i = 0; i < n; i++){
        if (abs(Arr[i] - media) > 2 * desv){
            if (i == 0){
                Res[i] = Arr[i + 1]
            } else {
                if (i == n - 1){
                    Res[i] = Arr[i - 1]
                } else {
                    Res[i] = (Arr[i - 1] + Arr[i + 1]) / 2
                }
            }
        } else {
            Res[i] = Arr[i]
        }
    }
}
```

---

## Problema 36 — Concatenación Segura de Dos Buffers

**Contexto:** unir dos vectores de tramas de comunicación digital en un tercer vector de mayor
capacidad, sin desbordar la memoria (C tiene tamaño `nA + nB`).
**E/P/S:** Vector 1 y Vector 2 → copiar secuencialmente en vector C → vector combinado.

```
Algoritmo ConcatenacionSegura

int main(){
    Definir A[], B[], C[] como enteros
    Definir nA, nB, i como enteros
    Escribir "Tamano del Vector 1"
    Leer nA
    Dimension A[nA]
    for (i = 0; i < nA; i++){
        Escribir "A[", i, "]"
        Leer A[i]
    }
    Escribir "Tamano del Vector 2"
    Leer nB
    Dimension B[nB]
    for (i = 0; i < nB; i++){
        Escribir "B[", i, "]"
        Leer B[i]
    }
    Dimension C[nA + nB]
    concatena(A, nA, B, nB, C)
    Escribir "Vector combinado (", nA + nB, " elementos):"
    for (i = 0; i < nA + nB; i++){
        Escribir sin saltar C[i], " "
    }
    return 0
}

funcion void concatena(int A[], int nA, int B[], int nB, int C[]){
    Definir i, k como enteros
    k = 0
    for (i = 0; i < nA; i++){              // primero todo A
        C[k] = A[i]
        k = k + 1
    }
    for (i = 0; i < nB; i++){              // luego todo B
        C[k] = B[i]
        k = k + 1
    }
}
```

> Código real en [`../soluciones`](../soluciones).
