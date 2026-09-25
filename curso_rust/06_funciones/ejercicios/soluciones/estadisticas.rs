// Ejercicio 3 - Devolver varios valores con una tupla.
//   rustc --edition 2021 estadisticas.rs && ./estadisticas
//
// Salida:
//   Datos: [12.5, 15.0, 9.5, 18.0, 14.0, 11.0]
//   Minimo: 9.50  Maximo: 18.00  Promedio: 13.33
//   Desviacion estandar: 2.76

fn main() {
    let datos = [12.5, 15.0, 9.5, 18.0, 14.0, 11.0];
    println!("Datos: {:?}", datos);

    let (min, max, promedio) = estadisticas(datos);
    println!("Minimo: {min:.2}  Maximo: {max:.2}  Promedio: {promedio:.2}");
    println!("Desviacion estandar: {:.2}", desviacion_estandar(datos, promedio));
}

/// Devuelve (minimo, maximo, promedio).
fn estadisticas(datos: [f64; 6]) -> (f64, f64, f64) {
    let mut min = datos[0];
    let mut max = datos[0];
    let mut suma = 0.0;
    for x in datos {
        if x < min {
            min = x;
        }
        if x > max {
            max = x;
        }
        suma += x;
    }
    (min, max, suma / datos.len() as f64)
}

/// Desviacion estandar poblacional: raiz del promedio de los cuadrados de las diferencias.
fn desviacion_estandar(datos: [f64; 6], promedio: f64) -> f64 {
    let mut suma_cuadrados = 0.0;
    for x in datos {
        let diferencia = x - promedio;
        suma_cuadrados += diferencia * diferencia;
    }
    (suma_cuadrados / datos.len() as f64).sqrt()
}
