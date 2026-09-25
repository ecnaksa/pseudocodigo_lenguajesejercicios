// Leccion 06 - Recursion: factorial, Fibonacci, MCD y potencia rapida.
//
//   rustc --edition 2021 recursion.rs && ./recursion
//
// Salida:
//   5! = 120
//   20! = 2432902008176640000
//   Fibonacci: 0 1 1 2 3 5 8 13 21 34 55
//   mcd(48, 18) = 6
//   2^10 = 1024
//   3^13 = 1594323
//   suma de digitos de 98765 = 35

fn main() {
    println!("5! = {}", factorial(5));
    println!("20! = {}", factorial(20));

    print!("Fibonacci:");
    for i in 0..=10 {
        print!(" {}", fibonacci(i));
    }
    println!();

    println!("mcd(48, 18) = {}", mcd(48, 18));
    println!("2^10 = {}", potencia(2, 10));
    println!("3^13 = {}", potencia(3, 13));
    println!("suma de digitos de 98765 = {}", suma_digitos(98765));
}

/// n! = 1 si n <= 1;  n * (n-1)! en otro caso.
fn factorial(n: u64) -> u64 {
    if n <= 1 {
        1 // caso base
    } else {
        n * factorial(n - 1) // caso recursivo
    }
}

/// F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2).
/// (Didactico pero lento: recalcula los mismos valores muchas veces; ver ejercicio 6.)
fn fibonacci(n: u32) -> u64 {
    match n {
        0 => 0,
        1 => 1,
        _ => fibonacci(n - 1) + fibonacci(n - 2),
    }
}

/// Maximo comun divisor por el algoritmo de Euclides: mcd(a, 0) = a; mcd(a, b) = mcd(b, a % b).
fn mcd(a: u64, b: u64) -> u64 {
    if b == 0 { a } else { mcd(b, a % b) }
}

/// Potencia rapida ("exponenciacion binaria"): O(log n) multiplicaciones en vez de n.
/// b^n = (b^(n/2))^2 si n es par;  b * b^(n-1) si es impar.
fn potencia(base: u64, exp: u32) -> u64 {
    if exp == 0 {
        return 1;
    }
    if exp & 1 == 0 {
        // bit 0 apagado = exponente par (leccion 04)
        let mitad = potencia(base, exp / 2);
        mitad * mitad
    } else {
        base * potencia(base, exp - 1)
    }
}

/// Suma de digitos: ultimo digito (n % 10) + suma de los digitos del resto (n / 10).
fn suma_digitos(n: u64) -> u64 {
    if n < 10 { n } else { n % 10 + suma_digitos(n / 10) }
}
