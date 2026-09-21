# Ejercicios — Lección 15

1. **Raíz segura.** `RaizSegura` con un método que lance `IllegalArgumentException` si el número es
   negativo; atrápala en `main` con varios valores.
   → [`soluciones/RaizSegura.java`](soluciones/RaizSegura.java)

2. **Validar edad.** `ValidarEdad` con un método `validar(int e)` que lance una excepción si la edad
   es negativa o mayor que 150. → [`soluciones/ValidarEdad.java`](soluciones/ValidarEdad.java)

3. **Lectura robusta.** `LecturaRobusta` que intente `Integer.parseInt` de varias cadenas (algunas
   no numéricas) y atrape `NumberFormatException`.
   → [`soluciones/LecturaRobusta.java`](soluciones/LecturaRobusta.java)

4. **Reto — pila con excepción.** Clase `Pila` (con arreglo) cuyo `pop()` lance
   `RuntimeException("pila vacia")` si está vacía; provoca y atrapa el error.
   → [`soluciones/PilaDemo.java`](soluciones/PilaDemo.java)
