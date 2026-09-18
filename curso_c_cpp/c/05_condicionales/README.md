# Lección 05 — Condicionales (tomar decisiones)

Un programa interesante **toma decisiones**: hace una cosa u otra según las condiciones. Para eso
están `if`, `else` y `switch`.

## `if`

Ejecuta un bloque **solo si** una condición es verdadera:

```c
int edad = 20;
if (edad >= 18) {
    printf("Eres mayor de edad\n");
}
```

- La **condición** va entre paréntesis. Recuerda: en C, cualquier valor **distinto de 0** es
  verdadero.
- El **bloque** entre `{ }` se ejecuta si la condición se cumple.
- Si el bloque es de **una sola** instrucción, las llaves son opcionales... pero **ponlas
  siempre**: evita errores y es más claro.

## `if` / `else`

`else` es el "en caso contrario":

```c
if (edad >= 18) {
    printf("Mayor de edad\n");
} else {
    printf("Menor de edad\n");
}
```

## `else if` (varios caminos)

Para más de dos casos, se encadenan:

```c
int nota = 75;
if (nota >= 90) {
    printf("Excelente\n");
} else if (nota >= 70) {
    printf("Aprobado\n");
} else if (nota >= 60) {
    printf("Regular\n");
} else {
    printf("Reprobado\n");
}
```

Se evalúan **en orden**; en cuanto una condición es verdadera, se ejecuta su bloque y **se
ignoran las demás**. El `else` final atrapa "todo lo demás".

## El error del `=` vs `==`

Dentro de un `if`, para **comparar** se usa `==`. Escribir `=` **asigna** y casi siempre es un bug:

```c
if (x = 5) { ... }    // MAL: asigna 5 a x, condicion siempre verdadera
if (x == 5) { ... }   // BIEN: compara
```
Compilar con `-Wall` te avisa de este error tan común.

## Condiciones compuestas

Usa `&&`, `||`, `!` (lección 04) para combinar:

```c
if (edad >= 18 && tieneLicencia) {
    printf("Puede conducir\n");
}
if (dia == 6 || dia == 7) {
    printf("Es fin de semana\n");
}
```

## El operador ternario `?:`

Un atajo para un `if/else` que **elige entre dos valores**:

```c
int a = 8, b = 5;
int mayor = (a > b) ? a : b;    // si a>b, mayor=a; si no, mayor=b
printf("El mayor es %d\n", mayor);
```
Se lee: `condicion ? valor_si_verdadero : valor_si_falso`. Úsalo para casos cortos; para lógica
compleja, un `if/else` normal es más legible.

## `switch` (elegir entre valores constantes)

Cuando comparas **una variable** contra **varios valores constantes**, `switch` es más claro que
muchos `else if`:

```c
int opcion = 2;
switch (opcion) {
    case 1:
        printf("Iniciar\n");
        break;
    case 2:
        printf("Cargar\n");
        break;
    case 3:
        printf("Salir\n");
        break;
    default:
        printf("Opcion invalida\n");
}
```

Puntos clave del `switch`:

- Compara `opcion` con cada `case` (que debe ser una **constante entera** o un `char`).
- **`break`** sale del `switch`. **Si lo olvidas**, la ejecución "cae" (*fallthrough*) al
  siguiente `case` y sigue ejecutando: un error muy común.
- **`default`** es el caso "ninguno de los anteriores" (opcional pero recomendable).
- El *fallthrough* a veces se usa a propósito para **agrupar** casos:

```c
switch (letra) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        printf("Es vocal\n");
        break;
    default:
        printf("Es consonante\n");
}
```

`switch` no sirve para rangos (`nota >= 90`) ni para `double`; para eso, usa `if/else if`.

## Anidamiento

Puedes poner un `if` dentro de otro. Con `-Wall` y buena indentación se mantiene legible, pero si
anidas mucho, considera combinar condiciones con `&&` o usar `else if`.

## Errores típicos

- `=` en vez de `==`.
- Olvidar `break` en un `switch`.
- Poner `;` justo tras el `if`: `if (x > 0);` — ese `;` es un bloque **vacío**, y el bloque
  siguiente se ejecuta siempre.
- Comparar `double` con `==` (por errores de redondeo; mejor comparar diferencias pequeñas).

## Resumen

- `if` / `else` / `else if` para decisiones; condiciones con `&& || !`.
- `==` compara, `=` asigna (¡no los confundas!).
- Ternario `cond ? a : b` para elegir un valor corto.
- `switch/case/break/default` para comparar contra constantes; cuidado con el *fallthrough*.

## Ejemplos

- [`ejemplos/par_impar.c`](ejemplos/par_impar.c)
- [`ejemplos/calificacion.c`](ejemplos/calificacion.c)
- [`ejemplos/menu_switch.c`](ejemplos/menu_switch.c)

## Ejercicios

En [`ejercicios/`](ejercicios/).

## Para profundizar

- **K&R**, cap. 3 ("Control Flow").
- **King**, cap. 5 ("Selection Statements").
- **cppreference**, "if" y "switch". https://en.cppreference.com/w/c/language/if
