# Lección 06 — Funciones

Las **funciones** permiten dividir un programa en piezas con nombre, reutilizables y fáciles de
probar. Ya conoces una: `main`. En esta lección aprenderás a escribir las tuyas, cómo reciben
datos (**parámetros**), cómo devuelven resultados (**retorno**) y cómo documentarlas. Verás también
la **recursión**.

Esta lección cierra el Bloque I. A partir de la siguiente entraremos en lo que hace único a Rust:
el *ownership*, que se entiende justamente viendo qué pasa con los valores al **pasarlos a
funciones**.

## Definir y llamar a una función

```rust
fn saludar() {
    println!("Hola!");
}

fn main() {
    saludar();     // llamada
    saludar();
}
```

- Se define con **`fn`**, el nombre en **`snake_case`**, paréntesis y un cuerpo entre llaves.
- **El orden no importa**: puedes llamar a una función definida **más abajo** en el archivo. En C
  necesitarías declarar antes su prototipo; en Rust, el compilador lee todo el archivo primero.

## Parámetros

```rust
fn saludar_a(nombre: &str, veces: u32) {
    for _ in 0..veces {
        println!("Hola, {nombre}!");
    }
}

fn main() {
    saludar_a("Ana", 2);
}
```

- Cada parámetro se declara como `nombre: tipo`. **El tipo es obligatorio**, aunque dentro de las
  funciones Rust infiera casi todo:

  ```
  error: expected one of `:`, `@`, or `|`, found `)`
    |
  1 | fn doble(x) -> i32 {
    |           ^ expected one of `:`, `@`, or `|`
    |
  help: if this is a parameter name, give it a type
  ```

  Es una decisión de diseño: la **firma** de una función (sus parámetros y su retorno) es un
  **contrato** que debe poder leerse sin mirar su interior. Además, así los errores de tipo se
  detectan en la función que los causa y no en otra parte del programa.

- Al llamar, hay que pasar **exactamente** los argumentos indicados, en orden y del tipo correcto:

  ```
  error[E0061]: this function takes 2 arguments but 1 argument was supplied
    |
  5 |     println!("{}", suma(4));
    |                    ^^^^--- argument #2 of type `i32` is missing
  ```

- El `_` de `for _ in 0..veces` indica que no necesitamos la variable del bucle.

> **Sin sobrecarga ni valores por defecto.** En Rust no puedes tener dos funciones con el mismo
> nombre y distintos parámetros (como en Java o C++), ni parámetros con valor por defecto. Se usan
> nombres distintos (`area_circulo`, `area_rectangulo`), o tipos como `Option` (lección 10). Esto
> hace que cada llamada sea inequívoca.

## Valor de retorno

```rust
fn doble(x: i32) -> i32 {
    x * 2
}
```

- El tipo de retorno se indica después de **`->`**.
- La función **devuelve el valor de su última expresión** (sin `;`). Es exactamente la regla de
  los bloques de la lección 04: el cuerpo de una función es un bloque.
- Si pones `;` al final, esa línea se convierte en sentencia, la función "devuelve" `()` y el
  compilador lo detecta:

  ```
  error[E0308]: mismatched types
   --> f1.rs:1:21
    |
  1 | fn doble(x: i32) -> i32 {
    |    -----            ^^^ expected `i32`, found `()`
    |    |
    |    implicitly returns `()` as its body has no tail or `return` expression
  2 |     x * 2;
    |          - help: remove this semicolon to return this value
  ```

### `return` para salir antes

`return` existe y sirve para **salir antes de tiempo** (típicamente en casos especiales al
principio de la función):

```rust
fn dividir(a: f64, b: f64) -> f64 {
    if b == 0.0 {
        return 0.0;          // caso especial: salir ya
    }
    a / b                    // caso normal: ultima expresion
}
```

El **estilo idiomático** es: `return` solo para salidas anticipadas; el resultado "normal" como
última expresión, sin `return`. (Escribir `return a / b;` al final funciona, pero no es el estilo
de Rust.)

### Funciones sin retorno

Si no hay `->`, la función devuelve `()` (*unit*), el equivalente a `void` en C y Java:

```rust
fn mostrar(x: i32) {          // equivale a: fn mostrar(x: i32) -> ()
    println!("{x}");
}
```

### Devolver varios valores: tuplas

Una función devuelve **un** valor, pero ese valor puede ser una **tupla**:

```rust
fn min_max(a: [i32; 5]) -> (i32, i32) {
    let mut min = a[0];
    let mut max = a[0];
    for x in a {
        if x < min { min = x; }
        if x > max { max = x; }
    }
    (min, max)
}

let (menor, mayor) = min_max([4, 9, 1, 7, 3]);   // desestructurar
```

En C tendrías que usar punteros de salida (`void min_max(int a[], int *min, int *max)`); en Java,
crear una clase o devolver un arreglo.

## ¿Cómo se pasan los argumentos?

Para los tipos que has visto hasta ahora (enteros, flotantes, `bool`, `char`, y tuplas y arreglos de
ellos), el argumento se **copia**. La función trabaja con su propia copia:

```rust
fn incrementar(mut x: i32) {   // `mut` en el parametro: la copia local puede cambiar
    x += 1;
    println!("dentro: {x}");   // 6
}

fn main() {
    let n = 5;
    incrementar(n);
    println!("fuera: {n}");    // 5  (n no cambio)
}
```

Igual que en C y Java con los tipos primitivos. Pero **no todos los tipos se copian**. Con un
`String` (texto que vive en el *heap*), pasar el valor a una función **transfiere su propiedad**:
después de la llamada, **ya no puedes usarlo**. Este comportamiento, que no existe en ningún otro
lenguaje popular, es el tema de la **lección 07**.

¿Y si queremos que la función **modifique** una variable de quien la llama? Se le pasa una
**referencia mutable** (`&mut`), como un puntero de C pero verificado por el compilador. Es el tema
de la **lección 08**. Adelanto:

```rust
fn incrementar(x: &mut i32) {  // recibe una referencia mutable
    *x += 1;                   // *x = "el valor al que apunta x"
}

let mut n = 5;
incrementar(&mut n);           // prestamos n de forma mutable
println!("{n}");               // 6
```

## Recursión

Una función **recursiva** se llama a sí misma. Necesita un **caso base** (que no se llama a sí
mismo) y un **caso recursivo** que se acerque al caso base:

```rust
fn factorial(n: u64) -> u64 {
    if n <= 1 {
        1                          // caso base
    } else {
        n * factorial(n - 1)       // caso recursivo
    }
}
```

Observa que, como `if` es una expresión, el cuerpo entero es una sola expresión: se lee casi como
la definición matemática (n! = 1 si n ≤ 1; n · (n−1)! en otro caso).

Si olvidas el caso base, el compilador a menudo te avisa:

```
warning: function cannot return without recursing
  = help: a `loop` may express intention better if this is on purpose
```

y si ejecutas el programa, cada llamada ocupa espacio en la **pila** hasta agotarla:

```
thread 'main' (14868) has overflowed its stack
fatal runtime error: stack overflow, aborting
```

A diferencia de C (donde un desbordamiento de pila puede corromper memoria), Rust lo detecta y
aborta de forma segura.

> **Recursión vs. bucles.** Rust **no garantiza** la optimización de llamadas en cola (*tail call
> optimization*). Para recursiones muy profundas (miles o millones de niveles), usa un bucle. La
> recursión brilla en problemas naturalmente recursivos: árboles, divide y vencerás, Torres de
> Hanói, recorrer estructuras anidadas.

## Funciones que nunca regresan: `-> !`

Algunas funciones **nunca** devuelven el control: terminan el programa o se quedan en un bucle
infinito. Su tipo de retorno es **`!`** (el tipo "nunca", *never*):

```rust
fn error_fatal(mensaje: &str) -> ! {
    eprintln!("ERROR: {mensaje}");
    std::process::exit(1);         // termina el programa con codigo 1
}
```

Como `!` "encaja" en cualquier tipo, una llamada así puede usarse en cualquier rama:
`let x: i32 = if ok { 5 } else { error_fatal("...") };`. Las macros `panic!`, `unreachable!` y
`todo!` también tienen tipo `!`. Por eso pudiste escribir `_ => unreachable!()` en un `match` que
devolvía `&str` en la lección 05.

## Documentar funciones: `///`

Los comentarios con **tres barras** son **comentarios de documentación**: se escriben en
**Markdown** y describen el elemento que tienen **debajo**:

```rust
/// Convierte una temperatura de grados Celsius a Fahrenheit.
///
/// # Ejemplos
///
/// ```
/// let f = celsius_a_fahrenheit(100.0);
/// assert_eq!(f, 212.0);
/// ```
fn celsius_a_fahrenheit(c: f64) -> f64 {
    c * 9.0 / 5.0 + 32.0
}
```

- `cargo doc --open` genera con ellos una página web de documentación, con el mismo aspecto que la
  documentación oficial de la biblioteca estándar (https://doc.rust-lang.org/std/).
- Las secciones habituales son `# Ejemplos`, `# Panics` (cuándo puede detener el programa) y
  `# Errors` (qué errores devuelve).
- Los ejemplos de código dentro de la documentación **se ejecutan como pruebas** con `cargo test`
  (lección 17): la documentación nunca queda desactualizada sin que te enteres.
- `//!` documenta el elemento que **contiene** al comentario (el archivo o módulo completo).

## Organizar un programa en funciones

Una buena práctica, en cualquier lenguaje: **`main` coordina, las funciones hacen el trabajo**.

```rust
fn main() {
    let datos = leer_datos();
    let resultado = procesar(datos);
    mostrar(resultado);
}
```

Pautas:

- Cada función hace **una sola cosa**, y su nombre dice cuál (`calcular_promedio`, `es_primo`,
  `leer_entero`).
- Si una función no cabe en la pantalla, probablemente haga demasiadas cosas.
- Prefiere funciones que **reciben datos y devuelven resultados** a funciones que imprimen: son más
  fáciles de reutilizar y de probar.
- Rust **desalienta las variables globales mutables**: una `static mut` solo puede usarse dentro de
  un bloque `unsafe` (fuera del alcance de este curso), y las alternativas seguras (tipos atómicos,
  `Mutex`) son deliberadamente más verbosas. Lo idiomático es pasar los datos como parámetros; así
  queda explícito qué usa cada función.

## Comparación con C y Java

| | C | Java | Rust |
|---|---|---|---|
| Definición | `int suma(int a, int b)` | `static int suma(int a, int b)` | `fn suma(a: i32, b: i32) -> i32` |
| Retorno | `return a + b;` | `return a + b;` | `a + b` (última expresión) |
| Sin retorno | `void` | `void` | sin `->` (devuelve `()`) |
| Varios resultados | punteros de salida | objeto o arreglo | tupla |
| Declarar antes de usar | sí (prototipos) | no | no |
| Sobrecarga | no | sí | no |
| Parámetros por defecto | no | no | no |

## Errores típicos

- Olvidar el tipo de un parámetro.
- Poner `;` después de la expresión que se quiere devolver → la función devuelve `()` (`E0308`).
- Olvidar `-> Tipo` cuando la función sí devuelve algo (el compilador dirá que esperaba `()`).
- Número o tipo incorrecto de argumentos al llamar (`E0061`, `E0308`).
- Recursión sin caso base → desbordamiento de pila.

## Resumen

- `fn nombre(param: Tipo, ...) -> TipoRetorno { cuerpo }`. Tipos de parámetros obligatorios.
- Se devuelve la **última expresión** sin `;`; `return` para salir antes.
- Sin `->`, se devuelve `()`. Con `-> !`, la función nunca regresa.
- Varios valores → **tupla**.
- Los tipos simples se pasan **por copia**. Otros tipos (como `String`) **mueven su propiedad**
  (lección 07) o se pasan por **referencia** (lección 08).
- Recursión: caso base + caso recursivo; cuidado con la profundidad.
- Documenta con `///` (Markdown, con ejemplos que se prueban solos).

## Ejemplos

- [`ejemplos/funciones_basicas.rs`](ejemplos/funciones_basicas.rs) — parámetros, retorno, `return`
  temprano, tuplas.
- [`ejemplos/paso_por_valor.rs`](ejemplos/paso_por_valor.rs) — copia de argumentos y adelanto de
  `&mut`.
- [`ejemplos/recursion.rs`](ejemplos/recursion.rs) — factorial, Fibonacci, MCD, potencia rápida.
- [`ejemplos/conversor_documentado.rs`](ejemplos/conversor_documentado.rs) — un programa organizado
  en funciones documentadas.

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- ***The Rust Programming Language***, 3.3 "Functions" y 3.4 "Comments".
  https://doc.rust-lang.org/book/ch03-03-how-functions-work.html
- ***Rust by Example***, "Functions". https://doc.rust-lang.org/rust-by-example/fn.html
- ***The rustdoc book***, "How to write documentation".
  https://doc.rust-lang.org/rustdoc/how-to-write-documentation.html
- ***Programming Rust*** (2.ª ed.), cap. 6 "Expressions" (funciones y `!`).
