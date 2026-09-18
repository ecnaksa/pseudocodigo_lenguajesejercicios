# Pista 2 — Lenguaje C++

C++ **construye sobre C**: casi todo lo que aprendiste en la pista de C sigue siendo válido, y
C++ añade herramientas potentes para escribir programas más grandes y seguros —sobre todo la
**Programación Orientada a Objetos (POO)** y la **biblioteca estándar (STL)**.

> **Recomendación:** haz primero la [pista de C](../c) (al menos hasta punteros y estructuras).
> C++ dará por sabidos esos fundamentos.

| # | Lección | Contenido |
|---|---------|-----------|
| 01 | [De C a C++](01_de_c_a_cpp) | `iostream`, `namespace`, qué mejora respecto a C |
| 02 | [Tipos, referencias y `const`](02_tipos_referencias_const) | Referencias, `auto`, `nullptr`, `bool`, `std::string` |
| 03 | [Funciones en C++](03_funciones) | Sobrecarga, parámetros por defecto, referencias |
| 04 | [Clases y objetos](04_clases_objetos) | Encapsulamiento, atributos, métodos, `public`/`private` |
| 05 | [Constructores y destructores](05_constructores_destructores) | Ciclo de vida, `this`, miembros `static` |
| 06 | [Herencia y polimorfismo](06_herencia_polimorfismo) | `virtual`, clases base y derivadas |
| 07 | [Sobrecarga de operadores](07_sobrecarga_operadores) | Que tus tipos se usen como los nativos |
| 08 | [Plantillas (templates)](08_plantillas) | Código genérico: funciones y clases plantilla |
| 09 | [STL: contenedores](09_stl_contenedores) | `vector`, `string`, `map`, `set`, iteradores |
| 10 | [STL: algoritmos y lambdas](10_stl_algoritmos_lambdas) | `sort`, `find`, `<algorithm>`, lambdas |
| 11 | [Punteros inteligentes y RAII](11_smart_pointers_raii) | `unique_ptr`, `shared_ptr`, recursos seguros |
| 12 | [Manejo de excepciones](12_excepciones) | `try`, `catch`, `throw` |
| 13 | [Proyecto final](13_proyecto_final) | Sistema de biblioteca (POO + STL) |

## Cómo trabajar cada lección

```bash
g++ -std=c++17 -Wall -Wextra ejemplos/nombre.cpp -o prog && ./prog
```

Lee el `README.md`, ejecuta los ejemplos, resuelve los ejercicios y solo entonces mira las
soluciones.
