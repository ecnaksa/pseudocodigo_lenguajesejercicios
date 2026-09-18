# Nivel Básico Aplicado (electrónica) — 20 problemas

Set de 20 problemas ("Nivel Básico" en 5 bloques) que aplican los patrones de arreglos a
contextos de electrónica e instrumentación (ADC, banco solar, PLC, osciloscopio, buffers FIFO,
telemetría…). Para cada problema hay **pseudocódigo híbrido**, **teoría** y **solución en C, C++
y Java**. El Problema 20 es conceptual (exposición), sin código.

## Contenido

```
nivel_basico/
├── pseudocodigo/     bloque_1.md … bloque_5.md   (los 20 problemas, con notas)
├── teoria/           conceptos nuevos de este set (double, indice vs valor, bool/rango,
│                     flanco, FIFO/espejo, producto punto, contexto ADC)
└── soluciones/
    ├── c/     problema01.c … problema19.c
    ├── cpp/   problema01.cpp … problema19.cpp
    └── java/  Problema01.java … Problema19.java
```

## Los 20 problemas

| # | Bloque | Problema | Firma / tarea |
|---|--------|----------|---------------|
| 1 | 1 Mediciones y contadores | Suma de Muestras de Corriente ADC | `double sumaCorrientes(double[], int)` |
| 2 | 1 | Voltaje Mínimo en Banco Solar | `double buscaMinimo(double[], int)` |
| 3 | 1 | Detección de Transitorios Impares | `int cuentaImpares(int[], int)` — índices impares |
| 4 | 1 | Código de Error en Buffer | `int buscaElemento(int[], int x, int)` |
| 5 | 2 Filtrado y estadísticas | Consumo Exclusivo de Cargas Pares | `double sumaPares(double[], int)` — índices pares |
| 6 | 2 | Frecuencia de Falla en PLC | `int cuentaRepeticiones(int[], int x, int)` |
| 7 | 2 | Clasificador de Polaridad AC | 10 lecturas: ceros/positivos/negativos + sumas |
| 8 | 2 | Umbral de Disipación Térmica Media | 5 temperaturas: media y cuántas la superan |
| 9 | 3 Operaciones de vectores | Superposición Lineal (A + B) | `C[i] = A[i] + B[i]` |
| 10 | 3 | Multiplicación Cruzada Inversa | `C[i] = A[i] * B[tam-1-i]` |
| 11 | 3 | Detección de Pico Máximo | máximo y su posición (15 muestras) |
| 12 | 3 | Verificación de Rango Seguro | `bool enRango(double[], int)` — `[3.3, 5.0]` |
| 13 | 4 Análisis secuencial | Potencia Aparente Promedio | `double potenciaPromedio(double[] V, double[] I, int)` |
| 14 | 4 | Ordenamiento por Intercambio | burbuja, 8 valores |
| 15 | 4 | Conteo de Muestras Saturadas | `int cuentaSaturadas(int[], int)` — `== 1023` |
| 16 | 4 | Primer Flanco de Subida | `int buscaFlanco(double[], int)` — `<0` y `>=0` |
| 17 | 5 Cierre | Desplazamiento de Buffer FIFO | shift a la derecha + nueva lectura |
| 18 | 5 | Comparación de Dos Canales | `bool sonIguales(int[] A, int[] B, int)` |
| 19 | 5 | Inversión Espejo de Primera Mitad | `Arr[n-1-i] = Arr[i]` |
| 20 | 5 | Exposición y Defensa Básica | síntesis conceptual (sin código) |

## Compilar y ejecutar

```bash
# C
gcc -std=c11 -Wall soluciones/c/problema01.c -o p01 && ./p01
# C++
g++ -std=c++17 -Wall soluciones/cpp/problema01.cpp -o p01 && ./p01
# Java (la clase se llama igual que el archivo)
javac soluciones/java/Problema01.java -d . && java Problema01
```

### Probar sin teclear

```bash
# P2 minimo (4 celdas): tamano y luego 4 voltajes
printf "4\n12.1\n11.8\n9.9\n13.0\n" | ./p02     # -> 9.90 V

# P17 FIFO (buffer 3 elementos + nueva lectura 9)
printf "3\n1\n2\n3\n9\n" | ./p17                # -> 9.00 1.00 2.00

# P19 espejo (n=5)
printf "5\n1\n2\n3\n4\n5\n" | ./p19             # -> 1.00 2.00 3.00 2.00 1.00
```

> Tamaño fijo: P7=10, P8=5, P9=5, P10=10, P11=15, P12=10, P14=8 (no piden el tamaño).
> El resto lee primero el tamaño.

## Notas de tipos

- **`double`** para magnitudes físicas (corriente, voltaje, temperatura, potencia): P1, P2, P5,
  P7–P14, P16, P17, P19. En C se lee con `%lf`.
- **`int`** para valores discretos (códigos de error, cuentas de ADC, telemetría): P3, P4, P6,
  P15, P18.
- La teoría de cada concepto nuevo está en [`teoria/`](teoria); los fundamentos generales, en
  la teoría del primer set: [`../../teoria`](../../teoria).
