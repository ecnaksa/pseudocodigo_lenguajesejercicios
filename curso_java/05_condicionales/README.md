# Lección 05 — Condicionales (tomar decisiones)

Para que un programa **decida** entre caminos según las condiciones, Java usa `if`, `else` y
`switch`. La condición siempre debe ser de tipo **`boolean`**.

## `if` / `else` / `else if`

```java
int edad = 20;
if (edad >= 18) {
    System.out.println("Mayor de edad");
} else {
    System.out.println("Menor de edad");
}
```

Para más casos, se encadenan con `else if`:

```java
int nota = 75;
if (nota >= 90) {
    System.out.println("Excelente");
} else if (nota >= 70) {
    System.out.println("Aprobado");
} else {
    System.out.println("Reprobado");
}
```
Se evalúan **en orden**; en cuanto una condición es verdadera, se ejecuta su bloque y se ignoran
las demás.

> **La condición debe ser `boolean`.** `if (x)` con `x` entero **no compila** en Java (a diferencia
> de C). Esto evita el clásico error de escribir `=` (asignar) en vez de `==` (comparar).

## Condiciones compuestas

```java
if (edad >= 18 && tieneLicencia) {
    System.out.println("Puede conducir");
}
if (dia == 6 || dia == 7) {
    System.out.println("Fin de semana");
}
```

## Recordatorio: comparar objetos con `.equals()`

Con `String` u otros objetos, usa `.equals()` para comparar el **contenido**, no `==`:

```java
String respuesta = sc.next();
if (respuesta.equals("si")) {   // correcto
    System.out.println("Confirmado");
}
```

## El operador ternario `?:`

Atajo para elegir entre dos valores:

```java
int a = 8, b = 5;
int mayor = (a > b) ? a : b;    // si a>b, mayor=a; si no, mayor=b
```
Se lee `condicion ? valorSiVerdadero : valorSiFalso`. Úsalo para casos cortos.

## `switch` clásico

Cuando comparas **una variable** contra **varios valores constantes**, `switch` es más claro que
muchos `else if`:

```java
int opcion = 2;
switch (opcion) {
    case 1:
        System.out.println("Iniciar");
        break;
    case 2:
        System.out.println("Cargar");
        break;
    case 3:
        System.out.println("Salir");
        break;
    default:
        System.out.println("Opcion invalida");
}
```

- **`break`** sale del `switch`. **Si lo olvidas**, la ejecución "cae" al siguiente `case`
  (*fallthrough*): un error muy común.
- **`default`** es el caso "ninguno de los anteriores".
- El `switch` clásico funciona con `int`, `char`, `String` y `enum`, entre otros. (¡Sí, en Java
  el `switch` acepta `String`!)

```java
String dia = "lunes";
switch (dia) {
    case "sabado":
    case "domingo":
        System.out.println("Fin de semana");
        break;
    default:
        System.out.println("Dia laboral");
}
```

## `switch` de expresión (Java 14+, moderno)

Java moderno tiene una forma más segura y concisa de `switch`, que **devuelve un valor** y usa
`->` (sin `break`, sin *fallthrough*):

```java
int dia = 3;
String nombre = switch (dia) {
    case 1 -> "Lunes";
    case 2 -> "Martes";
    case 3 -> "Miercoles";
    default -> "Otro";
};
System.out.println(nombre);   // Miercoles
```

- Cada rama usa `->`; **no** hay caída entre casos (no necesitas `break`).
- Puede **producir un valor** (aquí, asignado a `nombre`).
- Es más seguro (el compilador te avisa si faltan casos con `enum`) y más legible. **Recomendado**
  cuando tu Java lo soporte (17+ lo tiene de sobra).

## Errores típicos

- Olvidar `break` en un `switch` clásico.
- Comparar `String` con `==` en vez de `.equals()`.
- Poner `;` justo tras el `if`: `if (x > 0);` deja un bloque vacío.
- Esperar que `if (numero)` compile (la condición debe ser `boolean`).

## Resumen

- `if` / `else` / `else if` para decidir; la condición es siempre **`boolean`**.
- Objetos (`String`) se comparan con **`.equals()`**.
- Ternario `cond ? a : b` para elegir un valor corto.
- `switch` clásico (con `break`/`default`, acepta `String`) o **`switch` de expresión** con `->`
  (moderno, devuelve valor, sin *fallthrough*).

## Ejemplos

- [`ejemplos/ParImpar.java`](ejemplos/ParImpar.java)
- [`ejemplos/Calificacion.java`](ejemplos/Calificacion.java)
- [`ejemplos/SwitchExpresion.java`](ejemplos/SwitchExpresion.java)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **The Java Tutorials (Oracle)**, "Control Flow Statements".
  https://docs.oracle.com/javase/tutorial/java/nutsandbolts/if.html
- **Baeldung**, "Switch Expressions". https://www.baeldung.com/java-switch
