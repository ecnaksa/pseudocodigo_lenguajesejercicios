# Fuentes y bibliografía (Rust)

Este curso se apoya en material de referencia reconocido. **Nada de este curso copia texto de
esas obras**: son explicaciones propias, con ejemplos propios; las fuentes se citan como
referencia y como lectura ampliada.

## Fuente principal: "el libro"

- **Klabnik, S. & Nichols, C. — *The Rust Programming Language* (2.ª ed., No Starch Press, 2023).**
  Conocido en la comunidad simplemente como **"the book"**. Escrito por miembros del equipo de
  Rust, es la introducción oficial y la base de la estructura de este curso.
  - En línea y gratuito (versión actualizada continuamente): https://doc.rust-lang.org/book/
  - Sin conexión, con Rust instalado: `rustup doc --book`
  - **Traducción al español** (comunidad RustLangES): https://book.rustlang-es.org/

## Otros libros

- **Blandy, J., Orendorff, J. & Tindall, L. F. S. — *Programming Rust* (2.ª ed., O'Reilly, 2021).**
  Más profundo y técnico que "el libro"; explica **por qué** Rust está diseñado así y cómo se
  representa todo en memoria. Excelente segundo libro, sobre todo si vienes de C o C++.
- **McNamara, T. — *Rust in Action* (Manning, 2021).**
  Aprende Rust construyendo programas de sistemas reales (manejo de bits, memoria, archivos,
  redes). Muy práctico.
- **Gjengset, J. — *Rust for Rustaceans* (No Starch Press, 2021).**
  Nivel intermedio-avanzado: para cuando termines este curso y quieras escribir bibliotecas y
  código de calidad profesional.
- **Bos, M. — *Rust Atomics and Locks* (O'Reilly, 2023).**
  La referencia sobre concurrencia de bajo nivel en Rust (complementa la lección 19). Gratuito en
  línea: https://marabos.nl/atomics/
- **Palmieri, L. — *Zero To Production In Rust* (2022).**
  Construir un servicio web backend completo en Rust, con pruebas y despliegue. Para después del
  curso, si te interesa el desarrollo backend.

## Documentación oficial (https://www.rust-lang.org/learn)

- **Rust by Example** — https://doc.rust-lang.org/rust-by-example/
  El complemento práctico de "el libro": cada concepto con código ejecutable en el navegador.
- **Documentación de la biblioteca estándar** — https://doc.rust-lang.org/std/
  La referencia de todos los tipos (`Vec`, `String`, `HashMap`, `Option`, `Result`…) y sus
  métodos. Aprender a consultarla es una habilidad clave.
- **The Cargo Book** — https://doc.rust-lang.org/cargo/ — todo sobre Cargo y `Cargo.toml`.
- **The Rust Reference** — https://doc.rust-lang.org/reference/ — la definición precisa del
  lenguaje (no es un tutorial; es para consultar detalles exactos).
- **The Edition Guide** — https://doc.rust-lang.org/edition-guide/ — qué cambia entre ediciones
  (2015, 2018, 2021, 2024).
- **Índice de códigos de error** — https://doc.rust-lang.org/error_codes/ — la explicación larga
  de cada `E0xxx` (equivale a `rustc --explain E0xxx`).
- **Rust API Guidelines** — https://rust-lang.github.io/api-guidelines/ — convenciones de nombres
  y diseño idiomático.
- **The Rustonomicon** — https://doc.rust-lang.org/nomicon/ — Rust `unsafe` a fondo. Fuera del
  alcance de este curso; se menciona para que sepas dónde está.

## Cursos y práctica en línea

- **Rustlings** — https://github.com/rust-lang/rustlings — cientos de pequeños ejercicios que se
  corrigen solos, organizados siguiendo "el libro". El complemento ideal de este curso.
- **Comprehensive Rust (Google)** — https://google.github.io/comprehensive-rust/ — el curso interno
  con el que Google forma a sus ingenieros de Android. Tiene **traducción al español**:
  https://google.github.io/comprehensive-rust/es/
- **Exercism, pista de Rust** — https://exercism.org/tracks/rust — ejercicios con revisión de
  mentores voluntarios.
- **Tour of Rust** — https://tourofrust.com/ — recorrido interactivo paso a paso, con versión en
  español.
- **Microsoft Learn — "Primeros pasos con Rust"** —
  https://learn.microsoft.com/es-es/training/paths/rust-first-steps/ — ruta de aprendizaje en
  español.
- **Learn Rust With Entirely Too Many Linked Lists** —
  https://rust-unofficial.github.io/too-many-lists/ — un clásico para entender `Box`, `Rc` y
  `RefCell` implementando listas enlazadas (complementa la lección 18).

## Herramientas y ecosistema

- **rustup** — https://rustup.rs · **Rust Playground** — https://play.rust-lang.org/
- **crates.io** — https://crates.io — el registro público de bibliotecas (*crates*).
- **docs.rs** — https://docs.rs — documentación generada automáticamente de cada *crate*.
- **rust-analyzer** — https://rust-analyzer.github.io/ — el servidor de lenguaje para editores.
- **Clippy** (lista de *lints*) — https://rust-lang.github.io/rust-clippy/master/
- **This Week in Rust** — https://this-week-in-rust.org/ — boletín semanal de novedades.

## Datos citados en el curso (seguridad de memoria)

La afirmación de que ~70 % de las vulnerabilidades graves se deben a errores de memoria, y la
adopción de Rust en la industria, provienen de:

- **Microsoft Security Response Center — Miller, M., "A proactive approach to more secure code"
  (16 de julio de 2019).** Alrededor del 70 % de las vulnerabilidades (CVE) que Microsoft corrige
  cada año son problemas de seguridad de memoria.
  https://msrc.microsoft.com/blog/2019/07/a-proactive-approach-to-more-secure-code/
- **The Chromium Projects — "Memory safety".** Alrededor del 70 % de los errores de seguridad de
  gravedad alta en Chrome son de seguridad de memoria.
  https://www.chromium.org/Home/chromium-security/memory-safety/
- **Google Security Blog — "Memory Safe Languages in Android 13" (diciembre de 2022).** Al escribir
  el código nuevo en lenguajes seguros (Rust, Java, Kotlin), la proporción de vulnerabilidades de
  memoria en Android bajó del 76 % (2019) al 35 % (2022).
  https://security.googleblog.com/2022/12/memory-safe-languages-in-android-13.html
- **NSA — "Software Memory Safety", Cybersecurity Information Sheet (noviembre de 2022).**
  Recomienda migrar a lenguajes con seguridad de memoria, entre ellos Rust.
- **Núcleo de Linux:** el soporte para escribir código del núcleo en Rust se incorporó en la
  versión **6.1** (diciembre de 2022).

## Historia del lenguaje (lección 01)

- Rust empezó en 2006 como proyecto personal de **Graydon Hoare**; **Mozilla** lo patrocinó desde
  2009 y lo anunció en 2010. La versión **1.0** se publicó el **15 de mayo de 2015**.
- En 2021 se creó la **Rust Foundation** (con AWS, Google, Huawei, Microsoft y Mozilla como
  miembros fundadores), que hoy sostiene el proyecto.
- Blog oficial con los anuncios de cada versión: https://blog.rust-lang.org/

## Correspondencia lección → fuentes

Cada lección termina con una sección **"Para profundizar"** con referencias concretas. Esta tabla
resume la correspondencia principal (capítulos de "el libro" y de *Programming Rust*, 2.ª ed.):

| Lección | *The Rust Programming Language* | *Rust by Example* | *Programming Rust* |
|---|---|---|---|
| 01 Introducción | cap. 1 | Hello World | cap. 1–2 |
| 02 Variables y tipos | 3.1, 3.2 | Primitives, Variable Bindings | cap. 3 |
| 03 Entrada y salida | cap. 2 | Hello World → Formatted print | cap. 2, 18 |
| 04 Operadores y expresiones | 3.2, 3.3 | Types, Expressions | cap. 6 |
| 05 Control de flujo | 3.5 | Flow of Control | cap. 6 |
| 06 Funciones | 3.3, 3.4 | Functions | cap. 6 |
| 07 Ownership | 4.1 | Scoping rules → Ownership and moves | cap. 4 |
| 08 Referencias y préstamos | 4.2, 4.3 | Scoping rules → Borrowing | cap. 5 |
| 09 Structs | cap. 5 | Custom Types → Structures | cap. 9 |
| 10 Enums y *match* | cap. 6 y "Patterns and Matching" | Custom Types → Enums; Flow of Control → match | cap. 10 |
| 11 Colecciones | cap. 8 | Std library types | cap. 16–17 |
| 12 Errores | cap. 9 | Error handling | cap. 7 |
| 13 Genéricos y traits | 10.1, 10.2 | Generics, Traits | cap. 11, 13 |
| 14 Lifetimes | 10.3 | Scoping rules → Lifetimes | cap. 5 |
| 15 Closures e iteradores | cap. 13 | Functions → Closures; Traits → Iterators | cap. 14–15 |
| 16 Módulos y Cargo | cap. 7, 14 | Modules, Crates, Cargo | cap. 8 |
| 17 Pruebas | cap. 11 | Testing | cap. 8 |
| 18 Punteros inteligentes | cap. 15 | Std library types → Box, Rc | cap. 4, 13 |
| 19 Concurrencia | cap. 16 | Std misc → Threads, Channels | cap. 19 |
| 20 Proyecto final | cap. 12 (proyecto `minigrep`) | Std misc → File I/O | cap. 18 |
