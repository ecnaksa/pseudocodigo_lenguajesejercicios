// Ejercicio 3 - Transformar un valor paso a paso con shadowing (sin mut).
//   rustc --edition 2021 precio.rs && ./precio
//
// Salida:
//   Precio base:           100
//   Con 18% de impuesto:   118
//   Con 10% de descuento:  106.2
//   Parte entera:          106

fn main() {
    let precio = 100.0;
    println!("Precio base:           {precio}");

    let precio = precio * 1.18; // nueva variable `precio`, sombrea a la anterior
    println!("Con 18% de impuesto:   {precio}");

    let precio = precio * 0.90;
    println!("Con 10% de descuento:  {precio}");

    let precio = precio as i64; // incluso cambia de tipo: de f64 a i64 (trunca)
    println!("Parte entera:          {precio}");
}
