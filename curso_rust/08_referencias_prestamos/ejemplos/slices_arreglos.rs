// Leccion 08 - Slices de arreglos: ejercicios 01, 12, 13 y 14 del repositorio en Rust.
// Compara con ../../../soluciones/c/ejercicio01.c, ejercicio12.c, ejercicio13.c y ejercicio14.c
//
//   rustc --edition 2021 slices_arreglos.rs && ./slices_arreglos
//
// Salida:
//   parte de a: [20, 30, 40] (3 elementos)
//   suma(a) = 150   suma(parte) = 90   suma([1, 2, 3]) = 6
//   invertido: [50, 40, 30, 20, 10]
//   [1, 2, 3, 2, 1] es palindromo? true
//   [1, 2, 3] es palindromo? false
//   ordenado: [-7, -1, 4, 5, 9, 12]

fn main() {
    let a = [10, 20, 30, 40, 50];
    let parte: &[i32] = &a[1..4];
    println!("parte de a: {:?} ({} elementos)", parte, parte.len());

    // Ejercicio 01: la misma funcion sirve para arreglos de cualquier tamanio y para partes.
    println!(
        "suma(a) = {}   suma(parte) = {}   suma([1, 2, 3]) = {}",
        suma_elementos(&a),
        suma_elementos(parte),
        suma_elementos(&[1, 2, 3])
    );

    // Ejercicio 12: invertir EN SITIO (slice mutable).
    let mut b = a; // copia (arreglo de i32 es Copy)
    invierte_arreglo(&mut b);
    println!("invertido: {:?}", b);

    // Ejercicio 13: palindromo (solo lectura).
    for arr in [&[1, 2, 3, 2, 1][..], &[1, 2, 3][..]] {
        println!("{:?} es palindromo? {}", arr, es_palindromo(arr));
    }

    // Ejercicio 14: burbuja (slice mutable).
    let mut c = [4, -7, 12, 9, -1, 5];
    ordena_burbuja(&mut c);
    println!("ordenado: {:?}", c);
}

// En C:  int sumaElementos(int Arr[], int tam)  -> el tamanio va aparte.
// En Rust el slice lleva su longitud: imposible pasar un tamanio equivocado.
fn suma_elementos(arr: &[i32]) -> i32 {
    let mut suma = 0;
    for x in arr {
        // x es &i32; `suma += x` funciona porque += acepta &i32 (se desreferencia solo)
        suma += x;
    }
    suma
}

fn invierte_arreglo(arr: &mut [i32]) {
    let n = arr.len();
    for i in 0..n / 2 {
        arr.swap(i, n - 1 - i);
    }
}

fn es_palindromo(arr: &[i32]) -> bool {
    let n = arr.len();
    for i in 0..n / 2 {
        if arr[i] != arr[n - 1 - i] {
            return false;
        }
    }
    true
}

fn ordena_burbuja(arr: &mut [i32]) {
    let n = arr.len();
    for pasada in 0..n {
        let mut hubo_cambios = false;
        for j in 0..n - 1 - pasada {
            if arr[j] > arr[j + 1] {
                arr.swap(j, j + 1);
                hubo_cambios = true;
            }
        }
        if !hubo_cambios {
            break; // ya esta ordenado
        }
    }
}
