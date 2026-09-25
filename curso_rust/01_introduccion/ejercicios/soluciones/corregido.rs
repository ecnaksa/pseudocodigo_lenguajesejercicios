// Ejercicio 4 - Programa corregido.
//
// Errores del original:
//   1. `fn Main()`  -> el punto de entrada debe llamarse exactamente `main` (en minusculas).
//                      (error[E0601]: `main` function not found)
//   2. `println(...)` -> falta el `!`: println! es una macro, no una funcion.
//                      (error[E0423]: expected function, found macro `println`)
//   3. `'Paso a paso'` -> las cadenas van con comillas DOBLES; las simples son para un solo char.
//                      (error: character literal may only contain one codepoint)
//
//   rustc --edition 2021 corregido.rs && ./corregido

fn main() {
    println!("Aprendiendo Rust");
    println!("Paso a paso");
}
