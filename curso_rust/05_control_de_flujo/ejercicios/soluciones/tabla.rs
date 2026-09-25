// Ejercicio 4 - Tabla de multiplicar alineada.
//   rustc --edition 2021 tabla.rs && echo "7" | ./tabla

use std::io;

fn main() {
    println!("Tabla del numero:");
    let mut entrada = String::new();
    io::stdin().read_line(&mut entrada).expect("Error al leer");
    let n: i32 = entrada.trim().parse().expect("Debe ser un entero");

    for i in 1..=12 {
        println!("{n:2} x {i:2} = {:3}", n * i);
    }
}
