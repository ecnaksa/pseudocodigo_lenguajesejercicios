// Ejercicio 6 - Ejercicios 05, 06 y 15 del repositorio con slices.
//   rustc --edition 2021 repositorio.rs && ./repositorio
//
// Salida:
//   arreglo: [4, 7, 4, 2, 7, 7, 9, 2]
//   05) suma de pares: 12
//   06) repeticiones de 7: 3
//   15) sin duplicados: [4, 7, 2, 9] (nuevo tamanio 4)

fn main() {
    let mut arr = [4, 7, 4, 2, 7, 7, 9, 2];
    println!("arreglo: {:?}", arr);
    println!("05) suma de pares: {}", suma_pares(&arr));
    println!("06) repeticiones de 7: {}", cuenta_repeticiones(&arr, 7));

    let nuevo_tam = elimina_duplicados(&mut arr);
    println!("15) sin duplicados: {:?} (nuevo tamanio {nuevo_tam})", &arr[..nuevo_tam]);
}

fn suma_pares(arr: &[i32]) -> i32 {
    let mut suma = 0;
    for &x in arr {
        if x % 2 == 0 {
            suma += x;
        }
    }
    suma
}

fn cuenta_repeticiones(arr: &[i32], x: i32) -> usize {
    let mut cuenta = 0;
    for &valor in arr {
        if valor == x {
            cuenta += 1;
        }
    }
    cuenta
}

/// Deja los valores unicos (en su orden de primera aparicion) al principio del slice
/// y devuelve cuantos son. Lo que quede despues de esa posicion no importa.
fn elimina_duplicados(arr: &mut [i32]) -> usize {
    let mut tam = 0; // cantidad de unicos encontrados hasta ahora (ocupan arr[..tam])
    for i in 0..arr.len() {
        let actual = arr[i];
        // Ya esta entre los unicos? `contains` busca en el sub-slice arr[..tam].
        if !arr[..tam].contains(&actual) {
            arr[tam] = actual;
            tam += 1;
        }
    }
    tam
}
