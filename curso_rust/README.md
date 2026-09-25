# Curso de Rust — de cero a fundamentos sólidos

Un curso **progresivo** para aprender **Rust** desde cero, con **teoría a fondo** y **práctica**
(ejemplos ejecutables + ejercicios con solución). Inspirado en la forma de
[30-Days-Of-Python](https://github.com/Asabeneh/30-Days-Of-Python) —una lección por tema, cada una
con explicación completa y ejercicios—, pero organizado por **temas** en dificultad creciente, no
por días.

> **¿Por qué Rust?** Rust es un lenguaje de **sistemas** (como C y C++): compila a código máquina
> nativo, no tiene recolector de basura y es igual de rápido. La diferencia es que el compilador
> **garantiza la seguridad de memoria**: no hay punteros colgantes, dobles liberaciones, desbordes
> de búfer ni *data races* en código Rust seguro. Esos errores son la causa de alrededor del **70 %**
> de las vulnerabilidades graves en productos como Windows y Chrome (ver
> [`FUENTES.md`](FUENTES.md)). Rust los impide **al compilar** con el sistema de **ownership**
> (propiedad) y el **borrow checker** (verificador de préstamos). Por eso lo usan hoy el núcleo de
> Linux, Android, Windows, Firefox, Cloudflare, AWS y Discord, entre otros.

> **Si vienes de los otros cursos de este repositorio** ([C/C++](../curso_c_cpp),
> [Java](../curso_java)), gran parte de la sintaxis te resultará familiar. Lo **nuevo** son el
> *ownership*, el *borrowing* y los *lifetimes* (lecciones 07, 08 y 14), que no existen en esos
> lenguajes. En cada lección se señala qué cambia respecto a C, C++ y Java.

## Cómo está organizado

```
curso_rust/
├── README.md            ← este archivo (plan del curso)
├── CONFIGURACION.md     ← instalar Rust (rustup), compilar con rustc, proyectos con Cargo
├── FUENTES.md           ← bibliografía y fuentes usadas (libros, sitios, documentación)
└── 01_.. 20_..          ← una carpeta por lección
```

Cada lección es una carpeta con:

- **`README.md`** — la teoría del tema, explicada en detalle y con ejemplos comentados.
- **`ejemplos/`** — programas cortos y **ejecutables** que ilustran cada idea.
- **`ejercicios/README.md`** — enunciados de práctica.
- **`ejercicios/soluciones/`** — soluciones ejecutables de esos ejercicios.

Las lecciones 16, 17 y 20 incluyen además **proyectos de Cargo** completos (con `Cargo.toml`).

## Ruta de aprendizaje

El curso tiene **cuatro bloques**. Los dos primeros son imprescindibles; no avances al tercero sin
haber entendido bien las lecciones 07 y 08.

### Bloque I — Fundamentos (lo que Rust comparte con otros lenguajes)

| # | Lección | Aprendes a… |
|---|---------|-------------|
| 01 | [Introducción y primer programa](01_introduccion) | Qué es Rust, `rustc`, `cargo`, `Hola mundo`, macros |
| 02 | [Variables y tipos](02_variables_y_tipos) | `let`, `mut`, *shadowing*, `const`, enteros, flotantes, `char`, tuplas, arreglos |
| 03 | [Entrada y salida](03_entrada_salida) | `println!` y formato, leer de teclado con `stdin`, `parse` |
| 04 | [Operadores y expresiones](04_operadores_expresiones) | Aritmética, `as`, desbordamiento, **expresiones vs sentencias** |
| 05 | [Control de flujo](05_control_de_flujo) | `if` como expresión, `loop`, `while`, `for` con rangos, etiquetas |
| 06 | [Funciones](06_funciones) | Parámetros, retorno implícito, recursión, documentación `///` |

### Bloque II — El corazón de Rust (lo que lo hace único)

| # | Lección | Aprendes a… |
|---|---------|-------------|
| 07 | [Ownership (propiedad)](07_ownership) | *Stack* vs *heap*, reglas de propiedad, *move*, `clone`, `Copy`, `drop` |
| 08 | [Referencias y préstamos](08_referencias_prestamos) | `&` y `&mut`, reglas del *borrow checker*, *slices* `&str` y `&[T]` |
| 09 | [Structs y métodos](09_structs) | `struct`, `impl`, `&self`/`&mut self`, funciones asociadas, `derive` |
| 10 | [Enums y *pattern matching*](10_enums_match) | `enum` con datos, `Option` (adiós `null`), `match`, `if let`, patrones |

### Bloque III — Rust idiomático

| # | Lección | Aprendes a… |
|---|---------|-------------|
| 11 | [Colecciones](11_colecciones) | `Vec<T>`, `String` (UTF-8), `HashMap`, `HashSet` |
| 12 | [Manejo de errores](12_manejo_errores) | `panic!`, `Result<T, E>`, el operador `?`, errores propios |
| 13 | [Genéricos y traits](13_genericos_traits) | `<T>`, `trait`, *trait bounds*, `impl Trait`, `dyn Trait` |
| 14 | [Lifetimes](14_lifetimes) | Anotaciones `'a`, reglas de elisión, `'static`, structs con referencias |
| 15 | [Closures e iteradores](15_closures_iteradores) | `|x| ...`, `Fn`/`FnMut`/`FnOnce`, `map`/`filter`/`fold`/`collect` |

### Bloque IV — Rust profesional

| # | Lección | Aprendes a… |
|---|---------|-------------|
| 16 | [Módulos y Cargo](16_modulos_cargo) | `mod`, `pub`, `use`, *crates*, `Cargo.toml`, dependencias |
| 17 | [Pruebas automáticas](17_pruebas) | `#[test]`, `assert_eq!`, `cargo test`, pruebas de integración y de documentación |
| 18 | [Punteros inteligentes](18_punteros_inteligentes) | `Box`, `Rc`, `RefCell`, `Drop`, estructuras recursivas |
| 19 | [Concurrencia](19_concurrencia) | Hilos, `move`, canales `mpsc`, `Arc<Mutex<T>>`, `Send`/`Sync` |
| 20 | [Proyecto final](20_proyecto_final) | Inventario por consola con módulos, errores propios, archivos y pruebas |

## Cómo usar este curso

1. Lee [`CONFIGURACION.md`](CONFIGURACION.md) e instala Rust con `rustup`.
2. Ve en orden. Lee el `README.md` de cada lección, **escribe y ejecuta** tú mismo los ejemplos
   (no solo los leas) y luego resuelve los ejercicios **antes** de mirar la solución.
3. **Lee los mensajes del compilador.** En Rust, el compilador es tu profesor: sus errores explican
   qué falla, por qué y a menudo cómo arreglarlo. Aprender a leerlos es parte del curso; muchas
   lecciones muestran errores reales y cómo interpretarlos.
4. Consulta [`FUENTES.md`](FUENTES.md) cuando quieras profundizar con material serio. La fuente
   principal es el libro oficial, *The Rust Programming Language* ("el libro"), gratuito en línea.

## Rust frente a C, C++ y Java (vista rápida)

| Aspecto | C | C++ | Java | Rust |
|---|---|---|---|---|
| Gestión de memoria | Manual (`malloc`/`free`) | Manual o RAII (`unique_ptr`) | Recolector de basura (GC) | **Ownership**, verificado al compilar; sin GC |
| Valor nulo | `NULL` | `nullptr` | `null` | **No existe**: se usa `Option<T>` |
| Errores | Códigos de retorno | Excepciones | Excepciones | **`Result<T, E>`** y el operador `?` |
| Variables | Mutables por defecto | Mutables por defecto | Mutables por defecto | **Inmutables por defecto** (`mut` para cambiar) |
| Herencia de clases | No | Sí | Sí | **No**: composición + **traits** |
| *Data races* | Posibles | Posibles | Posibles | **Imposibles** en código seguro |
| Herramienta de proyecto | `make` (externa) | CMake (externa) | Maven/Gradle (externas) | **Cargo** (oficial, incluida) |

## Convenciones del curso

- El código está comentado en español; los mensajes en pantalla van **sin acentos** para evitar
  problemas de codificación entre terminales (salvo en la lección 11, donde el tema es justamente
  cómo Rust maneja UTF-8).
- Los archivos se nombran en `snake_case` (`hola.rs`, `leer_numero.rs`), que es la convención de
  Rust.
- Cada ejemplo indica **cómo compilarlo/ejecutarlo** y **qué salida** produce.
- Se usa la **edición 2021** del lenguaje. Como `rustc` usa por defecto la antigua edición 2015,
  los programas de un solo archivo se compilan así:
  ```bash
  rustc --edition 2021 hola.rs && ./hola
  ```
  Todo el código se probó también con la **edición 2024** (la que genera hoy `cargo new`). Versión
  de Rust usada para probar: **1.94**.
- Todo el código compila **sin advertencias** (*warnings*). Si al compilar ves una advertencia en tu
  propio código, léela: casi siempre señala algo real (una variable sin usar, un `mut` innecesario…).
