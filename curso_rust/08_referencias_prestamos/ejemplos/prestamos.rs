// Leccion 08 - Referencias: &, &mut, * y las reglas del prestamo.
//
//   rustc --edition 2021 prestamos.rs && ./prestamos
//
// Salida:
//   "hola" tiene 4 bytes
//   hola, mundo
//   n = 42
//   r1 = hola, r2 = hola
//   hola!
//   saldo = 150
//   saldo = 150 (el retiro de 500 fue rechazado)

fn main() {
    // 1. Prestamo inmutable: la funcion mira, no se adueña.
    let s1 = String::from("hola");
    let largo = calcular_longitud(&s1);
    println!("{:?} tiene {largo} bytes", s1); // s1 sigue siendo nuestra

    // 2. Prestamo mutable: tres `mut` (variable, prestamo y tipo del parametro).
    let mut s = String::from("hola");
    agregar_mundo(&mut s);
    println!("{s}");

    // 3. Desreferenciar con *
    let mut n = 21;
    duplicar(&mut n);
    println!("n = {n}");

    // 4. Muchas referencias inmutables a la vez: bien.
    let mut texto = String::from("hola");
    let r1 = &texto;
    let r2 = &texto;
    println!("r1 = {r1}, r2 = {r2}"); // ultimo uso de r1 y r2: sus prestamos terminan aqui

    // 5. Despues, un prestamo mutable: bien, porque r1 y r2 ya no se usan.
    let r3 = &mut texto;
    r3.push('!');
    println!("{r3}");

    // 6. Un caso "de verdad": funciones que leen (&) y que modifican (&mut) el mismo dato.
    let mut saldo: u32 = 100;
    depositar(&mut saldo, 50);
    mostrar(&saldo);
    if !retirar(&mut saldo, 500) {
        println!("saldo = {saldo} (el retiro de 500 fue rechazado)");
    }
}

// Clippy (el linter) sugeriria recibir `&str` en vez de `&String`: tiene razon, y es justo lo
// que explica la seccion de slices de esta leccion. Aqui usamos &String a proposito, para que se
// vea que es "una referencia a un String"; el atributo le indica a Clippy que es intencional.
#[allow(clippy::ptr_arg)]
fn calcular_longitud(s: &String) -> usize {
    s.len() // auto-desreferencia: no hace falta (*s).len()
}

fn agregar_mundo(s: &mut String) {
    s.push_str(", mundo");
}

fn duplicar(x: &mut i32) {
    *x *= 2; // aqui SI hace falta *: operamos sobre el entero apuntado
}

fn depositar(saldo: &mut u32, monto: u32) {
    *saldo += monto;
}

/// Devuelve true si pudo retirar; false si no habia saldo suficiente.
fn retirar(saldo: &mut u32, monto: u32) -> bool {
    if monto > *saldo {
        return false;
    }
    *saldo -= monto;
    true
}

fn mostrar(saldo: &u32) {
    println!("saldo = {saldo}");
}
