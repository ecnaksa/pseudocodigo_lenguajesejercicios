# Ejercicios — Lección 08

Compila cada solución con `rustc --edition 2021 archivo.rs`. Para cada función, decide primero si
el parámetro debe ser `T`, `&T` o `&mut T` (y prefiere `&str` / `&[T]` para leer).

1. **Arregla los préstamos.** Cada fragmento tiene un error distinto (`E0596`, `E0499`, `E0502`).
   Arréglalos con el **cambio mínimo**.
   ```rust
   // a)
   fn exclamar(s: &String) {
       s.push('!');
   }

   // b)
   let mut n = 5;
   let a = &mut n;
   let b = &mut n;
   *a += 1;
   *b += 1;

   // c)
   let mut nombres = vec![String::from("Ana"), String::from("Luis")];
   let primero = &nombres[0];
   nombres.push(String::from("Sara"));
   println!("{primero}");
   ```
   → [`soluciones/arreglar_prestamos.rs`](soluciones/arreglar_prestamos.rs)

2. **Estadísticas sobre *slices*.** Escribe `promedio(datos: &[f64]) -> f64`,
   `maximo(datos: &[f64]) -> f64` y `contar_mayores(datos: &[f64], umbral: f64) -> usize`. Úsalas
   con un arreglo de 8 mediciones, con su **primera mitad** y con sus **tres últimas** mediciones,
   sin copiar nada.
   → [`soluciones/estadisticas_slice.rs`](soluciones/estadisticas_slice.rs)

3. **Modificar en sitio.** Escribe `escalar(datos: &mut [f64], factor: f64)`,
   `normalizar(datos: &mut [f64])` (divide todo por el máximo, de modo que el mayor quede en 1.0) y
   `limitar(datos: &mut [i32], min: i32, max: i32)` (recorta cada valor al rango). Pista: recorre
   con `for x in datos.iter_mut()` y modifica con `*x = ...`.
   → [`soluciones/modificar_en_sitio.rs`](soluciones/modificar_en_sitio.rs)

4. **Palabras.** Escribe `contar_palabras(texto: &str) -> usize`,
   `palabra_mas_larga(texto: &str) -> &str` y `ultima_palabra(texto: &str) -> &str`. Las dos
   últimas deben devolver ***slices*** del texto original (sin crear `String` nuevos). Usa
   `split_whitespace()`.
   → [`soluciones/palabras.rs`](soluciones/palabras.rs)

5. **Intercambiar.** Escribe `intercambiar(a: &mut i32, b: &mut i32)` y úsala. ¿Qué pasa si
   intentas `intercambiar(&mut x, &mut x)`? ¿Por qué Rust tiene razón en impedirlo? (Existe
   `std::mem::swap`, que hace lo mismo para cualquier tipo.)
   → [`soluciones/intercambiar.rs`](soluciones/intercambiar.rs)

6. **Más ejercicios del repositorio.** Con *slices*, resuelve los ejercicios 05 (`sumaPares`), 06
   (`cuentaRepeticiones`) y 15 (`eliminaDuplicados`: quitar los repetidos **en sitio** y devolver
   el nuevo tamaño) de [`../../../soluciones/c/`](../../../soluciones/c). Para el 15, imprime solo
   la parte válida del arreglo con `&arr[..nuevo_tam]`.
   → [`soluciones/repositorio.rs`](soluciones/repositorio.rs)

7. **Reto — rotar un arreglo.** Escribe `rotar_izquierda(arr: &mut [i32], k: usize)`: con
   `[1, 2, 3, 4, 5, 6, 7]` y `k = 3`, el resultado es `[4, 5, 6, 7, 1, 2, 3]`. Usa el truco de las
   tres inversiones: invertir `arr[..k]`, invertir `arr[k..]` e invertir todo (reutiliza
   `invierte_arreglo` de los ejemplos, pasándole ***sub-slices* mutables**). Después, intenta tener
   `&mut arr[..k]` y `&mut arr[k..]` **a la vez**: ¿qué error da? Investiga
   `arr.split_at_mut(k)`, que devuelve las dos mitades mutables de forma segura.
   → [`soluciones/rotar.rs`](soluciones/rotar.rs)
