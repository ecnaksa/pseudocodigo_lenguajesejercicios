# Ejercicios — Lección 07

En esta lección, más que escribir programas nuevos, vas a **predecir** y **arreglar**. Es la forma
más rápida de interiorizar las reglas del *ownership*. Para cada ejercicio: piensa primero, luego
compila y lee el error completo, y solo después mira la solución.

1. **¿Compila o no?** Para cada fragmento (dentro de un `main`), decide si compila. Si no, ¿qué
   línea falla y por qué?
   ```rust
   // a)
   let a = 10;
   let b = a;
   println!("{a} {b}");

   // b)
   let a = String::from("x");
   let b = a;
   println!("{a}");

   // c)
   let a = String::from("x");
   let b = a.clone();
   println!("{a} {b}");

   // d)
   let t = (1, 2.0, 'z');
   let u = t;
   println!("{:?} {:?}", t, u);

   // e)
   let t = (1, String::from("z"));
   let u = t;
   println!("{:?}", t);

   // f)
   let s = String::from("hola");
   let n = s.len();
   let r = s;
   println!("{n} {r}");

   // g)   (con fn consumir(s: String) {} definida fuera de main)
   let s = String::from("x");
   consumir(s);
   consumir(s);

   // h)
   let v = [String::from("a"), String::from("b")];
   let w = v;
   println!("{:?}", v);
   ```
   → [`soluciones/prediccion.rs`](soluciones/prediccion.rs)

2. **Arregla: usar después de pasar a una función.** Este programa no compila. Arréglalo de **dos
   formas distintas** sin modificar la función `imprimir`: (a) con `clone`; (b) cambiando el orden
   de las líneas de `main`.
   ```rust
   fn imprimir(s: String) {
       println!("{s}");
   }

   fn main() {
       let nombre = String::from("Ferris");
       imprimir(nombre);
       println!("Adios, {nombre}");
   }
   ```
   → [`soluciones/arreglar_funcion.rs`](soluciones/arreglar_funcion.rs)

3. **Arregla: mover dentro de un bucle.** Este programa no compila. ¿Por qué el compilador dice
   *"value moved here, in previous iteration of loop"*? Arréglalo de dos formas: con `clone`, y
   **sin copiar nada** (pista: ¿hace falta la variable `copia`?).
   ```rust
   fn main() {
       let mensaje = String::from("hola");
       for i in 0..3 {
           let copia = mensaje;
           println!("{i}: {copia}");
       }
   }
   ```
   → [`soluciones/arreglar_bucle.rs`](soluciones/arreglar_bucle.rs)

4. **Pasar y devolver la propiedad.** Escribe `fn agregar_saludo(s: String) -> String` (antepone
   `"Hola, "`) y `fn contar_vocales(s: String) -> (String, usize)` (devuelve el texto y cuántas
   vocales tiene, recorriendo `s.chars()`). Úsalas en cadena desde `main` sin usar `clone`.
   → [`soluciones/devolver_propiedad.rs`](soluciones/devolver_propiedad.rs)

5. **Rastrear las liberaciones.** Copia el tipo `Recurso` de
   [`../ejemplos/ver_drop.rs`](../ejemplos/ver_drop.rs) y **predice** el orden exacto de los
   mensajes `creado:` y `liberado:` de este `main`. Hay dos trampas: el *shadowing* y el patrón `_`.
   (Al compilarlo verás además una advertencia sobre la primera `x`: entender por qué aparece
   forma parte del ejercicio.)
   ```rust
   fn main() {
       let x = Recurso::nuevo("A");
       let x = Recurso::nuevo("B");      // shadowing: ¿se libera A aqui?
       let _ = Recurso::nuevo("C");      // `_` a secas: ¿cuando se libera C?
       let _d = Recurso::nuevo("D");     // `_d`: ¿y D?
       {
           let e = Recurso::nuevo("E");
           let _movido = e;
       }
       println!("fin de main (x es {})", x.nombre);
   }
   ```
   → [`soluciones/rastrear_drops.rs`](soluciones/rastrear_drops.rs)

6. **Reto — una cadena de montaje.** Construye una frase pasando la propiedad de un `String` por
   varias funciones: `crear() -> String` (devuelve `"rust"`), `agregar(s: String, palabra: &str) ->
   String`, `en_mayusculas(s: String) -> String` (usa `s.to_uppercase()`, que crea un `String`
   **nuevo**: ¿qué pasa con el viejo?) y `con_marco(s: String) -> String` (rodea el texto con
   `*** `). Llama a todas en una sola expresión anidada y explica en comentarios cuántos `String`
   se crean en el heap y cuándo se libera cada uno.
   → [`soluciones/cadena_montaje.rs`](soluciones/cadena_montaje.rs)
