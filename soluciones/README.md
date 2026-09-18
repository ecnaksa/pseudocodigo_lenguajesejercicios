# Soluciones en C, C++ y Java

Versión **correcta y compilable** de cada uno de los 15 ejercicios, en los tres lenguajes.
Cada archivo es autónomo (pide sus datos por teclado e imprime el resultado) y lleva
comentarios que explican la parte clave.

```
soluciones/
├── c/     ejercicio01.c  … ejercicio15.c     (gcc, estándar c11)
├── cpp/   ejercicio01.cpp … ejercicio15.cpp   (g++, estándar c++17)
└── java/  Ejercicio01.java … Ejercicio15.java (javac / java 8+)
```

## Correspondencia archivo ↔ ejercicio

| # | Nivel | Ejercicio | C | C++ | Java |
|---|-------|-----------|---|-----|------|
| 01 | Básico | `sumaElementos` | `ejercicio01.c` | `ejercicio01.cpp` | `Ejercicio01.java` |
| 02 | Básico | `buscaMinimo` | `ejercicio02.c` | `ejercicio02.cpp` | `Ejercicio02.java` |
| 03 | Básico | `cuentaImpares` | `ejercicio03.c` | `ejercicio03.cpp` | `Ejercicio03.java` |
| 04 | Básico | `buscaElemento` | `ejercicio04.c` | `ejercicio04.cpp` | `Ejercicio04.java` |
| 05 | Intermedio | `sumaPares` | `ejercicio05.c` | `ejercicio05.cpp` | `Ejercicio05.java` |
| 06 | Intermedio | `cuentaRepeticiones` | `ejercicio06.c` | `ejercicio06.cpp` | `Ejercicio06.java` |
| 07 | Intermedio | Análisis de 10 números | `ejercicio07.c` | `ejercicio07.cpp` | `Ejercicio07.java` |
| 08 | Intermedio | Promedio y mayores | `ejercicio08.c` | `ejercicio08.cpp` | `Ejercicio08.java` |
| 09 | Intermedio | Suma de vectores A+B | `ejercicio09.c` | `ejercicio09.cpp` | `Ejercicio09.java` |
| 10 | Intermedio | Multiplicación cruzada | `ejercicio10.c` | `ejercicio10.cpp` | `Ejercicio10.java` |
| 11 | Intermedio | Mayor de 20 (valor y posición) | `ejercicio11.c` | `ejercicio11.cpp` | `Ejercicio11.java` |
| 12 | Avanzado | `invierteArreglo` | `ejercicio12.c` | `ejercicio12.cpp` | `Ejercicio12.java` |
| 13 | Avanzado | `esPalindromo` | `ejercicio13.c` | `ejercicio13.cpp` | `Ejercicio13.java` |
| 14 | Avanzado | `ordenaBurbuja` | `ejercicio14.c` | `ejercicio14.cpp` | `Ejercicio14.java` |
| 15 | Avanzado | `eliminaDuplicados` | `ejercicio15.c` | `ejercicio15.cpp` | `Ejercicio15.java` |

## Compilar y ejecutar

```bash
# --- C ---
gcc -std=c11 -Wall c/ejercicio01.c -o ej01 && ./ej01

# --- C++ ---
g++ -std=c++17 -Wall cpp/ejercicio01.cpp -o ej01 && ./ej01

# --- Java --- (compila a la carpeta actual; la clase se llama igual que el archivo)
javac java/Ejercicio01.java -d .
java Ejercicio01
```

### Probar sin teclear (alimentando la entrada)

Los programas leen en el mismo orden en que preguntan. Ejemplos:

```bash
# Ej. 02 (mínimo): tamaño 5 y luego los 5 valores
printf "5\n4\n-2\n9\n-7\n3\n" | ./ej02
# → El valor minimo es: -7

# Ej. 14 (burbuja): tam es fijo = 5, así que van directo los 5 valores
printf "5\n1\n4\n2\n3\n" | ./ej14
# → El arreglo ordenado es: 1 2 3 4 5

# Ej. 15 (duplicados): tam fijo = 8, van 8 valores
printf "1\n2\n1\n3\n2\n4\n1\n5\n" | ./ej15
# → Arreglo sin duplicados (5 elementos): 1 2 3 4 5
```

> **Tamaño fijo vs. leído.** En los ejercicios cuyo enunciado fija la cantidad (07=10, 08=5,
> 09=5, 10=10, 11=20, 14=5, 15=8) el programa **no** pregunta el tamaño: va directo a pedir
> los elementos. En los demás, primero pide el tamaño y luego los elementos.

## Notas de diseño

- **C** usa arreglos de longitud variable (`int arr[tam];`, C99/C11) cuando el tamaño se lee
  en ejecución; es lo más cercano al `Dimension Arr[tam]` del pseudocódigo.
- **C++** usa memoria dinámica `new int[tam]` / `delete[]` para mantener el paralelo con C.
  En C++ moderno lo idiomático sería `std::vector<int>`.
- **Java** usa `int[] arr = new int[tam]` y `Scanner` para la entrada.
- Los mensajes en pantalla van sin acentos a propósito, para evitar problemas de codificación
  en distintas terminales; los comentarios y esta documentación sí llevan acentos.
