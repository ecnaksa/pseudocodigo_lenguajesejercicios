# Lección 11 — Constructores, `static` y paquetes

En la lección anterior, tras crear un objeto había que inicializar sus atributos "a mano". Los
**constructores** automatizan eso: se ejecutan **al crear** el objeto. También veremos los miembros
**`static`** (compartidos por la clase) y cómo organizar el código en **paquetes**.

## El constructor

Un **constructor** es un método especial que:
- Se llama **igual que la clase**.
- **No** tiene tipo de retorno (ni `void`).
- Se ejecuta **automáticamente** al crear un objeto con `new`.

```java
public class Punto {
    double x, y;

    public Punto(double x, double y) {   // constructor
        this.x = x;                      // this distingue atributo de parametro
        this.y = y;
    }
}

Punto p = new Punto(3, 4);   // se llama al constructor: p.x=3, p.y=4
```

Sin constructor, había que hacer `p.x = 3; p.y = 4;` aparte. Con constructor, el objeto **nace
inicializado y válido**.

### El constructor por defecto

Si **no** escribes ningún constructor, Java te da uno **por defecto** (sin parámetros, que deja los
atributos en su valor por defecto). Pero **en cuanto escribes uno con parámetros**, el por defecto
**deja de existir**; si aún quieres uno sin parámetros, debes escribirlo tú.

## Sobrecarga de constructores

Como cualquier método, puedes tener **varios constructores** con distintos parámetros:

```java
public class Punto {
    double x, y;

    public Punto() {                    // sin parametros -> (0, 0)
        this(0, 0);                     // llama a otro constructor (encadenamiento)
    }
    public Punto(double x, double y) {  // con parametros
        this.x = x;
        this.y = y;
    }
}
```
`this(...)` **llama a otro constructor** de la misma clase (encadenamiento), para no repetir código.

## Miembros `static`: de la clase, no del objeto

Un miembro **`static`** pertenece a la **clase**, no a cada objeto: **todos** los objetos lo
comparten. Útil, por ejemplo, para **contar** cuántos objetos se han creado, o para constantes y
utilidades:

```java
public class Usuario {
    static int total = 0;        // compartido por toda la clase

    public Usuario() {
        total++;                 // cada objeto creado incrementa el contador comun
    }
}

new Usuario(); new Usuario(); new Usuario();
System.out.println(Usuario.total);   // 3  (se accede con Clase.miembro)
```

- Un **atributo `static`** es único para toda la clase (no uno por objeto).
- Un **método `static`** (como `main`, o `Math.sqrt`) se llama sobre la **clase**, no sobre un
  objeto: `Math.max(3, 5)`, `Usuario.total`.
- Las **constantes** suelen ser `static final`: `public static final double PI = 3.14159;`.

## `toString()`: cómo se imprime un objeto

Si imprimes un objeto directamente, ves algo como `Punto@1b6d3586` (la clase y una dirección). Para
que muestre algo útil, **redefine** el método `toString()`:

```java
@Override
public String toString() {
    return "(" + x + ", " + y + ")";
}
// ...
System.out.println(p);    // ahora imprime (3.0, 4.0)
```
`@Override` indica que estás redefiniendo un método heredado (de la clase `Object`, de la que
**todas** las clases heredan). Lo veremos más en herencia.

## Paquetes (`package` e `import`)

Un **paquete** (*package*) es una carpeta lógica que **agrupa clases relacionadas** y evita choques
de nombres, como los namespaces. Ya has usado paquetes al importar:

```java
import java.util.Scanner;   // Scanner esta en el paquete java.util
import java.util.ArrayList;
```

- **`import`** trae una clase de otro paquete para usarla por su nombre corto.
- Las clases de `java.lang` (como `String`, `System`, `Math`) se importan **automáticamente**.
- Para **tus** clases, puedes declarar un paquete al inicio del archivo:
  `package com.miapp.modelo;` (y colocar el archivo en carpetas que coincidan). En proyectos
  pequeños, sin `package`, todo va al "paquete por defecto". No te preocupes por esto al empezar;
  basta saber que `import` trae clases de la biblioteca estándar.

## Errores típicos

- Ponerle **tipo de retorno** al constructor (no lleva; si le pones `void`, ¡se convierte en un
  método normal, no un constructor!).
- Definir un constructor con parámetros y luego intentar `new Clase()` sin haber escrito el
  constructor sin parámetros.
- Olvidar definir/redefinir `toString()` y extrañarse de ver `Clase@hash` al imprimir.
- Acceder a un miembro `static` como si fuera de instancia (usa `Clase.miembro`).

## Resumen

- El **constructor** (mismo nombre que la clase, sin retorno) inicializa el objeto al crearlo con
  `new`; usa `this.` para distinguir atributos de parámetros.
- Puedes **sobrecambiar** (sobrecargar) constructores y encadenarlos con `this(...)`.
- Miembros **`static`** pertenecen a la clase (compartidos); constantes suelen ser `static final`.
- **`toString()`** define cómo se imprime un objeto.
- Los **paquetes** agrupan clases; `import` trae clases de otros paquetes.

## Ejemplos

- [`ejemplos/Punto.java`](ejemplos/Punto.java)
- [`ejemplos/ContadorStatic.java`](ejemplos/ContadorStatic.java)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **The Java Tutorials (Oracle)**, "Providing Constructors" y "Understanding Class Members".
  https://docs.oracle.com/javase/tutorial/java/javaOO/constructors.html
- **Baeldung**, "Java Constructors" y "Static Fields". https://www.baeldung.com/java-constructors
