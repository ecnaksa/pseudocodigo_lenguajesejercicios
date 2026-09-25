// Ejercicio 3 - Varios print! en la misma linea.
//   rustc --edition 2021 en_una_linea.rs && ./en_una_linea
//
// Salida:
//   1 2 3 4 5

fn main() {
    print!("1 ");
    print!("2 ");
    print!("3 ");
    print!("4 ");
    print!("5");
    println!(); // cierra la linea
}
