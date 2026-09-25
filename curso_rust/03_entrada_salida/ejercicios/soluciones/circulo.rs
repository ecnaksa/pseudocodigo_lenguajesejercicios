// Ejercicio 4 - Area y circunferencia de un circulo.
//   rustc --edition 2021 circulo.rs && echo "2.5" | ./circulo
//
// Salida:
//   Radio: 
//   Area:           19.63
//   Circunferencia: 15.71

use std::f64::consts::PI; // constante PI de la biblioteca estandar
use std::io;

fn main() {
    println!("Radio: ");
    let mut entrada = String::new();
    io::stdin().read_line(&mut entrada).expect("Error al leer");
    let radio: f64 = entrada.trim().parse().expect("Debe ser un numero");

    let area = PI * radio * radio; // tambien: PI * radio.powi(2)
    let circunferencia = 2.0 * PI * radio;

    println!("Area:           {area:.2}");
    println!("Circunferencia: {circunferencia:.2}");
}
