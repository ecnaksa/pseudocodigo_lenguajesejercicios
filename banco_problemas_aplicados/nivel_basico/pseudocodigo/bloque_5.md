# Bloque 5/5 — Cierre de Bloque Inicial (Problemas 17 a 20)

---

## Problema 17 — Desplazamiento Lineal de Buffer FIFO

**Contexto:** actualizar un búfer de temperatura moviendo todos los registros una posición a la
derecha y dejando espacio para una nueva lectura.
**E/P/S:** vector y tamaño → `Arr[i] = Arr[i-1]` desde el final → vector desplazado.

> ⚠️ El recorrido va **desde el final** hacia el inicio; si se hiciera al revés se
> sobre-escribirían los valores antes de copiarlos.
> Ver [`../teoria/05_desplazamiento_fifo_e_inversion_espejo.md`](../teoria/05_desplazamiento_fifo_e_inversion_espejo.md).

```
Algoritmo BufferFIFO

int main(){
    Definir Arr[] como real
    Definir tam, i como enteros
    Definir nueva como real
    Escribir "Ingrese el tamano del buffer"
    Leer tam
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Registro ", i
        Leer Arr[i]
    }
    Escribir "Nueva lectura a insertar:"
    Leer nueva
    desplazaFIFO(Arr, tam, nueva)
    Escribir "Buffer tras el desplazamiento:"
    for (i = 0; i < tam; i++){
        Escribir sin saltar Arr[i], " "
    }
    return 0
}

funcion void desplazaFIFO(double Arr[], int tam, double nueva){
    Definir i como entero
    for (i = tam - 1; i >= 1; i--){       // DESDE EL FINAL
        Arr[i] = Arr[i - 1]
    }
    Arr[0] = nueva                        // la nueva lectura entra al frente
}
```

---

## Problema 18 — Comparación de Dos Canales de Telemetría

**Contexto:** recibir dos vectores de igual tamaño y verificar mediante función booleana si
ambos canales son idénticos elemento por elemento.
**E/P/S:** vectores A y B → comparar `A[i] == B[i]` en bucle → booleano de igualdad.

```
Algoritmo ComparaCanales

int main(){
    Definir A[], B[] como enteros
    Definir tam, i como enteros
    Escribir "Ingrese el tamano de los canales"
    Leer tam
    Dimension A[tam], B[tam]
    for (i = 0; i < tam; i++){
        Escribir "Canal A, dato ", i
        Leer A[i]
        Escribir "Canal B, dato ", i
        Leer B[i]
    }
    if (sonIguales(A, B, tam) == true){
        Escribir "Los dos canales son identicos"
    } else {
        Escribir "Los canales difieren"
    }
    return 0
}

funcion bool sonIguales(int A[], int B[], int tam){
    Definir i como entero
    for (i = 0; i < tam; i++){
        if (A[i] != B[i]){
            return false
        }
    }
    return true
}
```

---

## Problema 19 — Inversión Espejo de Primera Mitad

**Contexto:** manipular la primera mitad de un vector y almacenar el espejo simétrico en la
segunda mitad para pruebas de impulso.
**E/P/S:** vector de tamaño N → asignar `Arr[N-1-i] = Arr[i]` → vector simetrizado.

```
Algoritmo EspejoPrimeraMitad

int main(){
    Definir Arr[] como real
    Definir n, i como enteros
    Escribir "Ingrese el tamano del vector"
    Leer n
    Dimension Arr[n]
    for (i = 0; i < n; i++){
        Escribir "Dato ", i
        Leer Arr[i]
    }
    espejoPrimeraMitad(Arr, n)
    Escribir "Vector simetrizado:"
    for (i = 0; i < n; i++){
        Escribir sin saltar Arr[i], " "
    }
    return 0
}

funcion void espejoPrimeraMitad(double Arr[], int n){
    Definir i como entero
    for (i = 0; i < int(n / 2); i++){
        Arr[n - 1 - i] = Arr[i]     // la posicion espejo copia el valor de la primera mitad
    }
}
```

---

## Problema 20 — Exposición y Defensa Básica (síntesis conceptual)

**Contexto:** este problema **no es de código**: es la síntesis conceptual de índices, bucles
`for` y recorridos lineales aplicados a los 19 problemas anteriores (exposición grupal sobre
lógica algorítmica y sintaxis de vectores en C/C++).

Guion sugerido para la exposición (mapa de los patrones que se repiten en todo el bloque):

1. **El recorrido lineal** `for (i = 0; i < tam; i++)` es el esqueleto de casi todo: sumar,
   contar, buscar, transformar. Cambia lo que va **dentro**, no la estructura.
2. **Acumuladores** (P1, P5, P13): una variable que arranca en 0 y crece con `suma = suma + …`.
3. **Contadores condicionales** (P3, P6, P7, P15): una variable que crece `+1` solo cuando se
   cumple una condición (sobre el **valor** o sobre el **índice** — P3/P5 muestran la diferencia).
4. **Búsqueda con salida temprana** (P4, P16): `return` en cuanto se encuentra; `-1` si no.
5. **Funciones booleanas de validación** (P12, P18): recorren y devuelven `false` al primer
   fallo, `true` si todo pasó.
6. **Extremos y espejo** `Arr[tam-1-i]` (P10, P19) y **desplazamientos** (P17): manipular
   posiciones, cuidando el sentido del recorrido y los límites del arreglo.
7. **Estadística simple** (P8, P11, P13): media, máximo con su posición, promedio de productos.

La "defensa" consiste en explicar, para cualquiera de los 19, **qué patrón** usa, **por qué**
el bucle tiene esos límites y **qué pasaría** si se cambia `<` por `<=`, `==` por `=`, o el
sentido del recorrido. Toda la teoría de apoyo está en [`../teoria`](../teoria).

> Código real de los problemas 1–19 en [`../soluciones`](../soluciones). El Problema 20 no
> tiene archivo de código por ser conceptual.
