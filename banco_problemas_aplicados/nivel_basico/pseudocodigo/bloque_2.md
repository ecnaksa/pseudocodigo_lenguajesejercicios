# Bloque 2/5 — Filtrado de Polaridad y Estadísticas (Problemas 5 a 8)

---

## Problema 5 — Consumo Exclusivo de Cargas Pares

**Contexto:** circuitos conectados a fases pares de un multiplexor.
`double sumaPares(double Arr[], int tam)` acumula los valores situados en **índices pares**.
**E/P/S:** vector de lecturas y N → acumular si `i % 2 == 0` → suma total.

> ⚠️ Igual que el P3, la condición es sobre el **índice** (`i % 2 == 0`), no sobre el valor.

```
Algoritmo CargasPares

int main(){
    Definir Arr[] como real
    Definir tam, i como enteros
    Escribir "Ingrese el numero de lecturas"
    Leer tam
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Lectura ", i
        Leer Arr[i]
    }
    Escribir "Suma de las cargas en indices pares: ", sumaPares(Arr, tam)
    return 0
}

funcion double sumaPares(double Arr[], int tam){
    Definir suma como real
    Definir i como entero
    suma = 0
    for (i = 0; i < tam; i++){
        if (i % 2 == 0){
            suma = suma + Arr[i]
        }
    }
    return suma
}
```

---

## Problema 6 — Frecuencia de Falla Específica en PLC

**Contexto:** monitoreo industrial. `int cuentaRepeticiones(int Arr[], int x, int tam)` cuenta
cuántas veces se repite el código de error `x` (incrementa si `Arr[i] == x`).

```
Algoritmo FrecuenciaFalla

int main(){
    Definir Arr[] como entero
    Definir tam, i, x como enteros
    Escribir "Ingrese el numero de registros"
    Leer tam
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Registro ", i
        Leer Arr[i]
    }
    Escribir "Ingrese el codigo de error a rastrear (x):"
    Leer x
    Escribir "El codigo ", x, " se repite: ", cuentaRepeticiones(Arr, x, tam)
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

## Problema 7 — Clasificador de Polaridad AC

**Contexto:** almacenar 10 lecturas de tensión; contar cuántas son **ceros exactos**, cuántas
**positivas** y cuántas **negativas**, con la suma de positivas y de negativas.
**E/P/S:** 10 valores → condicionales múltiples (`>0`, `<0`, `==0`) → 3 contadores y 2 acumuladores.

```
Algoritmo ClasificadorPolaridad

int main(){
    Definir Arr[] como real
    Definir tam, i como enteros
    tam = 10
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Lectura de tension ", i, " (V):"
        Leer Arr[i]
    }
    clasificaPolaridad(Arr, tam)
    return 0
}

funcion void clasificaPolaridad(double Arr[], int tam){
    Definir i, ceros, pos, neg como enteros
    Definir spos, sneg como reales
    ceros = 0
    pos = 0
    neg = 0
    spos = 0
    sneg = 0
    for (i = 0; i < tam; i++){
        if (Arr[i] == 0){
            ceros = ceros + 1
        } else {
            if (Arr[i] > 0){
                pos = pos + 1
                spos = spos + Arr[i]
            } else {
                neg = neg + 1
                sneg = sneg + Arr[i]
            }
        }
    }
    Escribir "Ceros exactos: ", ceros
    Escribir "Positivos: ", pos, "  suma = ", spos
    Escribir "Negativos: ", neg, "  suma = ", sneg
}
```

---

## Problema 8 — Umbral de Disipación Térmica Media

**Contexto:** 5 sensores en un disipador de CPU. Leer 5 temperaturas, calcular su **media**,
determinar cuántas superan ese umbral y desplegar la lista.
**E/P/S:** 5 temperaturas → promedio y comparación → contador y lista filtrada.

```
Algoritmo UmbralTermico

int main(){
    Definir Arr[] como real
    Definir tam, i como enteros
    tam = 5
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Temperatura del sensor ", i, " (C):"
        Leer Arr[i]
    }
    umbralMedia(Arr, tam)
    return 0
}

funcion void umbralMedia(double Arr[], int tam){
    Definir i, cuenta como enteros
    Definir suma, media como reales
    suma = 0
    for (i = 0; i < tam; i++){
        suma = suma + Arr[i]
    }
    media = suma / tam                 // division real (Arr es real)
    Escribir "Temperatura media (umbral): ", media
    cuenta = 0
    Escribir "Sensores por encima del umbral:"
    for (i = 0; i < tam; i++){
        if (Arr[i] > media){
            cuenta = cuenta + 1
            Escribir "  sensor ", i, " = ", Arr[i]
        }
    }
    Escribir "Cantidad que supera el umbral: ", cuenta
}
```

> Código real en [`../soluciones`](../soluciones).
