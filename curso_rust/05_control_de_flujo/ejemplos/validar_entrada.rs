// Leccion 05 - Pedir un dato hasta que sea valido (loop + match + break con valor).
//
//   rustc --edition 2021 validar_entrada.rs && ./validar_entrada
//   printf "hola\n-3\n200\n25\n" | ./validar_entrada
//
// Salida con esa entrada:
//   Edad (0-150): "hola" no es un numero entero. Intenta de nuevo.
//   Edad (0-150): "-3" no es un numero entero. Intenta de nuevo.
//   Edad (0-150): 200 esta fuera del rango 0-150. Intenta de nuevo.
//   Edad (0-150): Edad registrada: 25

use std::io::{self, Write};

fn main() {
    let edad: u32 = loop {
        print!("Edad (0-150): ");
        io::stdout().flush().expect("No se pudo vaciar stdout");

        let mut entrada = String::new();
        io::stdin().read_line(&mut entrada).expect("Error al leer");
        let texto = entrada.trim();

        match texto.parse::<u32>() {
            Ok(n) if n <= 150 => break n, // valido: sale con el valor (el `if` es una "guarda")
            Ok(n) => println!("{n} esta fuera del rango 0-150. Intenta de nuevo."),
            Err(_) => println!("{:?} no es un numero entero. Intenta de nuevo.", texto),
        }
    };

    println!("Edad registrada: {edad}");
}
