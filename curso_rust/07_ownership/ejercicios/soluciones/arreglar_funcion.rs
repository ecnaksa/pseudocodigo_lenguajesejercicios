// Ejercicio 2 - Dos formas de arreglar "usar despues de mover a una funcion".
//   rustc --edition 2021 arreglar_funcion.rs && ./arreglar_funcion
//
// Salida:
//   Ferris
//   Adios, Ferris
//   Adios, Ferris
//   Ferris

fn imprimir(s: String) {
    println!("{s}");
}

fn main() {
    // (a) clone: la funcion recibe una COPIA; `nombre` sigue siendo nuestra.
    let nombre = String::from("Ferris");
    imprimir(nombre.clone());
    println!("Adios, {nombre}");

    // (b) Reordenar: usamos `nombre` ANTES de entregarla a la funcion.
    let nombre = String::from("Ferris");
    println!("Adios, {nombre}");
    imprimir(nombre); // a partir de aqui ya no la necesitamos

    // (c) La solucion idiomatica (leccion 08): que imprimir reciba `&str` y solo PIDA PRESTADO
    //     el texto:  fn imprimir(s: &str) { ... }   imprimir(&nombre);
}
