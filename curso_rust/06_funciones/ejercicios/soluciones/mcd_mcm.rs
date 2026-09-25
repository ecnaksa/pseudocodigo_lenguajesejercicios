// Ejercicio 4 - MCD iterativo y MCM.
//   rustc --edition 2021 mcd_mcm.rs && ./mcd_mcm
//
// Salida:
//   mcd(12, 18) = 6    mcm(12, 18) = 36
//   mcd(7, 13) = 1    mcm(7, 13) = 91
//   mcd(100, 75) = 25    mcm(100, 75) = 300
//
// Por que dividir antes de multiplicar: a * b puede desbordar aunque el MCM si quepa.
// a / mcd(a, b) es exacto (mcd divide a `a`), y el producto posterior es mas pequenio.

fn main() {
    for (a, b) in [(12, 18), (7, 13), (100, 75)] {
        println!("mcd({a}, {b}) = {}    mcm({a}, {b}) = {}", mcd(a, b), mcm(a, b));
    }
}

/// Algoritmo de Euclides, version iterativa.
fn mcd(mut a: u64, mut b: u64) -> u64 {
    while b != 0 {
        let resto = a % b;
        a = b;
        b = resto;
    }
    a
}

fn mcm(a: u64, b: u64) -> u64 {
    a / mcd(a, b) * b
}
