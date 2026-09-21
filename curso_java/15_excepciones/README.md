# Lección 15 — Manejo de excepciones

¿Qué pasa cuando algo **sale mal** en ejecución? Dividir entre cero, un índice fuera de rango, leer
texto donde se esperaba un número, un archivo que no existe... Java usa **excepciones**: objetos que
representan errores y que puedes **atrapar** y **manejar** en vez de que el programa simplemente
"reviente".

## `try` / `catch`

- **`try`** envuelve el código que **podría** fallar.
- **`catch`** atrapa la excepción y la maneja.

```java
try {
    int[] a = {1, 2, 3};
    System.out.println(a[10]);      // lanza ArrayIndexOutOfBoundsException
} catch (ArrayIndexOutOfBoundsException e) {
    System.out.println("Indice invalido: " + e.getMessage());
}
System.out.println("El programa continua");
```

Cuando ocurre el error, la ejecución **salta** del `try` al `catch` correspondiente; el programa
**no** se cae, y sigue después del bloque.

`e.getMessage()` devuelve el mensaje del error. `e.printStackTrace()` imprime toda la traza (útil
para depurar).

## Jerarquía de excepciones

Todas las excepciones heredan de la clase **`Throwable`**. Lo importante para ti:

- **`Exception`** y sus subclases: los errores "normales" que puedes manejar.
  - **Unchecked** (`RuntimeException` y derivadas): errores de programación en ejecución
    (`NullPointerException`, `ArrayIndexOutOfBoundsException`, `ArithmeticException`...). **No**
    obligan a manejarlas.
  - **Checked** (el resto de `Exception`): errores previsibles que el compilador **te obliga** a
    manejar o declarar (`IOException`, `FileNotFoundException`...).
- **`Error`**: fallos graves de la JVM (`OutOfMemoryError`); normalmente no se manejan.

## Checked vs unchecked (una diferencia propia de Java)

- **Unchecked** (`RuntimeException`): el compilador **no** te obliga a nada. Suelen indicar **bugs**
  (accediste fuera de rango, usaste un `null`). Lo ideal es **prevenirlas**, no atraparlas.
- **Checked**: el compilador **exige** que las manejes con `try/catch` **o** las declares en el
  método con **`throws`**. Representan situaciones externas previsibles (E/S, red...).

```java
// Un metodo que puede lanzar una checked debe declararlo con throws:
static void leerArchivo(String ruta) throws java.io.IOException {
    // ... codigo que puede lanzar IOException ...
}
```

## Varios `catch` y `finally`

Puedes tener varios `catch`, del más específico al más general. `catch (Exception e)` atrapa
cualquier excepción "normal". El bloque **`finally`** se ejecuta **siempre** (haya error o no), ideal
para liberar recursos:

```java
try {
    int r = 10 / 0;             // ArithmeticException
} catch (ArithmeticException e) {
    System.out.println("No se puede dividir entre cero");
} catch (Exception e) {         // cualquier otra
    System.out.println("Otro error: " + e.getMessage());
} finally {
    System.out.println("Esto se ejecuta siempre");
}
```

## Lanzar excepciones: `throw`

Puedes **lanzar** una excepción cuando detectas un problema, con `throw`:

```java
static double raizSegura(double x) {
    if (x < 0) {
        throw new IllegalArgumentException("no existe raiz real de un negativo");
    }
    return Math.sqrt(x);
}
```
`IllegalArgumentException` es unchecked, así que no obliga a declararla. Quien llame al método puede
atraparla si quiere.

## Excepciones estándar comunes

| Excepción | Cuándo aparece |
|---|---|
| `NullPointerException` | usar un objeto que es `null` |
| `ArrayIndexOutOfBoundsException` | índice fuera de rango en un arreglo |
| `ArithmeticException` | división entera entre cero |
| `NumberFormatException` | convertir texto no numérico (`Integer.parseInt("abc")`) |
| `IllegalArgumentException` | un argumento inválido |
| `InputMismatchException` | `Scanner.nextInt()` con entrada no numérica |

## Crear tu propia excepción

Basta con heredar de `Exception` (checked) o `RuntimeException` (unchecked):

```java
class SaldoInsuficienteException extends RuntimeException {
    public SaldoInsuficienteException(String mensaje) {
        super(mensaje);
    }
}
// ...
throw new SaldoInsuficienteException("saldo insuficiente");
```

## `try-with-resources` (breve)

Para recursos que hay que cerrar (archivos, `Scanner`), Java tiene una forma que los **cierra
solos**:

```java
try (Scanner sc = new Scanner(System.in)) {
    int n = sc.nextInt();
    // ...
}   // sc.close() se llama automaticamente al salir
```

## ¿Cuándo usar excepciones?

- **Sí:** para errores **excepcionales** que impiden continuar normalmente.
- **No** para el **flujo normal** (que el usuario elija "salir" no es una excepción; usa un `if`).

## Errores típicos

- Atrapar `Exception` de forma demasiado general y **ocultar** errores (mejor específico).
- Un `catch` **vacío** que se traga el error sin hacer nada (dificulta depurar).
- No manejar ni declarar una **checked** → no compila.
- Usar excepciones como control de flujo normal.

## Resumen

- `try` envuelve el código riesgoso; `catch` maneja; `finally` se ejecuta siempre.
- **Checked** (el compilador obliga a manejar/declarar con `throws`) vs **unchecked**
  (`RuntimeException`, no obliga).
- `throw new ...Exception("mensaje")` lanza; `e.getMessage()` da el mensaje.
- Puedes crear tus excepciones heredando de `Exception`/`RuntimeException`.
- `try-with-resources` cierra recursos automáticamente. Usa excepciones para lo **excepcional**.

## Ejemplos

- [`ejemplos/Dividir.java`](ejemplos/Dividir.java)
- [`ejemplos/ConFinally.java`](ejemplos/ConFinally.java)
- [`ejemplos/ExcepcionPropia.java`](ejemplos/ExcepcionPropia.java)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **The Java Tutorials (Oracle)**, "Exceptions".
  https://docs.oracle.com/javase/tutorial/essential/exceptions/
- **Baeldung**, "Exception Handling in Java". https://www.baeldung.com/java-exceptions
