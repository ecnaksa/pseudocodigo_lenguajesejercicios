# Lección 02 — Variables, tipos de datos y constantes

## Qué es una variable

Una **variable** es un espacio con nombre que guarda un valor. En Java, como es **fuertemente
tipado**, debes declarar el **tipo** antes de usarla:

```java
int edad;          // declaracion
edad = 25;         // asignacion
int altura = 170;  // declaracion + inicializacion en una linea
```

Si intentas usar una variable local **sin inicializar**, Java **no** compila (a diferencia de C,
que te dejaba con basura). Es una red de seguridad.

## Los tipos primitivos

Java tiene **8 tipos primitivos**, que guardan valores simples directamente. Los que más usarás:

| Tipo | Guarda | Tamaño | Ejemplo | Rango aprox. |
|---|---|---|---|---|
| `int` | enteros | 32 bits | `42` | ±2.1 mil millones |
| `long` | enteros grandes | 64 bits | `9000000000L` | muy grande |
| `double` | reales (doble precisión) | 64 bits | `3.14` | decimales |
| `float` | reales (simple) | 32 bits | `3.14f` | menos preciso |
| `boolean` | verdadero/falso | — | `true`, `false` | — |
| `char` | un carácter | 16 bits | `'A'` | Unicode |
| `byte` | enteros pequeños | 8 bits | `100` | -128 a 127 |
| `short` | enteros medianos | 16 bits | `1000` | -32768 a 32767 |

```java
int cantidad = 5;
double precio = 2.50;
boolean activo = true;
char inicial = 'C';
long distancia = 9000000000L;   // la L marca que es long
float temperatura = 36.6f;      // la f marca que es float
```

> **Sufijos:** los literales enteros son `int` por defecto (usa `L` para `long`); los decimales
> son `double` por defecto (usa `f` para `float`).

### `boolean` de verdad

A diferencia de C, en Java `boolean` es un tipo aparte: **no** es un número. `true` no es `1` ni
`false` es `0`. Una condición **debe** ser `boolean` (`if (x)` con `x` entero no compila).

### `char` guarda un carácter Unicode

```java
char c = 'A';
System.out.println(c);        // A
System.out.println((int) c);  // 65  (su codigo Unicode)
```

## Tipos primitivos vs. tipos de referencia

Java divide sus tipos en dos grandes grupos:

- **Primitivos** (los 8 de arriba): guardan el valor **directamente**. Empiezan en minúscula
  (`int`, `double`...).
- **De referencia** (objetos): guardan una **referencia** a un objeto. Empiezan en mayúscula
  (`String`, `Scanner`, tus clases...).

**`String`** es el tipo de referencia más común: guarda texto. Aunque no es primitivo, se usa casi
como si lo fuera:

```java
String nombre = "Ana";
System.out.println("Hola, " + nombre);   // concatenacion con +
```
Veremos `String` a fondo en la lección 09.

### Clases envoltura (wrappers)

Cada primitivo tiene una **clase envoltura** (`Integer`, `Double`, `Boolean`, `Character`...) que lo
representa como objeto. Son necesarias, por ejemplo, para las **colecciones** (lección 14), que
solo guardan objetos. Java convierte entre ambos automáticamente (*autoboxing*):

```java
Integer numeroObjeto = 42;   // int -> Integer (autoboxing)
int numero = numeroObjeto;   // Integer -> int (unboxing)
```
Por ahora, usa los primitivos; los wrappers aparecerán más adelante.

## Nombres de variables (identificadores)

- Letras, dígitos, `_` y `$`, pero **no** empiezan con dígito.
- **Distinguen mayúsculas**: `edad` ≠ `Edad`.
- No pueden ser palabras reservadas (`int`, `class`, `if`...).
- **Convención de Java:** `camelCase` para variables y métodos (`precioTotal`), `PascalCase` para
  clases (`CuentaBancaria`), `MAYUSCULAS` para constantes (`MAX_INTENTOS`).

## Constantes con `final`

`final` marca una variable como **constante**: solo se le puede asignar valor **una vez**.

```java
final double PI = 3.14159;
final int MAX_INTENTOS = 3;
// PI = 4;   // ERROR de compilacion: no se puede reasignar una final
```
Por convención, las constantes se escriben en `MAYUSCULAS_CON_GUION`.

## `var`: inferencia de tipo (Java 10+)

Para variables **locales**, puedes usar `var` y dejar que Java **deduzca** el tipo del valor:

```java
var x = 5;              // Java infiere int
var pi = 3.14;          // double
var nombre = "Ana";     // String
```
`var` es azúcar de comodidad; el tipo **sigue siendo fijo** (Java lo deduce en compilación). Úsalo
cuando el tipo sea obvio; usa el tipo explícito cuando aporte claridad. **No** sirve para atributos
de clase ni parámetros, solo variables locales.

## Conversión de tipos (casting)

Java convierte automáticamente de un tipo "pequeño" a uno "grande" (**widening**, sin pérdida):

```java
int i = 10;
double d = i;      // int -> double automatico (10.0)
```

Pero de "grande" a "pequeño" (**narrowing**, con posible pérdida) debes hacer un **casting**
explícito:

```java
double precio = 9.99;
int entero = (int) precio;   // 9  (se trunca la parte decimal)
```

### La división entera (igual que en C)

Si divides dos enteros, el resultado es entero:

```java
int a = 7, b = 2;
System.out.println(a / b);            // 3  (division entera)
System.out.println((double) a / b);   // 3.5  (uno es double -> division real)
```

## Desbordamiento (overflow)

Un `int` tiene un rango limitado; superarlo "da la vuelta" a valores erróneos. Para números muy
grandes usa `long`. (`Integer.MAX_VALUE` te da el mayor `int`.)

## Errores típicos

- Usar una variable local **sin inicializar** → no compila.
- **División entera** inesperada (`1/2` da `0`).
- Confundir `=` (asignar) con `==` (comparar).
- Olvidar la `L` en un `long` grande o la `f` en un `float`.
- Intentar reasignar una variable `final`.

## Resumen

- Declara con `tipo nombre;` e inicializa antes de usar (Java lo exige).
- **8 primitivos** (`int`, `double`, `boolean`, `char`...); `String` es de **referencia**.
- `final` para constantes; `var` para inferir el tipo de variables locales.
- Conversión automática (widening) o con `(tipo)` (narrowing); cuidado con la división entera.
- Convención: `camelCase` variables, `PascalCase` clases, `MAYUSCULAS` constantes.

## Ejemplos

- [`ejemplos/TiposBasicos.java`](ejemplos/TiposBasicos.java)
- [`ejemplos/Casting.java`](ejemplos/Casting.java)
- [`ejemplos/Constantes.java`](ejemplos/Constantes.java)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **The Java Tutorials (Oracle)**, "Language Basics" → "Variables" y "Primitive Data Types".
  https://docs.oracle.com/javase/tutorial/java/nutsandbolts/datatypes.html
- **Baeldung**, "Java Primitives". https://www.baeldung.com/java-primitives
