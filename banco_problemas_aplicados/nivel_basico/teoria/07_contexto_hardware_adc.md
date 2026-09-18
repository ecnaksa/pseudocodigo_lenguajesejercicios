# 07 · Contexto de hardware: ADC, saturación, umbrales y polaridad

Los enunciados usan vocabulario de electrónica. No necesitas ser ingeniero para resolverlos
—son los mismos arreglos de siempre— pero entender el contexto ayuda a que los números y las
condiciones tengan sentido.

## 1. ¿Qué es un ADC? (Problemas 1, 15, 16)

Un **ADC** (Convertidor Analógico-Digital) transforma una señal continua del mundo real
(un voltaje, una corriente) en un **número entero** que el microcontrolador puede procesar.

- Un ADC de **10 bits** produce enteros de **0 a 1023** (porque 2¹⁰ = 1024 valores posibles:
  0, 1, 2, …, 1023). Por eso el Problema 15 compara contra `1023`.
- `0` representa el mínimo del rango medible y `1023` el máximo.

Ese "número de cuentas" es el que se guarda en el arreglo del Problema 15 (por eso es `int`),
mientras que cuando el valor ya está convertido a voltios/amperios reales se usa `double`
(Problemas 1, 2, 16…).

## 2. Saturación / overflow (Problema 15)

Cuando la señal real supera lo que el ADC puede medir, la conversión se queda "pegada" en el
valor máximo: **1023**. Eso es una **muestra saturada** (clipping/overflow). Contarlas
(`Arr[i] == 1023`) sirve para detectar si el sistema se está saturando y perdiendo información.

```c
if (arr[i] == 1023) contador++;   // esta muestra llego al tope: saturacion
```

## 3. Rango de operación segura (Problema 12)

Muchos circuitos solo funcionan bien dentro de una ventana de voltaje. `[3.3V, 5.0V]` son
niveles lógicos típicos (3.3V y 5V son estándares muy comunes en electrónica digital). Verificar
que **todas** las mediciones caen en ese rango es una comprobación de seguridad: si una se sale,
algo va mal. La lógica del rango (`val >= 3.3 && val <= 5.0`) está en
[`03_funciones_booleanas_validacion_rango.md`](03_funciones_booleanas_validacion_rango.md).

## 4. Polaridad y cruce por cero (Problemas 7 y 16)

Una señal **AC** (corriente alterna) oscila entre valores positivos y negativos. De ahí:

- **Clasificar polaridad (P7):** contar cuántas muestras son positivas (`> 0`), negativas
  (`< 0`) o cero exacto (`== 0`), y sumar cada grupo. Es un termómetro del balance de la señal.
- **Flanco de subida / cruce por cero (P16):** el instante en que la señal pasa de negativa a
  positiva (`Arr[i] < 0 && Arr[i+1] >= 0`). Detectar cruces por cero se usa para medir
  frecuencia, sincronizar, o disparar eventos.

## 5. FIFO de sensores (Problema 17)

Un **buffer FIFO** de lecturas de un sensor guarda las últimas N mediciones (una "ventana" de
historia reciente). Cada vez que llega una lectura nueva, entra al frente y la más antigua se
descarta. Es la base de filtros de promedio móvil, detección de tendencias, etc. La mecánica
del desplazamiento está en
[`05_desplazamiento_fifo_e_inversion_espejo.md`](05_desplazamiento_fifo_e_inversion_espejo.md).

## 6. Resumen: contexto → concepto de programación

| Palabra del enunciado | En realidad es… |
|---|---|
| ADC de 10 bits, "cuentas" | enteros de 0 a 1023 |
| muestra saturada / overflow | valor `== 1023` |
| rango de operación segura | validar `val >= 3.3 && val <= 5.0` |
| polaridad AC | signo del valor (`>0`, `<0`, `==0`) |
| flanco de subida / cruce por cero | `Arr[i] < 0 && Arr[i+1] >= 0` |
| buffer FIFO | arreglo con desplazamiento |
| potencia aparente | producto punto `V[i]*I[i]` |
| banco solar / celdas | arreglo de voltajes (`double`) |

La lección de fondo: casi cualquier problema de instrumentación se reduce a **recorrer un
arreglo** y, en cada elemento, **acumular, contar, comparar o mover**. El vocabulario cambia;
los patrones no.
