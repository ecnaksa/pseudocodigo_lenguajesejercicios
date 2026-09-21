# Lección 09 — Cadenas de texto (`String`)

El texto es uno de los datos más usados. En Java, el texto se representa con la clase **`String`**,
que es un **objeto** (tipo de referencia) con muchos métodos útiles. Ya la has usado; aquí la verás
a fondo.

## Crear cadenas

```java
String saludo = "Hola";              // la forma habitual (literal)
String vacia = "";                   // cadena vacia
String otra = new String("Hola");    // valida, pero innecesaria: usa el literal
```

## Las cadenas son **inmutables**

Un `String`, una vez creado, **no se puede modificar**. Los métodos que "cambian" una cadena en
realidad **devuelven una nueva**:

```java
String s = "hola";
s.toUpperCase();              // NO cambia s; devuelve "HOLA" y se descarta
System.out.println(s);       // sigue siendo "hola"

s = s.toUpperCase();         // hay que REASIGNAR para conservar el resultado
System.out.println(s);       // "HOLA"
```
Recuérdalo: **para conservar el resultado de un método de `String`, reasigna** (`s = s.metodo()`).

## Comparar cadenas: `.equals()`, no `==`

Este es el punto **más importante** de los `String`. `==` compara si dos variables apuntan al
**mismo objeto**; para comparar el **contenido** se usa **`.equals()`**:

```java
String a = "hola";
String b = "hola";
String c = new String("hola");

System.out.println(a == b);        // puede ser true (literales compartidos), NO fiable
System.out.println(a == c);        // false (objetos distintos)
System.out.println(a.equals(c));   // true  (mismo contenido) <- ESTO es lo correcto
```

- **`equals`** compara el contenido (distingue mayúsculas).
- **`equalsIgnoreCase`** ignora mayúsculas/minúsculas.

```java
if (respuesta.equalsIgnoreCase("SI")) { ... }   // acepta "si", "Si", "SI"...
```

## Métodos útiles de `String`

| Método | Qué hace | Ejemplo (`s = "Hola Mundo"`) |
|---|---|---|
| `s.length()` | longitud | `10` |
| `s.charAt(i)` | carácter en la posición `i` | `s.charAt(0)` → `'H'` |
| `s.substring(i)` | desde `i` hasta el final | `s.substring(5)` → `"Mundo"` |
| `s.substring(i, j)` | de `i` a `j-1` | `s.substring(0, 4)` → `"Hola"` |
| `s.indexOf("x")` | posición de `"x"` (o `-1`) | `s.indexOf("Mundo")` → `5` |
| `s.contains("x")` | ¿contiene `"x"`? | `s.contains("Hola")` → `true` |
| `s.toUpperCase()` / `toLowerCase()` | mayúsculas / minúsculas | `"HOLA MUNDO"` |
| `s.trim()` | quita espacios de los extremos | `" x ".trim()` → `"x"` |
| `s.replace("a","o")` | reemplaza | `"Holo Mundo"` |
| `s.split(" ")` | divide en un arreglo | `["Hola", "Mundo"]` |
| `s.isEmpty()` | ¿está vacía? | `false` |
| `String.valueOf(x)` | convierte un valor a texto | `String.valueOf(42)` → `"42"` |

> **Ojo:** `String` usa `.length()` **con paréntesis** (es un método), mientras que un **arreglo**
> usa `.length` **sin** paréntesis (es un atributo). No los confundas.

### Recorrer una cadena carácter a carácter

```java
String s = "Java";
for (int i = 0; i < s.length(); i++) {
    System.out.println(s.charAt(i));
}
```

## Concatenación

Con `+` (como ya viste) o con `.concat()`:

```java
String nombre = "Ana";
String saludo = "Hola, " + nombre + "!";   // lo mas comun
```

## `StringBuilder`: construir texto eficientemente

Como los `String` son inmutables, **concatenar muchas veces en un bucle** crea muchos objetos
temporales (ineficiente). Para construir texto pieza a pieza, usa **`StringBuilder`**, que **sí**
es modificable:

```java
StringBuilder sb = new StringBuilder();
for (int i = 1; i <= 5; i++) {
    sb.append(i).append(" ");     // append agrega al final
}
String resultado = sb.toString();   // "1 2 3 4 5 "
System.out.println(resultado);
```
Métodos de `StringBuilder`: `append`, `insert`, `reverse`, `toString`. Úsalo cuando construyas
cadenas en bucles; para concatenaciones sueltas, `+` está bien.

## Texto en bloque (Java 15+, opcional)

Java moderno permite cadenas de varias líneas con `"""`:

```java
String html = """
        <html>
          <body>Hola</body>
        </html>
        """;
```

## Errores típicos

- **Comparar con `==`** en vez de `.equals()` (el error más común con `String`).
- Olvidar **reasignar** el resultado de un método (`s = s.trim();`, no solo `s.trim();`).
- Confundir `.length()` (String, con paréntesis) y `.length` (arreglo, sin).
- Índice fuera de rango en `charAt`/`substring` → `StringIndexOutOfBoundsException`.

## Resumen

- `String` es un **objeto inmutable**; los métodos devuelven **nuevas** cadenas (reasigna).
- **Compara con `.equals()`** (o `equalsIgnoreCase`), **nunca con `==`**.
- Métodos clave: `length()`, `charAt`, `substring`, `indexOf`, `contains`, `toUpperCase`, `split`,
  `trim`, `replace`.
- **`StringBuilder`** para construir texto eficientemente en bucles.

## Ejemplos

- [`ejemplos/MetodosString.java`](ejemplos/MetodosString.java)
- [`ejemplos/CompararStrings.java`](ejemplos/CompararStrings.java)
- [`ejemplos/UsarStringBuilder.java`](ejemplos/UsarStringBuilder.java)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **The Java Tutorials (Oracle)**, "Strings".
  https://docs.oracle.com/javase/tutorial/java/data/strings.html
- **Baeldung**, "Java String" y "StringBuilder vs StringBuffer".
  https://www.baeldung.com/java-string
