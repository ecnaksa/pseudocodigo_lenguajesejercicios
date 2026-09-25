// Leccion 02 - let, mut, shadowing y const.
//
//   rustc --edition 2021 variables.rs && ./variables
//
// Salida:
//   edad = 20
//   contador = 0
//   contador = 1
//   contador = 2
//   x en el bloque: 12
//   x fuera: 6
//   espacios: 3
//   Maximo de alumnos: 30
//   Una hora tiene 3600 segundos

// Las constantes pueden ir fuera de las funciones (visibles en todo el archivo).
const MAX_ALUMNOS: u32 = 30;
const SEGUNDOS_POR_HORA: u32 = 60 * 60; // se calcula al compilar

fn main() {
    // 1. Variable inmutable: su valor no puede cambiar.
    let edad = 20;
    println!("edad = {edad}");
    // edad = 21;   // error[E0384]: cannot assign twice to immutable variable `edad`

    // 2. Variable mutable: se declara con `mut`.
    let mut contador = 0;
    println!("contador = {contador}");
    contador += 1;
    println!("contador = {contador}");
    contador += 1;
    println!("contador = {contador}");

    // 3. Shadowing: una NUEVA variable con el mismo nombre.
    let x = 5;
    let x = x + 1; // x = 6
    {
        let x = x * 2; // solo dentro de este bloque: x = 12
        println!("x en el bloque: {x}");
    }
    println!("x fuera: {x}"); // vuelve a ser 6

    // 4. Shadowing puede cambiar el TIPO (mut no puede).
    let espacios = "   "; // &str (texto)
    let espacios = espacios.len(); // usize (numero)
    println!("espacios: {espacios}");

    // 5. Constantes.
    println!("Maximo de alumnos: {MAX_ALUMNOS}");
    println!("Una hora tiene {SEGUNDOS_POR_HORA} segundos");
}
