// Leccion 04 - Expresiones y sentencias.
//
//   rustc --edition 2021 expresiones.rs && ./expresiones
//
// Salida:
//   y = 4
//   area = 12
//   unidad = ()
//   mayor = 9
//   precio final = 84.40

fn main() {
    // Un bloque es una expresion: vale lo que vale su ultima expresion SIN ';'.
    let y = {
        let x = 3;
        x + 1 // <- el valor del bloque
    };
    println!("y = {y}");

    // Util para calcular algo con variables auxiliares que no "ensucian" el resto.
    let area = {
        let base = 4;
        let altura = 3;
        base * altura
    };
    println!("area = {area}");
    // println!("{base}");   // error: `base` no existe fuera del bloque

    // Si la ultima linea lleva ';', el bloque vale () (unit).
    #[allow(clippy::let_unit_value)] // (le decimos a clippy que es a proposito)
    let unidad = {
        let x = 3;
        let _descartado = x + 1; // sentencia: el resultado se guarda y no se devuelve
    };
    println!("unidad = {:?}", unidad);

    // Adelanto de la leccion 05: if tambien es una expresion (sustituye al ternario ?: de C).
    let a = 4;
    let b = 9;
    let mayor = if a > b { a } else { b };
    println!("mayor = {mayor}");

    // Las expresiones se pueden anidar libremente.
    let precio_final = {
        let precio: f64 = 80.0;
        let impuesto = precio * 0.18;
        let descuento = if precio > 50.0 { 10.0 } else { 0.0 };
        precio + impuesto - descuento
    };
    println!("precio final = {precio_final:.2}");
}
