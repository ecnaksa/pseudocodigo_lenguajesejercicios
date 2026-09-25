// Leccion 05 - loop, while, for, rangos y etiquetas.
//
//   rustc --edition 2021 bucles.rs && ./bucles

fn main() {
    // ----- loop con break y continue -----
    let mut contador = 0;
    print!("loop:        ");
    loop {
        contador += 1;
        if contador == 3 {
            continue; // salta el 3
        }
        if contador > 5 {
            break;
        }
        print!("{contador} ");
    }
    println!();

    // ----- break con valor -----
    let mut n = 1;
    let potencia = loop {
        n *= 2;
        if n > 1000 {
            break n; // el loop "vale" n
        }
    };
    println!("primera potencia de 2 mayor que 1000: {potencia}");

    // ----- while -----
    let mut cuenta = 3;
    while cuenta > 0 {
        print!("{cuenta}... ");
        cuenta -= 1;
    }
    println!("Despegue!");

    // ----- for con rangos -----
    print!("0..5:        ");
    for i in 0..5 {
        print!("{i} ");
    }
    println!();

    print!("1..=5:       ");
    for i in 1..=5 {
        print!("{i} ");
    }
    println!();

    print!("rev:         ");
    for i in (1..=5).rev() {
        print!("{i} ");
    }
    println!();

    print!("step_by(2):  ");
    for i in (0..=10).step_by(2) {
        print!("{i} ");
    }
    println!();

    // ----- for sobre un arreglo -----
    let notas = [15, 18, 12, 20];
    let mut suma = 0; // acumulador
    let mut maxima = notas[0]; // maximo visto hasta ahora
    for nota in notas {
        suma += nota;
        if nota > maxima {
            maxima = nota;
        }
    }
    println!("suma = {suma}, maxima = {maxima}");

    for (i, nota) in notas.iter().enumerate() {
        println!("  nota[{i}] = {nota}");
    }

    // ----- etiquetas para bucles anidados -----
    'externo: for i in 1..=3 {
        for j in 1..=3 {
            if i * j == 4 {
                println!("encontrado: {i} x {j} = 4");
                break 'externo; // sale de ambos bucles
            }
        }
    }

    // ----- tabla de multiplicar con bucles anidados -----
    for fila in 1..=3 {
        for col in 1..=5 {
            print!("{:4}", fila * col);
        }
        println!();
    }
}
