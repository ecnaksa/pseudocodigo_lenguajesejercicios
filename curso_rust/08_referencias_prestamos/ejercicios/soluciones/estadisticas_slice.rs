// Ejercicio 2 - Funciones que reciben &[f64]: sirven para el arreglo entero y para partes.
//   rustc --edition 2021 estadisticas_slice.rs && ./estadisticas_slice
//
// Salida:
//   todo         -> n=8 promedio=21.60 max=25.40 mayores a 22: 5
//   1.a mitad    -> n=4 promedio=19.80 max=22.10 mayores a 22: 1
//   ultimas tres -> n=3 promedio=22.73 max=23.90 mayores a 22: 3

fn main() {
    let mediciones = [18.5, 19.2, 19.4, 22.1, 25.4, 23.9, 22.2, 22.1];

    let mitad = mediciones.len() / 2;
    let n = mediciones.len();

    informe("todo        ", &mediciones);
    informe("1.a mitad   ", &mediciones[..mitad]);
    informe("ultimas tres", &mediciones[n - 3..]);
}

fn informe(nombre: &str, datos: &[f64]) {
    println!(
        "{nombre} -> n={} promedio={:.2} max={:.2} mayores a 22: {}",
        datos.len(),
        promedio(datos),
        maximo(datos),
        contar_mayores(datos, 22.0)
    );
}

fn promedio(datos: &[f64]) -> f64 {
    let mut suma = 0.0;
    for x in datos {
        suma += x;
    }
    suma / datos.len() as f64
}

fn maximo(datos: &[f64]) -> f64 {
    let mut max = datos[0];
    for &x in datos {
        // `&x` en el patron: desestructura la referencia y deja en x el f64 (Copy)
        if x > max {
            max = x;
        }
    }
    max
}

fn contar_mayores(datos: &[f64], umbral: f64) -> usize {
    let mut cuenta = 0;
    for &x in datos {
        if x > umbral {
            cuenta += 1;
        }
    }
    cuenta
}
