//! Leccion 06 - Un programa organizado en funciones pequenias y documentadas.
//!
//! (Este comentario `//!` documenta el archivo entero; los `///` documentan
//! la funcion que tienen debajo.)
//!
//!   rustc --edition 2021 conversor_documentado.rs && echo "25" | ./conversor_documentado
//!
//! Salida con 25:
//!   Temperatura en Celsius:
//!     25.0 C =  77.0 F
//!     25.0 C = 298.1 K
//!   Sensacion: agradable

use std::io;

fn main() {
    let celsius = leer_numero("Temperatura en Celsius:");
    mostrar_conversiones(celsius);
    println!("Sensacion: {}", sensacion(celsius));
}

/// Muestra `mensaje`, lee una linea del teclado y la convierte a `f64`.
///
/// # Panics
///
/// Detiene el programa si no se puede leer o si el texto no es un numero.
fn leer_numero(mensaje: &str) -> f64 {
    println!("{mensaje}");
    let mut entrada = String::new();
    io::stdin().read_line(&mut entrada).expect("Error al leer");
    entrada.trim().parse().expect("Debe ser un numero")
}

/// Convierte grados Celsius a Fahrenheit.
///
/// # Ejemplos
///
/// ```
/// assert_eq!(celsius_a_fahrenheit(100.0), 212.0);
/// ```
fn celsius_a_fahrenheit(c: f64) -> f64 {
    c * 9.0 / 5.0 + 32.0
}

/// Convierte grados Celsius a Kelvin.
fn celsius_a_kelvin(c: f64) -> f64 {
    c + 273.15
}

/// Imprime la temperatura en las tres escalas, alineada.
fn mostrar_conversiones(c: f64) {
    println!("  {:5.1} C = {:5.1} F", c, celsius_a_fahrenheit(c));
    println!("  {:5.1} C = {:5.1} K", c, celsius_a_kelvin(c));
}

/// Describe con palabras como se siente la temperatura.
fn sensacion(c: f64) -> &'static str {
    // (&'static str = un texto literal, que vive durante todo el programa; leccion 14)
    if c < 10.0 {
        "frio"
    } else if c < 20.0 {
        "fresco"
    } else if c < 28.0 {
        "agradable"
    } else {
        "calor"
    }
}
