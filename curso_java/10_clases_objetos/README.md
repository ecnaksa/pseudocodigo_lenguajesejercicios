# Lección 10 — Clases y objetos

Llegamos al corazón de Java: la **Programación Orientada a Objetos (POO)**. Java es orientado a
objetos **desde su diseño**: hasta ahora todo tu código vivía en una clase con `main`, pero usabas
métodos `static`. Ahora crearás tus **propias clases** y **objetos**.

## Clase y objeto

- Una **clase** es un **molde**: define qué **datos** (atributos) y qué **comportamientos**
  (métodos) tendrán los objetos de ese tipo.
- Un **objeto** es una **instancia** concreta creada a partir de la clase.

Analogía: la clase `Coche` es el plano; tu coche particular es un objeto.

## Definir una clase

```java
public class Rectangulo {
    // atributos (datos de cada objeto)
    double base;
    double altura;

    // metodo de instancia (usa los atributos del objeto)
    double area() {
        return base * altura;
    }
}
```

- Los **atributos** (`base`, `altura`) son las variables que tendrá **cada objeto**.
- Los **métodos** sin `static` son **métodos de instancia**: operan sobre **un objeto concreto**.
  Dentro de `area()`, `base` y `altura` son los del objeto sobre el que se llame el método.

## Crear y usar objetos

Los objetos se crean con **`new`**:

```java
Rectangulo r = new Rectangulo();   // crea un objeto Rectangulo
r.base = 4;                        // acceder a atributos con .
r.altura = 3;
System.out.println(r.area());      // llamar a un metodo con .  -> 12
```

Cada objeto tiene **sus propios** valores:

```java
Rectangulo r1 = new Rectangulo();  r1.base = 2;  r1.altura = 5;
Rectangulo r2 = new Rectangulo();  r2.base = 10; r2.altura = 1;
System.out.println(r1.area());     // 10
System.out.println(r2.area());     // 10  (mismo resultado, objetos distintos)
```

> **`static` vs instancia:** un método `static` (como `main`) pertenece a la **clase** y no puede
> usar atributos de objeto. Un método de **instancia** (sin `static`) opera sobre **un objeto** y
> sí usa sus atributos. Por eso `area()` no es `static`: necesita `base` y `altura` de *este*
> rectángulo.

## Encapsulamiento: `private` y `public`

La gran idea de la POO es **ocultar los detalles internos** y exponer solo lo necesario. Los
miembros pueden ser:

- **`public`**: accesibles desde cualquier lugar.
- **`private`**: accesibles **solo dentro de la clase**.
- (`protected` y el "por defecto" existen; los veremos con herencia.)

Hacer los atributos `private` protege el estado del objeto:

```java
public class CuentaBancaria {
    private double saldo;      // nadie fuera puede tocarlo directamente

    public void depositar(double monto) {
        if (monto > 0) saldo += monto;      // control desde dentro
    }
    public void retirar(double monto) {
        if (monto > 0 && monto <= saldo) saldo -= monto;
    }
    public double getSaldo() {
        return saldo;
    }
}
```

Desde fuera **no** puedes hacer `cuenta.saldo = -1000;` (error de compilación). Solo puedes usar los
métodos públicos, que **protegen** los datos (por ejemplo, impiden retirar más de lo que hay). El
código queda **más seguro** y **fácil de mantener**: la clase controla su propio estado.

## Getters y setters

El patrón habitual: atributos `private` con métodos públicos para **leerlos** (*getter*) y
**modificarlos** con validación (*setter*):

```java
public class Persona {
    private String nombre;
    private int edad;

    public String getNombre() { return nombre; }
    public void setNombre(String n) { nombre = n; }

    public int getEdad() { return edad; }
    public void setEdad(int e) {
        if (e >= 0) edad = e;    // validacion
    }
}
```

## El objeto `this`

Dentro de un método de instancia, **`this`** se refiere al **objeto actual**. Es útil cuando un
parámetro tiene el **mismo nombre** que un atributo:

```java
public void setNombre(String nombre) {
    this.nombre = nombre;   // this.nombre = atributo; nombre = parametro
}
```

## Un archivo, ¿varias clases?

En Java, cada archivo tiene **una clase pública** (que le da nombre al archivo). Puedes tener otras
clases **no públicas** en el mismo archivo, pero lo habitual en proyectos es **una clase por
archivo**. En los ejemplos de esta lección, la clase que se enseña incluye un método `main` para
poder ejecutarla directamente.

## Errores típicos

- Intentar acceder a un miembro `private` desde fuera → error de compilación.
- Olvidar `new` al crear un objeto (`Rectangulo r;` sin `new r = new Rectangulo();` deja `r` en
  `null`).
- Usar un objeto `null` → `NullPointerException`.
- Llamar a un método de instancia desde `main` (que es `static`) sin crear antes un objeto.

## Resumen

- Una **clase** define **atributos** (datos) y **métodos** (comportamiento); un **objeto** es una
  instancia creada con `new`.
- Se accede a miembros con `.`; cada objeto tiene sus propios valores.
- **Encapsulamiento:** atributos `private` + métodos `public` (getters/setters con validación).
- **`this`** referencia al objeto actual (útil con nombres repetidos).
- Métodos de **instancia** (sin `static`) operan sobre un objeto; los `static` pertenecen a la
  clase.

## Ejemplos

- [`ejemplos/Rectangulo.java`](ejemplos/Rectangulo.java)
- [`ejemplos/CuentaBancaria.java`](ejemplos/CuentaBancaria.java)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **The Java Tutorials (Oracle)**, "Classes and Objects".
  https://docs.oracle.com/javase/tutorial/java/javaOO/index.html
- **Head First Java**, cap. 2–4.
- **Baeldung**, "Java Classes and Objects". https://www.baeldung.com/java-classes-objects
