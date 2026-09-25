// Ejercicio 3 - Celsius a Fahrenheit, preguntando en la misma linea.
//   rustc --edition 2021 temperatura.rs && echo "36.6" | ./temperatura
//
// Salida:
//   Temperatura en Celsius: 36.6 C = 97.9 F

use std::io::{self, Write};

fn main() {
    print!("Temperatura en Celsius: ");
    io::stdout().flush().expect("No se pudo vaciar stdout");

    let mut entrada = String::new();
    io::stdin().read_line(&mut entrada).expect("Error al leer");
    let celsius: f64 = entrada.trim().parse().expect("Debe ser un numero");

    let fahrenheit = celsius * 9.0 / 5.0 + 32.0; // 9.0 y no 9: no se mezclan f64 e i32
    println!("{celsius} C = {fahrenheit:.1} F");
}
