# Bloque 1/5 — Mediciones Lineales y Contadores (Problemas 1 a 4)

> Convención del pseudocódigo híbrido (igual que en el resto del repo): `int main(){…return 0}`,
> funciones con tipo de retorno, `Definir … como entero/real`, `Dimension Arr[tam]` tras leer
> `tam`, `for (i=0; i<tam; i++)`, `if (…){ } else { }`, y en las llamadas se pasan **solo
> argumentos** (sin tipos). `real` ↔ `double`.

---

## Problema 1 — Suma de Muestras de Corriente ADC

**Contexto:** monitoreo de corriente trifásica. `double sumaCorrientes(double Arr[], int tam)`
devuelve la sumatoria total de amperios.
**E/P/S:** vector de amperios y tamaño → bucle acumulador → total `double`.

```
Algoritmo SumaCorrientes

int main(){
    Definir Arr[] como real
    Definir tam, i como enteros
    Escribir "Ingrese el numero de muestras"
    Leer tam
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Muestra ", i, " (A):"
        Leer Arr[i]
    }
    Escribir "Suma total de corrientes: ", sumaCorrientes(Arr, tam)
    return 0
}

funcion double sumaCorrientes(double Arr[], int tam){
    Definir suma como real
    Definir i como entero
    suma = 0
    for (i = 0; i < tam; i++){
        suma = suma + Arr[i]
    }
    return suma
}
```

---

## Problema 2 — Voltaje Mínimo en Banco Solar

**Contexto:** banco fotovoltaico. `double buscaMinimo(double Arr[], int tam)` devuelve el
voltaje mínimo (búsqueda secuencial comparando contra el primer elemento).

```
Algoritmo VoltajeMinimo

int main(){
    Definir Arr[] como real
    Definir tam, i como enteros
    Escribir "Ingrese el numero de celdas"
    Leer tam
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Voltaje de la celda ", i, " (V):"
        Leer Arr[i]
    }
    Escribir "Voltaje minimo detectado: ", buscaMinimo(Arr, tam)
    return 0
}

funcion double buscaMinimo(double Arr[], int tam){
    Definir min como real
    Definir i como entero
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

## Problema 3 — Detección de Transitorios Impares

**Contexto:** análisis de ruido EM. `int cuentaImpares(int Arr[], int tam)` contabiliza las
muestras ubicadas en **índices impares**.
**E/P/S:** vector entero y tamaño → evaluar condición de **índice** `i % 2 != 0` → contador entero.

> ⚠️ **Clave:** aquí la condición es sobre el **índice** `i`, **no** sobre el valor `Arr[i]`.
> Es distinto del `cuentaImpares` del primer set (que miraba valores). Ver
> [`../teoria/02_condicion_sobre_indice_vs_valor.md`](../teoria/02_condicion_sobre_indice_vs_valor.md).

```
Algoritmo TransitoriosImpares

int main(){
    Definir Arr[] como entero
    Definir tam, i como enteros
    Escribir "Ingrese el numero de muestras"
    Leer tam
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Muestra ", i
        Leer Arr[i]
    }
    Escribir "Muestras en indices impares: ", cuentaImpares(Arr, tam)
    return 0
}

funcion int cuentaImpares(int Arr[], int tam){
    Definir i, contador como enteros
    contador = 0
    for (i = 0; i < tam; i++){
        if (i % 2 != 0){          // se evalua la POSICION, no Arr[i]
            contador = contador + 1
        }
    }
    return contador
}
```

---

## Problema 4 — Código de Error en Buffer

**Contexto:** registro de estados de microcontrolador. `int buscaElemento(int Arr[], int x, int tam)`
devuelve la posición del código de falla `x`, o `-1`.

```
Algoritmo CodigoErrorBuffer

int main(){
    Definir Arr[] como entero
    Definir tam, i, x, pos como enteros
    Escribir "Ingrese el tamano del buffer"
    Leer tam
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Estado ", i
        Leer Arr[i]
    }
    Escribir "Ingrese el codigo de falla a buscar:"
    Leer x
    pos = buscaElemento(Arr, x, tam)
    if (pos < 0){
        Escribir "El codigo no aparece en el buffer"
    } else {
        Escribir "El codigo esta en la posicion: ", pos
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

> Código real: [`../soluciones/c/problema0X.c`](../soluciones/c) · [`../soluciones/cpp`](../soluciones/cpp) · [`../soluciones/java`](../soluciones/java).
