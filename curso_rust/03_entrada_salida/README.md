# Lección 03 — Entrada y salida

Un programa útil **se comunica**: muestra resultados (salida) y recibe datos del usuario
(entrada). En esta lección dominarás el **formato** de `println!` y aprenderás a **leer del
teclado** y **convertir** el texto leído en números.

## Parte 1 — Salida

### Las macros de impresión

| Macro | Qué hace | Destino |
|---|---|---|
| `print!` | Imprime **sin** salto de línea | salida estándar (*stdout*) |
| `println!` | Imprime **con** salto de línea | salida estándar |
| `eprint!` / `eprintln!` | Igual, pero para **mensajes de error** | salida de error (*stderr*) |
| `format!` | **No imprime**: devuelve el texto formateado como `String` | — |

`eprintln!` escribe en un canal distinto. Así, si rediriges la salida a un archivo
(`./programa > salida.txt`), los errores siguen apareciendo en pantalla. Es buena costumbre usarlo
para mensajes de error.

`format!` usa exactamente la misma sintaxis que `println!`, pero guarda el resultado:

```rust
let saludo = format!("Hola, {}! Tienes {} mensajes.", "Ana", 3);
// saludo es un String: "Hola, Ana! Tienes 3 mensajes."
```

### Huecos `{}`: posición, nombre y variables

```rust
let nombre = "Ana";
let edad = 20;

println!("{} tiene {} anios", nombre, edad);         // en orden
println!("{0} tiene {1} anios. {0}!", nombre, edad); // por posicion (se puede repetir)
println!("{n} tiene {e} anios", n = nombre, e = edad); // por nombre
println!("{nombre} tiene {edad} anios");             // variable directamente en la llave
```

La última forma (llamada *inline*) es la más legible y la más usada hoy. Ojo: dentro de las llaves
solo puede ir un **nombre de variable**, no una expresión:

```rust
println!("{edad + 1}");         // ERROR: invalid format string: expected `}`, found `+`
println!("{}", edad + 1);       // correcto
```

Para escribir llaves literales, se duplican: `println!("{{ y }}")` imprime `{ y }`.

### `{}` frente a `{:?}`: *Display* y *Debug*

- **`{}`** usa el formato **Display**: la presentación "para el usuario final". Los números, `bool`,
  `char` y textos lo tienen.
- **`{:?}`** usa el formato **Debug**: la presentación "para el programador", pensada para
  depurar. Casi todos los tipos lo tienen, incluidos arreglos y tuplas.
- **`{:#?}`** es Debug "bonito" (*pretty-print*): una línea por elemento.

```rust
let notas = [15, 18, 12];
println!("{:?}", notas);      // [15, 18, 12]
println!("{}", notas);        // ERROR: `[{integer}; 3]` doesn't implement `std::fmt::Display`
```

¿Por qué un arreglo no tiene Display? Porque **no hay una única forma correcta** de mostrarlo a un
usuario (¿con corchetes?, ¿separado por comas?, ¿uno por línea?). Rust no adivina: te obliga a
decidir. En cambio, Debug sí tiene una forma estándar. En la lección 13 aprenderás a darle Display
a tus propios tipos.

También existe la macro **`dbg!`**, muy práctica para depurar: imprime en *stderr* el archivo, la
línea, la expresión y su valor, y **devuelve** el valor:

```rust
let x = dbg!(2 * 21);   // imprime: [src/main.rs:1:9] 2 * 21 = 42   y x vale 42
```

### Especificadores de formato

Después de `:` puedes controlar ancho, alineación, decimales, signo y base:

| Especificador | Significado | Ejemplo | Resultado |
|---|---|---|---|
| `{:5}` | Ancho mínimo 5 | `format!("[{:5}]", 42)` | `[   42]` |
| `{:<5}` | Alinear a la izquierda | `format!("[{:<5}]", 42)` | `[42   ]` |
| `{:>5}` | Alinear a la derecha | `format!("[{:>5}]", "ab")` | `[   ab]` |
| `{:^5}` | Centrar | `format!("[{:^5}]", "ab")` | `[ ab  ]` |
| `{:*^7}` | Centrar rellenando con `*` | `format!("{:*^7}", "ab")` | `**ab***` |
| `{:.2}` | 2 decimales (redondea) | `format!("{:.2}", 3.14159)` | `3.14` |
| `{:8.2}` | Ancho 8 y 2 decimales | `format!("[{:8.2}]", 3.14159)` | `[    3.14]` |
| `{:05}` | Rellenar con ceros | `format!("{:05}", 42)` | `00042` |
| `{:+}` | Mostrar siempre el signo | `format!("{:+}", 42)` | `+42` |
| `{:b}` `{:o}` `{:x}` `{:X}` | Binario, octal, hexadecimal | `format!("{:b} {:x}", 10, 255)` | `1010 ff` |
| `{:#b}` `{:#x}` | Con prefijo `0b` / `0x` | `format!("{:#x}", 255)` | `0xff` |
| `{:e}` | Notación científica | `format!("{:e}", 1234.5)` | `1.2345e3` |

Por defecto, los **números** se alinean a la **derecha** y los **textos** a la **izquierda**. Se
pueden combinar con variables *inline*: `{precio:>10.2}`. El ancho o la precisión también pueden
venir de una variable: `{:>ancho$}` o `{:.dec$}`.

Compara con C y Java: `printf("%8.2f", x)` / `System.out.printf("%8.2f", x)` equivale a
`println!("{:8.2}", x)`. La gran diferencia: en Rust **no indicas el tipo** (`%d`, `%f`, `%s`), porque
el compilador ya lo conoce, y un formato incompatible **no compila**.

## Parte 2 — Entrada: leer del teclado

Leer datos en Rust requiere algunos pasos más que `scanf` o `Scanner`, porque Rust te obliga a
**tener en cuenta que la lectura puede fallar**. Esta es la receta básica:

```rust
use std::io;

fn main() {
    println!("Escribe tu nombre:");

    let mut entrada = String::new();              // 1. un texto vacio (y mutable)
    io::stdin()                                   // 2. la entrada estandar
        .read_line(&mut entrada)                  // 3. lee una linea y la AGREGA a `entrada`
        .expect("No se pudo leer la entrada");    // 4. si hubo error, detener con este mensaje

    let nombre = entrada.trim();                  // 5. quitar el salto de linea final
    println!("Hola, {nombre}!");
}
```

Paso a paso:

1. **`use std::io;`** — trae el módulo de entrada/salida de la **biblioteca estándar** para poder
   escribir `io::stdin()` en lugar de `std::io::stdin()`. Es como `#include <stdio.h>` en C o
   `import java.util.Scanner;` en Java.
2. **`String::new()`** — crea un `String` vacío. `String` es el tipo de texto que **puede crecer**
   (a diferencia de `"literal"`, que es fijo). Lo estudiarás en la lección 11. Tiene que ser
   **`mut`** porque `read_line` va a escribir en él.
3. **`.read_line(&mut entrada)`** — lee hasta el Enter y **añade** lo leído al final de `entrada`.
   El `&mut` significa "te **presto** esta variable y te permito **modificarla**". Es el concepto de
   **préstamo mutable**, que verás a fondo en la lección 08. Si olvidas el `mut` de la declaración:

   ```
   error[E0596]: cannot borrow `entrada` as mutable, as it is not declared as mutable
   help: consider changing this to be mutable
     |
   3 |     let mut entrada = String::new();
     |         +++
   ```

4. **`.expect("...")`** — `read_line` devuelve un **`Result`**: un valor que puede ser **`Ok`**
   (todo bien) o **`Err`** (falló, por ejemplo porque la entrada no es texto válido). `expect`
   significa: "si es `Ok`, continúa; si es `Err`, **detén el programa** (*panic*) con este mensaje".
   Rust **no te deja ignorar** que una operación puede fallar. Aprenderás a manejar errores con
   elegancia en la lección 12; por ahora, `expect` basta.
5. **`.trim()`** — `read_line` guarda también el **salto de línea** (`"Ana\n"`, o `"Ana\r\n"` en
   Windows). `trim()` quita los espacios y saltos de línea del principio y del final.

> **Importante:** `read_line` **agrega** al `String`, no lo reemplaza. Si reutilizas la misma
> variable para leer varias veces, **vacíala** antes con `entrada.clear();`.

### Convertir el texto a número: `parse`

Todo lo que se lee del teclado es **texto**. Para obtener un número hay que **convertirlo**:

```rust
let mut entrada = String::new();
io::stdin().read_line(&mut entrada).expect("Error al leer");

let edad: u32 = entrada.trim().parse().expect("Eso no es un numero valido");
```

- **`parse()`** intenta convertir el texto al tipo que le pidas. Como puede convertir a muchos
  tipos (`i32`, `u8`, `f64`, `bool`…), **necesita saber cuál**. Se lo dices:
  - anotando la variable: `let edad: u32 = ....parse()...`, o
  - con la sintaxis ***turbofish*** `::<>`: `entrada.trim().parse::<u32>()`.
- Si no lo indicas de ninguna forma, no compila:

  ```
  error[E0284]: type annotations needed
  help: consider giving `n` an explicit type
    |
  5 |     let n: /* Type */ = entrada.trim().parse().expect("No es un numero");
    |          ++++++++++++
  ```

- `parse` también devuelve un `Result`: la conversión **puede fallar** (el usuario escribió `"hola"`,
  o `-5` para un `u32`, o `300` para un `u8`). Con `expect`, el programa se detiene con un mensaje.

**¡No olvides el `trim()`!** Sin él, se intenta convertir `"42\n"`, y el `\n` no es un dígito:

```
thread 'main' (1841) panicked at io1.rs:5:34:
No es un numero entero: ParseIntError { kind: InvalidDigit }
```

Este es **el error más común** de los principiantes al leer números en Rust.

Aquí vuelve a brillar el **shadowing** de la lección 02: puedes reutilizar el nombre al pasar de
texto a número:

```rust
let mut edad = String::new();
io::stdin().read_line(&mut edad).expect("Error al leer");
let edad: u32 = edad.trim().parse().expect("Numero invalido");   // mismo nombre, ahora es u32
```

### No detener el programa si el usuario se equivoca

`expect` es cómodo, pero detener el programa porque alguien escribió una letra es poco amable.
Adelanto de la lección 10: con `match` puedes reaccionar a cada caso:

```rust
match entrada.trim().parse::<i32>() {
    Ok(numero) => println!("El doble es {}", numero * 2),
    Err(_) => println!("Eso no es un numero entero."),
}
```

Y en la lección 05 lo combinarás con un bucle para **volver a preguntar** hasta que el dato sea
válido.

### Mostrar el mensaje en la misma línea que la respuesta

Si quieres que el usuario escriba **al lado** de la pregunta, usarás `print!` en vez de `println!`.
Pero la salida estándar se guarda en un **búfer** y normalmente solo se envía a la pantalla al
llegar un salto de línea. Hay que **vaciar** (*flush*) el búfer a mano:

```rust
use std::io::{self, Write};   // Write aporta el metodo flush()

print!("Edad: ");
io::stdout().flush().expect("No se pudo vaciar stdout");
// ahora si, leer...
```

`use std::io::{self, Write};` importa a la vez el módulo `io` (`self`) y el *trait* `Write`
(lección 13), que es el que aporta el método `flush`.

### Leer varios valores en una sola línea

Si el usuario escribe `3 4` en la misma línea, separa el texto por espacios con
`split_whitespace()` y convierte cada parte:

```rust
let mut linea = String::new();
io::stdin().read_line(&mut linea).expect("Error al leer");

let mut partes = linea.split_whitespace();       // un iterador sobre las palabras
let a: i32 = partes.next().expect("Falta el primer numero").parse().expect("No es numero");
let b: i32 = partes.next().expect("Falta el segundo numero").parse().expect("No es numero");
```

`next()` devuelve la siguiente palabra envuelta en un `Option` (puede no haberla); `expect` la
extrae. Entenderás del todo `Option` en la lección 10 y los iteradores en la lección 15; por ahora,
úsalo como receta.

## Comparación con otros lenguajes

| Tarea | C | Java | Rust |
|---|---|---|---|
| Imprimir | `printf("%d\n", x);` | `System.out.println(x);` | `println!("{x}");` |
| Con 2 decimales | `printf("%.2f", x);` | `System.out.printf("%.2f", x);` | `print!("{:.2}", x);` |
| Leer un entero | `scanf("%d", &x);` | `int x = sc.nextInt();` | `read_line` + `trim().parse()` |
| ¿Y si el usuario escribe letras? | `scanf` devuelve 0 y `x` queda sin cambios (fácil de ignorar) | `InputMismatchException` | `parse` devuelve `Err`: **no puedes ignorarlo** |

## Errores típicos

- Olvidar `trim()` antes de `parse()` → `ParseIntError { kind: InvalidDigit }`.
- Declarar el `String` sin `mut` → `E0596 cannot borrow as mutable`.
- No indicar el tipo destino de `parse` → `E0284 type annotations needed`.
- Reutilizar el `String` de entrada sin `clear()` → se acumulan las líneas.
- Usar `{}` con un arreglo o tupla → no tienen Display; usa `{:?}`.
- Escribir una expresión dentro de las llaves (`{x + 1}`) → solo se permiten nombres.

## Resumen

- `print!`/`println!` para la salida, `eprintln!` para errores, `format!` para crear un `String`.
- `{}` = Display (usuario), `{:?}` = Debug (programador), `{:#?}` = Debug con saltos de línea.
- Formato: `{:>8}`, `{:<8}`, `{:^8}`, `{:.2}`, `{:08.3}`, `{:+}`, `{:b}`, `{:x}`… y variables
  *inline* `{nombre}`.
- Leer: `String::new()` + `io::stdin().read_line(&mut s).expect(...)`.
- Convertir: `s.trim().parse::<T>()` — **siempre con `trim()`** — y manejar el posible error.
- `print!` + `io::stdout().flush()` para preguntar en la misma línea.

## Ejemplos

- [`ejemplos/formato.rs`](ejemplos/formato.rs) — todos los especificadores de formato.
- [`ejemplos/leer_nombre.rs`](ejemplos/leer_nombre.rs) — leer un texto.
- [`ejemplos/leer_numeros.rs`](ejemplos/leer_numeros.rs) — leer y convertir números, `flush`.
- [`ejemplos/parse_seguro.rs`](ejemplos/parse_seguro.rs) — convertir sin detener el programa.

Los ejemplos que leen del teclado se pueden probar también **redirigiendo** la entrada, lo cual es
útil para no escribir siempre lo mismo:

```bash
echo "Ana" | ./leer_nombre
printf "20\n1.65\n" | ./leer_numeros
```

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- ***The Rust Programming Language***, cap. 2 "Programming a Guessing Game" — un proyecto guiado
  que usa exactamente `read_line`, `trim` y `parse`.
  https://doc.rust-lang.org/book/ch02-00-guessing-game-tutorial.html
- ***Rust by Example***, "Formatted print". https://doc.rust-lang.org/rust-by-example/hello/print.html
- **Documentación de `std::fmt`** (la especificación completa del formato):
  https://doc.rust-lang.org/std/fmt/
- **Documentación de `std::io::Stdin`**: https://doc.rust-lang.org/std/io/struct.Stdin.html
- ***Programming Rust*** (2.ª ed.), cap. 17 "Strings and Text" (sección de formato) y cap. 18
  "Input and Output".
