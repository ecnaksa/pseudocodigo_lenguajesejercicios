# Lección 12 — Herencia y polimorfismo

Dos pilares de la POO. La **herencia** permite crear una clase **a partir de otra**, reutilizando su
código. El **polimorfismo** permite tratar objetos de clases relacionadas **de forma uniforme**.

## Herencia: `extends`

Imagina una clase `Animal` y quieres `Perro` y `Gato`, que **comparten** cosas (nombre, comer) pero
**añaden** o **cambian** otras. En vez de repetir código, heredan de `Animal` con **`extends`**:

```java
class Animal {                    // clase base (padre / superclase)
    protected String nombre;

    public Animal(String nombre) {
        this.nombre = nombre;
    }
    public void comer() {
        System.out.println(nombre + " esta comiendo");
    }
}

class Perro extends Animal {      // Perro HEREDA de Animal
    public Perro(String nombre) {
        super(nombre);           // llama al constructor de la superclase
    }
    public void ladrar() {
        System.out.println(nombre + " dice guau");
    }
}
```

- `class Perro extends Animal` significa "`Perro` **es un** `Animal`".
- `Perro` **hereda** los miembros de `Animal` (`nombre`, `comer`) y **añade** los suyos (`ladrar`).
- **`super(nombre)`** llama al **constructor de la superclase**. Debe ser la **primera** línea del
  constructor de la subclase.

```java
Perro p = new Perro("Rex");
p.comer();     // heredado de Animal
p.ladrar();    // propio de Perro
```

### `protected`

Un nivel de acceso entre `public` y `private`:
- **`private`**: solo la propia clase.
- **`protected`**: la propia clase **y sus subclases**.
- **`public`**: todos.

Por eso `nombre` es `protected`: para que `Perro` pueda usarlo, pero no el código externo.

### La clase `Object`

En Java, **toda** clase hereda (directa o indirectamente) de una clase raíz llamada **`Object`**.
De ahí vienen métodos como `toString()`, `equals()` y `hashCode()`, que puedes **redefinir**.

## Redefinir métodos: `@Override`

Una subclase puede **cambiar** un método heredado, redefiniéndolo. Se marca con **`@Override`**
(que el compilador verifique que de verdad redefine algo):

```java
class Animal {
    public void hacerSonido() {
        System.out.println("Sonido generico");
    }
}
class Gato extends Animal {
    @Override
    public void hacerSonido() {          // redefine el de Animal
        System.out.println("Miau");
    }
}
```

## Polimorfismo

El **polimorfismo** permite que una **variable del tipo de la superclase** contenga un objeto de
una **subclase**, y al llamar un método redefinido se ejecuta el de la **clase real** del objeto:

```java
Animal a = new Gato();   // una variable Animal apunta a un objeto Gato
a.hacerSonido();         // imprime "Miau" (el de Gato, su clase real)
```

Esto brilla con arreglos o listas de la superclase:

```java
Animal[] animales = {
    new Perro("Rex"),
    new Gato("Michi")
};
for (Animal an : animales) {
    an.hacerSonido();     // cada uno responde segun su tipo real
}
```
**Sin** redefinir, se usaría el método de `Animal`. **Con** la redefinición y el polimorfismo, se
llama al de cada subclase, aunque el arreglo sea de tipo `Animal`. Es la base de diseños flexibles
y extensibles.

> **`super.metodo()`:** dentro de un método redefinido, puedes llamar a la versión de la superclase
> con `super.metodo()`. Útil para "ampliar" en vez de reemplazar.

## Clases y métodos `abstract`

A veces la superclase representa un **concepto** sin implementación concreta (¿qué sonido hace un
"Animal" genérico?). Una clase **`abstract`**:
- **No** se puede instanciar (no `new`).
- Puede tener **métodos abstractos** (sin cuerpo), que las subclases **están obligadas** a
  implementar.

```java
abstract class Figura {
    abstract double area();          // metodo abstracto: sin cuerpo
}

class Circulo extends Figura {
    double r;
    public Circulo(double r) { this.r = r; }
    @Override
    double area() { return 3.14159 * r * r; }   // obligatorio implementarlo
}
```
`Figura` define una **plantilla**: "todo lo que sea `Figura` debe saber calcular su `area()`".

## Herencia simple

En Java, una clase **solo puede heredar de UNA** superclase (herencia **simple**, a diferencia de
C++). Para "heredar comportamiento" de varias fuentes se usan las **interfaces** (lección 13).

## Errores típicos

- Olvidar `super(...)` cuando la superclase no tiene constructor sin parámetros.
- Redefinir mal un método (firma distinta): sin `@Override` no te enteras; **con** `@Override` el
  compilador te avisa. Úsalo siempre.
- Intentar instanciar una clase `abstract` con `new`.
- Confundir herencia ("es un") con composición ("tiene un"): un `Coche` **tiene un** motor, no
  hereda de `Motor`.

## Resumen

- **Herencia** con `extends`: reutiliza y extiende; `protected` es visible para las subclases.
- El constructor de la subclase llama al de la superclase con **`super(...)`**.
- **`@Override`** redefine métodos; con **polimorfismo**, una variable de la superclase ejecuta el
  método de la clase real del objeto.
- Clases/métodos **`abstract`** definen plantillas que las subclases deben completar.
- Java tiene herencia **simple** (una superclase); lo múltiple se logra con interfaces.

## Ejemplos

- [`ejemplos/Animales.java`](ejemplos/Animales.java)
- [`ejemplos/Figuras.java`](ejemplos/Figuras.java)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **The Java Tutorials (Oracle)**, "Inheritance" y "Polymorphism".
  https://docs.oracle.com/javase/tutorial/java/IandI/subclasses.html
- **Baeldung**, "Inheritance in Java" y "Polymorphism".
  https://www.baeldung.com/java-inheritance
