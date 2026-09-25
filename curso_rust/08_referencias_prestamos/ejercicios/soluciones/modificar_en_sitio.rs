// Ejercicio 3 - Modificar datos en sitio con &mut [T] e iter_mut().
//   rustc --edition 2021 modificar_en_sitio.rs && ./modificar_en_sitio
//
// Salida:
//   original:    [2.0, 5.0, 4.0, 10.0]
//   escalado x3: [6.0, 15.0, 12.0, 30.0]
//   normalizado: [0.2, 0.5, 0.4, 1.0]
//   limitado:    [0, 3, 10, 10, 7, 0]

fn main() {
    let mut datos = [2.0, 5.0, 4.0, 10.0];
    println!("original:    {:?}", datos);

    escalar(&mut datos, 3.0);
    println!("escalado x3: {:?}", datos);

    normalizar(&mut datos);
    println!("normalizado: {:?}", datos);

    let mut lecturas = [-4, 3, 12, 99, 7, 0];
    limitar(&mut lecturas, 0, 10);
    println!("limitado:    {:?}", lecturas);
}

fn escalar(datos: &mut [f64], factor: f64) {
    for x in datos.iter_mut() {
        // x es &mut f64: una referencia mutable a CADA elemento
        *x *= factor;
    }
}

fn normalizar(datos: &mut [f64]) {
    let mut max = datos[0];
    for &x in datos.iter() {
        if x > max {
            max = x;
        }
    }
    if max != 0.0 {
        escalar(datos, 1.0 / max); // reutilizamos escalar: le "re-prestamos" el mismo slice
    }
}

fn limitar(datos: &mut [i32], min: i32, max: i32) {
    for x in datos.iter_mut() {
        *x = (*x).clamp(min, max);
    }
}
