# Configuración del entorno (Rust)

Para programar en Rust necesitas la **cadena de herramientas** (*toolchain*) de Rust y un
**editor**. La forma oficial —y la única recomendada— de instalarla es **`rustup`**.

## 1. Instalar Rust con `rustup`

`rustup` es el **instalador y gestor de versiones** oficial. Instala y mantiene al día:

| Herramienta | Qué hace |
|---|---|
| `rustc` | El **compilador**: traduce `.rs` a un ejecutable nativo (usa LLVM por debajo). |
| `cargo` | El **gestor de proyectos**: crea proyectos, compila, ejecuta, prueba, descarga dependencias. |
| `rustfmt` | **Formateador** automático de código (`cargo fmt`). |
| `clippy` | ***Linter***: cientos de sugerencias para escribir Rust más idiomático (`cargo clippy`). |
| `rust-docs` | La documentación **completa y sin conexión**, incluido el libro oficial. |

### Linux y macOS

```bash
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

Acepta la instalación por defecto (opción 1). Al terminar, **cierra y vuelve a abrir** la terminal
(o ejecuta `source "$HOME/.cargo/env"`) para que se actualice el `PATH`.

> En Linux también necesitas un **enlazador** (*linker*) de C. Si al compilar ves
> `linker 'cc' not found`, instala las herramientas de compilación:
> `sudo apt install build-essential` (Debian/Ubuntu) o `sudo dnf install gcc` (Fedora).

### Windows

1. Descarga y ejecuta **`rustup-init.exe`** desde https://rustup.rs
2. El instalador te pedirá las **Visual Studio C++ Build Tools** (el enlazador de Microsoft). Deja
   que las instale; son necesarias para generar ejecutables.

### Comprobar que funciona

```bash
rustc --version     # p. ej.: rustc 1.94.1 (e408947bf 2026-03-25)
cargo --version     # p. ej.: cargo 1.94.1
```

### Mantenerlo al día

Rust publica una versión **estable nueva cada 6 semanas**. Actualizar es un solo comando:

```bash
rustup update
```

> **Estabilidad garantizada:** el código que compila en una versión estable de Rust seguirá
> compilando en las siguientes. Los cambios que rompen compatibilidad solo llegan con las
> **ediciones** (2015, 2018, 2021, 2024), y cada proyecto elige la suya. Proyectos de ediciones
> distintas pueden usarse entre sí sin problema.

### El libro oficial, sin conexión

```bash
rustup doc --book   # abre "The Rust Programming Language" en el navegador
rustup doc --std    # abre la documentacion de la biblioteca estandar
```

## 2. El editor

Cualquier editor sirve, pero con **rust-analyzer** (el servidor de lenguaje oficial) la experiencia
mejora muchísimo: ves los **tipos inferidos** encima de cada variable, los errores mientras escribes,
autocompletado y "ir a la definición".

- **Visual Studio Code** (https://code.visualstudio.com) + la extensión **rust-analyzer**.
  Gratuito; es la opción más usada.
- **RustRover** (https://www.jetbrains.com/rust/) — el IDE de JetBrains para Rust; gratuito para
  uso no comercial.
- **Zed**, **Neovim**, **Helix**, **Emacs**… todos soportan rust-analyzer.

> Recomendación: activa en el editor **"format on save"** (formatear al guardar). Así `rustfmt`
> mantiene tu código con el estilo estándar de la comunidad sin que tengas que pensar en ello.

## 3. Forma A — Compilar un solo archivo con `rustc`

Es la forma más directa y la que usan los ejemplos y ejercicios de las lecciones 01 a 15:

```bash
rustc --edition 2021 hola.rs    # compila hola.rs -> genera el ejecutable "hola" ("hola.exe" en Windows)
./hola                          # lo ejecuta   (en Windows: .\hola.exe)
```

- **¿Por qué `--edition 2021`?** Por compatibilidad histórica, `rustc` usa por defecto la
  **edición 2015**. Algunas cosas del curso se comportan distinto en ella (por ejemplo, recorrer un
  arreglo con `into_iter`), así que indicamos la edición moderna. Con Cargo no hace falta: la
  edición va en `Cargo.toml`.
- A diferencia de Java, **no hay máquina virtual**: el resultado es un ejecutable nativo que puedes
  copiar y ejecutar en otra máquina con el mismo sistema operativo, sin instalar Rust.
- Como en C, el nombre del archivo **no** tiene que coincidir con nada del código.

Para compilar y ejecutar de una vez:

```bash
rustc --edition 2021 hola.rs && ./hola
```

## 4. Forma B — Proyectos con Cargo (la forma habitual)

En la práctica, **todo proyecto real de Rust usa Cargo**. Es como si `make`, un gestor de paquetes
y un ejecutor de pruebas vinieran de fábrica y se usaran igual en todos los proyectos del mundo.

### Crear un proyecto

```bash
cargo new saludo        # crea la carpeta "saludo" con un proyecto ejecutable
cd saludo
```

Estructura generada:

```
saludo/
├── Cargo.toml          ← manifiesto: nombre, version, edicion, dependencias
├── .gitignore          ← ya ignora la carpeta target/
└── src/
    └── main.rs         ← punto de entrada (ya trae un "Hello, world!")
```

`Cargo.toml` (formato TOML):

```toml
[package]
name = "saludo"
version = "0.1.0"
edition = "2024"     # cargo new usa la edicion mas reciente

[dependencies]       # aqui se agregan bibliotecas ("crates") de crates.io
```

### Comandos de Cargo que usarás siempre

| Comando | Qué hace |
|---|---|
| `cargo run` | Compila (si hace falta) y **ejecuta**. El que más usarás. |
| `cargo build` | Solo compila. El ejecutable queda en `target/debug/saludo`. |
| `cargo check` | Comprueba que el código **compila**, sin generar ejecutable. Mucho más rápido: úsalo mientras escribes. |
| `cargo build --release` | Compila **optimizado** (lento de compilar, rápido de ejecutar) en `target/release/`. |
| `cargo test` | Ejecuta las **pruebas** automáticas (lección 17). |
| `cargo fmt` | Formatea todo el código con el estilo estándar. |
| `cargo clippy` | Pasa el *linter*: sugerencias para mejorar el código. |
| `cargo doc --open` | Genera la documentación HTML del proyecto y la abre. |

> **Debug vs release.** Por defecto (`cargo build`/`cargo run`) se compila en modo **debug**: sin
> optimizaciones y con comprobaciones extra (por ejemplo, un desbordamiento de entero **detiene** el
> programa con un `panic`). En **release** (`--release`) se optimiza al máximo. Para medir
> rendimiento, usa siempre `--release`.

### Truco para practicar los ejercicios con Cargo

Crea **un** proyecto de práctica y pon cada ejercicio como un binario aparte dentro de `src/bin/`:

```
practica/
├── Cargo.toml
└── src/
    └── bin/
        ├── ej1.rs
        └── ej2.rs
```

y ejecuta cada uno con `cargo run --bin ej1`. Así tienes rust-analyzer, `cargo fmt` y `clippy`
funcionando en todos tus ejercicios.

## 5. Rust Playground (sin instalar nada)

https://play.rust-lang.org/ — compila y ejecuta Rust en el navegador. Ideal para probar una idea
rápida o compartir un fragmento de código. Tiene botones para `rustfmt` y `clippy`, y puedes elegir
edición y versión (estable, beta, nightly).

## 6. Leer los errores del compilador

Los mensajes de error de Rust son famosos por lo claros que son. Un error típico:

```
error[E0382]: borrow of moved value: `s1`
 --> mover.rs:5:20
  |
3 |     let s1 = String::from("hola");
  |         -- move occurs because `s1` has type `String`, which does not implement the `Copy` trait
4 |     let s2 = s1;
  |              -- value moved here
5 |     println!("{}", s1);
  |                    ^^ value borrowed here after move
  |
  = note: this error originates in the macro `$crate::format_args_nl` which comes from the expansion of the macro `println` (in Nightly builds, run with -Z macro-backtrace for more info)
help: consider cloning the value if the performance cost is acceptable
  |
4 |     let s2 = s1.clone();
  |                ++++++++
```

Cómo leerlo:

1. **`error[E0382]`** — el código del error. `rustc --explain E0382` te da una explicación larga
   con ejemplos (también en https://doc.rust-lang.org/error_codes/).
2. **`--> mover.rs:5:20`** — archivo, línea y columna.
3. Las **flechas y subrayados** cuentan la historia: dónde se creó el valor, dónde se movió y dónde
   se intentó usar después.
4. **`= note:`** — información adicional. Esta nota solo dice que el error se detectó dentro de la
   expansión de la macro `println!`; puedes ignorarla.
5. **`help:`** — una sugerencia concreta, a menudo con el código ya corregido.

Este error en concreto lo entenderás a fondo en la lección 07.

## 7. Resumen de comandos

```bash
# instalar / actualizar
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
rustup update

# un archivo suelto
rustc --edition 2021 archivo.rs && ./archivo

# un proyecto
cargo new mi_proyecto && cd mi_proyecto
cargo run            # compilar + ejecutar
cargo check          # solo verificar (rapido)
cargo test           # pruebas
cargo fmt            # formatear
cargo clippy         # sugerencias de estilo
cargo build --release

# ayuda
rustc --explain E0382
rustup doc --book
```
