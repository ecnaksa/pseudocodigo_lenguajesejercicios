# Lección 08 — Arreglos y cadenas

Hasta ahora cada variable guardaba **un** valor. Un **arreglo** (o **vector**) guarda **muchos**
valores del mismo tipo, uno tras otro, accesibles por un **índice**. Y una **cadena** (*string*)
en C no es más que un arreglo de caracteres.

## Arreglos: declaración y uso

```c
int notas[5];              // arreglo de 5 enteros (indices 0..4)
notas[0] = 90;
notas[1] = 85;
printf("%d\n", notas[0]);  // 90
```

- El **tamaño** va entre corchetes. Aquí, 5 casillas.
- El **primer** índice es **0**; el **último** es `tamaño - 1` (aquí, 4).
- Acceder fuera de rango (`notas[5]` o `notas[-1]`) es **comportamiento indefinido**: C **no**
  avisa; puede corromper datos o "reventar". Respeta siempre los límites.

### Inicialización

```c
int a[5] = {10, 20, 30, 40, 50};   // los cinco valores
int b[5] = {1, 2};                 // b[0]=1, b[1]=2, el resto queda en 0
int c[] = {1, 2, 3};               // tamaño deducido: 3
int d[100] = {0};                  // todo a 0
```

### Recorrer un arreglo (con `for`)

El patrón fundamental: un `for` de `0` a `tamaño - 1`.

```c
int a[5] = {10, 20, 30, 40, 50};
int suma = 0;
for (int i = 0; i < 5; i++) {
    suma += a[i];
}
printf("Suma: %d\n", suma);   // 150
```

> Como C no guarda el tamaño del arreglo junto a él, **tú** debes llevar la cuenta (una constante
> o una variable `n`). Es una fuente típica de errores; sé cuidadoso.

## Arreglos y funciones

Al pasar un arreglo a una función, **no se copia**: la función recibe una referencia al arreglo
original (en realidad, un puntero a su primer elemento — lección 09). Por eso **la función puede
modificar** el arreglo, y hay que pasarle también **el tamaño**:

```c
double promedio(int arr[], int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) suma += arr[i];
    return (double) suma / n;
}
```

## Arreglos de varias dimensiones (matrices)

Un arreglo 2D es una tabla de filas y columnas:

```c
int m[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
printf("%d\n", m[1][2]);   // 6  (fila 1, columna 2)
```
Se recorre con **dos** bucles anidados (uno por dimensión).

## Cadenas de texto (strings)

En C **no hay un tipo `string`**: una cadena es un **arreglo de `char`** terminado por un
carácter especial, el **nulo** `'\0'` (código 0), que marca dónde acaba el texto.

```c
char nombre[] = "Ana";
// en memoria: 'A' 'n' 'a' '\0'   -> ocupa 4 chars aunque "Ana" tenga 3 letras
```

- Entre **comillas dobles** `"Ana"` es una cadena; entre **comillas simples** `'A'` es un solo
  carácter.
- El `'\0'` es **automático** cuando inicializas con `"..."`, y es lo que permite a `printf("%s")`
  saber dónde parar.

### Leer e imprimir cadenas

```c
char nombre[50];
printf("Tu nombre: ");
scanf("%49s", nombre);        // lee UNA palabra (sin espacios). Nota: sin & (el arreglo ya es direccion)
printf("Hola, %s\n", nombre);
```

- `%s` lee/imprime una cadena. Al **leer**, `scanf("%s")` se detiene en el primer espacio (lee
  una sola palabra) y **no** lleva `&` (el nombre del arreglo ya representa una dirección).
- El `%49s` limita a 49 caracteres + el `'\0'`, evitando desbordar `nombre[50]`. **Leer sin
  límite es peligroso** (desbordamiento de buffer).
- Para leer **una línea completa** con espacios, se usa `fgets` (lección 12).

## La biblioteca `<string.h>`

Como las cadenas son arreglos, **no** puedes copiarlas con `=` ni compararlas con `==`. Para eso
está `<string.h>`:

| Función | Qué hace |
|---|---|
| `strlen(s)` | longitud (sin contar el `'\0'`) |
| `strcpy(dest, src)` | copia `src` en `dest` |
| `strcat(dest, src)` | añade `src` al final de `dest` |
| `strcmp(a, b)` | compara: 0 si iguales, <0 o >0 según orden |

```c
#include <string.h>
char saludo[50] = "Hola";
strcat(saludo, ", mundo");         // saludo = "Hola, mundo"
printf("Largo: %zu\n", strlen(saludo));   // 11
if (strcmp(saludo, "Hola") == 0) { /* ... */ }
```

> **Cuidado con el espacio:** `strcpy`/`strcat` no comprueban si cabe; asegúrate de que el
> destino sea lo bastante grande, o usa las variantes con `n` (`strncpy`, `strncat`).

## Errores típicos

- **Salirse de los límites** del arreglo (índice inválido).
- **Olvidar el tamaño** al pasar el arreglo a una función.
- Comparar cadenas con `==` (compara direcciones, no contenido) → usa `strcmp`.
- Olvidar espacio para el `'\0'` (una cadena de N letras necesita N+1 chars).
- Leer una cadena con `scanf("%s")` sin límite → desbordamiento.

## Resumen

- Arreglo: `tipo nombre[tam];`, índices `0..tam-1`; C no verifica límites.
- Recorre con `for`; pasa siempre el **tamaño** a las funciones.
- Matrices: `tipo m[filas][cols];`, dos bucles.
- Cadenas = arreglos de `char` terminados en `'\0'`; `%s` para E/S.
- Copia/compara/concatena con `<string.h>` (`strcpy`, `strcmp`, `strcat`, `strlen`).

## Ejemplos

- [`ejemplos/recorrer_arreglo.c`](ejemplos/recorrer_arreglo.c)
- [`ejemplos/matriz.c`](ejemplos/matriz.c)
- [`ejemplos/cadenas.c`](ejemplos/cadenas.c)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **K&R**, cap. 1 (§1.6 arreglos), cap. 5 (§5.5 cadenas).
- **King**, cap. 8 ("Arrays") y cap. 13 ("Strings").
- **cppreference**, "Arrays" y "String library". https://en.cppreference.com/w/c/string/byte
