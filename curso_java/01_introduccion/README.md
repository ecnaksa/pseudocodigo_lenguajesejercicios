# Lección 01 — Introducción y primer programa

## Qué es Java

**Java** es un lenguaje de programación creado por **James Gosling** en Sun Microsystems (hoy
Oracle), lanzado en 1995. Es:

- **Orientado a objetos:** todo el código vive dentro de **clases**; Java te hace pensar en
  objetos desde el primer programa.
- **Fuertemente tipado:** cada variable tiene un tipo fijo, y el compilador verifica muchos
  errores antes de ejecutar.
- **Multiplataforma:** no se compila a lenguaje máquina directo, sino a **bytecode**, que ejecuta
  la **JVM** (Java Virtual Machine). El mismo programa corre en Windows, Linux o Mac sin cambios:
  *"write once, run anywhere"* ("escribe una vez, ejecuta donde sea").
- **De propósito general:** se usa en aplicaciones empresariales, Android, sistemas backend, banca,
  *big data* y mucho más.

### JDK, JVM y bytecode

- **JDK** (Java Development Kit): las herramientas para **desarrollar**: el compilador `javac`, la
  JVM `java` y las bibliotecas. Es lo que instalas ([`CONFIGURACION.md`](../CONFIGURACION.md)).
- **Compilar:** `javac` traduce tu `.java` a **bytecode** (`.class`), un formato intermedio.
- **Ejecutar:** la **JVM** (`java`) ejecuta ese bytecode.

```
Tu codigo (.java)  --javac-->  Bytecode (.class)  --JVM-->  Programa en ejecucion
```

## Tu primer programa: "Hola, mundo"

Crea un archivo llamado **`Hola.java`** (el nombre importa, ver abajo):

```java
public class Hola {
    public static void main(String[] args) {
        System.out.println("Hola, mundo");
    }
}
```

Compílalo y ejecútalo:

```bash
javac Hola.java     # genera Hola.class
java Hola           # ejecuta la clase Hola (¡sin extension!)
```

Salida:

```
Hola, mundo
```

Ahora entendamos **cada parte**, porque en este programa tan corto está la estructura de todo
programa Java.

## Anatomía del programa

```java
public class Hola {
```
- En Java, **todo el código vive dentro de una clase**. Aquí la clase se llama `Hola`.
- `public` significa que la clase es accesible desde cualquier lugar.
- **Regla clave:** el archivo **debe** llamarse igual que la clase pública: `Hola` → `Hola.java`.
  Si no coinciden, el compilador da error.

```java
    public static void main(String[] args) {
```
Esta es la línea más importante: el **método `main`**, el **punto de entrada** por donde la JVM
empieza a ejecutar. Desglosémosla:
- **`public`**: accesible desde fuera (la JVM debe poder llamarlo).
- **`static`**: pertenece a la clase, no a un objeto; se puede ejecutar sin crear un objeto de
  `Hola`.
- **`void`**: no devuelve ningún valor.
- **`main`**: el nombre exacto que la JVM busca para empezar.
- **`(String[] args)`**: recibe los **argumentos de la línea de comandos** (un arreglo de cadenas).
  Por ahora no los usaremos, pero la firma debe ser exactamente esa.

Debes escribir esta línea **tal cual**; es una fórmula fija que memorizarás rápido.

```java
        System.out.println("Hola, mundo");
```
- **`System.out`** es el objeto de la **salida estándar** (la consola).
- **`println`** (*print line*) imprime el texto **y** salta de línea al final.
  (`print` imprime **sin** saltar de línea.)
- Entre comillas dobles va una **cadena de texto** (*String*).
- La instrucción termina en **`;`** (punto y coma). En Java, casi toda instrucción acaba en `;`.

```java
    }
}
```
Las llaves cierran, respectivamente, el método `main` y la clase `Hola`. Cada `{` tiene su `}`.

## `println` vs `print`

```java
System.out.println("Linea 1");   // imprime y salta de linea
System.out.println("Linea 2");
System.out.print("Sin ");        // NO salta
System.out.print("salto\n");     // \n es un salto de linea manual
```
Salida:
```
Linea 1
Linea 2
Sin salto
```

## Secuencias de escape

Dentro de una cadena, `\` empieza un carácter especial:

| Secuencia | Significado |
|---|---|
| `\n` | Salto de línea |
| `\t` | Tabulación |
| `\"` | Comilla doble literal |
| `\\` | Barra invertida literal |

## Comentarios

```java
// Comentario de una linea

/* Comentario
   de varias lineas */

/** Comentario de documentacion (Javadoc), para describir clases y metodos */
```
El compilador **ignora** los comentarios; son para las personas. El tercer tipo (`/** */`) es
**Javadoc**, que sirve para generar documentación automática.

## Errores típicos al empezar

- **El nombre del archivo no coincide** con la clase pública → error de compilación.
- **Olvidar el `;`** al final de una instrucción.
- **Mayúsculas:** Java distingue mayúsculas. `System` no es `system`, `String` no es `string`.
- Escribir mal la firma de `main` → el programa compila pero la JVM no encuentra dónde empezar.
- Ejecutar con `java Hola.class` (mal) en vez de `java Hola` (bien).

## Resumen

- En Java todo va dentro de **clases**; el archivo se llama igual que la clase pública.
- El programa empieza en `public static void main(String[] args)`.
- `System.out.println(...)` imprime con salto de línea; las instrucciones terminan en `;`.
- Se compila con `javac Archivo.java` y se ejecuta con `java Clase`.
- Java pasa por **bytecode** que ejecuta la **JVM** (multiplataforma).

## Ejemplos de esta lección

- [`ejemplos/Hola.java`](ejemplos/Hola.java) — el clásico "Hola, mundo".
- [`ejemplos/VariasLineas.java`](ejemplos/VariasLineas.java) — `println`, `print`, `\n` y `\t`.
- [`ejemplos/Comentarios.java`](ejemplos/Comentarios.java) — tipos de comentarios.

## Ejercicios

Ve a [`ejercicios/`](ejercicios/). Intenta resolverlos antes de mirar las soluciones.

## Para profundizar

- **The Java Tutorials (Oracle)**, "Getting Started" →
  https://docs.oracle.com/javase/tutorial/getStarted/
- **Head First Java**, cap. 1 ("Breaking the Surface").
- **Baeldung**, "Java Main Method". https://www.baeldung.com/java-main-method
