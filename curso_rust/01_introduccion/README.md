# Lección 01 — Introducción a Rust y primer programa

En esta lección conocerás **qué es Rust**, **qué problema resuelve**, cómo se **compila** un
programa y escribirás tu primer "Hola mundo", tanto con el compilador `rustc` como con la
herramienta de proyectos `cargo`.

## ¿Qué es Rust?

Rust es un lenguaje de programación:

- **Compilado**: el código fuente se traduce **antes** de ejecutarse a **código máquina nativo**
  (como C y C++; a diferencia de Python, que se interpreta, o de Java, que se compila a *bytecode*
  para una máquina virtual).
- **De sistemas**: sirve para escribir software donde el **rendimiento** y el **control** del
  hardware importan: sistemas operativos, navegadores, motores de bases de datos, servidores,
  videojuegos, sistemas embebidos, herramientas de línea de comandos.
- **De tipado estático y fuerte**: cada valor tiene un tipo conocido al compilar y no hay
  conversiones implícitas "sorpresa". Aun así, gracias a la **inferencia de tipos**, casi nunca
  tienes que escribirlos.
- **Multiparadigma**: combina ideas **imperativas** (como C), **funcionales** (closures,
  iteradores, *pattern matching*, inmutabilidad por defecto) y de **tipos abstractos** (traits),
  pero **sin herencia de clases**.
- **Sin recolector de basura** (*garbage collector*) y **con seguridad de memoria**. Esta es la
  combinación que lo hace único, y la explicamos a continuación.

## El problema que Rust resuelve

Durante décadas, los programadores tuvieron que elegir entre dos mundos:

| | **Control y velocidad** (C, C++) | **Seguridad** (Java, Python, C#, Go) |
|---|---|---|
| Memoria | La gestiona el programador (`malloc`/`free`, `new`/`delete`) | La gestiona un **recolector de basura** |
| Rendimiento | Máximo, predecible | Bueno, pero con pausas del recolector y más consumo de memoria |
| Riesgo | Errores de memoria: el programa puede **corromperse** o ser **atacado** | Esos errores no ocurren |

Los errores de memoria de C y C++ no son un problema teórico. Algunos ejemplos que viste (o
verás) en el curso de C:

- **Usar memoria ya liberada** (*use-after-free*): `free(p); printf("%d", *p);`
- **Liberar dos veces** (*double free*): `free(p); free(p);`
- **Salirse de un arreglo** (*buffer overflow*): `int a[5]; a[10] = 3;`
- **Punteros colgantes** (*dangling pointers*): devolver la dirección de una variable local.
- ***Data races***: dos hilos modifican el mismo dato a la vez sin sincronización.

El compilador de C **acepta** todos esos programas. Microsoft y Google han reportado que alrededor
del **70 %** de las vulnerabilidades de seguridad graves de sus productos (Windows, Chrome)
provienen justamente de este tipo de errores (ver [`FUENTES.md`](../FUENTES.md)).

**Rust elimina ese dilema:** ofrece el rendimiento y el control de C/C++ **y** la seguridad de un
lenguaje con recolector de basura. Lo consigue con un conjunto de reglas llamado **ownership**
(propiedad) que el compilador **verifica al compilar**. Si tu programa podría tener uno de esos
errores, **no compila**. No hay coste en tiempo de ejecución: las comprobaciones ocurren antes de
que el programa exista.

> Verás el *ownership* en detalle en las lecciones 07 y 08. Por ahora basta con la idea: en Rust,
> **el compilador es mucho más estricto**, y a cambio, **si compila, una clase entera de errores
> es imposible**.

## Un poco de historia

- **2006**: Graydon Hoare empieza Rust como proyecto personal.
- **2009–2010**: **Mozilla** lo patrocina y lo anuncia públicamente; quería un lenguaje para
  construir un navegador más seguro y paralelo.
- **15 de mayo de 2015**: sale **Rust 1.0**, con la promesa de **estabilidad**: el código que
  compila en una versión estable seguirá compilando en las siguientes.
- **2021**: se crea la **Rust Foundation** (AWS, Google, Huawei, Microsoft, Mozilla).
- **2022**: el núcleo de **Linux** (versión 6.1) acepta código en Rust.
- Desde entonces, lo usan Android, Windows, Firefox, Cloudflare, AWS (por ejemplo, Firecracker, la
  tecnología detrás de AWS Lambda), Discord, Dropbox y muchas herramientas de línea de comandos
  populares (`ripgrep`, `fd`, `bat`).

## ¿Qué pasa cuando compilas un programa Rust?

```
 hola.rs ──► rustc ──────────────────────────────────────────────► hola (ejecutable nativo)
              │  1. analiza el código (sintaxis)
              │  2. comprueba TIPOS
              │  3. comprueba OWNERSHIP y PRESTAMOS  (borrow checker)  ◄── lo exclusivo de Rust
              │  4. genera una representacion intermedia y se la pasa a LLVM
              │  5. LLVM optimiza y produce codigo maquina
```

- El paso 3 es el que hace a Rust especial: ahí se detectan los errores de memoria.
- **LLVM** es el mismo motor de optimización que usa el compilador `clang` de C/C++, por eso el
  código Rust es tan rápido como el de C.
- El resultado es un **ejecutable nativo**. No necesitas instalar nada para ejecutarlo en otra
  máquina con el mismo sistema operativo (a diferencia de Java, que necesita la JVM).

Comparación con los otros lenguajes del repositorio:

| Lenguaje | Compilar | Resultado | Ejecutar |
|---|---|---|---|
| C | `gcc hola.c -o hola` | ejecutable nativo | `./hola` |
| C++ | `g++ hola.cpp -o hola` | ejecutable nativo | `./hola` |
| Java | `javac Hola.java` | *bytecode* (`Hola.class`) | `java Hola` (sobre la JVM) |
| **Rust** | `rustc --edition 2021 hola.rs` | **ejecutable nativo** | `./hola` |

## Tu primer programa

Archivo [`ejemplos/hola.rs`](ejemplos/hola.rs):

```rust
fn main() {
    println!("Hola, mundo!");
}
```

Línea por línea:

- **`fn main()`** — declara una **función** (`fn` viene de *function*) llamada `main`. Como en C,
  C++ y Java, `main` es el **punto de entrada**: el programa empieza a ejecutarse ahí. No recibe
  parámetros (`()`) ni devuelve nada. A diferencia de C, **no** se escribe `int main` ni se hace
  `return 0`.
- **`{ ... }`** — las llaves delimitan el **cuerpo** de la función. Rust exige llaves siempre
  (también en `if` y bucles, aunque haya una sola línea).
- **`println!(...)`** — imprime un texto y un salto de línea. Observa el **`!`**: `println!` **no es
  una función, es una macro**.
- **`"Hola, mundo!"`** — una cadena literal, siempre entre **comillas dobles**.
- **`;`** — termina la instrucción. (En la lección 04 verás que en Rust el `;` tiene un significado
  más profundo: convierte una *expresión* en una *sentencia*.)

### ¿Por qué `println!` lleva `!`?

En Rust, un nombre seguido de `!` es una **macro**: código que **genera código** durante la
compilación. `println!` es una macro, y no una función, por dos motivos:

1. **Acepta un número variable de argumentos** (`println!("{} y {}", a, b)`); las funciones de Rust
   tienen un número fijo de parámetros.
2. **Revisa la cadena de formato al compilar.** Si escribes `println!("{} {}", x)` (dos huecos, un
   valor), el programa **no compila**. En C, `printf("%d %d", x)` compila y produce basura o se
   rompe al ejecutarse.

Otras macros que verás pronto: `print!`, `format!`, `vec!`, `panic!`, `assert!`.

### Compilar y ejecutar

```bash
cd ejemplos
rustc --edition 2021 hola.rs     # genera el ejecutable "hola"
./hola                           # Hola, mundo!
```

(En Windows, el ejecutable es `hola.exe` y se ejecuta con `.\hola.exe`.)

## El mismo programa con Cargo

`rustc` está bien para un archivo suelto, pero en la vida real todo proyecto usa **Cargo**:

```bash
cargo new hola_cargo
cd hola_cargo
cargo run
```

Salida:

```
   Compiling hola_cargo v0.1.0 (/ruta/hola_cargo)
    Finished `dev` profile [unoptimized + debuginfo] target(s) in 0.40s
     Running `target/debug/hola_cargo`
Hello, world!
```

Cargo creó la estructura del proyecto (`Cargo.toml` + `src/main.rs`), compiló con `rustc` por ti y
ejecutó el programa. Abre `src/main.rs`: contiene exactamente el mismo `fn main()` que acabas de
escribir. En [`../CONFIGURACION.md`](../CONFIGURACION.md) tienes todos los comandos de Cargo.

> En las lecciones 01 a 15 usaremos archivos sueltos con `rustc` para que cada ejemplo sea
> autocontenido. A partir de la 16 trabajaremos con proyectos de Cargo.

## Comentarios

```rust
// Comentario de una linea

/* Comentario
   de varias lineas */

/// Comentario de DOCUMENTACION: describe el elemento que viene debajo
/// (una funcion, un struct...). Lo usa `cargo doc` para generar la documentacion HTML.
fn saludar() {}
```

En Rust se usan casi siempre comentarios `//`, incluso para varias líneas. Los de documentación
(`///`) los verás en la lección 06.

## Varias instrucciones

`main` puede tener tantas instrucciones como quieras; se ejecutan **de arriba hacia abajo**
([`ejemplos/presentacion.rs`](ejemplos/presentacion.rs)):

```rust
fn main() {
    println!("Me llamo Ferris.");
    println!("Soy el cangrejo mascota de Rust.");
    print!("Esto no salta de linea... ");
    println!("pero esto si.");
    println!();                        // linea en blanco
    println!("Fin.");
}
```

- `print!` imprime **sin** salto de línea (como `printf` sin `\n` en C, o `System.out.print` en
  Java).
- `println!()` sin argumentos imprime una línea en blanco.
- Los programadores de Rust se llaman a sí mismos ***rustaceans***, y la mascota no oficial es
  **Ferris**, un cangrejo.

## Estilo del código

La comunidad de Rust sigue un estilo **único y automático**:

- **4 espacios** de sangría (no tabuladores).
- Nombres de funciones y variables en **`snake_case`**: `calcular_area`, `numero_de_intentos`.
- Nombres de tipos (structs, enums, traits) en **`PascalCase`**: `Rectangulo`, `CuentaBancaria`.
- Constantes en **`MAYUSCULAS`**: `PI`, `MAX_INTENTOS`.
- La llave de apertura `{` va en la **misma línea** que la declaración.

No hace falta memorizarlo: `rustfmt` (o `cargo fmt`) formatea tu código automáticamente. Y si
usas un nombre con el estilo equivocado, el compilador te avisará con una advertencia.

## Errores típicos (y cómo los reporta el compilador)

**1. Olvidar el `!` de la macro:**

```rust
println("Hola");
```
```
error[E0423]: expected function, found macro `println`
 --> e1.rs:2:5
  |
2 |     println("Hola");
  |     ^^^^^^^ not a function
  |
help: use `!` to invoke the macro
  |
2 |     println!("Hola");
  |            +
```

Observa que el compilador no solo detecta el error: **te dice exactamente qué agregar** (el `+`
señala el carácter que falta).

**2. Usar comillas simples para una cadena:**

```rust
println!('Hola');
```
```
error: character literal may only contain one codepoint
...
help: if you meant to write a string literal, use double quotes
```

En Rust, las comillas simples son para **un solo carácter** (`'a'`, tipo `char`); las cadenas van
con comillas **dobles**. (Igual que en C, C++ y Java.)

**3. Llamar de otra forma a `main`:**

```
error[E0601]: `main` function not found in crate `e3`
```

Todo programa ejecutable necesita una función llamada exactamente `main`.

**4. Compilar sin `--edition 2021`:** en ejemplos sencillos no notarás nada, pero algunas cosas del
curso se comportan distinto en la edición 2015 que `rustc` usa por defecto. Acostúmbrate a
escribirlo (o usa Cargo, que lo toma de `Cargo.toml`).

## Resumen

- Rust es un lenguaje **compilado a código nativo**, **de sistemas**, con **tipado estático** e
  **inferencia de tipos**.
- Su gran aporte: **seguridad de memoria sin recolector de basura**, verificada **al compilar**
  mediante el *ownership* y el *borrow checker*.
- Un programa empieza en **`fn main()`**.
- **`println!`** es una **macro** (lleva `!`); revisa la cadena de formato al compilar.
- Se compila con `rustc --edition 2021 archivo.rs` o, en proyectos, con **`cargo run`**.
- El estilo es único y automático: `snake_case`, 4 espacios, `rustfmt`.
- **Lee los errores del compilador**: explican el problema y casi siempre sugieren la solución.

## Ejemplos

- [`ejemplos/hola.rs`](ejemplos/hola.rs) — el "Hola mundo".
- [`ejemplos/presentacion.rs`](ejemplos/presentacion.rs) — varias instrucciones, `print!` vs
  `println!`.
- [`ejemplos/formato_basico.rs`](ejemplos/formato_basico.rs) — adelanto de cómo imprimir valores
  con `{}` (se ve a fondo en la lección 03).

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- ***The Rust Programming Language***, cap. 1 "Getting Started" (instalación, Hola mundo, Cargo).
  https://doc.rust-lang.org/book/ch01-00-getting-started.html
- ***Rust by Example***, "Hello World". https://doc.rust-lang.org/rust-by-example/hello.html
- ***Programming Rust*** (2.ª ed.), cap. 1 "Systems Programmers Can Have Nice Things" (por qué
  existe Rust) y cap. 2 "A Tour of Rust".
- **Chromium, "Memory safety"** — el dato del 70 %:
  https://www.chromium.org/Home/chromium-security/memory-safety/
