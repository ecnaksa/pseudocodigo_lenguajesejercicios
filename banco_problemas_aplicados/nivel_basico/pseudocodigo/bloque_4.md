# Bloque 4/5 — Análisis Secuencial de Datos (Problemas 13 a 16)

---

## Problema 13 — Cálculo de Potencia Aparente Promedio

**Contexto:** arreglos de voltajes V e corrientes I de tamaño N. Calcular la sumatoria de
productos `V[i] * I[i]` y devolver el **promedio** (dividir entre N).
**E/P/S:** vectores V e I de tamaño N → sumatoria de productos → potencia promedio (`double`).

```
Algoritmo PotenciaPromedio

int main(){
    Definir V[], I[] como reales
    Definir n, i como enteros
    Escribir "Ingrese el numero de muestras"
    Leer n
    Dimension V[n], I[n]
    for (i = 0; i < n; i++){
        Escribir "V[", i, "] (V):"
        Leer V[i]
        Escribir "I[", i, "] (A):"
        Leer I[i]
    }
    Escribir "Potencia aparente promedio: ", potenciaPromedio(V, I, n)
    return 0
}

funcion double potenciaPromedio(double V[], double I[], int n){
    Definir i como entero
    Definir suma como real
    suma = 0
    for (i = 0; i < n; i++){
        suma = suma + V[i] * I[i]      // producto punto de V e I
    }
    return suma / n                    // promedio
}
```

---

## Problema 14 — Ordenamiento Lineal Simple por Intercambio

**Contexto:** organizar 8 valores de calibración de forma ascendente con un algoritmo de dos
bucles anidados (intercambio por comparación = burbuja).

```
Algoritmo OrdenamientoIntercambio

int main(){
    Definir Arr[] como real
    Definir tam, i como enteros
    tam = 8
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Valor de calibracion ", i
        Leer Arr[i]
    }
    ordenaIntercambio(Arr, tam)
    Escribir "Valores ordenados:"
    for (i = 0; i < tam; i++){
        Escribir sin saltar Arr[i], " "
    }
    return 0
}

funcion void ordenaIntercambio(double Arr[], int tam){
    Definir i, f como enteros
    Definir aux como real
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

## Problema 15 — Conteo de Muestras Saturadas (Overflow)

**Contexto:** evaluar un vector de conversiones de un ADC de 10 bits y contar cuántas
alcanzaron el límite superior exacto de **1023** cuentas.
**E/P/S:** vector ADC de tamaño N → contar si `Arr[i] == 1023` → cantidad entera.

```
Algoritmo MuestrasSaturadas

int main(){
    Definir Arr[] como entero
    Definir tam, i como enteros
    Escribir "Ingrese el numero de conversiones"
    Leer tam
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Conversion ", i, " (0..1023):"
        Leer Arr[i]
    }
    Escribir "Muestras saturadas (== 1023): ", cuentaSaturadas(Arr, tam)
    return 0
}

funcion int cuentaSaturadas(int Arr[], int tam){
    Definir i, contador como enteros
    contador = 0
    for (i = 0; i < tam; i++){
        if (Arr[i] == 1023){
            contador = contador + 1
        }
    }
    return contador
}
```

---

## Problema 16 — Búsqueda de Primer Flanco de Subida

**Contexto:** detectar en qué índice un arreglo de voltajes pasa de negativo a positivo
(cruce de umbral cero ascendente).
**E/P/S:** vector bipolar → buscar `Arr[i] < 0 Y Arr[i+1] >= 0` → índice del flanco (o `-1`).

> ⚠️ Como se usa `Arr[i+1]`, el bucle llega solo hasta `tam-2` (`i < tam-1`) para no salirse.
> Ver [`../teoria/04_pares_adyacentes_y_deteccion_de_flanco.md`](../teoria/04_pares_adyacentes_y_deteccion_de_flanco.md).

```
Algoritmo FlancoSubida

int main(){
    Definir Arr[] como real
    Definir tam, i, idx como enteros
    Escribir "Ingrese el numero de muestras"
    Leer tam
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Voltaje ", i, " (V):"
        Leer Arr[i]
    }
    idx = buscaFlanco(Arr, tam)
    if (idx < 0){
        Escribir "No se detecto ningun flanco de subida"
    } else {
        Escribir "Primer flanco de subida entre los indices ", idx, " y ", idx + 1
    }
    return 0
}

funcion int buscaFlanco(double Arr[], int tam){
    Definir i como entero
    for (i = 0; i < tam - 1; i++){
        if (Arr[i] < 0 && Arr[i + 1] >= 0){
            return i
        }
    }
    return -1
}
```

> Código real en [`../soluciones`](../soluciones).
