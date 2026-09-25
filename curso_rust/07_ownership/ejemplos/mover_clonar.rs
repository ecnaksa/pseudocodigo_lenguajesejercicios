// Leccion 07 - Move, clone y tipos Copy.
//
//   rustc --edition 2021 mover_clonar.rs && ./mover_clonar
//
// Salida:
//   x = 5, y = 5
//   s2 = hola
//   original = hola, copia = hola
//   original = hola, copia = hola!!!
//   punto = (1.5, 2.5), otro = (1.5, 2.5)
//   notas = [15, 18], copia_notas = [15, 18]
//   persona movida: ("Ana", 20)

fn main() {
    // 1. Tipos Copy: se copian, ambas variables siguen validas.
    let x = 5;
    let y = x;
    println!("x = {x}, y = {y}");

    // 2. String: se MUEVE. s1 deja de ser valida.
    let s1 = String::from("hola");
    let s2 = s1;
    // println!("{s1}");   // error[E0382]: borrow of moved value: `s1`
    println!("s2 = {s2}");

    // 3. clone: copia profunda explicita. Dos Strings independientes en el heap.
    let original = String::from("hola");
    let mut copia = original.clone();
    println!("original = {original}, copia = {copia}");
    copia.push_str("!!!"); // modificar la copia no afecta al original
    println!("original = {original}, copia = {copia}");

    // 4. Tuplas y arreglos de tipos Copy tambien son Copy.
    let punto = (1.5, 2.5);
    let otro = punto;
    println!("punto = {:?}, otro = {:?}", punto, otro);

    let notas = [15, 18];
    let copia_notas = notas;
    println!("notas = {:?}, copia_notas = {:?}", notas, copia_notas);

    // 5. Pero si la tupla contiene un String, ya no es Copy: se mueve entera.
    let persona = (String::from("Ana"), 20);
    let movida = persona;
    // println!("{:?}", persona);   // error[E0382]: use of moved value: `persona`
    println!("persona movida: {:?}", movida);
}
