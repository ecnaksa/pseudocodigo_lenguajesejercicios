// Leccion 01 - Adelanto: imprimir valores con {} (se estudia a fondo en la leccion 03).
//
// Compilar y ejecutar:
//   rustc --edition 2021 formato_basico.rs && ./formato_basico
//
// Salida:
//   Rust 1.0 salio en 2015.
//   2 + 3 = 5
//   Lenguaje: Rust, mascota: Ferris
//   Lenguaje: Rust, mascota: Ferris

fn main() {
    // Cada {} es un "hueco" que se rellena con el siguiente argumento, en orden.
    println!("Rust 1.0 salio en {}.", 2015);

    // Los argumentos pueden ser expresiones: se calculan antes de imprimir.
    println!("{} + {} = {}", 2, 3, 2 + 3);

    // Tambien se pueden guardar valores en variables (leccion 02)...
    let lenguaje = "Rust";
    let mascota = "Ferris";
    println!("Lenguaje: {}, mascota: {}", lenguaje, mascota);

    // ...y escribir el nombre de la variable DENTRO de las llaves (Rust 1.58+).
    println!("Lenguaje: {lenguaje}, mascota: {mascota}");

    // Si el numero de {} no coincide con el de argumentos, NO compila:
    // println!("{} {}", 1);   // error: 2 positional arguments in format string, but there is 1 argument
}
