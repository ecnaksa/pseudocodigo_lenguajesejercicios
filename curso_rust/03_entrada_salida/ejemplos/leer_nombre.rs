// Leccion 03 - Leer una linea de texto del teclado.
//
//   rustc --edition 2021 leer_nombre.rs && ./leer_nombre
//   (o sin escribir a mano:  echo "Ana" | ./leer_nombre)
//
// Salida (si escribes Ana):
//   Escribe tu nombre:
//   Hola, Ana!
//   Tu nombre tiene 3 letras.
//   Sin trim() la variable contenia: "Ana\n"

use std::io; // modulo de entrada/salida de la biblioteca estandar

fn main() {
    println!("Escribe tu nombre:");

    let mut entrada = String::new(); // texto vacio y MUTABLE (read_line escribira en el)
    io::stdin()
        .read_line(&mut entrada) // lee hasta Enter y lo AGREGA a `entrada`
        .expect("No se pudo leer la entrada"); // si falla, detiene el programa con este mensaje

    let nombre = entrada.trim(); // quita el salto de linea final (y espacios)
    println!("Hola, {nombre}!");
    println!("Tu nombre tiene {} letras.", nombre.len());

    // {:?} muestra el texto "crudo", con caracteres especiales escapados:
    println!("Sin trim() la variable contenia: {:?}", entrada);
}
