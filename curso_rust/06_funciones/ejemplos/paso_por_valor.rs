// Leccion 06 - Paso de argumentos por copia y adelanto de &mut.
//
//   rustc --edition 2021 paso_por_valor.rs && ./paso_por_valor
//
// Salida:
//   dentro de incrementar_copia: 6
//   fuera: 5
//   arreglo dentro: [100, 2, 3]
//   arreglo fuera:  [1, 2, 3]
//   con &mut: 6
//   notas con bonificacion: [16, 19, 13]

fn main() {
    // 1. Los enteros se COPIAN al pasarlos: la funcion no puede cambiar el original.
    let n = 5;
    incrementar_copia(n);
    println!("fuera: {n}");

    // 2. Un arreglo de numeros tambien se copia completo.
    let a = [1, 2, 3];
    modificar_copia(a);
    println!("arreglo fuera:  {:?}", a);

    // 3. Adelanto (leccion 08): para modificar el original se presta con &mut.
    let mut m = 5;
    incrementar(&mut m);
    println!("con &mut: {m}");

    let mut notas = [15, 18, 12];
    bonificar(&mut notas, 1);
    println!("notas con bonificacion: {:?}", notas);
}

// `mut x`: la COPIA local es mutable; el original no se ve afectado.
fn incrementar_copia(mut x: i32) {
    x += 1;
    println!("dentro de incrementar_copia: {x}");
}

fn modificar_copia(mut a: [i32; 3]) {
    a[0] = 100;
    println!("arreglo dentro: {:?}", a);
}

// &mut i32: una referencia mutable al entero de quien llama.
fn incrementar(x: &mut i32) {
    *x += 1; // *x: "el valor al que apunta x"
}

// &mut [i32; 3]: una referencia mutable a un arreglo.
fn bonificar(notas: &mut [i32; 3], puntos: i32) {
    for nota in notas.iter_mut() {
        *nota += puntos;
    }
}
