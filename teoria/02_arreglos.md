# 02 · Arreglos (vectores)

Un **arreglo** (o **vector**) es una colección de elementos del **mismo tipo**, guardados en
posiciones **consecutivas** de memoria y accesibles por un **índice**. Es el protagonista de
los 15 ejercicios.

## 1. Declaración y dimensión

En el pseudocódigo híbrido se separa en dos pasos:

```
Definir Arr[] como entero     // declaro que Arr es un arreglo de enteros
Dimension Arr[tam]            // reservo espacio para 'tam' elementos
```

**Regla de oro:** primero se **conoce** `tam` (por `Leer tam` o `tam = 10`) y **después** se
dimensiona. Dimensionar antes de saber el tamaño era uno de los errores del JSON original
(Ejercicios 01 y 12).

### Cómo se traduce

**C** — arreglo de tamaño fijo o *arreglo de longitud variable* (VLA, desde C99):

```c
int tam = 10;
int arr[10];        // tamaño fijo conocido al escribir el programa
// o bien, con tam leído en tiempo de ejecución:
int arr[tam];       // VLA: el tamaño se decide al ejecutar
```

**C++** — tamaño fijo, o **memoria dinámica** con `new`/`delete` (lo usado en las soluciones):

```cpp
int* arr = new int[tam];   // reserva 'tam' enteros
// ... usarlo igual que un arreglo: arr[i] ...
delete[] arr;              // MUY importante: liberar la memoria al terminar
```
> C++ moderno prefiere `std::vector<int> arr(tam);`, que se encarga solo de la memoria. En
> estas soluciones se usó `new[]`/`delete[]` para que el paralelo con C sea directo.

**Java** — siempre con `new`; el arreglo es un **objeto**:

```java
int[] arr = new int[tam];  // la JVM administra la memoria (no hay que liberarla)
```

## 2. Índices: empiezan en 0

En los tres lenguajes (y en el pseudocódigo híbrido) **el primer elemento es `Arr[0]`** y el
último es **`Arr[tam-1]`**.

```
Arr:      [ 7 ][ 3 ][ 9 ][ 2 ][ 5 ]
índice:      0    1    2    3    4      (tam = 5, último índice = tam-1 = 4)
```

Por eso el bucle típico va de `0` a `tam-1`:

```
for (i = 0; i < tam; i++){ ... Arr[i] ... }
```

La condición es `i < tam` (no `i <= tam`), porque `Arr[tam]` **ya está fuera** del arreglo.

### El truco del "espejo": `Arr[tam-1-i]`

Varios ejercicios recorren el arreglo "desde los dos extremos hacia el centro". La posición
**espejo** de `i` es `tam-1-i`:

- `i = 0` ↔ `tam-1` (primero ↔ último)
- `i = 1` ↔ `tam-2` (segundo ↔ penúltimo)

Se usa en **invertir** (Ej. 12), **palíndromo** (Ej. 13) y en la multiplicación cruzada
(Ej. 10: `C[i] = A[i] * B[tam-1-i]`). Para recorrer solo la mitad se usa `i < tam/2`.

## 3. Salirse del arreglo (¡peligro!)

Acceder a un índice fuera de `[0, tam-1]` es un error clásico:

- **C / C++:** **no avisan**. Leer/escribir fuera de rango es *comportamiento indefinido*:
  puede dar basura, corromper datos o "reventar" el programa. El original del Ejercicio 02
  hacía `Arr[i+1]` y en la última vuelta leía fuera del arreglo.
- **Java:** **sí avisa**: lanza `ArrayIndexOutOfBoundsException` y detiene el programa. Es más
  seguro, pero hay que respetar igual los límites.

## 4. Tamaño físico vs. tamaño lógico

- **Tamaño físico:** cuántas casillas se reservaron (p. ej. 8).
- **Tamaño lógico:** cuántas casillas se están *usando de verdad*.

En el **Ejercicio 15 (eliminar duplicados)** el arreglo se reservó con 8 casillas, pero tras
quitar repetidos quizá solo 5 son válidas. La función devuelve ese **tamaño lógico** (`ntam`)
y al imprimir se recorre `for (i = 0; i < ntam; i++)`. En Java esto es aún más visible:
`arr.length` sigue siendo 8 (el objeto no cambia de tamaño); el 5 es un valor que llevamos
aparte.

## 5. `.length` en Java

En Java el arreglo **conoce su propia longitud**:

```java
int[] arr = new int[20];
System.out.println(arr.length);   // 20
for (int i = 0; i < arr.length; i++) { ... }
```

En C y C++ el arreglo **no** guarda su tamaño: por eso **siempre** se pasa `tam` como
parámetro extra a las funciones (`sumaElementos(int arr[], int tam)`). Ese es el motivo de que
todas las firmas de los ejercicios lleven `int tam`.

## 6. Resumen por lenguaje

| | Declarar (tam dinámico) | ¿Conoce su tamaño? | ¿Verifica límites? | ¿Liberar memoria? |
|---|---|---|---|---|
| **C** | `int arr[tam];` o `malloc` | No (se pasa `tam`) | No | Solo si usaste `malloc` → `free` |
| **C++** | `int* arr = new int[tam];` o `vector` | No (con arreglo crudo) | No | `delete[]` (o lo hace `vector`) |
| **Java** | `int[] arr = new int[tam];` | Sí (`arr.length`) | Sí (excepción) | No (recolector de basura) |
