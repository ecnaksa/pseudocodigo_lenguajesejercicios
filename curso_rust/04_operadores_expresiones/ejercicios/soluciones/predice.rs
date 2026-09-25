// Ejercicio 5 - Resultados de las conversiones, con su explicacion.
//   rustc --edition 2021 predice.rs && ./predice

fn main() {
    // 1000 = 0b11_1110_1000; se quedan los 8 bits bajos: 1110_1000 = 232
    println!("1000 as u8          = {}", 1000_i32 as u8);
    // -128 en i8 es 1000_0000; leido como u8 es 128
    println!("-128i8 as u8        = {}", -128i8 as u8);
    // 255 en u8 es 1111_1111; leido como i8 (complemento a dos) es -1
    println!("255u8 as i8         = {}", 255u8 as i8);
    // flotante -> entero: trunca
    println!("2.9 as u8           = {}", 2.9_f64 as u8);
    // trunca hacia cero: -0.9 -> 0
    println!("-0.9 as i32         = {}", -0.9_f64 as i32);
    // fuera de rango: satura en u8::MAX
    println!("300.7 as u8         = {}", 300.7_f64 as u8);
    let z = 'z';
    println!("'z' as u8           = {}", z as u8); // codigo Unicode de 'z' (cabe en u8)
    println!("122u8 as char       = {}", 122u8 as char);
    // try_from comprueba: 1000 no cabe en u8
    println!("u8::try_from(1000)  = {:?}", u8::try_from(1000_i32));
    // from solo existe si nunca se pierde informacion: i32 -> i64 siempre cabe
    println!("i64::from(-5i32)    = {}", i64::from(-5i32));
}
