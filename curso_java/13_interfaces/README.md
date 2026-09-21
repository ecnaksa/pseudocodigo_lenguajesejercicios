# Lección 13 — Interfaces

Una **interfaz** es un **contrato**: define **qué** métodos debe tener una clase, sin decir **cómo**
los implementa. Es una de las herramientas más potentes de Java para escribir código flexible y
desacoplado.

## Qué es una interfaz

Una interfaz declara un conjunto de **métodos** (su firma, sin cuerpo). Una clase que **implementa**
la interfaz **se compromete** a proporcionar esos métodos:

```java
interface Volador {
    void volar();     // metodo sin cuerpo: solo la firma (el contrato)
}

class Pajaro implements Volador {
    @Override
    public void volar() {
        System.out.println("El pajaro bate las alas");
    }
}

class Avion implements Volador {
    @Override
    public void volar() {
        System.out.println("El avion enciende motores");
    }
}
```

- `interface Volador { ... }` define el contrato.
- `class Pajaro implements Volador` promete cumplirlo (y **debe** implementar `volar()`).
- Los métodos de una interfaz son `public` y `abstract` por defecto.

## Polimorfismo con interfaces

Igual que con la herencia, puedes usar una variable del **tipo de la interfaz** para referirte a
cualquier objeto que la implemente:

```java
Volador v1 = new Pajaro();
Volador v2 = new Avion();
v1.volar();     // "El pajaro bate las alas"
v2.volar();     // "El avion enciende motores"

Volador[] voladores = { new Pajaro(), new Avion() };
for (Volador v : voladores) {
    v.volar();  // cada uno segun su clase real
}
```
Lo importante: `Pajaro` y `Avion` **no** están relacionados por herencia (uno no es el otro), pero
**ambos son `Volador`**. La interfaz los une por lo que **saben hacer**, no por lo que **son**.

## Implementar varias interfaces

A diferencia de la herencia (una sola superclase), una clase puede **implementar varias
interfaces** a la vez. Así Java logra la "herencia múltiple" de comportamiento:

```java
interface Nadador { void nadar(); }

class Pato implements Volador, Nadador {   // implementa DOS interfaces
    @Override public void volar() { System.out.println("El pato vuela"); }
    @Override public void nadar() { System.out.println("El pato nada"); }
}
```

## Métodos `default` (Java 8+)

Una interfaz puede proporcionar una **implementación por defecto** de un método con `default`, para
no obligar a todas las clases a escribirlo:

```java
interface Saludable {
    void trabajar();
    default void descansar() {           // implementacion por defecto
        System.out.println("Tomando un descanso");
    }
}
```
Las clases que implementen `Saludable` obtienen `descansar()` gratis (pueden redefinirlo si
quieren).

## Constantes en interfaces

Los campos de una interfaz son `public static final` (constantes) por defecto:

```java
interface Config {
    int MAX = 100;      // en realidad public static final int MAX = 100;
}
```

## Interfaz vs. clase abstracta

Se parecen (ambas definen métodos que las subclases implementan), pero:

| | Interfaz | Clase abstracta |
|---|---|---|
| ¿Herencia múltiple? | Sí (una clase implementa varias) | No (una sola superclase) |
| ¿Atributos con estado? | No (solo constantes) | Sí |
| ¿Constructores? | No | Sí |
| ¿Métodos con cuerpo? | Solo `default`/`static` | Sí (los no abstractos) |
| Relación | "es capaz de" (comportamiento) | "es un tipo de" (jerarquía) |

**Regla práctica:** usa una **interfaz** para definir una **capacidad** que clases muy distintas
puedan tener (`Comparable`, `Volador`); usa una **clase abstracta** cuando compartas **estado y
código** entre clases relacionadas.

## Interfaces de la biblioteca estándar

Java usa interfaces por todas partes. Una muy común es **`Comparable`**, que permite **ordenar**
objetos de tu clase (por ejemplo, con `Collections.sort` o `Arrays.sort`):

```java
class Persona implements Comparable<Persona> {
    String nombre;
    int edad;
    // ...
    @Override
    public int compareTo(Persona otra) {
        return Integer.compare(this.edad, otra.edad);   // ordena por edad
    }
}
```
`compareTo` devuelve negativo, 0 o positivo según si `this` va antes, igual o después. Con esto,
Java sabe cómo ordenar tus objetos.

## Errores típicos

- Olvidar implementar **todos** los métodos de la interfaz (no compila).
- Olvidar `public` al implementar un método de interfaz (deben ser `public`).
- Intentar poner atributos con estado (no constantes) en una interfaz.
- Confundir `implements` (interfaz) con `extends` (clase).

## Resumen

- Una **interfaz** es un **contrato** de métodos; una clase la cumple con `implements`.
- Una clase puede implementar **varias** interfaces (herencia múltiple de comportamiento).
- El **polimorfismo** funciona con interfaces: una variable del tipo de la interfaz apunta a
  cualquier implementación.
- Métodos **`default`** dan implementación por defecto; los campos son constantes.
- Interfaz = "capacidad"; clase abstracta = "tipo de" con estado compartido. `Comparable` permite
  ordenar tus objetos.

## Ejemplos

- [`ejemplos/Voladores.java`](ejemplos/Voladores.java)
- [`ejemplos/OrdenarPersonas.java`](ejemplos/OrdenarPersonas.java)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **The Java Tutorials (Oracle)**, "Interfaces".
  https://docs.oracle.com/javase/tutorial/java/IandI/createinterface.html
- **Baeldung**, "Java Interfaces" y "Comparable". https://www.baeldung.com/java-interfaces
