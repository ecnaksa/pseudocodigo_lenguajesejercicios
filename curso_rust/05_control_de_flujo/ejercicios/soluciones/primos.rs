// Ejercicio 6 - Primos menores que 100 (division por tanteo hasta la raiz).
//   rustc --edition 2021 primos.rs && ./primos
//
// Salida:
//   2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
//   Hay 25 primos menores que 100.

fn main() {
    let mut cantidad = 0;

    for n in 2..100 {
        let mut es_primo = true;
        let mut d = 2;
        // Basta probar hasta sqrt(n): si n = a * b, uno de los dos es <= sqrt(n).
        while d * d <= n {
            if n % d == 0 {
                es_primo = false;
                break;
            }
            d += 1;
        }
        if es_primo {
            print!("{n} ");
            cantidad += 1;
        }
    }
    println!();
    println!("Hay {cantidad} primos menores que 100.");
}
