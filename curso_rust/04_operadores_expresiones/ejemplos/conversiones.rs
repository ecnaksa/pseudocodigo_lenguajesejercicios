// Leccion 04 - Conversiones (as, from, try_from) y desbordamiento.
//
//   rustc --edition 2021 conversiones.rs && ./conversiones

fn main() {
    // ----- as: explicito, pero sin comprobaciones -----
    println!("200u8 as i32     = {}", 200u8 as i32); // sin perdida
    println!("300i32 as u8     = {}", 300i32 as u8); // 44: se quedan los 8 bits bajos
    println!("-1i32 as u32     = {}", -1i32 as u32); // 4294967295: mismos bits
    println!("3.99 as i32      = {}", 3.99_f64 as i32); // 3: trunca
    println!("-3.99 as i32     = {}", -3.99_f64 as i32); // -3: trunca hacia cero
    println!("1e10 as i32      = {}", 1e10_f64 as i32); // satura en i32::MAX
    println!("-1.5 as u8       = {}", -1.5_f64 as u8); // satura en 0
    let no_es_numero: f64 = "NaN".parse().expect("f64 acepta el texto NaN");
    println!("NaN as i32       = {}", no_es_numero as i32); // 0
    println!("true as i32      = {}", true as i32);
    let letra = 'A';
    println!("'A' as u8        = {}", letra as u8); // (para un literal ASCII, b'A' es mas directo)
    println!("97u8 as char     = {}", 97u8 as char);

    // Caso real: promedio de enteros. Hay que convertir ANTES de dividir.
    let suma: i32 = 47;
    let cantidad: i32 = 6;
    println!("promedio mal   = {}", suma / cantidad); // 7 (division entera)
    println!("promedio bien  = {:.2}", suma as f64 / cantidad as f64); // 7.83

    // ----- from / try_from: conversiones comprobadas -----
    let pequeno: i32 = 1_000;
    let grande = i64::from(pequeno); // nunca pierde informacion
    println!("i64::from(1000)     = {grande}");
    println!("u8::try_from(200)   = {:?}", u8::try_from(200i32));
    println!("u8::try_from(300)   = {:?}", u8::try_from(300i32));
    println!("u8::try_from(-1)    = {:?}", u8::try_from(-1i32));

    // ----- Desbordamiento: elegir el comportamiento explicitamente -----
    let x: u8 = 250;
    println!("checked_add(10)     = {:?}", x.checked_add(10)); // None
    println!("checked_add(5)      = {:?}", x.checked_add(5)); // Some(255)
    println!("wrapping_add(10)    = {}", x.wrapping_add(10)); // 4
    println!("saturating_add(10)  = {}", x.saturating_add(10)); // 255
    println!("overflowing_add(10) = {:?}", x.overflowing_add(10)); // (4, true)
    println!("saturating_sub(255) = {}", x.saturating_sub(255)); // 0, no negativo

    // let y = x + 10;  // si 10 fuera un valor leido al ejecutar: panic en debug
    //                  // "attempt to add with overflow"; en release daria 4.
}
