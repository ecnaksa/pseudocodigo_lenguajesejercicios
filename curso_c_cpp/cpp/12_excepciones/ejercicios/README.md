# Ejercicios — Lección 12 (C++)

1. **Raíz cuadrada segura.** Escribe una función que lance `invalid_argument` si el número es
   negativo, y atrápala en `main`. → [`soluciones/ej1_raiz.cpp`](soluciones/ej1_raiz.cpp)

2. **Validar edad.** Función `void validarEdad(int e)` que lance una excepción si la edad es
   negativa o mayor que 150; pruébala con varios valores dentro de un `try`.
   → [`soluciones/ej2_edad.cpp`](soluciones/ej2_edad.cpp)

3. **Reto — pila con excepción.** Una clase `Pila` (con arreglo) cuyo `pop()` lance
   `runtime_error("pila vacia")` si está vacía. Provoca y atrapa el error.
   → [`soluciones/ej3_pila.cpp`](soluciones/ej3_pila.cpp)
