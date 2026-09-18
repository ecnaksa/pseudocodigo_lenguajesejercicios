# 04 · Entrada y salida (`Escribir` / `Leer`)

Los ejercicios usan `Escribir` para mostrar y `Leer` para pedir datos por teclado. Aquí se
ve cómo se traduce cada uno, incluyendo el `Escribir sin saltar`.

## 1. Mostrar en pantalla (`Escribir`)

Pseudocódigo:

```
Escribir "La suma es: ", total
```

### C — `printf` con *especificadores de formato*

En C hay que decirle a `printf` **qué tipo** de dato va en cada hueco:

```c
printf("La suma es: %d\n", total);
```

- `%d` → un `int`
- `%f` → un `double`/`float` (`%.2f` = 2 decimales)
- `%c` → un carácter, `%s` → una cadena
- `\n` → salto de línea

Para varios valores, varios especificadores:

```c
printf("C[%d] = %d\n", i, C[i]);
```

### C++ — `cout` con `<<`

C++ no necesita especificadores: `cout` "sabe" el tipo. Los valores se encadenan con `<<`:

```cpp
cout << "La suma es: " << total << endl;   // endl = salto de línea
```

### Java — `System.out.println` / `print`

Java concatena texto y valores con `+`:

```java
System.out.println("La suma es: " + total);   // println = imprime y salta de línea
```

## 2. El "escribir sin saltar" (Ejercicios 14 y 15)

`Escribir sin saltar` significa **imprimir sin bajar de renglón**, para que varias
impresiones queden en la **misma línea**. Es exactamente lo que hace falta al mostrar un
arreglo separado por espacios:

```
for (i = 0; i < tam; i++){
    Escribir sin saltar Arr[i], " "
}
```
Salida deseada: `1 2 3 4 5` (todo en un renglón).

La clave es: **`Escribir` normal** baja de línea al final; **`Escribir sin saltar`** no.

| | Salta de línea | NO salta (sin saltar) |
|---|---|---|
| **C** | `printf("%d\n", x);` | `printf("%d ", x);` (sin `\n`) |
| **C++** | `cout << x << endl;` | `cout << x << " ";` (sin `endl`) |
| **Java** | `System.out.println(x);` | `System.out.print(x + " ");` (`print`, no `println`) |

Y al terminar el bucle se pone **un solo** salto de línea:

```c
for (int i = 0; i < tam; i++) printf("%d ", arr[i]);
printf("\n");   // un único salto al final
```

## 3. Leer del teclado (`Leer`)

Pseudocódigo:

```
Leer tam
Leer Arr[i]
```

### C — `scanf` (¡ojo con el `&`!)

```c
scanf("%d", &tam);       // el & es la DIRECCIÓN de la variable
scanf("%d", &arr[i]);    // dónde guardar el número leído
```
`scanf` necesita **saber dónde** poner el dato, por eso se le pasa `&variable` (su dirección).
Con arreglos, `&arr[i]` es la dirección de esa casilla.

### C++ — `cin` con `>>`

```cpp
cin >> tam;
cin >> arr[i];    // aquí NO se usa &
```

### Java — `Scanner`

Primero se crea un lector una sola vez y luego se pide cada dato:

```java
import java.util.Scanner;
...
Scanner sc = new Scanner(System.in);
int tam = sc.nextInt();      // lee un entero
arr[i] = sc.nextInt();
...
sc.close();                  // se cierra al terminar
```
`nextInt()` lee un entero; existen `nextDouble()`, `nextLine()`, etc.

## 4. Números con decimales al imprimir (Ejercicio 08)

El promedio es un número real. Para mostrar 2 decimales:

```c
printf("Promedio: %.2f\n", promedio);                 // C
```
```cpp
cout << fixed << setprecision(2) << promedio << endl; // C++ (incluir <iomanip>)
```
```java
System.out.printf(Locale.US, "Promedio: %.2f%n", promedio);  // Java
```
> En Java se usa `Locale.US` para forzar el **punto** decimal; sin él, algunos sistemas
> mostrarían coma (`30,00`). `%n` es el salto de línea de `printf`.

## 5. Cuadro resumen

| Acción | Pseudocódigo | C | C++ | Java |
|---|---|---|---|---|
| Mostrar texto+valor y saltar | `Escribir "S:", x` | `printf("S:%d\n", x);` | `cout<<"S:"<<x<<endl;` | `System.out.println("S:"+x);` |
| Mostrar **sin** saltar | `Escribir sin saltar x` | `printf("%d ", x);` | `cout<<x<<" ";` | `System.out.print(x+" ");` |
| Leer entero | `Leer x` | `scanf("%d",&x);` | `cin>>x;` | `x=sc.nextInt();` |
