// Ejercicio 7 - Ejercicios 01-04 del repositorio (arreglos) resueltos en Rust.
//   rustc --edition 2021 arreglos_basicos.rs && ./arreglos_basicos
//
// Salida:
//   Arreglo: [4, -7, 12, 9, -1, 12, 5]
//   1) Suma: 34
//   2) Minimo: -7
//   3) Impares: 4
//   4) Posicion de 12: 2
//      Posicion de 100: -1
//
// Diferencia con C: en C las funciones reciben `int Arr[], int tam` porque un arreglo
// no "sabe" su tamanio. En Rust, `a.len()` siempre esta disponible, y `for x in a`
// recorre los elementos sin posibilidad de salirse del arreglo.

fn main() {
    let a = [4, -7, 12, 9, -1, 12, 5];
    println!("Arreglo: {:?}", a);

    // 1) Suma de los elementos (acumulador)
    let mut suma = 0;
    for x in a {
        suma += x;
    }
    println!("1) Suma: {suma}");

    // 2) Minimo: empezar con el PRIMER elemento (no con 0, el error del pseudocodigo original)
    let mut minimo = a[0];
    for x in a {
        if x < minimo {
            minimo = x;
        }
    }
    println!("2) Minimo: {minimo}");

    // 3) Cantidad de impares (contador). x % 2 != 0 funciona tambien con negativos (-7 % 2 == -1).
    let mut impares = 0;
    for x in a {
        if x % 2 != 0 {
            impares += 1;
        }
    }
    println!("3) Impares: {impares}");

    // 4) Busqueda: primera posicion de un valor, o -1 si no esta.
    for buscado in [12, 100] {
        let mut posicion: i32 = -1;
        for (i, x) in a.iter().enumerate() {
            if *x == buscado {
                // *x: "el valor al que apunta x" (se explica en la leccion 08)
                posicion = i as i32;
                break; // la primera aparicion
            }
        }
        if buscado == 12 {
            println!("4) Posicion de {buscado}: {posicion}");
        } else {
            println!("   Posicion de {buscado}: {posicion}");
        }
    }
    // (En la leccion 10 veras que en Rust es mas idiomatico devolver un Option<usize>
    //  -Some(posicion) o None- en lugar de usar -1 como "valor especial".)
}
