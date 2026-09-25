# Lección 02 — Variables, mutabilidad y tipos de datos

Un programa trabaja con **datos**: números, texto, valores verdadero/falso. En esta lección verás
cómo se guardan en **variables**, por qué en Rust las variables son **inmutables por defecto** y
qué **tipos** de datos básicos ofrece el lenguaje.

## Declarar variables con `let`

```rust
let edad = 20;
let nombre = "Ana";
let pi = 3.14159;
```

- **`let`** crea una variable (en Rust se suele decir *binding*: "ligar" un nombre a un valor).
- **No hace falta escribir el tipo**: el compilador lo **infiere** a partir del valor. `edad` es
  un entero, `nombre` un texto, `pi` un número con decimales. Pero el tipo **existe** y está
  **fijado** al compilar: Rust es de **tipado estático**, como C y Java (no como Python).
- Puedes escribir el tipo si quieres (o si el compilador no puede deducirlo) con una
  **anotación**:

```rust
let edad: i32 = 20;
let pi: f64 = 3.14159;
```

Compara:

| C | Java | Rust |
|---|---|---|
| `int edad = 20;` | `int edad = 20;` | `let edad: i32 = 20;` o simplemente `let edad = 20;` |

En Rust el tipo va **después** del nombre, separado por `:`.

## Inmutabilidad por defecto

Aquí está la primera gran diferencia con C, C++ y Java. En Rust, **una variable no puede cambiar
de valor** a menos que lo pidas explícitamente:

```rust
let x = 5;
println!("x = {x}");
x = 6;            // ERROR
```

```
error[E0384]: cannot assign twice to immutable variable `x`
 --> m1.rs:4:5
  |
2 |     let x = 5;
  |         - first assignment to `x`
3 |     println!("x = {x}");
4 |     x = 6;
  |     ^^^^^ cannot assign twice to immutable variable
  |
help: consider making this binding mutable
  |
2 |     let mut x = 5;
  |         +++
```

Para poder modificarla, se declara con **`mut`**:

```rust
let mut x = 5;
println!("x = {x}");   // x = 5
x = 6;
println!("x = {x}");   // x = 6
```

### ¿Por qué inmutable por defecto?

1. **Menos errores.** Si un valor no debería cambiar, el compilador **garantiza** que no cambie.
   En C, cualquier función a la que le pases un puntero podría modificar tu variable sin que lo
   notes.
2. **Código más fácil de leer.** Al ver `let total = ...` sabes que `total` tendrá **ese** valor
   hasta el final. Si ves `let mut`, sabes que debes prestar atención: ese valor va a cambiar.
3. **Concurrencia segura.** Los datos inmutables se pueden compartir entre hilos sin riesgo (lo
   verás en la lección 19).

Es lo contrario de C/Java, donde todo es mutable y hay que pedir la inmutabilidad (`const` en C,
`final` en Java). En Rust, **la opción segura es la predeterminada**.

> El compilador también te **avisa** si pones `mut` sin necesidad (`warning: variable does not need
> to be mutable`). Usa `mut` solo cuando de verdad vayas a modificar la variable.

## *Shadowing* (sombreado)

Puedes declarar una **nueva** variable con el **mismo nombre** que una anterior. La nueva
"sombrea" (oculta) a la vieja:

```rust
let x = 5;
let x = x + 1;        // nueva x = 6 (la vieja x ya no es accesible)
{
    let x = x * 2;    // dentro de este bloque, x = 12
    println!("x en el bloque: {x}");   // 12
}
println!("x fuera: {x}");               // 6
```

¿En qué se diferencia de `mut`?

- Con *shadowing* se crea una variable **nueva** con `let`; la variable sigue siendo inmutable
  después de cada transformación.
- **Puede cambiar de tipo**, algo que `mut` no permite:

```rust
let espacios = "   ";          // &str (texto)
let espacios = espacios.len(); // usize (numero): 3
```

```rust
let mut espacios = "   ";
espacios = espacios.len();     // ERROR: mismatched types (expected `&str`, found `usize`)
```

El *shadowing* es muy común en Rust para **transformar** un valor paso a paso sin inventar nombres
como `texto_entrada`, `texto_limpio`, `texto_numero`. Lo usarás mucho en la lección 03 al leer del
teclado (leer texto → quitar espacios → convertir a número).

## Constantes: `const`

```rust
const MAX_ALUMNOS: u32 = 30;
const PI: f64 = 3.141_592_653_589_793;
const SEGUNDOS_POR_HORA: u32 = 60 * 60;
```

Diferencias con `let`:

- Son **siempre** inmutables (no admiten `mut`).
- El **tipo es obligatorio**.
- Su valor debe poder **calcularse al compilar** (`60 * 60` sí; leer del teclado no).
- Se pueden declarar **fuera de cualquier función** (a nivel global) y usarse en todo el archivo.
- Por convención se escriben en **`MAYUSCULAS_CON_GUIONES`**.

Úsalas para valores **fijos con significado**: en lugar de escribir `30` suelto por el código
(un "número mágico"), escribe `MAX_ALUMNOS`.

> También existe `static`, parecido a `const` pero con una dirección de memoria fija durante todo
> el programa. Para empezar, usa siempre `const`.

## Tipos escalares

Un tipo **escalar** representa **un solo valor**. Rust tiene cuatro familias: enteros, flotantes,
booleanos y caracteres.

### Enteros

El nombre indica si tiene **signo** (`i`, admite negativos) o **no** (`u`, *unsigned*, solo 0 y
positivos) y **cuántos bits** ocupa:

| Bits | Con signo | Rango | Sin signo | Rango |
|---|---|---|---|---|
| 8 | `i8` | −128 … 127 | `u8` | 0 … 255 |
| 16 | `i16` | −32 768 … 32 767 | `u16` | 0 … 65 535 |
| 32 | **`i32`** | −2 147 483 648 … 2 147 483 647 | `u32` | 0 … 4 294 967 295 |
| 64 | `i64` | ≈ −9,2·10¹⁸ … 9,2·10¹⁸ | `u64` | 0 … ≈ 1,8·10¹⁹ |
| 128 | `i128` | ≈ ±1,7·10³⁸ | `u128` | 0 … ≈ 3,4·10³⁸ |
| arquitectura | `isize` | depende (64 bits en PC modernos) | **`usize`** | depende |

- **`i32`** es el tipo por **defecto** si no dices otra cosa (`let x = 5;` → `i32`).
- **`usize`** es el tipo de los **índices** y **tamaños** (`len()` devuelve `usize`, y los arreglos
  se indexan con `usize`). Es "del tamaño de un puntero" de la máquina.
- `u8` se usa mucho para **bytes** (datos binarios, archivos, red).

A diferencia de C, donde `int` puede medir 16 o 32 bits según la plataforma, en Rust el tamaño de
cada tipo **está en su nombre** y es **igual en todas las plataformas** (salvo `isize`/`usize`).

Cada tipo conoce sus límites:

```rust
println!("{} .. {}", i8::MIN, i8::MAX);     // -128 .. 127
println!("{}", u32::MAX);                   // 4294967295
```

**Literales enteros:**

| Forma | Ejemplo | Valor |
|---|---|---|
| Decimal (con separador `_`) | `1_000_000` | 1000000 |
| Hexadecimal | `0xff` | 255 |
| Octal | `0o77` | 63 |
| Binario | `0b1111_0000` | 240 |
| Byte (solo `u8`) | `b'A'` | 65 |
| Con sufijo de tipo | `42u8`, `7i64`, `100_usize` | 42 (u8), 7 (i64), 100 (usize) |

El `_` se ignora: solo sirve para leer mejor los números grandes (como los puntos de miles).

### Flotantes (números con decimales)

- **`f64`**: 64 bits, doble precisión (~15–16 dígitos). **Es el tipo por defecto** (`let x = 2.5;`
  → `f64`). Equivale a `double` en C/Java.
- **`f32`**: 32 bits, precisión simple (~7 dígitos). Equivale a `float`.

Siguen el estándar **IEEE-754**, así que tienen las mismas "rarezas" que en cualquier lenguaje:

```rust
println!("{}", 0.1 + 0.2);   // 0.30000000000000004
```

Por eso **nunca** se comparan flotantes con `==` en cálculos reales; se comprueba si la diferencia
es muy pequeña: `(a - b).abs() < 1e-9`.

### Booleanos

```rust
let activo: bool = true;
let terminado = false;
```

- Ocupan 1 byte y solo valen `true` o `false`.
- **No son números.** En C, `if (1)` es válido porque cualquier entero distinto de 0 es
  "verdadero". En Rust, la condición de un `if` **debe** ser `bool`:

```rust
let n = 1;
if n { println!("si"); }   // ERROR
```
```
error[E0308]: mismatched types
 --> m5.rs:3:8
  |
3 |     if n { println!("si"); }
  |        ^ expected `bool`, found integer
```

Hay que escribir la comparación explícita: `if n != 0 { ... }`. Esto evita errores clásicos de C
como `if (x = 5)` (asignar en vez de comparar).

### Caracteres (`char`)

```rust
let letra = 'a';
let enie = 'ñ';
let omega = 'Ω';
let corazon = '♥';
```

- Van entre **comillas simples**.
- Un `char` de Rust ocupa **4 bytes** y representa **cualquier carácter Unicode** (letras de
  cualquier idioma, símbolos, emojis). En C, `char` es **1 byte** y solo cubre ASCII; en Java,
  `char` es de 2 bytes (UTF-16).
- El texto (`String`, `&str`) **no** es un arreglo de `char`: se guarda en **UTF-8**. Lo verás en
  la lección 11.

### Tamaño en memoria

Puedes consultarlo con `std::mem::size_of`:

```rust
println!("{}", std::mem::size_of::<i32>());    // 4
println!("{}", std::mem::size_of::<char>());   // 4
println!("{}", std::mem::size_of::<bool>());   // 1
```

## Tipos compuestos

Agrupan **varios valores** en uno.

### Tuplas

Una **tupla** agrupa un número **fijo** de valores de **tipos posiblemente distintos**:

```rust
let persona: (&str, i32, f64) = ("Ana", 20, 1.65);

// acceso por posicion con .0, .1, .2 ...
println!("{} tiene {} anios", persona.0, persona.1);

// desestructurar: extraer todos los valores de una vez
let (nombre, edad, altura) = persona;
println!("{nombre} mide {altura} m");
```

- Su tamaño no puede cambiar después de creada.
- Son útiles para devolver **varios valores** desde una función (lección 06).
- La tupla vacía **`()`** se llama **unit** ("unidad"). Es el "valor" de algo que no devuelve nada
  (como `void` en C/Java). Aparecerá mucho.

### Arreglos (*arrays*)

Un **arreglo** agrupa un número **fijo** de valores del **mismo tipo**:

```rust
let notas: [i32; 5] = [15, 18, 12, 20, 16];   // tipo: [tipo_elemento; cantidad]
let ceros = [0; 10];                          // 10 elementos, todos 0
let dias = ["lun", "mar", "mie", "jue", "vie"];

println!("{}", notas[0]);      // 15  (los indices empiezan en 0)
println!("{}", notas.len());   // 5
```

- El tamaño es **parte del tipo**: `[i32; 5]` y `[i32; 6]` son tipos **distintos**.
- Viven en la **pila** (*stack*), como los arreglos locales de C.
- Para una lista que **crece o decrece**, se usa `Vec<T>` (lección 11), el equivalente al
  `ArrayList` de Java o al `vector` de C++.
- Para modificar un elemento, el arreglo debe ser `mut`: `let mut a = [0; 3]; a[1] = 7;`

#### Acceso fuera de rango: la diferencia con C

En C, `a[10]` en un arreglo de 3 elementos **compila y se ejecuta**, leyendo memoria que no te
pertenece (**comportamiento indefinido**: puede devolver basura, romper el programa o abrir una
vulnerabilidad). En Rust eso **nunca** ocurre:

- Si el índice es una **constante** conocida al compilar, **no compila**:

```
error: this operation will panic at runtime
 --> m3.rs:3:20
  |
3 |     println!("{}", a[5]);
  |                    ^^^^ index out of bounds: the length is 3 but the index is 5
```

- Si el índice se calcula al ejecutar, Rust **comprueba** el límite y, si está fuera, **detiene
  el programa de forma controlada** (un ***panic***) en lugar de leer memoria ajena:

```
thread 'main' (1180) panicked at m4.rs:4:20:
index out of bounds: the len is 3 but the index is 5
note: run with `RUST_BACKTRACE=1` environment variable to display a backtrace
```

(El número entre paréntesis identifica al hilo y cambia en cada ejecución.) Un *panic* es un
error, sí, pero un error **seguro y con mensaje claro**, no una corrupción silenciosa de memoria.
Esta comprobación tiene un coste mínimo y el compilador la elimina cuando puede demostrar que el
índice es válido (por ejemplo, al recorrer con `for`).

## Variables sin inicializar

En C, una variable local sin inicializar contiene **basura**. En Rust, usarla es un **error de
compilación**:

```rust
let x: i32;
println!("{}", x);   // ERROR
```
```
error[E0381]: used binding `x` isn't initialized
...
help: consider assigning a value
  |
2 |     let x: i32 = 42;
```

Sí puedes declarar primero y asignar después, siempre que el compilador vea que **todos** los
caminos asignan un valor antes de usarla.

## Variables sin usar

Si declaras una variable y no la usas, el compilador avisa (`warning: unused variable`). Si es
intencional, empieza su nombre con `_`: `let _temporal = 5;`

## Conversión entre tipos

Rust **no convierte tipos automáticamente**, ni siquiera entre enteros:

```rust
let a: i32 = 10;
let b: i64 = 20;
let c = a + b;             // ERROR: mismatched types (expected `i32`, found `i64`)
let c = a as i64 + b;      // correcto: conversion explicita con `as`
```

Parece incómodo al principio, pero elimina toda una clase de errores silenciosos (pérdidas de
precisión y desbordes). Verás `as` y sus reglas en la lección 04.

## Tabla de equivalencias

| Concepto | C | Java | Rust |
|---|---|---|---|
| Entero de 32 bits | `int` (normalmente) | `int` | `i32` |
| Entero de 64 bits | `long long` | `long` | `i64` |
| Byte sin signo | `unsigned char` | — (`byte` tiene signo) | `u8` |
| Tamaño / índice | `size_t` | `int` | `usize` |
| Doble precisión | `double` | `double` | `f64` |
| Booleano | `_Bool` / `int` | `boolean` | `bool` |
| Carácter | `char` (1 byte) | `char` (2 bytes) | `char` (4 bytes, Unicode) |
| Constante | `const int` / `#define` | `static final` | `const` |
| Variable mutable | por defecto | por defecto | `let mut` |
| Variable inmutable | `const` | `final` | por defecto (`let`) |

## Errores típicos

- Intentar modificar una variable sin `mut` → `E0384`.
- Mezclar tipos numéricos sin convertir (`i32 + i64`, `i32 + f64`) → `E0308 mismatched types`.
- Usar un entero como condición (`if n`) → `E0308`.
- Usar comillas dobles para un `char` (`let c: char = "a";`) → `E0308`: `"a"` es texto (`&str`),
  no un carácter.
- Olvidar que los índices empiezan en 0: el último elemento de un arreglo de 5 es `a[4]`.

## Resumen

- `let` crea variables **inmutables**; `let mut`, mutables. El tipo se **infiere**, o se anota con
  `: tipo`.
- El ***shadowing*** (`let x = x + 1;`) crea una variable nueva con el mismo nombre; puede cambiar
  de tipo.
- **`const`**: tipo obligatorio, valor conocido al compilar, nombre en mayúsculas.
- Escalares: enteros (`i8`…`i128`, `u8`…`u128`, `isize`, `usize`; por defecto `i32`), flotantes
  (`f64` por defecto, `f32`), `bool`, `char` (Unicode, 4 bytes).
- Compuestos: **tuplas** `(a, b, c)` (tipos distintos, acceso `.0`) y **arreglos** `[T; N]` (mismo
  tipo, tamaño fijo, acceso `[i]` con comprobación de límites).
- Sin conversiones implícitas ni variables sin inicializar: **el compilador te protege**.

## Ejemplos

- [`ejemplos/variables.rs`](ejemplos/variables.rs) — `let`, `mut`, *shadowing*, `const`.
- [`ejemplos/tipos_escalares.rs`](ejemplos/tipos_escalares.rs) — enteros, límites, literales,
  flotantes, `bool`, `char`, tamaños.
- [`ejemplos/compuestos.rs`](ejemplos/compuestos.rs) — tuplas y arreglos.

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- ***The Rust Programming Language***, 3.1 "Variables and Mutability" y 3.2 "Data Types".
  https://doc.rust-lang.org/book/ch03-01-variables-and-mutability.html
- ***Rust by Example***, "Primitives" y "Variable Bindings".
  https://doc.rust-lang.org/rust-by-example/primitives.html
- ***Programming Rust*** (2.ª ed.), cap. 3 "Fundamental Types" (representación en memoria de cada
  tipo, con diagramas).
- **Documentación de `i32`** (todos los métodos de un entero):
  https://doc.rust-lang.org/std/primitive.i32.html
