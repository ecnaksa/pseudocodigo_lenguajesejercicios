// Ejercicio 1 - if como expresion.
//   rustc --edition 2021 signo_paridad.rs && echo "-8" | ./signo_paridad
//
// Salida:
//   -8 es negativo y par

use std::io;

fn main() {
    println!("Escribe un entero:");
    let mut entrada = String::new();
    io::stdin().read_line(&mut entrada).expect("Error al leer");
    let n: i32 = entrada.trim().parse().expect("Debe ser un entero");

    let signo = if n > 0 {
        "positivo"
    } else if n < 0 {
        "negativo"
    } else {
        "cero"
    };
    // % puede dar -1 con negativos impares, por eso comparamos con 0 y no con 1.
    let paridad = if n % 2 == 0 { "par" } else { "impar" };

    println!("{n} es {signo} y {paridad}");
}
