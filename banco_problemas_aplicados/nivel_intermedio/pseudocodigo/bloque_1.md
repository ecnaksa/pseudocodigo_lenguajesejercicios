# Bloque 1/5 — Análisis de Señales y Buffers (Problemas 21 a 24)

> Convención del pseudocódigo híbrido (igual que en todo el repo): `int main(){…return 0}`,
> funciones con tipo de retorno, `Definir … como entero/real`, `Dimension`, `for (i=0; i<tam; i++)`,
> `if (…){ } else { }`, y en las llamadas solo se pasan argumentos. `real` ↔ `double`.

---

## Problema 21 — Pico Máximo y Su Índice Modular

**Contexto:** 20 muestras analógicas. Una función "modular" que devuelva **tanto** el valor
pico máximo **como** su índice de muestreo.
**E/P/S:** vector y tamaño → función modular con paso de parámetros → valor y posición.

> Como una función solo puede **retornar un valor**, el índice se entrega **por referencia**
> (el `&pos` significa "parámetro de salida"). Ver
> [`../teoria/01_devolver_varios_valores.md`](../teoria/01_devolver_varios_valores.md).

```
Algoritmo PicoMaximoModular

int main(){
    Definir Arr[] como real
    Definir tam, i, posicion como enteros
    Definir valor como real
    tam = 20
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Muestra ", i
        Leer Arr[i]
    }
    valor = picoMaximo(Arr, tam, posicion)   // posicion se llena por referencia
    Escribir "Pico maximo: ", valor
    Escribir "Indice de muestreo: ", posicion
    return 0
}

funcion double picoMaximo(double Arr[], int tam, int &pos){
    Definir i como entero
    Definir mayor como real
    mayor = Arr[0]
    pos = 0
    for (i = 1; i < tam; i++){
        if (Arr[i] > mayor){
            mayor = Arr[i]
            pos = i
        }
    }
    return mayor
}
```

---

## Problema 22 — Conteo Avanzado de Códigos de Falla

**Contexto:** diagnóstico en PLC. `int contarFalla(int Arr[], int tam, int codigo)` cuantifica
las ocurrencias del código buscado.

```
Algoritmo ContarFalla

int main(){
    Definir Arr[] como entero
    Definir tam, i, codigo como enteros
    Escribir "Ingrese el numero de fallas registradas"
    Leer tam
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Falla ", i
        Leer Arr[i]
    }
    Escribir "Ingrese el codigo a cuantificar:"
    Leer codigo
    Escribir "El codigo ", codigo, " aparece: ", contarFalla(Arr, tam, codigo)
    return 0
}

funcion int contarFalla(int Arr[], int tam, int codigo){
    Definir i, contador como enteros
    contador = 0
    for (i = 0; i < tam; i++){
        if (Arr[i] == codigo){
            contador = contador + 1
        }
    }
    return contador
}
```

---

## Problema 23 — Inversión Espectral In-Place en Memoria

**Contexto:** optimización de RAM. `void invertirBuffer(int Arr[], int tam)` ordena
simétricamente (invierte) **sin vectores auxiliares**: solo una variable temporal, con
`swap(Arr[i], Arr[tam-1-i])`.

```
Algoritmo InversionInPlace

int main(){
    Definir Arr[] como entero
    Definir tam, i como enteros
    Escribir "Ingrese el tamano del buffer"
    Leer tam
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Dato ", i
        Leer Arr[i]
    }
    invertirBuffer(Arr, tam)
    Escribir "Buffer invertido:"
    for (i = 0; i < tam; i++){
        Escribir sin saltar Arr[i], " "
    }
    return 0
}

funcion void invertirBuffer(int Arr[], int tam){
    Definir i, aux como enteros       // aux: unica variable temporal, NO un arreglo
    for (i = 0; i < int(tam / 2); i++){
        aux = Arr[i]
        Arr[i] = Arr[tam - 1 - i]
        Arr[tam - 1 - i] = aux
    }
}
```

---

## Problema 24 — Verificación de Rango de Histéresis

**Contexto:** sensor térmico. `bool enHisteresis(double Arr[], int tam, double vmin, double vmax)`
comprueba si **todas** las lecturas se mantienen **de manera estricta** dentro de `(vmin, vmax)`.
**E/P/S:** vector, Vmin, Vmax → validación estricta de umbrales → booleano de estado.

> "Estricta" ⇒ se usan `>` y `<` (los extremos **no** se permiten), a diferencia del rango
> inclusivo `>=`/`<=`. Ver
> [`../teoria/05_verificaciones_orden_y_simetria.md`](../teoria/05_verificaciones_orden_y_simetria.md).

```
Algoritmo RangoHisteresis

int main(){
    Definir Arr[] como real
    Definir tam, i como enteros
    Definir vmin, vmax como reales
    Escribir "Ingrese el numero de lecturas"
    Leer tam
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Lectura ", i
        Leer Arr[i]
    }
    Escribir "Ingrese Vmin:"
    Leer vmin
    Escribir "Ingrese Vmax:"
    Leer vmax
    if (enHisteresis(Arr, tam, vmin, vmax) == true){
        Escribir "OK: todas estrictamente dentro del intervalo"
    } else {
        Escribir "ALERTA: alguna lectura toca o cruza los limites"
    }
    return 0
}

funcion bool enHisteresis(double Arr[], int tam, double vmin, double vmax){
    Definir i como entero
    for (i = 0; i < tam; i++){
        if (!(Arr[i] > vmin && Arr[i] < vmax)){
            return false
        }
    }
    return true
}
```

> Código real: [`../soluciones/c`](../soluciones/c) · [`../soluciones/cpp`](../soluciones/cpp) · [`../soluciones/java`](../soluciones/java).
