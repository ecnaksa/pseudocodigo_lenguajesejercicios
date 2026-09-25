// Ejercicio 2 - match con rangos + bucle de validacion.
//   rustc --edition 2021 calificacion.rs && printf "abc\n25\n15\n" | ./calificacion
//
// Salida con esa entrada:
//   Nota (0-20): "abc" no es un numero.
//   Nota (0-20): 25 no esta entre 0 y 20.
//   Nota (0-20): Nota 15: Bueno

use std::io::{self, Write};

fn main() {
    let nota: u8 = loop {
        print!("Nota (0-20): ");
        io::stdout().flush().expect("No se pudo vaciar stdout");
        let mut entrada = String::new();
        io::stdin().read_line(&mut entrada).expect("Error al leer");
        let texto = entrada.trim();

        match texto.parse::<u8>() {
            Ok(n) if n <= 20 => break n,
            Ok(n) => println!("{n} no esta entre 0 y 20."),
            Err(_) => println!("{:?} no es un numero.", texto),
        }
    };

    // Como `nota` ya esta validada (0..=20), cubrimos los rangos y dejamos `_` para el resto.
    let texto = match nota {
        18..=20 => "Excelente",
        14..=17 => "Bueno",
        11..=13 => "Aprobado",
        0..=10 => "Desaprobado",
        _ => unreachable!("la nota ya fue validada"), // macro para casos "imposibles"
    };
    println!("Nota {nota}: {texto}");
}
