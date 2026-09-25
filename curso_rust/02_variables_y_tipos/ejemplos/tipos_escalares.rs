// Leccion 02 - Tipos escalares: enteros, flotantes, bool, char.
//
//   rustc --edition 2021 tipos_escalares.rs && ./tipos_escalares

fn main() {
    // ----- Enteros -----
    let a = 42; // sin anotacion: i32 por defecto
    let b: u8 = 255; // entero sin signo de 8 bits (su maximo)
    let c: i64 = -9_000_000_000; // no cabe en i32
    let indice: usize = 3; // tipo de indices y tamanios
    println!("a={a} b={b} c={c} indice={indice}");

    // Limites de cada tipo (constantes asociadas MIN y MAX)
    println!("i8:  {} .. {}", i8::MIN, i8::MAX);
    println!("u8:  {} .. {}", u8::MIN, u8::MAX);
    println!("i32: {} .. {}", i32::MIN, i32::MAX);
    println!("u64: {} .. {}", u64::MIN, u64::MAX);

    // Literales en distintas bases
    let millon = 1_000_000;
    let hex = 0xff;
    let octal = 0o77;
    let binario = 0b1111_0000;
    let byte = b'A'; // u8 con el codigo ASCII de 'A'
    let con_sufijo = 42u8;
    println!("{millon} {hex} {octal} {binario} {byte} {con_sufijo}");

    // ----- Flotantes -----
    let x = 2.5; // f64 por defecto
    let y: f32 = 3.25;
    println!("x={x} y={y}");
    println!("0.1 + 0.2 = {}", 0.1 + 0.2); // 0.30000000000000004 (IEEE-754)
    let diferencia: f64 = (0.1 + 0.2) - 0.3;
    println!("casi iguales? {}", diferencia.abs() < 1e-9); // true

    // ----- Booleanos -----
    let activo = true;
    let terminado: bool = false;
    println!("activo={activo} terminado={terminado}");

    // ----- Caracteres (Unicode, 4 bytes) -----
    let letra = 'a';
    let enie = '\u{00F1}'; // la letra "enie" escrita con su codigo Unicode (U+00F1)
    let omega = '\u{03A9}'; // letra griega omega mayuscula (U+03A9)
    println!("letra={letra} codigos: {} {} {}", letra as u32, enie as u32, omega as u32);

    // ----- Tamanio en memoria (en bytes) -----
    println!("i32:  {} bytes", std::mem::size_of::<i32>());
    println!("u8:   {} bytes", std::mem::size_of::<u8>());
    println!("i128: {} bytes", std::mem::size_of::<i128>());
    println!("f64:  {} bytes", std::mem::size_of::<f64>());
    println!("bool: {} bytes", std::mem::size_of::<bool>());
    println!("char: {} bytes", std::mem::size_of::<char>());
    println!("usize: {} bytes (en esta maquina)", std::mem::size_of::<usize>());
}
