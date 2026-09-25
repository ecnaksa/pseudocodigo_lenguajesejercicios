// Leccion 02 - Tipos compuestos: tuplas y arreglos.
//
//   rustc --edition 2021 compuestos.rs && ./compuestos

fn main() {
    // ----- Tuplas: tipos distintos, cantidad fija -----
    let persona: (&str, i32, f64) = ("Ana", 20, 1.65);
    println!("{} tiene {} anios", persona.0, persona.1); // acceso por posicion

    let (nombre, edad, altura) = persona; // desestructurar
    println!("{nombre} ({edad}) mide {altura} m");

    let mut punto = (0, 0); // una tupla mutable
    punto.0 = 3;
    punto.1 = -2;
    println!("punto = ({}, {})", punto.0, punto.1);

    let vacio = (); // la tupla vacia: "unit"
    println!("unit se imprime con {{:?}} como: {:?}", vacio);

    // ----- Arreglos: mismo tipo, cantidad fija -----
    let notas: [i32; 5] = [15, 18, 12, 20, 16];
    println!("primera nota: {}", notas[0]);
    println!("ultima nota:  {}", notas[notas.len() - 1]);
    println!("cantidad:     {}", notas.len());

    let ceros = [0; 4]; // [0, 0, 0, 0]
    println!("ceros = {:?}", ceros); // {:?} imprime el arreglo completo

    let mut dias = ["lun", "mar", "mie", "jue", "vie"];
    dias[4] = "VIE"; // modificar exige que el arreglo sea mut
    println!("dias = {:?}", dias);

    // Arreglo de dos dimensiones (matriz 2x3): un arreglo de arreglos
    let matriz = [[1, 2, 3], [4, 5, 6]];
    println!("matriz[1][2] = {}", matriz[1][2]); // 6

    // Acceso fuera de rango:
    // println!("{}", notas[10]);  // NO compila: "this operation will panic at runtime"
    // Con un indice calculado al ejecutar, el programa se detiene con un panic
    // ("index out of bounds") en lugar de leer memoria ajena como en C.
}
