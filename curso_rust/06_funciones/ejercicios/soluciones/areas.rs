// Ejercicio 1 - Funciones de areas.
//   rustc --edition 2021 areas.rs && ./areas
//
// Salida:
//   Rectangulo 4 x 3:  12.00
//   Circulo r = 2:     12.57
//   Triangulo 6 x 5:   15.00

use std::f64::consts::PI;

fn main() {
    println!("Rectangulo 4 x 3:  {:.2}", area_rectangulo(4.0, 3.0));
    println!("Circulo r = 2:     {:.2}", area_circulo(2.0));
    println!("Triangulo 6 x 5:   {:.2}", area_triangulo(6.0, 5.0));
}

fn area_rectangulo(base: f64, altura: f64) -> f64 {
    base * altura
}

fn area_circulo(radio: f64) -> f64 {
    PI * radio * radio
}

fn area_triangulo(base: f64, altura: f64) -> f64 {
    base * altura / 2.0
}
