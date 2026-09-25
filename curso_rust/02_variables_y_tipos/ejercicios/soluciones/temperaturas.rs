// Ejercicio 4 - Arreglo de temperaturas.
//   rustc --edition 2021 temperaturas.rs && ./temperaturas

fn main() {
    //                         lun   mar   mie   jue   vie   sab   dom
    let mut temps: [f64; 7] = [18.5, 19.0, 21.3, 20.1, 17.8, 16.4, 15.0];

    println!("Lunes:     {}", temps[0]);
    println!("Miercoles: {}", temps[2]);
    println!("Domingo:   {}", temps[6]); // o temps[temps.len() - 1]
    println!("Dias:      {}", temps.len());

    temps[6] = 15.9; // correccion: por eso el arreglo es `mut`
    println!("Semana corregida: {:?}", temps);
}
