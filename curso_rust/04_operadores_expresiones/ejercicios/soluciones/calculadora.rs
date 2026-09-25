// Ejercicio 1 - Calculadora de enteros sin panic al dividir entre cero.
//   rustc --edition 2021 calculadora.rs && echo "17 5" | ./calculadora
//
// Salida con "17 5":            Salida con "17 0":
//   17 + 5 = 22                   17 + 0 = 17
//   17 - 5 = 12                   17 - 0 = 17
//   17 * 5 = 85                   17 * 0 = 0
//   17 / 5 = Some(3)              17 / 0 = None
//   17 % 5 = Some(2)              17 % 0 = None
//   17 / 5 (real) = 3.40          17 / 0 (real) = inf

use std::io;

fn main() {
    println!("Escribe dos enteros separados por espacio:");
    let mut linea = String::new();
    io::stdin().read_line(&mut linea).expect("Error al leer");
    let mut partes = linea.split_whitespace();
    let a: i32 = partes.next().expect("Falta a").parse().expect("a no es entero");
    let b: i32 = partes.next().expect("Falta b").parse().expect("b no es entero");

    println!("{a} + {b} = {}", a + b);
    println!("{a} - {b} = {}", a - b);
    println!("{a} * {b} = {}", a * b);
    // checked_div / checked_rem devuelven None si b == 0 (en vez de detener el programa).
    println!("{a} / {b} = {:?}", a.checked_div(b));
    println!("{a} % {b} = {:?}", a.checked_rem(b));
    // En flotantes, dividir entre cero da inf (no hay panic).
    println!("{a} / {b} (real) = {:.2}", a as f64 / b as f64);
}
