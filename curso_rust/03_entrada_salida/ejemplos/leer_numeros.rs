// Leccion 03 - Leer numeros: trim + parse, y preguntar en la misma linea con flush.
//
//   rustc --edition 2021 leer_numeros.rs && ./leer_numeros
//   printf "20\n1.65\n7 5\n" | ./leer_numeros
//
// Salida (con la entrada anterior):
//   Edad: Altura (m): Dos enteros separados por espacio: 
//   El proximo anio tendras 21 anios.
//   Tu altura en cm: 165.0
//   7 + 5 = 12

use std::io::{self, Write}; // `self` = el modulo io; Write aporta flush()

fn main() {
    // --- 1. Un entero ---
    print!("Edad: ");
    io::stdout().flush().expect("No se pudo vaciar stdout"); // mostrar la pregunta YA
    let mut edad = String::new();
    io::stdin().read_line(&mut edad).expect("Error al leer");
    // Shadowing: mismo nombre, ahora de tipo u32.
    let edad: u32 = edad.trim().parse().expect("La edad debe ser un entero positivo");

    // --- 2. Un flotante (con turbofish en lugar de anotar la variable) ---
    print!("Altura (m): ");
    io::stdout().flush().expect("No se pudo vaciar stdout");
    let mut linea = String::new();
    io::stdin().read_line(&mut linea).expect("Error al leer");
    let altura = linea.trim().parse::<f64>().expect("La altura debe ser un numero");

    // --- 3. Dos enteros en la MISMA linea ---
    print!("Dos enteros separados por espacio: ");
    io::stdout().flush().expect("No se pudo vaciar stdout");
    linea.clear(); // read_line AGREGA: hay que vaciar el String antes de reutilizarlo
    io::stdin().read_line(&mut linea).expect("Error al leer");
    let mut partes = linea.split_whitespace();
    let a: i32 = partes.next().expect("Falta el primer numero").parse().expect("No es entero");
    let b: i32 = partes.next().expect("Falta el segundo numero").parse().expect("No es entero");

    println!();
    println!("El proximo anio tendras {} anios.", edad + 1);
    println!("Tu altura en cm: {:.1}", altura * 100.0);
    println!("{a} + {b} = {}", a + b);
}
