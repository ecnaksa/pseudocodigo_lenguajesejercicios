# Bloque 3/5 — Operaciones Combinadas de Vectores (Problemas 9 a 12)

---

## Problema 9 — Superposición Lineal de Dos Canales (A + B)

**Contexto:** suma de señales de dos micrófonos. Llenar A y B de 5 elementos y calcular
`C[i] = A[i] + B[i]`; imprimir C.

```
Algoritmo Superposicion

int main(){
    Definir A[], B[], C[] como reales
    Definir tam, i como enteros
    tam = 5
    Dimension A[tam], B[tam], C[tam]
    for (i = 0; i < tam; i++){
        Escribir "Canal A, muestra ", i
        Leer A[i]
        Escribir "Canal B, muestra ", i
        Leer B[i]
    }
    superpone(A, B, C, tam)
    return 0
}

funcion void superpone(double A[], double B[], double C[], int tam){
    Definir i como entero
    for (i = 0; i < tam; i++){
        C[i] = A[i] + B[i]
    }
    Escribir "Vector resultante C (A + B):"
    for (i = 0; i < tam; i++){
        Escribir "C[", i, "] = ", C[i]
    }
}
```

---

## Problema 10 — Multiplicación Cruzada Inversa en Retardos

**Contexto:** simulación de convolución simple. Con A y B de 10 elementos,
`C[i] = A[i] * B[tam-1-i]` (primer A × último B, etc.), guardando en C de izquierda a derecha.

```
Algoritmo MultiplicacionCruzada

int main(){
    Definir A[], B[], C[] como reales
    Definir tam, i como enteros
    tam = 10
    Dimension A[tam], B[tam], C[tam]
    for (i = 0; i < tam; i++){
        Escribir "A[", i, "]:"
        Leer A[i]
        Escribir "B[", i, "]:"
        Leer B[i]
    }
    multCruzada(tam, A, B, C)
    return 0
}

funcion void multCruzada(int tam, double A[], double B[], double C[]){
    Definir i como entero
    for (i = 0; i < tam; i++){
        C[i] = A[i] * B[tam - 1 - i]
    }
    Escribir "Vector resultante C (cruce A * B):"
    for (i = 0; i < tam; i++){
        Escribir "C[", i, "] = ", C[i]
    }
}
```

---

## Problema 11 — Detección de Pico Máximo Absoluto

**Contexto:** 15 muestras de un osciloscopio (valores únicos). Imprimir el valor **máximo** y su
**posición** en el tiempo.

```
Algoritmo PicoMaximo

int main(){
    Definir Arr[] como real
    Definir tam, i como enteros
    tam = 15
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Muestra ", i, " (V):"
        Leer Arr[i]
    }
    picoMaximo(Arr, tam)
    return 0
}

funcion void picoMaximo(double Arr[], int tam){
    Definir i, posicion como enteros
    Definir mayor como real
    mayor = Arr[0]
    posicion = 0
    for (i = 1; i < tam; i++){
        if (Arr[i] > mayor){
            mayor = Arr[i]
            posicion = i
        }
    }
    Escribir "Pico maximo: ", mayor
    Escribir "Posicion (indice) del pico: ", posicion
}
```

---

## Problema 12 — Verificación de Rango de Operación Segura

**Contexto:** comprobar si 10 mediciones de voltaje están **todas** dentro de `[3.3V, 5.0V]`,
retornando un booleano.
**E/P/S:** 10 voltajes → validar `3.3 <= val <= 5.0` para todo elemento → booleano.

> ⚠️ **Trampa clásica:** en C/C++/Java **no** existe `3.3 <= val <= 5.0` como en matemáticas;
> hay que escribir **dos** comparaciones unidas con `&&`: `val >= 3.3 && val <= 5.0`.
> Ver [`../teoria/03_funciones_booleanas_validacion_rango.md`](../teoria/03_funciones_booleanas_validacion_rango.md).

```
Algoritmo RangoSeguro

int main(){
    Definir Arr[] como real
    Definir tam, i como enteros
    tam = 10
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Medicion ", i, " (V):"
        Leer Arr[i]
    }
    if (enRango(Arr, tam) == true){
        Escribir "OK: todas dentro del rango [3.3, 5.0]"
    } else {
        Escribir "ALERTA: al menos una fuera del rango [3.3, 5.0]"
    }
    return 0
}

funcion bool enRango(double Arr[], int tam){
    Definir i como entero
    for (i = 0; i < tam; i++){
        if (!(Arr[i] >= 3.3 && Arr[i] <= 5.0)){
            return false        // en cuanto una se sale, ya es false
        }
    }
    return true                 // todas pasaron
}
```

> Código real en [`../soluciones`](../soluciones).
