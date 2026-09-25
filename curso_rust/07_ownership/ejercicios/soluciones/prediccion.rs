// Ejercicio 1 - Prediccion. Aqui se ejecutan los fragmentos que COMPILAN; los que no,
// estan comentados con la explicacion del error.
//   rustc --edition 2021 prediccion.rs && ./prediccion
//
// Salida:
//   a) 10 10
//   c) x x
//   d) (1, 2.0, 'z') (1, 2.0, 'z')
//   f) 4 hola

#[allow(dead_code)] // se usa solo en el fragmento g), que esta comentado
fn consumir(_s: String) {}

fn main() {
    // a) COMPILA. i32 es Copy: `let b = a` copia; ambas siguen validas.
    let a = 10;
    let b = a;
    println!("a) {a} {b}");

    // b) NO COMPILA. String no es Copy: `let b = a` MUEVE el valor; `a` queda invalida.
    //    error[E0382]: borrow of moved value: `a`
    // let a = String::from("x");
    // let b = a;
    // println!("{a}");

    // c) COMPILA. clone() crea un segundo String independiente.
    let a = String::from("x");
    let b = a.clone();
    println!("c) {a} {b}");

    // d) COMPILA. Una tupla de tipos Copy (i32, f64, char) es Copy.
    let t = (1, 2.0, 'z');
    let u = t;
    println!("d) {:?} {:?}", t, u);

    // e) NO COMPILA. La tupla contiene un String -> no es Copy -> se mueve entera.
    //    error[E0382]: borrow of moved value: `t`
    // let t = (1, String::from("z"));
    // let u = t;
    // println!("{:?}", t);

    // f) COMPILA. s.len() devuelve un usize (Copy) y NO mueve s (solo lo mira).
    //    Despues `let r = s` mueve s a r, pero ya no volvemos a usar s.
    let s = String::from("hola");
    let n = s.len();
    let r = s;
    println!("f) {n} {r}");

    // g) NO COMPILA. La primera llamada mueve s dentro de consumir; la segunda usa un
    //    valor ya movido.  error[E0382]: use of moved value: `s`
    // let s = String::from("x");
    // consumir(s);
    // consumir(s);

    // h) NO COMPILA. Un arreglo de String no es Copy: `let w = v` mueve el arreglo entero.
    //    error[E0382]: borrow of moved value: `v`
    // let v = [String::from("a"), String::from("b")];
    // let w = v;
    // println!("{:?}", v);
}
