# 01 · Estructura de un programa: `main`, funciones y `return`

## 1. El punto de entrada: `main`

Todo programa en C, C++ y Java empieza a ejecutarse en una función especial llamada
**`main`**. Es el "director de orquesta": pide los datos, llama a las funciones y muestra
los resultados.

En el pseudocódigo híbrido:

```
int main(){
    ...
    return 0
}
```

Traducción:

| | Firma de `main` | Qué devuelve |
|---|---|---|
| **C** | `int main(void){ … }` | `int`: `return 0;` = "terminó bien". |
| **C++** | `int main(){ … }` | `int`: `return 0;` (opcional en C++, pero se acostumbra ponerlo). |
| **Java** | `public static void main(String[] args){ … }` | `void`: no devuelve nada; no lleva `return 0`. |

**Detalle importante en Java:** `main` **debe** estar dentro de una **clase pública** cuyo
nombre coincida con el del archivo. Por eso los archivos se llaman `Ejercicio01.java` y
contienen `public class Ejercicio01`.

```java
public class Ejercicio01 {
    public static void main(String[] args) {
        // ...
    }
}
```

> El caso especial es el **Ejercicio 12**: en estilo PSeInt puro el bloque
> `Algoritmo … FinAlgoritmo` **es** el `main`. Al traducirlo a C/C++/Java, ese bloque se
> convierte en `int main(){ … return 0; }`.

## 2. Funciones

Una **función** es un bloque de código con nombre que recibe **parámetros** y (opcionalmente)
**devuelve** un valor. Sirve para no repetir código y para separar responsabilidades.

Estructura general en pseudocódigo:

```
funcion <tipo_de_retorno> nombre(<parámetros>){
    ... cuerpo ...
    return <valor>          // solo si el tipo no es void
}
```

Ejemplo (Ejercicio 01):

```
funcion int sumaElementos(int Arr[], int tam){
    Definir suma, i como enteros
    suma = 0
    for (i = 0; i < tam; i++){
        suma = suma + Arr[i]
    }
    return suma
}
```

### El tipo de retorno

El tipo de retorno dice **qué clase de valor entrega** la función:

- **`int`** → entrega un entero. Ej.: `sumaElementos`, `buscaMinimo`, `cuentaImpares`,
  `buscaElemento`, `eliminaDuplicados`.
- **`void`** → **no entrega nada**; solo *hace* algo (imprimir, modificar un arreglo).
  Ej.: `analizarArreglo`, `invierteArreglo`, `ordenaBurbuja`.
- **`bool`** (Java: `boolean`) → entrega verdadero o falso. Ej.: `esPalindromo`.

Comparación de la misma función en los tres lenguajes:

```c
/* C */
int sumaElementos(int arr[], int tam) {
    int suma = 0;
    for (int i = 0; i < tam; i++) suma += arr[i];
    return suma;
}
```
```cpp
// C++  (idéntico a C)
int sumaElementos(int arr[], int tam) {
    int suma = 0;
    for (int i = 0; i < tam; i++) suma += arr[i];
    return suma;
}
```
```java
// Java: los métodos sueltos (que no pertenecen a un objeto) se marcan static
static int sumaElementos(int[] arr, int tam) {
    int suma = 0;
    for (int i = 0; i < tam; i++) suma += arr[i];
    return suma;
}
```

### ¿Por qué `static` en Java?

En Java no hay funciones "sueltas": todo método pertenece a una clase. Como `main` es
`static` y llamamos a las funciones **sin crear un objeto**, esas funciones también deben ser
`static`. Así `main` puede invocar `sumaElementos(arr, tam)` directamente.

## 3. `return`: dos usos

1. **Devolver un valor** y terminar la función:
   ```
   return suma        // la función entrega 'suma' a quien la llamó
   ```
2. **Salir anticipadamente.** En cuanto se ejecuta un `return`, la función termina. Esto se
   aprovecha en `buscaElemento` (devuelve la posición **apenas** encuentra el valor) y en
   `esPalindromo` (devuelve `false` **apenas** halla un par distinto):
   ```
   funcion int buscaElemento(int Arr[], int x, int tam){
       for (i = 0; i < tam; i++){
           if (Arr[i] == x){
               return i         // encontrado: salimos ya con la posición
           }
       }
       return -1                // recorrió todo sin encontrarlo
   }
   ```

Una función `void` puede usar `return;` (sin valor) para salir antes, pero no es obligatorio.

## 4. Ámbito (scope) de las variables

Cada variable "vive" dentro del bloque `{ }` donde se declaró:

- La `suma` de `sumaElementos` **no** es la misma `suma` de otra función: son locales.
- La `i` de un `for` normalmente solo existe dentro de ese `for`.

Por eso en el Ejercicio 01 original había un problema de claridad: la función se llamaba
`suma` **y** tenía una variable local `suma`. Renombrar la función a `sumaElementos` evita la
confusión. Que dos funciones distintas usen `i` o `suma` por separado no es problema: son
variables independientes.

## 5. Flujo completo (Ejercicio 01)

```
main  ──llama──▶  sumaElementos(Arr, tam)
                        │
                        │ recorre el arreglo y acumula
                        ▼
main  ◀──return suma──  (el valor regresa y se imprime)
```
