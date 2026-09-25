// Ejercicio 7 (reto) - Rotar un arreglo con sub-slices mutables.
//   rustc --edition 2021 rotar.rs && ./rotar
//
// Salida:
//   original:          [1, 2, 3, 4, 5, 6, 7]
//   rotado 3:          [4, 5, 6, 7, 1, 2, 3]
//   con split_at_mut:  izquierda = [1, 2, 3], derecha = [40, 50, 60, 70]
//
// Tener `&mut arr[..k]` y `&mut arr[k..]` a la vez NO compila:
//   error[E0499]: cannot borrow `arr` as mutable more than once at a time
// El compilador no analiza los rangos: solo ve dos prestamos mutables de `arr`.
// split_at_mut(k) resuelve el caso (internamente garantiza que las dos partes no se solapan)
// y devuelve una tupla con las dos mitades mutables.

fn main() {
    let mut arr = [1, 2, 3, 4, 5, 6, 7];
    println!("original:          {:?}", arr);
    rotar_izquierda(&mut arr, 3);
    println!("rotado 3:          {:?}", arr);

    // Dos mitades mutables a la vez, de forma segura:
    let mut datos = [1, 2, 3, 4, 5, 6, 7];
    let (izquierda, derecha) = datos.split_at_mut(3);
    for x in derecha.iter_mut() {
        *x *= 10; // modificamos solo la derecha...
    }
    println!("con split_at_mut:  izquierda = {:?}, derecha = {:?}", izquierda, derecha);
}

/// Rota k posiciones a la izquierda con tres inversiones:
/// [1 2 3 | 4 5 6 7] -> [3 2 1 | 7 6 5 4] -> [4 5 6 7 1 2 3]
fn rotar_izquierda(arr: &mut [i32], k: usize) {
    if arr.is_empty() {
        return;
    }
    let k = k % arr.len(); // rotar len posiciones es no hacer nada
    invierte_arreglo(&mut arr[..k]); // sub-slice mutable: primera parte
    invierte_arreglo(&mut arr[k..]); // luego la segunda (el prestamo anterior ya termino)
    invierte_arreglo(arr); // y todo
}

fn invierte_arreglo(arr: &mut [i32]) {
    let n = arr.len();
    for i in 0..n / 2 {
        arr.swap(i, n - 1 - i);
    }
}
