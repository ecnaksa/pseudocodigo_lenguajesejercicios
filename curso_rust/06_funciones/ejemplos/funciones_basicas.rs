// Leccion 06 - Definir funciones: parametros, retorno, return temprano, tuplas.
//
//   rustc --edition 2021 funciones_basicas.rs && ./funciones_basicas
//
// Salida:
//   Hola!
//   Hola, Ana!
//   Hola, Ana!
//   doble(21) = 42
//   10 / 4 = 2.5
//   10 / 0 = 0
//   hipotenusa(3, 4) = 5
//   min = 1, max = 9
//   17 dividido entre 5: cociente 3, resto 2

fn main() {
    // Las funciones pueden definirse despues de main: el orden no importa.
    saludar();
    saludar_a("Ana", 2);

    println!("doble(21) = {}", doble(21));
    println!("10 / 4 = {}", dividir(10.0, 4.0));
    println!("10 / 0 = {}", dividir(10.0, 0.0));
    println!("hipotenusa(3, 4) = {}", hipotenusa(3.0, 4.0));

    let (menor, mayor) = min_max([4, 9, 1, 7, 3]);
    println!("min = {menor}, max = {mayor}");

    let (c, r) = division_entera(17, 5);
    println!("17 dividido entre 5: cociente {c}, resto {r}");
}

// Sin parametros ni retorno.
fn saludar() {
    println!("Hola!");
}

// Con parametros: el tipo de cada uno es obligatorio.
fn saludar_a(nombre: &str, veces: u32) {
    for _ in 0..veces {
        println!("Hola, {nombre}!");
    }
}

// Con retorno: devuelve la ultima expresion (sin ;).
fn doble(x: i32) -> i32 {
    x * 2
}

// return para salir antes en un caso especial.
fn dividir(a: f64, b: f64) -> f64 {
    if b == 0.0 {
        return 0.0;
    }
    a / b
}

// Una funcion puede llamar a otras (y usar variables locales).
fn hipotenusa(a: f64, b: f64) -> f64 {
    let suma_cuadrados = cuadrado(a) + cuadrado(b);
    suma_cuadrados.sqrt()
}

fn cuadrado(x: f64) -> f64 {
    x * x
}

// Devolver dos valores con una tupla.
fn min_max(a: [i32; 5]) -> (i32, i32) {
    let mut min = a[0];
    let mut max = a[0];
    for x in a {
        if x < min {
            min = x;
        }
        if x > max {
            max = x;
        }
    }
    (min, max)
}

fn division_entera(dividendo: i32, divisor: i32) -> (i32, i32) {
    (dividendo / divisor, dividendo % divisor)
}
