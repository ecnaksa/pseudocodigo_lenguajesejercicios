// Ejercicio 6 - Funcion reutilizable de lectura validada.
//   rustc --edition 2021 fecha.rs && printf "2024\n13\n2\n30\n29\n" | ./fecha
//
// Salida con esa entrada:
//   Anio (1-9999): Mes (1-12): Fuera de rango (1-12). Intenta de nuevo.
//   Mes (1-12): Dia (1-29): Fuera de rango (1-29). Intenta de nuevo.
//   Dia (1-29): Fecha valida: 29/02/2024

use std::io::{self, Write};

fn main() {
    let anio = leer_entero_en_rango("Anio", 1, 9999);
    let mes = leer_entero_en_rango("Mes", 1, 12);
    let max_dia = dias_en_mes(mes as u32, anio) as i32;
    let dia = leer_entero_en_rango("Dia", 1, max_dia);
    println!("Fecha valida: {dia:02}/{mes:02}/{anio}");
}

/// Pregunta hasta obtener un entero en [min, max].
fn leer_entero_en_rango(mensaje: &str, min: i32, max: i32) -> i32 {
    loop {
        print!("{mensaje} ({min}-{max}): ");
        io::stdout().flush().expect("No se pudo vaciar stdout");
        let mut entrada = String::new();
        io::stdin().read_line(&mut entrada).expect("Error al leer");
        match entrada.trim().parse::<i32>() {
            Ok(n) if n >= min && n <= max => return n, // return dentro del loop: sale de la funcion
            Ok(_) => println!("Fuera de rango ({min}-{max}). Intenta de nuevo."),
            Err(_) => println!("No es un numero entero. Intenta de nuevo."),
        }
    }
}

fn es_bisiesto(anio: i32) -> bool {
    (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0
}

fn dias_en_mes(mes: u32, anio: i32) -> u32 {
    match mes {
        1 | 3 | 5 | 7 | 8 | 10 | 12 => 31,
        4 | 6 | 9 | 11 => 30,
        2 if es_bisiesto(anio) => 29, // guarda: el brazo solo aplica si la condicion se cumple
        2 => 28,
        _ => 0,
    }
}
