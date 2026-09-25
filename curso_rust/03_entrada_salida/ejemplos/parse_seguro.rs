// Leccion 03 - Convertir texto a numero SIN detener el programa si falla.
// (Adelanto de `match` y `Result`, que se estudian en las lecciones 10 y 12.)
//
//   rustc --edition 2021 parse_seguro.rs && ./parse_seguro
//   echo "hola" | ./parse_seguro
//
// Salida con "21":    El doble de 21 es 42
// Salida con "hola":  "hola" no es un numero entero.

use std::io;

fn main() {
    println!("Escribe un numero entero:");
    let mut entrada = String::new();
    io::stdin().read_line(&mut entrada).expect("Error al leer");
    let texto = entrada.trim();

    // parse devuelve un Result: Ok(numero) si pudo convertir, Err(error) si no.
    match texto.parse::<i32>() {
        Ok(numero) => println!("El doble de {numero} es {}", numero * 2),
        Err(_) => println!("{:?} no es un numero entero.", texto),
    }

    // Algunas conversiones y su resultado (Debug de Result):
    println!("{:?}", "42".parse::<i32>()); // Ok(42)
    println!("{:?}", "-7".parse::<u32>()); // Err(... InvalidDigit): u32 no admite negativos
    println!("{:?}", "300".parse::<u8>()); // Err(... PosOverflow): no cabe en un u8
    println!("{:?}", "".parse::<i32>()); // Err(... Empty)
    println!("{:?}", "2.5".parse::<f64>()); // Ok(2.5)
    println!("{:?}", "true".parse::<bool>()); // Ok(true)
}
