// Leccion 03 - Especificadores de formato de println!/format!.
//
//   rustc --edition 2021 formato.rs && ./formato

fn main() {
    let nombre = "Ana";
    let edad = 20;

    // ----- Formas de indicar los argumentos -----
    println!("{} tiene {} anios", nombre, edad); // en orden
    println!("{0} tiene {1} anios. Bien, {0}!", nombre, edad); // por posicion
    println!("{n} tiene {e} anios", n = nombre, e = edad); // por nombre
    println!("{nombre} tiene {edad} anios"); // inline
    println!("{{ llaves literales }}");

    // ----- format! devuelve un String en lugar de imprimir -----
    let saludo = format!("Hola, {}! Tienes {} mensajes.", nombre, 3);
    println!("{saludo}");

    // ----- Display {} frente a Debug {:?} -----
    let notas = [15, 18, 12];
    let punto = (3, -2);
    println!("Debug arreglo: {:?}", notas);
    println!("Debug tupla:   {:?}", punto);
    println!("Debug texto:   {:?}", "hola"); // Debug muestra las comillas
    println!("Pretty:\n{:#?}", punto);

    // ----- Ancho y alineacion -----
    println!("[{:5}]", 42); // numeros: derecha por defecto
    println!("[{:5}]", "ab"); // textos: izquierda por defecto
    println!("[{:<5}]", 42);
    println!("[{:>5}]", "ab");
    println!("[{:^5}]", "ab");
    println!("{:*^7}", "ab"); // relleno personalizado

    // ----- Decimales -----
    let pi = 3.14159;
    println!("{:.2}", pi); // 3.14
    println!("[{:8.2}]", pi); // [    3.14]
    println!("{:.0}", 2.5_f64); // 2 (redondeo "al par" en el empate)
    println!("{:.0}", 3.5_f64); // 4

    // ----- Ceros, signo, bases, notacion cientifica -----
    println!("{:05}", 42); // 00042
    println!("{:+}", 42); // +42
    println!("{:b} {:o} {:x} {:X}", 10, 8, 255, 255); // 1010 10 ff FF
    println!("{:#b} {:#x}", 10, 255); // 0b1010 0xff
    println!("{:08b}", 5u8); // 00000101 (un byte completo)
    println!("{:e}", 1234.5); // 1.2345e3

    // ----- Ancho y precision tomados de variables -----
    let ancho = 10;
    let dec = 3;
    println!("[{:>ancho$}]", "derecha");
    println!("[{:.dec$}]", pi);
    println!("[{pi:>ancho$.dec$}]"); // todo inline

    // ----- Una pequenia tabla alineada -----
    println!("{:<10}|{:>8}|{:>8}", "Producto", "Cant.", "Precio");
    println!("{:-<10}+{:->8}+{:->8}", "", "", "");
    println!("{:<10}|{:>8}|{:>8.2}", "Manzana", 3, 1.5);
    println!("{:<10}|{:>8}|{:>8.2}", "Pan", 12, 0.25);
    println!("{:<10}|{:>8}|{:>8.2}", "Leche", 2, 3.9);
}
