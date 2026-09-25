// Ejercicio 2 - Segundos a HH:MM:SS con / y %.
//   rustc --edition 2021 segundos.rs && echo "3725" | ./segundos
//
// Salida:
//   3725 segundos = 01:02:05

use std::io;

fn main() {
    println!("Segundos:");
    let mut entrada = String::new();
    io::stdin().read_line(&mut entrada).expect("Error al leer");
    let total: u32 = entrada.trim().parse().expect("Debe ser un entero no negativo");

    let horas = total / 3600; // cuantas horas completas
    let minutos = (total % 3600) / 60; // lo que sobra, en minutos completos
    let segundos = total % 60; // lo que sobra, en segundos

    println!("{total} segundos = {horas:02}:{minutos:02}:{segundos:02}");
}
