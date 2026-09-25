// Ejercicio 2 - Leer dos enteros y operar.
//   rustc --edition 2021 dos_numeros.rs && printf "12\n5\n" | ./dos_numeros
//
// Salida:
//   12 + 5 = 17
//   12 - 5 = 7
//   12 * 5 = 60

use std::io;

fn main() {
    println!("Primer numero:");
    let mut a = String::new();
    io::stdin().read_line(&mut a).expect("Error al leer");
    let a: i32 = a.trim().parse().expect("Debe ser un entero");

    println!("Segundo numero:");
    let mut b = String::new();
    io::stdin().read_line(&mut b).expect("Error al leer");
    let b: i32 = b.trim().parse().expect("Debe ser un entero");

    println!("{a} + {b} = {}", a + b);
    println!("{a} - {b} = {}", a - b);
    println!("{a} * {b} = {}", a * b);
}
