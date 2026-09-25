// Ejercicio 1 - Leer dos lineas de texto reutilizando el mismo String.
//   rustc --edition 2021 saludo.rs && printf "Ana\nLima\n" | ./saludo

use std::io;

fn main() {
    let mut linea = String::new();

    println!("Como te llamas?");
    io::stdin().read_line(&mut linea).expect("Error al leer");
    // to_string() crea un String propio con el contenido recortado:
    // lo necesitamos porque a continuacion vamos a vaciar `linea`.
    let nombre = linea.trim().to_string();

    println!("De que ciudad eres?");
    linea.clear(); // read_line agrega: vaciar antes de reutilizar
    io::stdin().read_line(&mut linea).expect("Error al leer");
    let ciudad = linea.trim();

    println!("Hola, {nombre} de {ciudad}!");
}
