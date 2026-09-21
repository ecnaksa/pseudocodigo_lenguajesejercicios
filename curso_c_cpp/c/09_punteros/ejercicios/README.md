# Ejercicios — Lección 09

1. **Duplicar por puntero.** Escribe `void duplicar(int *n)` que multiplique por 2 la variable
   apuntada. Pruébala. → [`soluciones/ej1_duplicar.c`](soluciones/ej1_duplicar.c)

2. **Devolver dos resultados.** Escribe `void divmod(int a, int b, int *coc, int *res)` que ponga
   en `*coc` el cociente `a/b` y en `*res` el residuo `a%b`.
   → [`soluciones/ej2_divmod.c`](soluciones/ej2_divmod.c)

3. **Mínimo y máximo a la vez.** Escribe `void minmax(int arr[], int n, int *min, int *max)` que
   deje el mínimo y el máximo del arreglo en las variables apuntadas.
   → [`soluciones/ej3_minmax.c`](soluciones/ej3_minmax.c)

4. **Recorrer con puntero.** Recorre un arreglo usando aritmética de punteros (`*(p+i)`) en vez de
   `arr[i]`. → [`soluciones/ej4_recorrer.c`](soluciones/ej4_recorrer.c)

5. **Reto — incrementar todos.** Escribe `void incrementar(int arr[], int n, int cantidad)` que
   sume `cantidad` a cada elemento del arreglo (modificándolo). Comprueba que el cambio se ve en
   `main`. → [`soluciones/ej5_incrementar.c`](soluciones/ej5_incrementar.c)
