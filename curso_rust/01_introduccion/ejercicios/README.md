# Ejercicios — Lección 01

Compila cada solución con `rustc --edition 2021 archivo.rs` y ejecútala con `./archivo`.
Intenta resolver cada ejercicio **antes** de mirar la solución.

1. **Preséntate.** Escribe un programa que imprima tu nombre, lo que estudias y tu ciudad, cada
   dato en una línea distinta.
   → [`soluciones/presentacion_personal.rs`](soluciones/presentacion_personal.rs)

2. **Figura con asteriscos.** Imprime este triángulo usando un `println!` por línea:
   ```
       *
      ***
     *****
    *******
   ```
   → [`soluciones/triangulo.rs`](soluciones/triangulo.rs)

3. **En una sola línea.** Imprime `1 2 3 4 5` en **una sola línea** usando cinco llamadas a
   `print!` (una por número) y un `println!()` final para cerrar la línea.
   → [`soluciones/en_una_linea.rs`](soluciones/en_una_linea.rs)

4. **Corrige los errores.** Este programa tiene **tres** errores. Compílalo, lee los mensajes del
   compilador y corrígelo:
   ```rust
   fn Main() {
       println("Aprendiendo Rust");
       println!('Paso a paso');
   }
   ```
   Pista: el compilador te dirá los problemas uno por uno (a veces solo muestra el siguiente
   después de corregir el anterior).
   → [`soluciones/corregido.rs`](soluciones/corregido.rs)

5. **Reto — tu primer proyecto con Cargo.** (Sin archivo de solución: es práctica de la
   herramienta.)
   1. Ejecuta `cargo new mi_primer_proyecto` y entra en la carpeta.
   2. Abre `Cargo.toml` y localiza el nombre, la versión y la edición.
   3. Cambia `src/main.rs` para que imprima `Mi primer proyecto en Rust`.
   4. Ejecuta `cargo run`. Luego ejecuta `cargo build --release` y busca el ejecutable en
      `target/release/`. Ejecútalo directamente desde ahí.
   5. Escribe mal a propósito el nombre de `println!` y ejecuta `cargo check`: verás el mismo error
      que con `rustc`, pero sin generar ejecutable.
