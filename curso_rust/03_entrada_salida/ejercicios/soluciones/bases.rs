// Ejercicio 6 (reto) - Un numero en varias bases, sin detener el programa si es invalido.
//   rustc --edition 2021 bases.rs && echo "2026" | ./bases
//
// Salida con 2026:
//   Decimal:     2026
//   Binario:     0b0000011111101010
//   Octal:       0o3752
//   Hexadecimal: 0x7EA
//
// Salida con "abc":
//   "abc" no es un entero sin signo valido.

use std::io;

fn main() {
    println!("Escribe un entero sin signo:");
    let mut entrada = String::new();
    io::stdin().read_line(&mut entrada).expect("Error al leer");
    let texto = entrada.trim();

    match texto.parse::<u32>() {
        Ok(n) => {
            println!("Decimal:     {n}");
            // {:#018b}: con prefijo 0b, relleno con ceros, ancho TOTAL 18 (2 del prefijo + 16 bits)
            println!("Binario:     {n:#018b}");
            println!("Octal:       {n:#o}");
            println!("Hexadecimal: {n:#X}");
        }
        Err(_) => println!("{:?} no es un entero sin signo valido.", texto),
    }
}
