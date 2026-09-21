# Lección 07 — Métodos

Un **método** es un bloque de código con nombre que realiza una tarea, puede recibir **parámetros**
y puede **devolver** un resultado. En Java, todos los métodos viven dentro de una **clase** (ya usas
uno: `main`). Aquí aprenderás a crear los tuyos.

## Por qué usar métodos

- **No repetir código** (DRY): escribes la lógica una vez y la reutilizas.
- **Dividir** el problema en piezas pequeñas.
- **Legibilidad:** `double area = areaCirculo(5);` se lee mejor que la fórmula repetida.

## Anatomía de un método

```java
modificadores  tipoDeRetorno  nombre(parametros) {
    // cuerpo
    return valor;   // si el tipo no es void
}
```

Ejemplo, dentro de una clase:

```java
public class Demo {
    static int sumar(int a, int b) {
        return a + b;
    }

    public static void main(String[] args) {
        int total = sumar(3, 4);   // llamada
        System.out.println(total); // 7
    }
}
```

- **`static`**: por ahora usaremos métodos `static`, que pertenecen a la **clase** (se pueden
  llamar desde `main`, que también es `static`, sin crear objetos). Cuando lleguemos a la POO
  (lección 10) verás los métodos **de instancia** (sin `static`).
- **`int`**: el **tipo que devuelve**.
- **`(int a, int b)`**: los **parámetros**.
- **`return`**: entrega el valor y termina el método.

## Métodos `void` (no devuelven nada)

Si el método solo **hace** algo (imprimir, por ejemplo), su tipo de retorno es **`void`**:

```java
static void saludar(String nombre) {
    System.out.println("Hola, " + nombre);
}
// ...
saludar("Ana");
```

## Sobrecarga de métodos

Java permite **varios métodos con el mismo nombre**, distinguidos por sus **parámetros** (número o
tipos). El compilador elige el correcto según cómo lo llames:

```java
static int    sumar(int a, int b)       { return a + b; }
static double sumar(double a, double b) { return a + b; }
static int    sumar(int a, int b, int c){ return a + b + c; }

sumar(3, 4);        // la de dos int
sumar(2.5, 1.5);    // la de dos double
sumar(1, 2, 3);     // la de tres int
```
Lo que **no** basta para distinguir es solo el tipo de retorno.

## Paso de argumentos: siempre **por valor**

En Java **todo se pasa por valor** (una copia). Esto tiene un matiz importante según el tipo:

- **Primitivos** (`int`, `double`...): se copia el **valor**. Modificar el parámetro **no** afecta a
  la variable original:
  ```java
  static void intentarCambiar(int x) { x = 100; }   // cambia solo la copia
  // ...
  int n = 5;
  intentarCambiar(n);
  System.out.println(n);   // sigue siendo 5
  ```
- **Objetos** (incluidos los **arreglos**): se copia la **referencia** (la "dirección"). El método
  **no** puede hacer que tu variable apunte a otro objeto, pero **sí** puede **modificar el
  contenido** del objeto al que ambos apuntan:
  ```java
  static void duplicarTodos(int[] arr) {
      for (int i = 0; i < arr.length; i++) arr[i] *= 2;   // modifica el arreglo original
  }
  ```
  Por eso un método puede "cambiar" un arreglo que le pasaste, pero no un `int`. (En Java **no**
  existen los punteros ni el paso por referencia de C/C++: para "devolver" un valor, se usa
  `return`.)

## Ámbito (scope)

Las variables declaradas dentro de un método (incluidos sus parámetros) son **locales**: solo
existen ahí. Dos métodos pueden usar `i` sin interferir.

## Recursión

Un método puede llamarse a sí mismo, con un **caso base** que detenga la recursión:

```java
static long factorial(int n) {
    if (n <= 1) return 1;             // caso base
    return n * factorial(n - 1);      // caso recursivo
}
```
`factorial(4)` = `4 * factorial(3)` = ... = `24`. Sin caso base, la recursión sería infinita
(`StackOverflowError`).

## Buenas prácticas

- **Un método, una tarea.** Si hace demasiado, divídelo.
- **Nombres que digan qué hace** (`calcularPromedio`, no `f`), en `camelCase`.
- Mantenlos **cortos** y documenta con un comentario qué reciben y qué devuelven.

## Errores típicos

- Olvidar el `return` en un método que no es `void`.
- Esperar que un método modifique un **primitivo** pasado como argumento (no lo hará; usa
  `return`).
- Dos sobrecargas que solo difieren en el tipo de retorno → error.
- Recursión sin caso base → `StackOverflowError`.

## Resumen

- `static tipo nombre(parametros){ ... return valor; }`, dentro de una clase.
- `void` si no devuelve nada; **sobrecarga** por parámetros.
- Todo se pasa **por valor**: los primitivos no cambian afuera; los objetos/arreglos sí pueden ver
  modificado su **contenido**.
- **Recursión**: caso base + caso recursivo.

## Ejemplos

- [`ejemplos/Sumar.java`](ejemplos/Sumar.java)
- [`ejemplos/PorValor.java`](ejemplos/PorValor.java)
- [`ejemplos/Recursion.java`](ejemplos/Recursion.java)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **The Java Tutorials (Oracle)**, "Defining Methods" y "Passing Information to a Method".
  https://docs.oracle.com/javase/tutorial/java/javaOO/methods.html
- **Baeldung**, "Java Pass-By-Value". https://www.baeldung.com/java-pass-by-value-or-pass-by-reference
