# Lección 11 — Estructuras y tipos compuestos

Un arreglo agrupa varios valores **del mismo tipo**. Pero muchas veces quieres agrupar datos
**distintos** que describen **una cosa**: un estudiante tiene nombre (cadena), edad (entero) y
promedio (real). Para eso está la **estructura** (`struct`).

## Declarar una `struct`

Una `struct` define un **nuevo tipo** que agrupa varios campos (**miembros**):

```c
struct Estudiante {
    char nombre[50];
    int edad;
    double promedio;
};
```

Esto **no** crea ninguna variable todavía; define el **molde**. Para crear una variable de ese
tipo:

```c
struct Estudiante e1;
```

## Acceder a los miembros: el operador `.`

```c
struct Estudiante e1;
strcpy(e1.nombre, "Ana");     // las cadenas se copian con strcpy
e1.edad = 20;
e1.promedio = 8.5;

printf("%s, %d anios, %.1f\n", e1.nombre, e1.edad, e1.promedio);
```

También puedes **inicializar** al declarar:

```c
struct Estudiante e2 = {"Luis", 22, 7.8};
// o por nombre de campo (mas claro, C99+):
struct Estudiante e3 = {.nombre = "Sara", .edad = 19, .promedio = 9.1};
```

## `typedef`: darle un nombre más corto

Escribir `struct Estudiante` cada vez es tedioso. Con **`typedef`** creas un **alias**:

```c
typedef struct {
    char nombre[50];
    int edad;
    double promedio;
} Estudiante;             // ahora el tipo se llama simplemente "Estudiante"

Estudiante e1;            // sin escribir "struct"
```
Esta es la forma más común de definir estructuras en C moderno.

## Arreglos de estructuras

Puedes tener muchas estructuras en un arreglo, ideal para listas de registros:

```c
Estudiante grupo[3];
grupo[0].edad = 20;
strcpy(grupo[1].nombre, "Luis");

for (int i = 0; i < 3; i++) {
    printf("%s\n", grupo[i].nombre);
}
```

## Estructuras y funciones

Puedes pasar una `struct` a una función. Por defecto se pasa **por valor** (se copia toda la
estructura), así que la función no modifica el original:

```c
void imprimir(Estudiante e) {
    printf("%s (%d)\n", e.nombre, e.edad);
}
```

Para **modificar** la estructura original (o para evitar copiar una estructura grande), se pasa un
**puntero** a ella. Y aquí aparece un operador nuevo: **`->`**.

## El operador `->` (miembro a través de un puntero)

Cuando tienes un **puntero** a una estructura, para acceder a sus miembros usas `->` en vez de
`.`:

```c
void cumplirAnios(Estudiante *e) {
    e->edad = e->edad + 1;    // e->edad equivale a (*e).edad
}
// ...
Estudiante ana = {"Ana", 20, 8.5};
cumplirAnios(&ana);           // pasamos su direccion
printf("%d\n", ana.edad);     // 21
```
`e->edad` es azúcar sintáctico de `(*e).edad`: "desreferencia `e` y toma su campo `edad`". Como se
usa muchísimo, C le dio la flecha `->`.

## `enum`: constantes con nombre

Un **`enum`** (enumeración) define un conjunto de **constantes enteras con nombre**, útil para
representar estados, opciones o categorías de forma legible:

```c
enum Dia { LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO };
// LUNES vale 0, MARTES 1, ... DOMINGO 6 (automatico)

enum Dia hoy = MIERCOLES;
if (hoy == SABADO || hoy == DOMINGO) {
    printf("Fin de semana\n");
}
```
Es mucho más claro que usar números "mágicos" (`if (hoy == 5)`). También se combinan con
`typedef`: `typedef enum { ... } Dia;`.

## `union`: (breve) varios campos, una misma memoria

Una **`union`** se parece a una `struct`, pero **todos sus miembros comparten el mismo espacio**:
solo uno está "activo" a la vez. Se usa para ahorrar memoria o interpretar los mismos bytes de
distintas formas. Es un tema avanzado; basta con saber que existe:

```c
union Valor {
    int entero;
    double real;
};   // ocupa el tamaño del miembro mayor, no la suma
```

## Errores típicos

- Usar `.` con un **puntero** a struct (debe ser `->`) o viceversa.
- Copiar cadenas con `=` en vez de `strcpy` (las cadenas dentro de la struct son arreglos).
- Pasar una struct grande por valor sin necesidad (copia costosa); mejor por puntero (`const` si
  no la modificas).
- Olvidar el `;` **después** de la llave de cierre de la `struct`.

## Resumen

- `struct` agrupa datos de distintos tipos bajo un nombre; se accede con `.`.
- `typedef` da un alias corto al tipo.
- Arreglos de structs para listas de registros.
- Con un **puntero** a struct, se usa `->` (equivale a `(*p).campo`) y permite **modificar** el
  original.
- `enum` para constantes con nombre; `union` (avanzado) comparte memoria.

## Ejemplos

- [`ejemplos/estudiante.c`](ejemplos/estudiante.c)
- [`ejemplos/puntero_struct.c`](ejemplos/puntero_struct.c)
- [`ejemplos/enumeracion.c`](ejemplos/enumeracion.c)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **K&R**, cap. 6 ("Structures").
- **King**, cap. 16 ("Structures, Unions, and Enumerations").
- **cppreference**, "struct", "union", "enum". https://en.cppreference.com/w/c/language/struct
