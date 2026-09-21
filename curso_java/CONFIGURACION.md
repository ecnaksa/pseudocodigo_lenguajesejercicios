# Configuración del entorno (Java)

Para programar en Java necesitas el **JDK** (Java Development Kit) y un **editor de texto**.

## 1. El JDK

El **JDK** incluye el **compilador** (`javac`), la **máquina virtual** (`java`) y las bibliotecas
estándar. No confundir con el **JRE** (solo ejecuta, no compila): tú necesitas el **JDK**.

Elige una versión **LTS** (soporte a largo plazo): **Java 17** o **Java 21** son excelentes
opciones actuales. Distribuciones populares (todas gratuitas):

- **Eclipse Temurin (Adoptium)** — https://adoptium.net (recomendada, multiplataforma)
- **Oracle JDK** — https://www.oracle.com/java/technologies/downloads/
- **OpenJDK** (el de tu sistema) — en Linux: `sudo apt install openjdk-21-jdk`

### Comprobar que funciona

```bash
java -version     # muestra la version de la maquina virtual
javac -version    # muestra la version del compilador
```

## 2. El editor / IDE

Para empezar, cualquier editor sirve; para proyectos, un IDE ayuda mucho:

- **Visual Studio Code** (https://code.visualstudio.com) + "Extension Pack for Java" de Microsoft.
  Ligero y gratuito.
- **IntelliJ IDEA Community** (https://www.jetbrains.com/idea/) — el IDE de Java más popular,
  gratuito en su edición Community.
- **Eclipse** (https://www.eclipseide.org/) — clásico y gratuito.

## 3. Compilar y ejecutar

Un programa Java pasa por dos pasos: **compilar** (traducir a *bytecode*, un `.class`) y
**ejecutar** ese bytecode sobre la JVM.

```bash
javac Hola.java     # compila Hola.java -> genera Hola.class (bytecode)
java Hola           # ejecuta la clase Hola (¡sin la extension!)
```

> **Importante:** al ejecutar se pone el **nombre de la clase**, no el archivo: `java Hola`, no
> `java Hola.class` ni `java Hola.java`.

Desde **Java 11** puedes ejecutar un archivo de una sola clase **sin compilar aparte**:

```bash
java Hola.java      # compila y ejecuta al vuelo (comodo para probar)
```

### El nombre del archivo importa

En Java, si una clase es `public`, el archivo **debe** llamarse igual que la clase, con
extensión `.java`:

```java
// archivo: Hola.java
public class Hola {           // la clase publica se llama Hola -> archivo Hola.java
    public static void main(String[] args) {
        System.out.println("Hola, mundo");
    }
}
```

## 4. Dar entrada al programa sin teclear (útil para probar)

Si un programa lee del teclado, puedes "alimentárselo":

```bash
printf "25\n" | java Programa
```

## 5. Sobre la JVM y el bytecode (idea general)

Java no se compila directamente a lenguaje máquina, sino a **bytecode** (`.class`), un formato
intermedio. La **JVM** ejecuta ese bytecode. Como hay una JVM para cada sistema (Windows, Linux,
Mac), el **mismo** `.class` corre en todos: es el famoso *"write once, run anywhere"*. Además, la
JVM optimiza el código en caliente (compilación JIT), lo que hace a Java muy rápido pese a ese
paso intermedio.

## 6. Cómo trabajar con este curso

1. Crea una carpeta de trabajo tuya (aparte del repo) para experimentar.
2. Copia o reescribe los ejemplos, compílalos y ejecútalos. **Cambia cosas** y observa qué pasa.
3. Resuelve los ejercicios tú antes de ver la solución.

Ya con esto listo, empieza por la lección [`01_introduccion`](01_introduccion/).
