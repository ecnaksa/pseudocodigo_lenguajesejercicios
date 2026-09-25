// Ejercicio 3 - Promedio de tres notas (convertir ANTES de dividir).
//   rustc --edition 2021 promedio.rs && echo "14 15 17" | ./promedio
//
// Salida:
//   Promedio (division entera, MAL): 15
//   Promedio (real, BIEN):           15.33

use std::io;

fn main() {
    println!("Tres notas separadas por espacio:");
    let mut linea = String::new();
    io::stdin().read_line(&mut linea).expect("Error al leer");
    let mut partes = linea.split_whitespace();
    let n1: i32 = partes.next().expect("Falta la nota 1").parse().expect("Nota invalida");
    let n2: i32 = partes.next().expect("Falta la nota 2").parse().expect("Nota invalida");
    let n3: i32 = partes.next().expect("Falta la nota 3").parse().expect("Nota invalida");

    let suma = n1 + n2 + n3;
    println!("Promedio (division entera, MAL): {}", suma / 3);
    println!("Promedio (real, BIEN):           {:.2}", suma as f64 / 3.0);
}
