// Ejercicio 5 - Boleta alineada con format.
//   rustc --edition 2021 boleta.rs && printf "Cuaderno\n3\n4.5\n" | ./boleta

use std::io;

const TASA_IMPUESTO: f64 = 0.18;

fn main() {
    let mut linea = String::new();

    println!("Producto:");
    io::stdin().read_line(&mut linea).expect("Error al leer");
    let producto = linea.trim().to_string(); // copia propia: luego vaciamos `linea`

    println!("Cantidad:");
    linea.clear();
    io::stdin().read_line(&mut linea).expect("Error al leer");
    let cantidad: u32 = linea.trim().parse().expect("Cantidad invalida");

    println!("Precio unitario:");
    linea.clear();
    io::stdin().read_line(&mut linea).expect("Error al leer");
    let precio: f64 = linea.trim().parse().expect("Precio invalido");

    let subtotal = cantidad as f64 * precio; // convertir u32 -> f64 para multiplicar
    let impuesto = subtotal * TASA_IMPUESTO;
    let total = subtotal + impuesto;

    // Columna izquierda de 16 caracteres (alineada a la izquierda) + columna derecha de 14
    // (alineada a la derecha) = 30 de ancho total, igual que las lineas de "=" y "-".
    // "=".repeat(30) crea un String con el texto "=" repetido 30 veces.
    println!("{}", "=".repeat(30));
    println!("{:<16}{:>14}", "Producto", producto);
    println!("{:<16}{:>14}", "Cantidad", cantidad);
    println!("{:<16}{:>14.2}", "Precio unit.", precio);
    println!("{}", "-".repeat(30));
    println!("{:<16}{:>14.2}", "Subtotal", subtotal);
    println!("{:<16}{:>14.2}", "Impuesto (18%)", impuesto);
    println!("{:<16}{:>14.2}", "TOTAL", total);
    println!("{}", "=".repeat(30));
}
