// Leccion 05 - Menu interactivo: loop + match.
//
//   rustc --edition 2021 menu.rs && ./menu
//   printf "1\n5\n2\n3\n9\n3\n0\n" | ./menu
//
// Un contador que se puede subir, bajar, reiniciar y consultar.

use std::io::{self, Write};

fn main() {
    let mut contador: i32 = 0;

    loop {
        println!();
        println!("== MENU == (contador = {contador})");
        println!("1) Sumar 1");
        println!("2) Restar 1");
        println!("3) Reiniciar");
        println!("0) Salir");
        print!("Opcion: ");
        io::stdout().flush().expect("No se pudo vaciar stdout");

        let mut entrada = String::new();
        io::stdin().read_line(&mut entrada).expect("Error al leer");

        match entrada.trim() {
            "1" => contador += 1,
            "2" => contador -= 1,
            "3" => {
                contador = 0;
                println!("Contador reiniciado.");
            }
            "0" => {
                println!("Hasta luego! Valor final: {contador}");
                break;
            }
            otra => println!("Opcion {:?} no valida.", otra),
        }
    }
}
