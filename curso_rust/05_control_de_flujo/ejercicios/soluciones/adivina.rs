// Ejercicio 8 (reto) - Adivina el numero.
//   rustc --edition 2021 adivina.rs && ./adivina
//   Prueba automatica (intenta 1, 2, 3, ... hasta acertar):  seq 1 100 | ./adivina

use std::io::{self, Write};
use std::time::{SystemTime, UNIX_EPOCH};

fn main() {
    // "Aleatorio" casero: los nanosegundos del reloj del sistema (entre 1 y 100).
    let nanos = SystemTime::now()
        .duration_since(UNIX_EPOCH)
        .expect("El reloj del sistema esta antes de 1970")
        .subsec_nanos();
    let secreto = nanos % 100 + 1;

    println!("He pensado un numero entre 1 y 100. Adivinalo!");
    let mut intentos = 0;

    loop {
        print!("Tu intento: ");
        io::stdout().flush().expect("No se pudo vaciar stdout");

        let mut entrada = String::new();
        let bytes = io::stdin().read_line(&mut entrada).expect("Error al leer");
        if bytes == 0 {
            // read_line devuelve 0 bytes cuando la entrada se termino (Ctrl+D o fin del archivo)
            println!();
            println!("Se acabo la entrada. El numero era {secreto}.");
            break;
        }

        let intento: u32 = match entrada.trim().parse() {
            Ok(n) => n,
            Err(_) => {
                println!("Escribe un numero entero.");
                continue; // no cuenta como intento
            }
        };
        intentos += 1;

        if intento < secreto {
            println!("Mas alto.");
        } else if intento > secreto {
            println!("Mas bajo.");
        } else {
            println!("Correcto! El numero era {secreto}. Lo lograste en {intentos} intentos.");
            break;
        }
    }
}
