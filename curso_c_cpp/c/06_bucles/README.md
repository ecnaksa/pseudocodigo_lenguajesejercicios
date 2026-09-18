# Lección 06 — Bucles (repetir)

Un **bucle** repite un bloque de código varias veces. Es lo que hace que un programa procese
listas, cuente, acumule o espere. C tiene tres: `while`, `do-while` y `for`.

## `while` — "mientras se cumpla"

Repite **mientras** la condición sea verdadera. Comprueba la condición **antes** de cada
repetición:

```c
int i = 1;
while (i <= 5) {
    printf("%d ", i);
    i++;               // ¡IMPRESCINDIBLE! sin esto, el bucle nunca termina
}
// imprime: 1 2 3 4 5
```

**Anatomía de un bucle contado:**
1. **Inicializar** una variable de control (`i = 1`).
2. **Condición** de continuación (`i <= 5`).
3. **Actualizar** la variable dentro del cuerpo (`i++`).

> **Bucle infinito:** si olvidas actualizar la variable (o la condición nunca se vuelve falsa),
> el programa se queda repitiendo para siempre. Si te pasa, corta con `Ctrl+C`.

## `do-while` — "haz y luego comprueba"

Como `while`, pero comprueba la condición **al final**, así que el cuerpo se ejecuta **al menos
una vez**. Útil para menús o validar entradas:

```c
int opcion;
do {
    printf("Elige (1-3): ");
    scanf("%d", &opcion);
} while (opcion < 1 || opcion > 3);   // repite mientras la opcion sea invalida
```

Fíjate en el **`;`** al final del `do-while`.

## `for` — el bucle contado por excelencia

Reúne las tres partes (inicializar, condición, actualizar) en **una sola línea**, separadas por
`;`:

```c
for (int i = 1; i <= 5; i++) {
    printf("%d ", i);
}
// 1 2 3 4 5
```

Se lee: "para `i` desde 1, mientras `i <= 5`, incrementando `i` en cada vuelta". Es el más usado
para recorrer un número **conocido** de veces o un arreglo.

Orden de ejecución del `for`:
1. `i = 1` (una vez, al principio).
2. ¿`i <= 5`? Si sí, ejecuta el cuerpo; si no, termina.
3. `i++`.
4. Vuelve al paso 2.

## ¿Cuál usar?

- **`for`**: cuando sabes (o llevas la cuenta de) **cuántas** veces repetir. Recorrer arreglos.
- **`while`**: cuando repites **mientras** pase algo, sin saber cuántas veces (leer hasta que
  llegue un valor, etc.).
- **`do-while`**: cuando debe ejecutarse **al menos una vez** (menús, validaciones).

Los tres son intercambiables; usa el que exprese mejor tu intención.

## `break` y `continue`

- **`break`** sale del bucle **inmediatamente**.
- **`continue`** salta el resto del cuerpo y pasa a la **siguiente** vuelta.

```c
for (int i = 1; i <= 10; i++) {
    if (i == 6) break;          // corta al llegar a 6 -> imprime 1..5
    if (i % 2 == 0) continue;   // salta los pares
    printf("%d ", i);
}
// 1 3 5
```

## Bucles anidados

Un bucle dentro de otro. El interno completa **todas** sus vueltas por **cada** vuelta del
externo. Sirven para tablas, matrices y patrones:

```c
for (int fila = 1; fila <= 3; fila++) {
    for (int col = 1; col <= 3; col++) {
        printf("* ");
    }
    printf("\n");        // salto de linea al terminar cada fila
}
// * * *
// * * *
// * * *
```

## Patrones fundamentales con bucles

**Acumular una suma:**
```c
int suma = 0;
for (int i = 1; i <= 100; i++) suma += i;   // 1+2+...+100 = 5050
```

**Contar bajo una condición:**
```c
int pares = 0;
for (int i = 1; i <= 20; i++) if (i % 2 == 0) pares++;
```

**Leer hasta un centinela (valor de parada):**
```c
int n, suma = 0;
while (scanf("%d", &n) == 1 && n != 0) {   // hasta que llegue 0 o no haya mas datos
    suma += n;
}
```

## Errores típicos

- **Bucle infinito** por olvidar actualizar la variable de control.
- **Error de "uno de más/menos"** (*off-by-one*): usar `<=` donde iba `<` o al revés.
- Poner `;` justo tras el `for`/`while`: `for(...);` deja el cuerpo **vacío**.
- Declarar la variable de control fuera cuando solo la necesitas dentro.

## Resumen

- `while` comprueba antes; `do-while` al menos una vez; `for` para conteos.
- `break` sale, `continue` salta a la siguiente vuelta.
- Los bucles anidados recorren tablas/matrices.
- Patrones: acumular, contar, recorrer, leer hasta centinela.

## Ejemplos

- [`ejemplos/contar_for.c`](ejemplos/contar_for.c)
- [`ejemplos/suma_while.c`](ejemplos/suma_while.c)
- [`ejemplos/tabla_anidada.c`](ejemplos/tabla_anidada.c)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **K&R**, cap. 3 ("Control Flow").
- **King**, cap. 6 ("Loops").
- **cppreference**, "for", "while", "do-while". https://en.cppreference.com/w/c/language/for
