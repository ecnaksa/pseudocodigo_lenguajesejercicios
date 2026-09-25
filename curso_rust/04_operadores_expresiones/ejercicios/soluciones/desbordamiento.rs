// Ejercicio 6 (reto) - Las cuatro estrategias ante el desbordamiento.
//   rustc --edition 2021 desbordamiento.rs && echo "200 100" | ./desbordamiento
//
// Salida con "200 100":
//   SUMA 200 + 100
//     checked:     None
//     wrapping:    44
//     saturating:  255
//     overflowing: (44, true)
//   PRODUCTO 200 * 100
//     checked:     None
//     wrapping:    32
//     saturating:  255
//     overflowing: (32, true)
//   La suma real (300) es el 117.6% del maximo de u8 (255)

use std::io;

fn main() {
    println!("Dos numeros entre 0 y 255:");
    let mut linea = String::new();
    io::stdin().read_line(&mut linea).expect("Error al leer");
    let mut partes = linea.split_whitespace();
    let a: u8 = partes.next().expect("Falta a").parse().expect("a debe estar entre 0 y 255");
    let b: u8 = partes.next().expect("Falta b").parse().expect("b debe estar entre 0 y 255");

    println!("SUMA {a} + {b}");
    println!("  checked:     {:?}", a.checked_add(b));
    println!("  wrapping:    {}", a.wrapping_add(b));
    println!("  saturating:  {}", a.saturating_add(b));
    println!("  overflowing: {:?}", a.overflowing_add(b));

    println!("PRODUCTO {a} * {b}");
    println!("  checked:     {:?}", a.checked_mul(b));
    println!("  wrapping:    {}", a.wrapping_mul(b));
    println!("  saturating:  {}", a.saturating_mul(b));
    println!("  overflowing: {:?}", a.overflowing_mul(b));

    // En u16 la suma nunca desborda (como maximo 255 + 255 = 510).
    let suma_real = u16::from(a) + u16::from(b);

    // Bloque como expresion: la variable auxiliar `maximo` solo existe dentro.
    let porcentaje = {
        let maximo = f64::from(u8::MAX);
        f64::from(suma_real) / maximo * 100.0 // <- valor del bloque (sin ;)
    };
    println!(
        "La suma real ({suma_real}) es el {porcentaje:.1}% del maximo de u8 ({})",
        u8::MAX
    );
}
