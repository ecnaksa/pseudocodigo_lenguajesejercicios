# Curso de Java — de cero a fundamentos sólidos

Un curso **progresivo** para aprender **Java** desde cero, con **teoría a fondo** y **práctica**
(ejemplos ejecutables + ejercicios con solución). Inspirado en la forma de
[30-Days-Of-Python](https://github.com/Asabeneh/30-Days-Of-Python) —una lección por tema, cada una
con explicación completa y ejercicios—, pero organizado por **temas** en dificultad creciente, no
por días.

> **¿Por qué Java?** Es uno de los lenguajes más usados del mundo: aplicaciones empresariales,
> Android, sistemas backend de gran escala, banca. Es **orientado a objetos desde el diseño**,
> fuertemente tipado y se ejecuta sobre la **JVM** (Java Virtual Machine), lo que lo hace
> **multiplataforma** ("escribe una vez, ejecuta en cualquier lugar"). Aprender Java te enseña a
> pensar en objetos y a construir programas grandes y mantenibles.

> Si vienes de los cursos de [C](../curso_c_cpp/c) y [C++](../curso_c_cpp/cpp) de este repositorio,
> muchas ideas te sonarán (tipos, bucles, clases). Java las presenta de forma más segura y
> uniforme; se irán señalando las diferencias.

## Cómo está organizado

```
curso_java/
├── README.md            ← este archivo (plan del curso)
├── CONFIGURACION.md     ← instalar el JDK, compilar, ejecutar
├── FUENTES.md           ← bibliografía y fuentes usadas (libros, sitios, docs)
└── 01_.. 17_..          ← una carpeta por lección
```

Cada lección es una carpeta con:
- **`README.md`** — la teoría del tema, explicada en detalle y con ejemplos comentados.
- **`ejemplos/`** — programas cortos y **ejecutables** que ilustran cada idea.
- **`ejercicios/README.md`** — enunciados de práctica.
- **`ejercicios/soluciones/`** — soluciones ejecutables de esos ejercicios.

## Ruta de aprendizaje

| # | Lección | Aprendes a… |
|---|---------|-------------|
| 01 | [Introducción y primer programa](01_introduccion) | Qué es Java y la JVM, `Hola mundo`, compilar y ejecutar |
| 02 | [Variables, tipos y constantes](02_variables_y_tipos) | Tipos primitivos, `String`, `var`, `final`, conversiones |
| 03 | [Entrada y salida](03_entrada_salida) | `System.out`, `Scanner`, formato con `printf` |
| 04 | [Operadores](04_operadores) | Aritméticos, relacionales, lógicos, precedencia |
| 05 | [Condicionales](05_condicionales) | `if/else`, `switch` (clásico y de expresión), ternario |
| 06 | [Bucles](06_bucles) | `while`, `do-while`, `for`, `for-each`, `break`/`continue` |
| 07 | [Métodos](07_metodos) | Parámetros, retorno, sobrecarga, `static`, paso por valor |
| 08 | [Arreglos](08_arreglos) | Vectores, matrices, `Arrays`, recorrido |
| 09 | [Cadenas de texto](09_cadenas) | `String` (inmutable), métodos, `StringBuilder` |
| 10 | [Clases y objetos](10_clases_objetos) | POO: atributos, métodos, encapsulamiento, `this` |
| 11 | [Constructores, `static` y paquetes](11_constructores_static) | Ciclo de vida, miembros de clase, `package`/`import` |
| 12 | [Herencia y polimorfismo](12_herencia_polimorfismo) | `extends`, `super`, `@Override`, `abstract` |
| 13 | [Interfaces](13_interfaces) | Contratos, implementación múltiple, `default` |
| 14 | [Colecciones y genéricos](14_colecciones) | `ArrayList`, `HashMap`, `HashSet`, `<T>` |
| 15 | [Manejo de excepciones](15_excepciones) | `try/catch/finally`, checked vs unchecked, `throw` |
| 16 | [Lambdas y Streams](16_lambdas_streams) | Programación funcional, `filter`/`map`/`collect` |
| 17 | [Proyecto final](17_proyecto_final) | Gestor de tareas por consola (integra todo) |

## Cómo usar este curso

1. Lee [`CONFIGURACION.md`](CONFIGURACION.md) e instala el JDK.
2. Ve en orden. Lee el `README.md` de cada lección, **escribe y ejecuta** tú mismo los ejemplos
   (no solo los leas), y luego resuelve los ejercicios **antes** de mirar la solución.
3. Consulta [`FUENTES.md`](FUENTES.md) cuando quieras profundizar con material serio.

## Convenciones del curso

- El código está comentado en español; los mensajes en pantalla, sin acentos, para evitar
  problemas de codificación entre terminales.
- Cada ejemplo indica **cómo compilarlo/ejecutarlo** y **qué salida** produce.
- En Java, **el nombre del archivo debe coincidir con el nombre de la clase pública** que
  contiene. Por eso los archivos se llaman `Hola.java` (con `public class Hola`), `Ej1Saludo.java`,
  etc.
- Se usa una versión moderna del lenguaje (**Java 17+**, LTS). El JDK usado para probar es 21.
