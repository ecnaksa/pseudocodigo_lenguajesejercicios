# Ejercicios — Lección 03

Compila cada solución con `rustc --edition 2021 archivo.rs`. Como estos programas leen del
teclado, puedes probarlos escribiendo a mano o redirigiendo la entrada, por ejemplo:
`printf "Ana\nLima\n" | ./saludo`.

1. **Saludo personalizado.** Pide el nombre y la ciudad del usuario (cada uno en su línea) y
   responde `Hola, <nombre> de <ciudad>!`. Recuerda: `trim()` y `clear()` si reutilizas el
   `String`.
   → [`soluciones/saludo.rs`](soluciones/saludo.rs)

2. **Dos números.** Lee dos enteros (uno por línea) e imprime su suma, su resta y su producto.
   → [`soluciones/dos_numeros.rs`](soluciones/dos_numeros.rs)

3. **Conversor de temperatura.** Lee una temperatura en grados Celsius (`f64`) y muéstrala en
   Fahrenheit con **un decimal**: F = C × 9 / 5 + 32. Pregunta en la misma línea (`print!` +
   `flush`).
   → [`soluciones/temperatura.rs`](soluciones/temperatura.rs)

4. **Área del círculo.** Lee el radio y muestra el área y la circunferencia con **dos decimales**.
   Usa la constante `std::f64::consts::PI`.
   → [`soluciones/circulo.rs`](soluciones/circulo.rs)

5. **Boleta de venta.** Lee el nombre de un producto, la cantidad (`u32`) y el precio unitario
   (`f64`). Imprime una boleta **alineada** con el subtotal, un impuesto del 18 % y el total, así:
   ```
   ==============================
   Producto              Cuaderno
   Cantidad                     3
   Precio unit.              4.50
   ------------------------------
   Subtotal                 13.50
   Impuesto (18%)            2.43
   TOTAL                    15.93
   ==============================
   ```
   Pista: una columna izquierda de 16 caracteres (`{:<16}`) y una derecha de 14 (`{:>14}`) suman
   30, el mismo ancho que la línea de `=` (`"=".repeat(30)`).
   → [`soluciones/boleta.rs`](soluciones/boleta.rs)

6. **Reto — bases numéricas.** Lee un entero sin signo (`u32`) y muéstralo en decimal, binario
   (con prefijo `0b` y relleno a 16 bits), octal y hexadecimal (con prefijo `0x`, en mayúsculas).
   Si el usuario no escribe un número válido, en lugar de detener el programa muestra un mensaje
   (usa `match` como en [`../ejemplos/parse_seguro.rs`](../ejemplos/parse_seguro.rs)).
   → [`soluciones/bases.rs`](soluciones/bases.rs)
