# Ejercicios — Lección 10

1. **Suma dinámica.** Pide `n`, reserva un arreglo dinámico de `n` enteros, léelos y muestra su
   suma. No olvides `free`. → [`soluciones/ej1_suma_dinamica.c`](soluciones/ej1_suma_dinamica.c)

2. **Copia de un arreglo.** Escribe una función `int *copiar(int *origen, int n)` que reserve un
   nuevo arreglo, copie los `n` elementos y lo devuelva. Libéralo en `main`.
   → [`soluciones/ej2_copiar.c`](soluciones/ej2_copiar.c)

3. **Rellenar con `calloc`.** Usa `calloc` para crear un arreglo de `n` enteros (ya en 0) e
   incrementa cada posición en su índice. → [`soluciones/ej3_calloc.c`](soluciones/ej3_calloc.c)

4. **Reto — invertir dinámico.** Pide `n`, reserva y llena un arreglo, luego invierte su orden
   *in situ* (sin otro arreglo) y muéstralo. Libera al final.
   → [`soluciones/ej4_invertir.c`](soluciones/ej4_invertir.c)

> **Sugerencia:** compila con `-g` y ejecuta `valgrind ./prog` para verificar que no hay fugas.
