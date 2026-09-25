// Leccion 04 - Operadores aritmeticos, logicos, de bits y metodos numericos.
//
//   rustc --edition 2021 aritmetica.rs && ./aritmetica

fn main() {
    // ----- Aritmeticos -----
    println!("7 + 2 = {}", 7 + 2);
    println!("7 / 2 = {} (division entera)", 7 / 2);
    println!("7.0 / 2.0 = {}", 7.0 / 2.0);
    println!("-7 / 2 = {} (trunca hacia cero)", -7 / 2);
    println!("-7 % 2 = {} (signo del dividendo)", -7 % 2);
    println!("(-7).rem_euclid(2) = {}", (-7i32).rem_euclid(2));
    println!("(-7).div_euclid(2) = {}", (-7i32).div_euclid(2));

    // Division entre flotantes por cero: no hay panic, hay infinito / NaN.
    println!("1.0 / 0.0 = {}", 1.0 / 0.0);
    let numerador = 0.0_f64;
    let denominador = 0.0_f64;
    let nan = numerador / denominador;
    let otro_nan = f64::NAN;
    println!("0.0 / 0.0 es NaN? {}  NaN == NaN? {}", nan.is_nan(), nan == otro_nan);

    // ----- Asignacion compuesta (no existe ++) -----
    let mut total = 10;
    total += 5;
    total *= 2;
    total %= 7;
    println!("total = {total}"); // ((10 + 5) * 2) % 7 = 2

    // ----- Comparacion y logicos (cortocircuito) -----
    let edad = 20;
    let tiene_entrada = true;
    println!("puede entrar? {}", edad >= 18 && tiene_entrada);
    let divisor = 0;
    // Gracias al cortocircuito, 100 / divisor NUNCA se evalua cuando divisor == 0.
    println!("seguro? {}", divisor != 0 && 100 / divisor > 10);

    // ----- Bits -----
    let a: u8 = 0b1100;
    let b: u8 = 0b1010;
    println!("{a:04b} & {b:04b} = {:04b}", a & b);
    println!("{a:04b} | {b:04b} = {:04b}", a | b);
    println!("{a:04b} ^ {b:04b} = {:04b}", a ^ b);
    println!("!0u8 = {}", !0u8);
    println!("1 << 3 = {}   16 >> 2 = {}", 1 << 3, 16 >> 2);

    // Encender, apagar y consultar un bit (tipico en registros de hardware)
    let mut registro: u8 = 0;
    registro |= 1 << 2; // enciende el bit 2
    registro |= 1 << 0; // enciende el bit 0
    println!("registro = {registro:08b}");
    registro &= !(1 << 2); // apaga el bit 2
    println!("registro = {registro:08b}");
    println!("bit 0 encendido? {}", registro & 1 != 0);

    // ----- Metodos numericos -----
    let x: f64 = 2.0;
    println!("sqrt(2) = {:.4}", x.sqrt());
    println!("2^3 = {}  2^0.5 = {:.4}", x.powi(3), x.powf(0.5));
    println!("2^10 = {}", 2i32.pow(10));
    println!("round(2.5)={} round(-2.5)={} floor(2.7)={} ceil(2.1)={} trunc(2.7)={}",
        2.5f64.round(), (-2.5f64).round(), 2.7f64.floor(), 2.1f64.ceil(), 2.7f64.trunc());
    let (p, q) = (7, 3);
    println!("min={} max={} clamp={}", p.min(q), p.max(q), 15.clamp(0, 10));

    // Trampa de precedencia: el metodo se aplica antes que el menos unario.
    println!("-5i32.abs()   = {}", -5i32.abs()); // -(5.abs()) = -5
    println!("(-5i32).abs() = {}", (-5i32).abs()); // 5
}
