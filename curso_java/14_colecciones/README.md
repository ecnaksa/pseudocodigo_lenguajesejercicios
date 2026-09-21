# Lección 14 — Colecciones y genéricos

Los arreglos (lección 08) tienen un tamaño **fijo**. El **framework de colecciones** de Java ofrece
estructuras de datos **dinámicas** y potentes: listas que crecen, diccionarios, conjuntos... Todas
viven en `java.util`.

## Genéricos: `<T>`

Antes de las colecciones, un apunte. Las colecciones son **genéricas**: les dices **qué tipo** de
elementos guardan con `<...>` (los ángulos):

```java
ArrayList<String> nombres;   // una lista de String
ArrayList<Integer> numeros;  // una lista de Integer
```

Esto le da **seguridad de tipos**: el compilador impide que metas un tipo equivocado, y no tienes
que hacer *casts*. Como las colecciones guardan **objetos**, para tipos primitivos se usan sus
**wrappers** (`Integer`, `Double`, `Boolean`...), y Java convierte solo (*autoboxing*, lección 02).

## `ArrayList`: la lista dinámica

`ArrayList` es como un arreglo que **crece y encoge** solo. Es la colección que más usarás.

```java
import java.util.ArrayList;

ArrayList<String> nombres = new ArrayList<>();   // <> vacio: infiere el tipo
nombres.add("Ana");             // agregar al final
nombres.add("Luis");
nombres.add("Sara");

System.out.println(nombres.size());     // 3
System.out.println(nombres.get(0));     // "Ana"  (acceso por indice)
nombres.set(1, "Luisa");                // reemplazar
nombres.remove("Sara");                 // quitar

for (String n : nombres) {              // recorrer con for-each
    System.out.println(n);
}
```

Operaciones habituales de `ArrayList`:

| Método | Qué hace |
|---|---|
| `add(x)` | agrega al final |
| `add(i, x)` | inserta en la posición `i` |
| `get(i)` | elemento en `i` |
| `set(i, x)` | reemplaza el de `i` |
| `remove(i)` / `remove(obj)` | quita por índice u objeto |
| `size()` | número de elementos |
| `contains(x)` | ¿lo contiene? |
| `isEmpty()` | ¿está vacía? |
| `clear()` | vacía la lista |

> **`List` como tipo:** es buena práctica declarar `List<String> nombres = new ArrayList<>();`
> (usando la interfaz `List` a la izquierda). Así puedes cambiar la implementación sin tocar el
> resto del código. `List` es una interfaz (lección 13); `ArrayList` es una implementación.

## `HashMap`: diccionario (clave → valor)

`HashMap` asocia **claves** con **valores**, como un diccionario. Buscar por clave es muy rápido.

```java
import java.util.HashMap;

HashMap<String, Integer> edades = new HashMap<>();
edades.put("Ana", 25);          // insertar / asignar
edades.put("Luis", 30);

System.out.println(edades.get("Ana"));       // 25
System.out.println(edades.containsKey("Luis")); // true

for (String clave : edades.keySet()) {       // recorrer las claves
    System.out.println(clave + " -> " + edades.get(clave));
}
// o recorrer las entradas (clave y valor a la vez):
for (var entrada : edades.entrySet()) {
    System.out.println(entrada.getKey() + " = " + entrada.getValue());
}
```

Métodos: `put`, `get`, `containsKey`, `remove`, `keySet`, `values`, `entrySet`, `size`.

> Un truco útil: `getOrDefault(clave, valorPorDefecto)` devuelve el valor o uno por defecto si la
> clave no existe. Ideal para **contar** (frecuencias): `mapa.put(c, mapa.getOrDefault(c, 0) + 1);`.

## `HashSet`: conjunto de elementos únicos

`HashSet` guarda elementos **únicos** (sin duplicados). Ideal para quitar repetidos o comprobar
pertenencia rápido:

```java
import java.util.HashSet;

HashSet<Integer> s = new HashSet<>();
s.add(3);
s.add(1);
s.add(3);        // ignorado: ya estaba
System.out.println(s.size());       // 2
System.out.println(s.contains(1));  // true
```
(Existe `TreeSet` si además los quieres **ordenados**, y `LinkedHashSet` si quieres conservar el
orden de inserción.)

## ¿Cuál elegir?

- **`ArrayList`**: lista de elementos por posición. La opción por defecto.
- **`HashMap`**: asociar clave → valor (contar, indexar por nombre).
- **`HashSet`**: elementos únicos / comprobar pertenencia.

(Hay más: `LinkedList`, `TreeMap`, `Stack`, `Queue`... pero con estas tres cubres casi todo al
empezar.)

## La clase de utilidad `Collections`

`java.util.Collections` trae métodos para colecciones (parecido a `Arrays` para arreglos):

```java
import java.util.Collections;

Collections.sort(lista);          // ordena una List
Collections.max(lista);           // el mayor
Collections.reverse(lista);       // invierte
```

## Errores típicos

- Olvidar los `import` (`java.util.ArrayList`, etc.).
- Usar un tipo primitivo en `<>`: es `ArrayList<Integer>`, no `ArrayList<int>`.
- Modificar una colección **mientras** la recorres con `for-each` → `ConcurrentModificationException`
  (usa un iterador o recorre una copia).
- Confundir `get(i)` de `List` (por índice) con `get(clave)` de `Map` (por clave).

## Resumen

- Las **colecciones** (`java.util`) son estructuras dinámicas **genéricas** (`<Tipo>`); usan
  wrappers para primitivos.
- **`ArrayList`**: lista dinámica (`add`, `get`, `size`, recorrer con `for-each`).
- **`HashMap`**: diccionario clave→valor (`put`, `get`, `getOrDefault`, `entrySet`).
- **`HashSet`**: elementos únicos.
- Declara con la interfaz (`List`, `Map`, `Set`) y usa `Collections` para ordenar, etc.

## Ejemplos

- [`ejemplos/UsarArrayList.java`](ejemplos/UsarArrayList.java)
- [`ejemplos/UsarHashMap.java`](ejemplos/UsarHashMap.java)
- [`ejemplos/UsarHashSet.java`](ejemplos/UsarHashSet.java)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **The Java Tutorials (Oracle)**, "Collections".
  https://docs.oracle.com/javase/tutorial/collections/
- **Baeldung**, "Java Collections", "Guide to HashMap".
  https://www.baeldung.com/java-collections
