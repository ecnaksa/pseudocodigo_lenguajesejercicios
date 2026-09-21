# Lección 08 — Arreglos

Un **arreglo** guarda **muchos** valores del mismo tipo bajo un solo nombre, accesibles por un
**índice**. En Java, un arreglo es un **objeto** que **conoce su propio tamaño** (a diferencia de
C).

## Declarar y crear un arreglo

```java
int[] notas = new int[5];   // arreglo de 5 enteros, inicializados en 0
notas[0] = 90;
notas[1] = 85;
System.out.println(notas[0]);   // 90
```

- `int[]` es "arreglo de enteros". (También se acepta `int notas[]`, pero `int[] notas` es el
  estilo preferido en Java.)
- `new int[5]` **crea** el arreglo con 5 casillas.
- El **primer** índice es **0**; el **último** es `longitud - 1` (aquí, 4).
- **Al crearlo, Java inicializa** los elementos a su valor por defecto (0 para números, `false`
  para `boolean`, `null` para objetos). No hay "basura" como en C.

### Inicialización directa

```java
int[] a = {10, 20, 30, 40, 50};        // tamaño 5, deducido
String[] nombres = {"Ana", "Luis"};    // arreglo de String
double[] ceros = new double[3];        // {0.0, 0.0, 0.0}
```

## `.length`: el tamaño

Todo arreglo Java **sabe cuántos elementos tiene**, con el atributo `.length` (¡sin paréntesis, no
es un método!):

```java
int[] a = {10, 20, 30};
System.out.println(a.length);   // 3
```
Por eso, a diferencia de C, **no** necesitas llevar el tamaño aparte: el arreglo lo lleva consigo.

## Recorrer un arreglo

Con `for` clásico (si necesitas el índice):

```java
int suma = 0;
for (int i = 0; i < a.length; i++) {
    suma += a[i];
}
```

Con `for-each` (más limpio, solo lectura):

```java
for (int x : a) {
    System.out.print(x + " ");
}
```

## Índices fuera de rango: excepción (más seguro que C)

Si accedes a un índice inválido (`a[10]` en un arreglo de 3), Java **lanza** una excepción
`ArrayIndexOutOfBoundsException` y detiene el programa. En C esto era un error silencioso y
peligroso; en Java, al menos te enteras enseguida.

## Arreglos y métodos

Al pasar un arreglo a un método, se pasa su **referencia** (lección 07): el método **puede
modificar** su contenido. Como el arreglo conoce su `.length`, muchas veces no hace falta pasar el
tamaño:

```java
static int suma(int[] arr) {
    int total = 0;
    for (int x : arr) total += x;
    return total;
}
```

## La clase de utilidad `Arrays`

`java.util.Arrays` trae métodos muy útiles para arreglos:

```java
import java.util.Arrays;

int[] a = {5, 2, 8, 1};
System.out.println(Arrays.toString(a));   // [5, 2, 8, 1]  (imprimir bonito)
Arrays.sort(a);                            // ordena: [1, 2, 5, 8]
Arrays.fill(a, 0);                         // rellena todo con 0
int[] b = Arrays.copyOf(a, a.length);      // copia
```
> Ojo: `System.out.println(a)` a secas imprime algo como `[I@1b6d3586` (la dirección), **no** el
> contenido. Para ver el contenido usa `Arrays.toString(a)`.

## Arreglos de varias dimensiones (matrices)

Un arreglo 2D es un "arreglo de arreglos":

```java
int[][] m = {
    {1, 2, 3},
    {4, 5, 6}
};
System.out.println(m[1][2]);      // 6  (fila 1, columna 2)
System.out.println(m.length);     // 2  (numero de filas)
System.out.println(m[0].length);  // 3  (columnas de la fila 0)
```
Se recorre con dos bucles anidados (uno por dimensión).

## Errores típicos

- Acceder a un índice **fuera de rango** → `ArrayIndexOutOfBoundsException`.
- Usar `.length()` (con paréntesis) en un arreglo: es `.length` **sin** paréntesis. (`String` sí
  usa `.length()` con paréntesis — no los confundas.)
- Imprimir un arreglo con `println(a)` esperando ver el contenido (usa `Arrays.toString`).
- Confundir el orden de índices en una matriz (`m[fila][columna]`).

## Resumen

- `tipo[] nombre = new tipo[n];` o con `{...}`; índices `0..length-1`.
- **`.length`** (sin paréntesis) da el tamaño; Java verifica límites (lanza excepción).
- Recorre con `for` (si necesitas índice) o `for-each` (solo lectura).
- `Arrays.toString`, `Arrays.sort`, `Arrays.fill`, `Arrays.copyOf` para operaciones comunes.
- Matrices: `tipo[][]`, `m[fila][columna]`, dos bucles.

## Ejemplos

- [`ejemplos/Recorrer.java`](ejemplos/Recorrer.java)
- [`ejemplos/UtilArrays.java`](ejemplos/UtilArrays.java)
- [`ejemplos/Matriz.java`](ejemplos/Matriz.java)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **The Java Tutorials (Oracle)**, "Arrays".
  https://docs.oracle.com/javase/tutorial/java/nutsandbolts/arrays.html
- **Baeldung**, "Arrays in Java". https://www.baeldung.com/java-arrays-guide
