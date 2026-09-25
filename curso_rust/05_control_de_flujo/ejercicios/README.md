# Ejercicios — Lección 05

Compila cada solución con `rustc --edition 2021 archivo.rs`.

1. **Signo y paridad.** Lee un entero y di si es positivo, negativo o cero, y si es par o impar.
   Usa `if` **como expresión** para guardar cada respuesta en una variable antes de imprimir.
   → [`soluciones/signo_paridad.rs`](soluciones/signo_paridad.rs)

2. **Calificación con `match`.** Lee una nota de 0 a 20 y muestra: 18–20 `Excelente`, 14–17
   `Bueno`, 11–13 `Aprobado`, 0–10 `Desaprobado`. Si el dato no es un número o es mayor que 20,
   vuelve a pedirlo (bucle de validación).
   → [`soluciones/calificacion.rs`](soluciones/calificacion.rs)

3. **FizzBuzz.** Imprime los números del 1 al 20, pero en los múltiplos de 3 escribe `Fizz`, en los
   de 5 `Buzz`, y en los de ambos `FizzBuzz`. Pista: haz `match` sobre la **tupla**
   `(n % 3, n % 5)`.
   → [`soluciones/fizzbuzz.rs`](soluciones/fizzbuzz.rs)

4. **Tabla de multiplicar.** Lee un número `n` e imprime su tabla del 1 al 12, alineada:
   ```
    7 x  1 =   7
    7 x  2 =  14
   ...
    7 x 12 =  84
   ```
   → [`soluciones/tabla.rs`](soluciones/tabla.rs)

5. **Factoriales hasta desbordar.** Calcula `1!`, `2!`, `3!`… en un `u64` usando `checked_mul`
   (lección 04) dentro de un `loop`. Imprime cada factorial y **detente** cuando el siguiente ya no
   quepa en un `u64`, indicando cuál fue el último que cupo.
   → [`soluciones/factoriales.rs`](soluciones/factoriales.rs)

6. **Números primos.** Imprime todos los primos menores que 100. Para cada `n`, prueba divisores
   `d` mientras `d * d <= n`; si alguno divide a `n`, no es primo (sal con `break`). Al final
   muestra cuántos encontraste (son 25).
   → [`soluciones/primos.rs`](soluciones/primos.rs)

7. **Los arreglos del repositorio, en Rust.** Con el arreglo
   `[4, -7, 12, 9, -1, 12, 5]`, resuelve con bucles `for` los ejercicios 01–04 de la raíz de este
   repositorio ([`../../../soluciones/c/`](../../../soluciones/c)): (1) suma de los elementos,
   (2) mínimo, (3) cantidad de impares, (4) posición de un valor buscado, o `-1` si no está.
   Compara tu solución con la versión en C: ¿qué necesitaba C que Rust no necesita?
   → [`soluciones/arreglos_basicos.rs`](soluciones/arreglos_basicos.rs)

8. **Reto — adivina el número.** El programa elige un número secreto entre 1 y 100 y el usuario
   intenta adivinarlo; tras cada intento se le dice `Mas alto` o `Mas bajo`. Al acertar, muestra
   cuántos intentos necesitó. Las entradas no numéricas no cuentan como intento. Para elegir el
   secreto sin bibliotecas externas, usa los nanosegundos del reloj del sistema:
   ```rust
   use std::time::{SystemTime, UNIX_EPOCH};
   let nanos = SystemTime::now().duration_since(UNIX_EPOCH).expect("reloj").subsec_nanos();
   let secreto = nanos % 100 + 1;
   ```
   (Para un número aleatorio "de verdad" se usa la biblioteca `rand`; lo verás en la lección 16.)
   Puedes probarlo sin jugar a mano con `seq 1 100 | ./adivina`.
   → [`soluciones/adivina.rs`](soluciones/adivina.rs)
