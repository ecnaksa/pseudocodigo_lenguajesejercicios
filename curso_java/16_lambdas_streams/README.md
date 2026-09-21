# Lección 16 — Lambdas y Streams

Desde Java 8, el lenguaje incorpora **programación funcional**: las **lambdas** (funciones anónimas)
y los **Streams** (procesamiento de colecciones de forma declarativa). Permiten escribir en pocas
líneas, y de forma muy legible, operaciones que antes requerían bucles largos.

## Lambdas: funciones anónimas

Una **lambda** es una función corta y **sin nombre** que escribes en el sitio. Su sintaxis básica:

```java
(parametros) -> expresion
(parametros) -> { instrucciones; }
```

Ejemplos:

```java
x -> x * x                     // recibe x, devuelve x*x
(a, b) -> a + b                // recibe a y b, devuelve la suma
() -> System.out.println("hola")   // sin parametros
nombre -> { System.out.println("Hola " + nombre); }   // con cuerpo de bloque
```

### ¿Dónde se usan? Interfaces funcionales

Una lambda implementa una **interfaz funcional**: una interfaz con **un solo** método abstracto. Por
ejemplo, `Runnable` (un método `run`), `Comparator` (un método `compare`), o las del paquete
`java.util.function` (`Predicate`, `Function`, `Consumer`...).

```java
// Ordenar una lista con un Comparator escrito como lambda:
List<String> nombres = new ArrayList<>(List.of("Carlos", "Ana", "Beto"));
nombres.sort((a, b) -> a.length() - b.length());   // por longitud
```

Antes de las lambdas, esto requería crear una clase anónima entera; ahora es una línea.

### Referencias a métodos (breve)

Si tu lambda solo llama a un método existente, puedes usar una **referencia a método** con `::`:

```java
nombres.forEach(System.out::println);   // equivale a  n -> System.out.println(n)
```

## Streams: procesar colecciones de forma declarativa

Un **Stream** es una "tubería" por la que fluyen los elementos de una colección, aplicando
operaciones **encadenadas**. Se obtiene con `.stream()`:

```java
import java.util.List;

List<Integer> numeros = List.of(5, 2, 8, 1, 9, 4);

int sumaPares = numeros.stream()
        .filter(n -> n % 2 == 0)    // deja solo los pares
        .mapToInt(Integer::intValue)
        .sum();                     // los suma
System.out.println(sumaPares);      // 12
```

Se lee de arriba abajo como una receta: "toma los números, quédate con los pares, súmalos". Sin
bucles ni variables acumuladoras a mano.

### Operaciones más comunes

**Intermedias** (transforman el stream y devuelven otro stream; se encadenan):

| Operación | Qué hace |
|---|---|
| `filter(predicado)` | deja solo los que cumplen la condición |
| `map(funcion)` | transforma cada elemento |
| `sorted()` | ordena |
| `distinct()` | quita duplicados |
| `limit(n)` | se queda con los primeros `n` |

**Terminales** (producen un resultado y cierran el stream):

| Operación | Qué produce |
|---|---|
| `forEach(accion)` | ejecuta una acción por cada elemento |
| `count()` | cuántos elementos hay |
| `collect(Collectors.toList())` | recolecta en una lista |
| `reduce(...)` | combina en un solo valor |
| `anyMatch/allMatch(predicado)` | ¿alguno/todos cumplen? |

### Ejemplos

**Filtrar y recolectar:**
```java
import java.util.stream.Collectors;

List<String> nombres = List.of("Ana", "Beto", "Carlos", "Ana");
List<String> largos = nombres.stream()
        .filter(n -> n.length() > 3)     // solo los de mas de 3 letras
        .distinct()                       // sin repetidos
        .collect(Collectors.toList());
System.out.println(largos);              // [Beto, Carlos]
```

**Transformar (map):**
```java
List<Integer> longitudes = nombres.stream()
        .map(String::length)             // cada nombre -> su longitud
        .collect(Collectors.toList());
System.out.println(longitudes);          // [3, 4, 6, 3]
```

**Contar los que cumplen:**
```java
long cuantos = numeros.stream().filter(n -> n > 4).count();
```

## Streams vs. bucles: ¿cuándo usar cada uno?

- Los **streams** brillan para **encadenar** filtros, transformaciones y agregaciones sobre
  colecciones, de forma legible y concisa.
- Un **bucle** clásico sigue siendo perfecto para lógica simple, o cuando necesitas índices, romper
  con `break`, o modificar la colección.

No fuerces streams donde un bucle es más claro. Con la práctica, sabrás cuándo cada uno luce mejor.

## Errores típicos

- Olvidar la **operación terminal** (un stream sin `collect`/`forEach`/`count` no hace nada).
- Intentar **reusar** un stream ya consumido (cada stream se usa una vez).
- Olvidar `import java.util.stream.Collectors;` para `collect(Collectors.toList())`.
- Meter efectos secundarios complicados en una lambda (mejor mantenerlas puras y cortas).

## Resumen

- Una **lambda** `(params) -> cuerpo` es una función anónima; implementa una **interfaz funcional**
  (un solo método).
- Referencias a métodos con `::` cuando la lambda solo llama a un método.
- Los **Streams** procesan colecciones encadenando operaciones **intermedias** (`filter`, `map`,
  `sorted`...) y una **terminal** (`collect`, `count`, `forEach`, `reduce`).
- Legibles y concisos para transformar/filtrar/agregar datos; los bucles siguen siendo válidos para
  lo simple.

## Ejemplos

- [`ejemplos/Lambdas.java`](ejemplos/Lambdas.java)
- [`ejemplos/Streams.java`](ejemplos/Streams.java)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **The Java Tutorials (Oracle)**, "Lambda Expressions" y "Aggregate Operations".
  https://docs.oracle.com/javase/tutorial/collections/streams/
- **Baeldung**, "Java 8 Streams" y "Java Lambda Expressions".
  https://www.baeldung.com/java-8-streams
