# Ejercicios — Lección 11 (C++)

1. **unique_ptr a una clase.** Crea una clase `Perro` con un método `ladrar()`. Crea un
   `unique_ptr<Perro>` con `make_unique` y llama al método.
   → [`soluciones/ej1_unique.cpp`](soluciones/ej1_unique.cpp)

2. **Contador de referencias.** Con un `shared_ptr<int>`, crea copias en distintos ámbitos e imprime
   `use_count()` en cada momento. → [`soluciones/ej2_shared.cpp`](soluciones/ej2_shared.cpp)

3. **Reto — vector de formas.** Usando la jerarquía `Figura`/`Circulo`/`Rectangulo` (lección 06),
   guarda `unique_ptr<Figura>` en un `vector` y muestra sus áreas. Observa que **no** necesitas
   `delete`. → [`soluciones/ej3_figuras.cpp`](soluciones/ej3_figuras.cpp)
