# Lección 03 — Entrada y salida

Ya sabes **mostrar** con `System.out.println`. Ahora aprenderás a **leer** datos del teclado con
la clase **`Scanner`**, y a dar formato a la salida.

## Salida: `println`, `print` y `printf`

- **`System.out.println(x)`** — imprime `x` y salta de línea.
- **`System.out.print(x)`** — imprime `x` **sin** saltar de línea.
- **`System.out.printf(...)`** — imprime **con formato** (estilo `printf` de C).

### Concatenar con `+`

La forma más directa de mostrar texto y valores juntos es concatenar con `+`:

```java
int edad = 25;
System.out.println("Tengo " + edad + " anios");
```
Cuando un `+` tiene un `String` de un lado, el otro operando se convierte a texto automáticamente.

### `printf` para formato

`printf` usa **especificadores** (como en C) y **no** salta de línea solo (pon `%n` o `\n`):

```java
double pi = 3.14159;
System.out.printf("Pi con 2 decimales: %.2f%n", pi);   // 3.14
System.out.printf("%-8s %5d%n", "Ana", 25);            // texto y numero alineados
```

| Especificador | Para |
|---|---|
| `%d` | entero |
| `%f` | decimal (`%.2f` = 2 decimales) |
| `%s` | cadena |
| `%c` | carácter |
| `%b` | booleano |
| `%n` | salto de línea (portable) |

> **Ojo con decimales y locale:** `printf` usa la configuración regional del sistema, que en
> algunos países muestra coma decimal. Para forzar el punto se puede usar
> `System.out.printf(java.util.Locale.US, "%.2f%n", pi);`.

## Entrada: la clase `Scanner`

Para leer del teclado se usa **`Scanner`** (de `java.util.Scanner`). El flujo es:

1. **Importar** la clase (arriba del archivo): `import java.util.Scanner;`
2. **Crear** un `Scanner` conectado a la entrada estándar: `Scanner sc = new Scanner(System.in);`
3. **Leer** con sus métodos (`nextInt`, `nextDouble`, `nextLine`...).
4. **Cerrar** al terminar: `sc.close();`

```java
import java.util.Scanner;

public class Ejemplo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Tu edad: ");
        int edad = sc.nextInt();

        System.out.println("El proximo anio tendras " + (edad + 1));
        sc.close();
    }
}
```

### Métodos de `Scanner`

| Método | Lee… |
|---|---|
| `sc.nextInt()` | un entero (`int`) |
| `sc.nextLong()` | un `long` |
| `sc.nextDouble()` | un `double` |
| `sc.nextBoolean()` | un `boolean` |
| `sc.next()` | **una palabra** (hasta el primer espacio) |
| `sc.nextLine()` | **una línea completa** (con espacios) |

```java
System.out.print("Nombre (una palabra): ");
String palabra = sc.next();

System.out.print("Frase completa: ");
String frase = sc.nextLine();
```

## El problema clásico: `nextLine` después de `nextInt`

`nextInt()` (y `nextDouble()`, etc.) lee el número pero **deja el Enter (`\n`) pendiente** en el
buffer. Si justo después llamas a `nextLine()`, esta captura ese `\n` vacío en vez de lo que
esperabas:

```java
int edad = sc.nextInt();
String nombre = sc.nextLine();   // ¡captura el '\n' pendiente, queda vacio!
```

**Solución:** consumir esa línea pendiente con un `nextLine()` extra antes de leer el texto:

```java
int edad = sc.nextInt();
sc.nextLine();                   // consume el '\n' que quedo
String nombre = sc.nextLine();   // ahora si lee el nombre
```
Es el equivalente Java del truco del `" %c"` de C. Recuérdalo: **tras leer números, si luego lees
una línea, consume el salto pendiente**.

## Leer varios valores

```java
System.out.print("Dos enteros: ");
int a = sc.nextInt();
int b = sc.nextInt();
System.out.println("Suma: " + (a + b));
```
`nextInt` salta automáticamente los espacios/saltos previos, así que el usuario puede separar los
números con espacios o Enter.

## Ejemplo completo

```java
import java.util.Scanner;

public class Sueldo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Sueldo por hora: ");
        double porHora = sc.nextDouble();

        System.out.print("Horas trabajadas: ");
        int horas = sc.nextInt();

        System.out.printf("Total: %.2f%n", porHora * horas);
        sc.close();
    }
}
```

## Errores típicos

- **Olvidar `import java.util.Scanner;`**.
- El **`\n` pendiente** al mezclar `nextInt`/`nextDouble` con `nextLine` (usa un `nextLine()`
  extra).
- **`InputMismatchException`:** leer con `nextInt()` cuando el usuario escribe texto no numérico.
- Olvidar `%n`/`\n` en `printf` (no salta solo).

## Resumen

- Salida: `println` (salta), `print` (no salta), `printf` (formato con `%d`, `%.2f`, `%s`, `%n`).
- Entrada: `Scanner sc = new Scanner(System.in);` y `sc.nextInt()`, `nextDouble()`, `next()`,
  `nextLine()`; cierra con `sc.close()`.
- Tras leer un número, consume el salto pendiente con un `nextLine()` extra antes de leer una línea.

## Ejemplos

- [`ejemplos/LeerEntero.java`](ejemplos/LeerEntero.java)
- [`ejemplos/FormatoPrintf.java`](ejemplos/FormatoPrintf.java)
- [`ejemplos/LeerLinea.java`](ejemplos/LeerLinea.java)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **The Java Tutorials (Oracle)**, "Basic I/O" → Scanning.
  https://docs.oracle.com/javase/tutorial/essential/io/scanning.html
- **Baeldung**, "Java Scanner". https://www.baeldung.com/java-scanner
