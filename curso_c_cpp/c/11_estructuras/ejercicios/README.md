# Ejercicios — Lección 11

1. **Punto 2D.** Define `typedef struct { double x, y; } Punto;`. Crea dos puntos y calcula la
   distancia entre ellos (`sqrt((x2-x1)^2 + (y2-y1)^2)`, con `<math.h>`, compila con `-lm`).
   → [`soluciones/ej1_punto.c`](soluciones/ej1_punto.c)

2. **Rectángulo con función.** Define `typedef struct { double base, altura; } Rectangulo;` y una
   función `double area(Rectangulo r)`. → [`soluciones/ej2_rectangulo.c`](soluciones/ej2_rectangulo.c)

3. **Lista de productos.** Define `Producto` (nombre y precio) y un arreglo de 3. Muestra el más
   caro. → [`soluciones/ej3_productos.c`](soluciones/ej3_productos.c)

4. **Modificar por puntero.** Con la struct `Producto`, escribe `void aplicarDescuento(Producto
   *p, double pct)` que reduzca el precio un porcentaje.
   → [`soluciones/ej4_descuento.c`](soluciones/ej4_descuento.c)

5. **Reto — enum de estados.** Define `typedef enum { PENDIENTE, EN_PROGRESO, HECHO } Estado;` y
   una función que reciba un `Estado` y devuelva su nombre como cadena.
   → [`soluciones/ej5_estado.c`](soluciones/ej5_estado.c)
