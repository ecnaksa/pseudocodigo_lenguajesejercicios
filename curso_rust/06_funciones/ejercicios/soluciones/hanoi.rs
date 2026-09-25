// Ejercicio 7 (reto) - Torres de Hanoi.
//   rustc --edition 2021 hanoi.rs && ./hanoi
//
// Salida (inicio):
//   Movimientos para 3 discos:
//     disco 1: A -> C
//     disco 2: A -> B
//     disco 1: C -> B
//     disco 3: A -> C
//     disco 1: B -> A
//     disco 2: B -> C
//     disco 1: A -> C
//   Total: 7
//
// La cantidad sigue la formula 2^n - 1: cada disco extra duplica el trabajo y suma uno.
// Con 64 discos (la leyenda) serian 18446744073709551615 movimientos.

fn main() {
    println!("Movimientos para 3 discos:");
    let total = hanoi(3, 'A', 'C', 'B', true);
    println!("Total: {total}");
    println!();

    println!(" n  movimientos   2^n - 1");
    for n in 1..=20 {
        let movimientos = hanoi(n, 'A', 'C', 'B', false);
        println!("{n:2}  {movimientos:11}  {:8}", 2u64.pow(n) - 1);
    }
}

/// Mueve `n` discos de `origen` a `destino` usando `auxiliar`. Devuelve cuantos movimientos hizo.
fn hanoi(n: u32, origen: char, destino: char, auxiliar: char, imprimir: bool) -> u64 {
    if n == 0 {
        return 0; // caso base: nada que mover
    }
    // 1. Los n-1 discos de arriba, de origen a auxiliar (usando destino como apoyo)
    let antes = hanoi(n - 1, origen, auxiliar, destino, imprimir);
    // 2. El disco mas grande, de origen a destino
    if imprimir {
        println!("  disco {n}: {origen} -> {destino}");
    }
    // 3. Los n-1 discos, de auxiliar a destino (usando origen como apoyo)
    let despues = hanoi(n - 1, auxiliar, destino, origen, imprimir);
    antes + 1 + despues
}
