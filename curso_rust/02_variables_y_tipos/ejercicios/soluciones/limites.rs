// Ejercicio 2 - Limites de los tipos enteros.
//   rustc --edition 2021 limites.rs && ./limites
//
// Un u8 tiene 8 bits: 2^8 = 256 valores -> 0..=255.
// Un i8 tambien tiene 256 valores, pero repartidos entre negativos y positivos.
// Con complemento a dos, el 0 "ocupa" un valor del lado no negativo: -128..=127.

fn main() {
    println!("i8:  {} .. {}", i8::MIN, i8::MAX);
    println!("u8:  {} .. {}", u8::MIN, u8::MAX);
    println!("i16: {} .. {}", i16::MIN, i16::MAX);
    println!("u16: {} .. {}", u16::MIN, u16::MAX);
    println!("i32: {} .. {}", i32::MIN, i32::MAX);
    println!("u32: {} .. {}", u32::MIN, u32::MAX);
    println!("i64: {} .. {}", i64::MIN, i64::MAX);
    println!("u64: {} .. {}", u64::MIN, u64::MAX);
}
