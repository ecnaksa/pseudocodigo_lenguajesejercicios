# Lección 06 — Bucles (repetir)

Un **bucle** repite un bloque varias veces. Java tiene `while`, `do-while`, `for` y, además, un
`for-each` muy cómodo para recorrer colecciones y arreglos.

## `while` — "mientras se cumpla"

Repite **mientras** la condición sea verdadera; la comprueba **antes** de cada vuelta:

```java
int i = 1;
while (i <= 5) {
    System.out.print(i + " ");
    i++;               // ¡imprescindible! sin esto, bucle infinito
}
// 1 2 3 4 5
```

## `do-while` — "haz y luego comprueba"

Comprueba la condición **al final**, así que el cuerpo se ejecuta **al menos una vez**. Útil para
menús o validar entradas:

```java
int opcion;
do {
    System.out.print("Elige (1-3): ");
    opcion = sc.nextInt();
} while (opcion < 1 || opcion > 3);
```
Fíjate en el `;` final del `do-while`.

## `for` — el bucle contado

Reúne inicialización, condición y actualización en una línea (separadas por `;`):

```java
for (int i = 1; i <= 5; i++) {
    System.out.print(i + " ");
}
// 1 2 3 4 5
```

Orden de ejecución:
1. `int i = 1` (una vez).
2. ¿`i <= 5`? Si sí, ejecuta el cuerpo; si no, termina.
3. `i++`.
4. Vuelve al paso 2.

## `for-each` — "para cada elemento"

Java tiene una forma especial de `for` para recorrer **cada elemento** de un arreglo o colección,
sin manejar índices. Se lee "para cada `x` en la colección":

```java
int[] numeros = {10, 20, 30};
for (int n : numeros) {          // para cada n en numeros
    System.out.print(n + " ");
}
// 10 20 30
```

Es más limpio y evita errores de índice, pero **no** te da el índice ni te deja modificar el
arreglo por posición. Cuando necesites el índice o cambiar elementos, usa el `for` clásico.

## ¿Cuál usar?

- **`for`**: cuando sabes (o llevas la cuenta de) **cuántas** veces repetir, o necesitas el índice.
- **`for-each`**: para **recorrer** un arreglo/colección de principio a fin (solo lectura).
- **`while`**: cuando repites **mientras** pase algo, sin saber cuántas veces.
- **`do-while`**: cuando debe ejecutarse **al menos una vez** (menús, validaciones).

## `break` y `continue`

- **`break`** sale del bucle inmediatamente.
- **`continue`** salta a la siguiente vuelta.

```java
for (int i = 1; i <= 10; i++) {
    if (i == 6) break;          // corta al llegar a 6 -> 1..5
    if (i % 2 == 0) continue;   // salta los pares
    System.out.print(i + " ");
}
// 1 3 5
```

## Bucles anidados

Un bucle dentro de otro; el interno completa todas sus vueltas por cada vuelta del externo. Útiles
para tablas y matrices:

```java
for (int fila = 1; fila <= 3; fila++) {
    for (int col = 1; col <= 3; col++) {
        System.out.print("* ");
    }
    System.out.println();       // salto al terminar cada fila
}
```

## Patrones fundamentales

**Acumular una suma:**
```java
int suma = 0;
for (int i = 1; i <= 100; i++) suma += i;   // 5050
```

**Contar bajo una condición:**
```java
int pares = 0;
for (int i = 1; i <= 20; i++) if (i % 2 == 0) pares++;
```

## Errores típicos

- **Bucle infinito** por olvidar actualizar la variable de control.
- **Error de "uno de más/menos"** (*off-by-one*): `<=` donde iba `<` o al revés.
- Poner `;` tras el `for`/`while`: `for(...);` deja el cuerpo **vacío**.
- Intentar usar el índice o modificar el arreglo con `for-each` (usa el `for` clásico).

## Resumen

- `while` comprueba antes; `do-while` al menos una vez; `for` para conteos; **`for-each`** para
  recorrer colecciones.
- `break` sale, `continue` salta a la siguiente vuelta.
- Bucles anidados para tablas/matrices. Patrones: acumular, contar, recorrer.

## Ejemplos

- [`ejemplos/ContarFor.java`](ejemplos/ContarFor.java)
- [`ejemplos/ForEach.java`](ejemplos/ForEach.java)
- [`ejemplos/TablaAnidada.java`](ejemplos/TablaAnidada.java)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **The Java Tutorials (Oracle)**, "The for Statement" / "while and do-while".
  https://docs.oracle.com/javase/tutorial/java/nutsandbolts/for.html
- **Baeldung**, "Java Loops". https://www.baeldung.com/java-loops
