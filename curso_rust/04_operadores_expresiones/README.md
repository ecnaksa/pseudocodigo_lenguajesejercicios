# Lección 04 — Operadores, conversiones y expresiones

Esta lección tiene dos partes. La primera es conocida si vienes de otro lenguaje: los
**operadores** (con algunas diferencias importantes en Rust: no hay `++`, no hay conversiones
automáticas, y el desbordamiento está controlado). La segunda es **fundamental** para entender
Rust: la diferencia entre **expresiones** y **sentencias**. De ella dependen el `if` de la lección
05 y el retorno de las funciones de la lección 06.

## Parte 1 — Operadores

### Aritméticos

| Operador | Significado | Ejemplo | Resultado |
|---|---|---|---|
| `+` | Suma | `7 + 2` | `9` |
| `-` | Resta (y negación unaria) | `7 - 2`, `-x` | `5` |
| `*` | Multiplicación | `7 * 2` | `14` |
| `/` | División | `7 / 2` · `7.0 / 2.0` | `3` · `3.5` |
| `%` | Resto (módulo) | `7 % 2` | `1` |

**División entera.** Entre enteros, `/` descarta los decimales **truncando hacia cero**, igual
que en C y Java:

```rust
println!("{}", 7 / 2);      // 3
println!("{}", -7 / 2);     // -3  (no -4: trunca hacia cero)
println!("{}", -7 % 2);     // -1  (el resto lleva el signo del dividendo)
```

Si necesitas la división "matemática" (resto siempre no negativo, útil para ciclos como días de la
semana u horas del reloj), usa `div_euclid` y `rem_euclid`:

```rust
println!("{}", (-7i32).div_euclid(2));   // -4
println!("{}", (-7i32).rem_euclid(2));   // 1
```

**No se mezclan tipos.** Los dos operandos deben ser del **mismo tipo**:

```rust
let a: i32 = 7;
let b: f64 = 2.0;
let c = a / b;             // ERROR: no implementation for `i32 / f64`
let c = a as f64 / b;      // 3.5
```

En C, `7 / 2.0` convierte el `7` a `double` sin decírtelo. Rust exige que **tú** decidas. Por eso
en las fórmulas con `f64` escribirás `9.0 / 5.0` en vez de `9 / 5`.

**División por cero:**

- Entre **enteros**: el programa se detiene con `panic` (`attempt to divide by zero`). Si el divisor
  es una constante `0`, directamente no compila.
- Entre **flotantes**: no hay error; sigue el estándar IEEE-754: `1.0 / 0.0` es `inf`
  (infinito) y `0.0 / 0.0` es `NaN` ("no es un número").

### No existen `++` ni `--`

```rust
x++;      // ERROR
```
```
error: Rust has no postfix increment operator
help: use `+= 1` instead
```

Se usa `x += 1;`. Rust los eliminó a propósito: en C, expresiones como `a[i] = i++` o `i = i++ + ++i`
tienen un orden de evaluación confuso o directamente indefinido.

### Asignación compuesta

`+=`, `-=`, `*=`, `/=`, `%=`, y también los de bits `&=`, `|=`, `^=`, `<<=`, `>>=`. La variable debe
ser `mut`:

```rust
let mut total = 10;
total += 5;    // 15
total *= 2;    // 30
total %= 7;    // 2
```

### Comparación

`==`, `!=`, `<`, `>`, `<=`, `>=`. Devuelven un `bool`. Ambos lados deben ser del **mismo tipo**
(`5 == 5.0` no compila).

> **Cuidado con los flotantes:** por el redondeo binario, `0.1 + 0.2 == 0.3` es `false`. Compara con
> una tolerancia: `(a - b).abs() < 1e-9`. Además, `NaN` no es igual a nada, **ni a sí mismo**
> (`f64::NAN == f64::NAN` es `false`); para detectarlo usa `x.is_nan()`.

### Lógicos

| Operador | Significado |
|---|---|
| `&&` | Y (verdadero si **ambos** lo son) |
| `\|\|` | O (verdadero si **alguno** lo es) |
| `!` | NO (invierte) |

Solo funcionan con `bool` (recuerda: en Rust los números **no** son booleanos). Son de
**cortocircuito**: en `a && b`, si `a` es `false`, `b` **ni se evalúa**; en `a || b`, si `a` es
`true`, tampoco. Esto permite escribir cosas como:

```rust
if divisor != 0 && total / divisor > 10 { ... }   // nunca divide entre cero
```

### De bits

| Operador | Significado | Ejemplo (`u8`) | Resultado |
|---|---|---|---|
| `&` | Y bit a bit | `0b1100 & 0b1010` | `0b1000` (8) |
| `\|` | O bit a bit | `0b1100 \| 0b1010` | `0b1110` (14) |
| `^` | O exclusivo (XOR) | `0b1100 ^ 0b1010` | `0b0110` (6) |
| `!` | Negación bit a bit | `!0u8` | `255` |
| `<<` | Desplazar a la izquierda | `1 << 3` | `8` |
| `>>` | Desplazar a la derecha | `16 >> 2` | `4` |

Observa que en Rust el NOT bit a bit es `!` (en C es `~`). Estos operadores son la base de la
programación de bajo nivel: registros de microcontroladores, protocolos, banderas (*flags*).

### Precedencia (de mayor a menor)

| Nivel | Operadores |
|---|---|
| 1 | Llamadas a métodos `x.metodo()`, acceso a campos, índices `a[i]`, `?` |
| 2 | Unarios: `-x`, `!x`, `*x`, `&x` |
| 3 | `as` |
| 4 | `*` `/` `%` |
| 5 | `+` `-` |
| 6 | `<<` `>>` |
| 7 | `&` · luego `^` · luego `\|` |
| 8 | `==` `!=` `<` `>` `<=` `>=` |
| 9 | `&&` · luego `\|\|` |
| 10 | Rangos `..` `..=` |
| 11 | Asignación `=` `+=` `-=` … |

Ante la duda, **usa paréntesis**: no cuestan nada y hacen el código más claro.

> **Trampa clásica:** la llamada a método tiene **más** precedencia que el menos unario.
> `-5i32.abs()` se lee como `-(5i32.abs())`, que es **`-5`**, no `5`. Escribe `(-5i32).abs()`.

## Parte 2 — Métodos de los números

En Rust, los números tienen **métodos** (funciones que se llaman con punto). No hace falta
`#include <math.h>` como en C ni `Math.` como en Java:

```rust
let x: f64 = 2.0;
x.sqrt()          // raiz cuadrada: 1.414...
x.powi(3)         // potencia con exponente entero: 8
x.powf(0.5)       // potencia con exponente real: 1.414...
(-3.7f64).abs()   // valor absoluto: 3.7
2.5f64.round()    // redondeo: 3 (los empates se alejan del cero: -2.5 -> -3)
2.7f64.floor()    // hacia abajo: 2
2.1f64.ceil()     // hacia arriba: 3
2.7f64.trunc()    // quita decimales: 2

let n: i32 = 2;
n.pow(10)         // 1024
7.min(3)          // 3
7.max(3)          // 7
15.clamp(0, 10)   // 10 (limita al rango)
(-8i32).signum()  // -1
```

Cuando el número es un literal, el compilador a veces necesita saber su tipo para encontrar el
método; se lo indicas con un sufijo: `2.0_f64.sqrt()`, `(-5i32).abs()`.

Constantes útiles: `std::f64::consts::PI`, `std::f64::consts::E`, `f64::INFINITY`, `f64::NAN`,
`i32::MAX`, etc.

## Parte 3 — Conversiones con `as`

`as` convierte entre tipos **primitivos**. Es explícito, pero **no comprueba nada**: si el valor no
cabe, lo transforma según unas reglas fijas. Conócelas:

| Conversión | Regla | Ejemplo | Resultado |
|---|---|---|---|
| Entero → entero más grande | Sin pérdida | `200u8 as i32` | `200` |
| Entero → entero más pequeño | Se **quedan los bits bajos** (el valor "da la vuelta") | `300i32 as u8` | `44` (300 − 256) |
| Con signo → sin signo | Se reinterpretan los bits | `-1i32 as u32` | `4294967295` |
| Flotante → entero | **Trunca** hacia cero | `3.99 as i32` | `3` |
| Flotante → entero (fuera de rango) | **Satura** al límite | `1e10 as i32` · `-1.5 as u8` | `2147483647` · `0` |
| `NaN` → entero | Da 0 | `f64::NAN as i32` | `0` |
| Entero → flotante | Al valor más cercano | `7 as f64` | `7.0` |
| `bool` → entero | `false`=0, `true`=1 | `true as i32` | `1` |
| `char` ↔ número | Código Unicode | `'A' as u8` · `65u8 as char` | `65` · `'A'` |

### Conversiones seguras: `from` y `try_from`

Si quieres que el compilador (o el programa) **compruebe** la conversión, usa:

- **`T::from(x)`** — solo existe cuando la conversión **nunca pierde información**
  (`i64::from(5i32)`, `f64::from(3u8)`). Si no puede perder nada, no puede fallar.
- **`T::try_from(x)`** — para conversiones que **pueden fallar**; devuelve un `Result`:

```rust
println!("{:?}", u8::try_from(200i32));   // Ok(200)
println!("{:?}", u8::try_from(300i32));   // Err(TryFromIntError(()))
```

Regla práctica: usa `as` cuando **sabes** que el valor cabe (o cuando quieres el truncamiento, como
`precio as i64`); usa `try_from` cuando el valor viene de fuera y podría no caber.

## Parte 4 — Desbordamiento de enteros (*overflow*)

¿Qué pasa si una operación produce un número que no cabe en el tipo? Por ejemplo, `250u8 + 10`
(el máximo de `u8` es 255).

- En **C**, con enteros con signo es **comportamiento indefinido**: el compilador puede hacer
  cualquier cosa. Con enteros sin signo, da la vuelta en silencio.
- En **Rust**:
  - Si los valores son **constantes**, **no compila**: `this arithmetic operation will overflow`.
  - En modo **debug** (el normal al desarrollar), el programa se detiene con un **panic**:
    ```
    thread 'main' (4075) panicked at op2.rs:4:13:
    attempt to add with overflow
    ```
  - En modo **release** (`-O` o `cargo build --release`), por rendimiento, **da la vuelta** en
    complemento a dos (250 + 10 = 4 en `u8`). Nunca es comportamiento indefinido.

Si tu programa **necesita** un comportamiento concreto ante el desbordamiento, dilo explícitamente
con estos métodos:

| Método | Comportamiento | `250u8.metodo(10)` |
|---|---|---|
| `checked_add` | Devuelve `None` si desborda, `Some(r)` si no | `None` |
| `wrapping_add` | Da la vuelta siempre | `4` |
| `saturating_add` | Se queda en el límite | `255` |
| `overflowing_add` | Da la vuelta **y** avisa si desbordó | `(4, true)` |

Existen igual para `sub`, `mul`, `div`, `pow`, etc. `checked_*` devuelve un `Option` (lección 10):
es la forma más segura.

## Parte 5 — Expresiones y sentencias (¡clave!)

Rust es un lenguaje **basado en expresiones**. Hay que distinguir:

- Una **expresión** se **evalúa y produce un valor**: `5`, `x + 1`, `a > b`, `x.sqrt()`, la llamada
  a una función, un bloque `{ ... }`, un `if`, un `match`.
- Una **sentencia** (*statement*) **realiza una acción y no produce valor**: `let x = 5;`, la
  definición de una función, o **cualquier expresión seguida de `;`**.

### `let` es una sentencia

En C puedes escribir `x = y = 6` porque la asignación devuelve un valor. En Rust, `let` no produce
valor, así que esto no compila:

```rust
let x = (let y = 6);
```
```
error: expected expression, found `let` statement
```

### Los bloques son expresiones

Un bloque `{ ... }` es una expresión cuyo valor es el de su **última expresión, escrita sin `;`**:

```rust
let y = {
    let x = 3;
    x + 1          // sin ; -> es el VALOR del bloque
};
println!("{y}");   // 4
```

Esto permite calcular un valor con variables auxiliares que **desaparecen** al cerrar el bloque
(`x` no existe fuera), sin ensuciar el resto del código.

### El `;` convierte una expresión en sentencia

Si pones `;` después de `x + 1`, esa línea pasa a ser una **sentencia**: se calcula `x + 1`, se
descarta el resultado, y el bloque ya no tiene expresión final. Un bloque sin expresión final vale
**`()`** (*unit*, la tupla vacía de la lección 02):

```rust
let y: i32 = {
    let x = 3;
    x + 1;        // <- con ;
};
```
```
error[E0308]: mismatched types
 --> op5.rs:2:18
  |
2 |       let y: i32 = {
  |  __________________^
3 | |         let x = 3;
4 | |         x + 1;
  | |              - help: remove this semicolon to return this value
5 | |     };
  | |_____^ expected `i32`, found `()`
```

El compilador te dice exactamente qué pasó: esperaba un `i32` y el bloque vale `()`, y te sugiere
quitar el `;`.

**Regla para recordar:** *el `;` "tira" el valor*. Lo que no lleva `;` al final de un bloque es lo
que el bloque devuelve.

### ¿Por qué importa tanto?

Porque todo Rust se apoya en esta idea:

- **`if` es una expresión** (lección 05): `let mayor = if a > b { a } else { b };` (esto sustituye
  al operador ternario `? :` de C y Java, que Rust no tiene).
- **Las funciones devuelven su última expresión** (lección 06): `fn doble(x: i32) -> i32 { x * 2 }`,
  sin escribir `return`.
- **`match` y `loop` también producen valores** (lecciones 05 y 10).

## Errores típicos

- Mezclar tipos numéricos (`i32 / f64`, `u8 + i32`) → convierte uno con `as` (o usa literales del
  tipo correcto: `2.0` en lugar de `2`).
- Esperar decimales de una división entera: `5 / 2` es `2`. Usa `5.0 / 2.0`.
- Escribir `x++` → usa `x += 1`.
- Olvidar que `as` **no avisa** si el valor no cabe (`300 as u8` es `44`).
- `-5i32.abs()` → `-5`. Usa paréntesis: `(-5i32).abs()`.
- Poner `;` después del valor final de un bloque → el bloque vale `()`.

## Resumen

- Aritmética: `/` entre enteros trunca hacia cero; `%` lleva el signo del dividendo;
  `rem_euclid` para el módulo matemático.
- **Sin conversiones implícitas** y **sin `++`/`--`**.
- Lógicos `&&`, `||`, `!` con cortocircuito, solo sobre `bool`. Bits: `&`, `|`, `^`, `!`, `<<`, `>>`.
- Los números tienen métodos: `sqrt`, `pow`, `abs`, `round`, `min`, `max`, `clamp`…
- `as` convierte sin comprobar (trunca, satura o da la vuelta); `from`/`try_from` convierten de forma
  segura.
- Desbordamiento: error al compilar si se puede detectar, *panic* en debug, vuelta en release; o
  elige con `checked_`/`wrapping_`/`saturating_`/`overflowing_`.
- **Expresión** = produce valor; **sentencia** = no. Un bloque vale su última expresión **sin
  `;`**.

## Ejemplos

- [`ejemplos/aritmetica.rs`](ejemplos/aritmetica.rs) — operadores, división, métodos numéricos,
  bits.
- [`ejemplos/conversiones.rs`](ejemplos/conversiones.rs) — `as`, `from`, `try_from`,
  desbordamiento.
- [`ejemplos/expresiones.rs`](ejemplos/expresiones.rs) — bloques como expresiones, el efecto del
  `;`.

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- ***The Rust Programming Language***, 3.2 "Data Types" (sección *Integer Overflow*) y 3.3
  "Functions" (sección *Statements and Expressions*).
  https://doc.rust-lang.org/book/ch03-03-how-functions-work.html
- ***Rust by Example***, "Expressions" y "Types → Casting".
  https://doc.rust-lang.org/rust-by-example/expression.html
- ***The Rust Reference***, "Operator expressions" (precedencia exacta y reglas de `as`).
  https://doc.rust-lang.org/reference/expressions/operator-expr.html
- ***Programming Rust*** (2.ª ed.), cap. 6 "Expressions".
