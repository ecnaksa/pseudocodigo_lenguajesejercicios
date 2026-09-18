# Bloque 2/5 — Manipulación de Estructuras (Problemas 25 a 28)

---

## Problema 25 — Partición Pares/Impares en Vector

**Contexto:** procesamiento multiplexado. Reorganizar el arreglo colocando **primero** los
valores de **índices pares** (0, 2, 4…) y **luego** los de **índices impares** (1, 3, 5…),
usando un vector auxiliar de salida.

```
Algoritmo ParticionParesImpares

int main(){
    Definir Arr[], Res[] como enteros
    Definir tam, i como enteros
    Escribir "Ingrese el tamano del vector"
    Leer tam
    Dimension Arr[tam], Res[tam]
    for (i = 0; i < tam; i++){
        Escribir "Dato ", i
        Leer Arr[i]
    }
    particiona(Arr, tam, Res)
    Escribir "Vector particionado (pares | impares):"
    for (i = 0; i < tam; i++){
        Escribir sin saltar Res[i], " "
    }
    return 0
}

funcion void particiona(int Arr[], int tam, int Res[]){
    Definir i, k como enteros
    k = 0
    for (i = 0; i < tam; i++){          // primero los indices pares
        if (i % 2 == 0){
            Res[k] = Arr[i]
            k = k + 1
        }
    }
    for (i = 0; i < tam; i++){          // luego los indices impares
        if (i % 2 != 0){
            Res[k] = Arr[i]
            k = k + 1
        }
    }
}
```

---

## Problema 26 — Desplazamiento Circular de Muestras

**Contexto:** simulación de retardos en líneas de transmisión. Desplazamiento **circular**
hacia la derecha por `K` posiciones: el elemento de la posición `i` pasa a `(i + K) % tam`;
lo que sale por la derecha reingresa por la izquierda.
**E/P/S:** vector y pasos K → rotación cíclica de índices → buffer desplazado.

> El operador `%` (módulo) hace que el índice "dé la vuelta". Ver
> [`../teoria/03_transformaciones_de_vector.md`](../teoria/03_transformaciones_de_vector.md).

```
Algoritmo DesplazamientoCircular

int main(){
    Definir Arr[] como real
    Definir tam, i, k como enteros
    Escribir "Ingrese el numero de muestras"
    Leer tam
    Dimension Arr[tam]
    for (i = 0; i < tam; i++){
        Escribir "Muestra ", i
        Leer Arr[i]
    }
    Escribir "Ingrese K (posiciones a rotar a la derecha):"
    Leer k
    rotaDerecha(Arr, tam, k)
    Escribir "Buffer desplazado:"
    for (i = 0; i < tam; i++){
        Escribir sin saltar Arr[i], " "
    }
    return 0
}

funcion void rotaDerecha(double Arr[], int tam, int k){
    Definir i como entero
    Definir Aux[] como real
    Dimension Aux[tam]
    k = k % tam                          // si k >= tam, la rotacion se repite
    for (i = 0; i < tam; i++){
        Aux[(i + k) % tam] = Arr[i]      // indice circular con modulo
    }
    for (i = 0; i < tam; i++){
        Arr[i] = Aux[i]                  // copiar el resultado de vuelta
    }
}
```

---

## Problema 27 — Cálculo de Derivada Discreta de Señal

**Contexto:** analizar la tasa de cambio de una señal digital. Vector de diferencias sucesivas
`dv[i] = v[i+1] - v[i]`. El resultado tiene **un elemento menos** (n-1).

```
Algoritmo DerivadaDiscreta

int main(){
    Definir V[], DV[] como reales
    Definir n, i como enteros
    Escribir "Ingrese el numero de voltajes"
    Leer n
    Dimension V[n]
    for (i = 0; i < n; i++){
        Escribir "v[", i, "]"
        Leer V[i]
    }
    Dimension DV[n - 1]                   // una posicion menos
    derivada(V, n, DV)
    Escribir "Derivada discreta (delta v):"
    for (i = 0; i < n - 1; i++){
        Escribir sin saltar DV[i], " "
    }
    return 0
}

funcion void derivada(double V[], int n, double DV[]){
    Definir i como entero
    for (i = 0; i < n - 1; i++){          // hasta n-2 porque se usa V[i+1]
        DV[i] = V[i + 1] - V[i]
    }
}
```

---

## Problema 28 — Normalización Lineal de Rango [0.0, 1.0]

**Contexto:** escalamiento de señales para redes neuronales de control. Ajustar linealmente
los valores respecto al **máximo absoluto** hallado: `Arr[i] / maxVal`.
**E/P/S:** vector y valor máximo → división `Arr[i] / maxVal` → vector normalizado.

> Si los datos son ≥ 0 el resultado cae en `[0, 1]`; si hay negativos, en `[-1, 1]`. Ver
> [`../teoria/03_transformaciones_de_vector.md`](../teoria/03_transformaciones_de_vector.md).

```
Algoritmo NormalizacionLineal

int main(){
    Definir Arr[] como real
    Definir n, i como enteros
    Escribir "Ingrese el numero de valores"
    Leer n
    Dimension Arr[n]
    for (i = 0; i < n; i++){
        Escribir "Valor ", i
        Leer Arr[i]
    }
    normaliza(Arr, n)
    Escribir "Vector normalizado:"
    for (i = 0; i < n; i++){
        Escribir sin saltar Arr[i], " "
    }
    return 0
}

funcion void normaliza(double Arr[], int n){
    Definir i como entero
    Definir maxVal como real
    maxVal = abs(Arr[0])                  // abs = valor absoluto
    for (i = 1; i < n; i++){
        if (abs(Arr[i]) > maxVal){
            maxVal = abs(Arr[i])
        }
    }
    if (maxVal == 0){
        return                            // todos 0: no se puede dividir
    }
    for (i = 0; i < n; i++){
        Arr[i] = Arr[i] / maxVal
    }
}
```

> Código real en [`../soluciones`](../soluciones).
