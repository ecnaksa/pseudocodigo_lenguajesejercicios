// Ejercicio 6 (reto) - Tuplas: desestructurar e intercambiar.
//   rustc --edition 2021 punto3d.rs && ./punto3d
//
// Salida:
//   Punto: (2, 3, 6)
//   Distancia al origen: 7
//   Antes:   a = 1, b = 2
//   Despues: a = 2, b = 1

fn main() {
    let punto: (f64, f64, f64) = (2.0, 3.0, 6.0);
    let (x, y, z) = punto;
    let distancia = (x * x + y * y + z * z).sqrt(); // sqrt(4 + 9 + 36) = sqrt(49) = 7
    println!("Punto: ({x}, {y}, {z})");
    println!("Distancia al origen: {distancia}");

    let a = 1;
    let b = 2;
    println!("Antes:   a = {a}, b = {b}");
    let (a, b) = (b, a); // se arma la tupla (2, 1) y se desestructura en nuevas a y b
    println!("Despues: a = {a}, b = {b}");
}
