# Ejercicios — Lección 06 (C++)

1. **Empleado y Gerente.** Clase base `Empleado` (nombre, `salario()` que devuelve un básico) y
   derivada `Gerente` que redefina `salario()` sumando un bono.
   → [`soluciones/ej1_empleado.cpp`](soluciones/ej1_empleado.cpp)

2. **Formas con área.** Clase abstracta `Forma` con `virtual double area() = 0` y derivadas
   `Cuadrado` y `Triangulo`. Guárdalas en un arreglo de punteros a `Forma` y muestra sus áreas.
   → [`soluciones/ej2_formas.cpp`](soluciones/ej2_formas.cpp)

3. **Reto — Vehículos.** Base `Vehiculo` con método virtual `describir()`. Derivadas `Coche` y
   `Moto` que lo redefinan. Recórrelos polimórficamente.
   → [`soluciones/ej3_vehiculos.cpp`](soluciones/ej3_vehiculos.cpp)
