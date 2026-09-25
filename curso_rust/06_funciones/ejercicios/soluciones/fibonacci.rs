// Ejercicio 5 - Fibonacci recursivo vs iterativo (los tiempos varian segun la maquina).
//   rustc --edition 2021 fibonacci.rs && ./fibonacci
//
// Salida aproximada:
//   n = 0..=20 coinciden: true
//   fib_iterativo(35) = 9227465   en 387ns
//   fib_recursivo(35) = 9227465   en 87.918932ms
//
// Por que el recursivo es lento: fib(35) llama a fib(34) y fib(33); fib(34) vuelve a llamar
// a fib(33)... cada valor se recalcula muchisimas veces. El numero de llamadas crece como
// ~1.6^n (unos 30 millones para n = 35). El iterativo hace solo n sumas.

use std::time::Instant;

fn main() {
    let mut coinciden = true;
    for n in 0..=20 {
        if fib_recursivo(n) != fib_iterativo(n) {
            coinciden = false;
        }
    }
    println!("n = 0..=20 coinciden: {coinciden}");

    let inicio = Instant::now();
    let r = fib_iterativo(35);
    println!("fib_iterativo(35) = {r}   en {:?}", inicio.elapsed());

    let inicio = Instant::now();
    let r = fib_recursivo(35);
    println!("fib_recursivo(35) = {r}   en {:?}", inicio.elapsed());
}

fn fib_recursivo(n: u32) -> u64 {
    if n < 2 {
        n as u64
    } else {
        fib_recursivo(n - 1) + fib_recursivo(n - 2)
    }
}

fn fib_iterativo(n: u32) -> u64 {
    let (mut anterior, mut actual) = (0u64, 1u64); // F(0), F(1)
    for _ in 0..n {
        let siguiente = anterior + actual;
        anterior = actual;
        actual = siguiente;
    }
    anterior // tras n pasos, `anterior` es F(n)
}
