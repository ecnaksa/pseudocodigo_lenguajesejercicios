// Leccion 01 - Varias instrucciones, print! frente a println!.
//
// Compilar y ejecutar:
//   rustc --edition 2021 presentacion.rs && ./presentacion
//
// Salida:
//   Me llamo Ferris.
//   Soy el cangrejo mascota de Rust.
//   Esto no salta de linea... pero esto si.
//
//   Fin.

fn main() {
    println!("Me llamo Ferris.");
    println!("Soy el cangrejo mascota de Rust.");
    print!("Esto no salta de linea... "); // print! NO agrega salto de linea
    println!("pero esto si."); // println! SI lo agrega
    println!(); // sin argumentos: linea en blanco
    println!("Fin.");
}
