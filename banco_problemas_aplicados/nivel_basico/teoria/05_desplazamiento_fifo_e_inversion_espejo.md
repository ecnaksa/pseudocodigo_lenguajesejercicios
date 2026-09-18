# 05 · Desplazamiento FIFO e inversión espejo

Los problemas 17 (buffer FIFO) y 19 (espejo) **mueven datos dentro del arreglo**. Lo delicado
no es la fórmula, sino el **sentido del recorrido**: hacerlo al revés destruye la información.

## 1. Buffer FIFO: desplazar a la derecha (P17)

Un buffer **FIFO** (First In, First Out) guarda las últimas N lecturas. Cuando llega una nueva:
- entra por el frente (`Arr[0]`),
- todo lo demás se corre una posición a la derecha,
- la lectura más vieja (`Arr[tam-1]`) se pierde.

```
Antes:   [10][20][30][40]         nueva = 99
Después: [99][10][20][30]         (el 40 se descarta)
```

### El sentido importa: de derecha a izquierda

Cada elemento debe copiar al de su **izquierda**: `Arr[i] = Arr[i-1]`. Si recorremos **desde el
final** hacia el inicio, cada valor se copia **antes** de ser sobrescrito:

```c
void desplazaFIFO(double arr[], int tam, double nueva) {
    for (int i = tam - 1; i >= 1; i--) {   // DESDE EL FINAL hacia el inicio
        arr[i] = arr[i - 1];
    }
    arr[0] = nueva;                        // la nueva lectura entra al frente
}
```

**¿Por qué no al revés?** Si empezáramos desde `i = 1` hacia adelante:

```
i=1: arr[1] = arr[0]  ->  [10][10][30][40]   (¡el 20 se perdió!)
i=2: arr[2] = arr[1]  ->  [10][10][10][40]   (se propaga el 10)
```
Al copiar hacia adelante, sobrescribimos un valor **antes** de haberlo movido, y se "arrastra"
el mismo número por todo el arreglo. Por eso, para **desplazar a la derecha se recorre desde el
final**. (Si el desplazamiento fuera a la izquierda, sería al revés: desde el inicio.)

## 2. Inversión espejo de la primera mitad (P19)

Aquí se copia la primera mitad **reflejada** en la segunda, dejando el arreglo simétrico
(un palíndromo):

```
Antes:   [1][2][3][4][5]
Después: [1][2][3][2][1]     (la 2.ª mitad es espejo de la 1.ª; el centro no se toca)
```

La posición **espejo** de `i` es `n-1-i` (primero ↔ último, segundo ↔ penúltimo…). Se recorre
solo la **primera mitad** (`i < n/2`) copiando cada valor a su espejo:

```c
void espejoPrimeraMitad(double arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        arr[n - 1 - i] = arr[i];   // la posicion espejo recibe el valor de la primera mitad
    }
}
```

- Con `n` **par** (p. ej. 6), se copian las 3 primeras a las 3 últimas.
- Con `n` **impar** (p. ej. 5), `n/2` es `2` (división entera), así que el elemento **central**
  (índice 2) se queda como está, que es justo lo que debe pasar en un palíndromo.

> Diferencia con "invertir" (primer set): invertir **intercambia** extremos (`aux` de por
> medio) y cambia todo el arreglo; aquí solo se **copia** la primera mitad sobre la segunda,
> sin conservar los valores originales de la segunda mitad.

## 3. Regla para no corromper datos al mover

Cuando un desplazamiento **lee y escribe el mismo arreglo**, pregúntate: *"¿estoy por
sobrescribir una casilla que todavía necesito leer?"*

- Desplazar a la **derecha** (`Arr[i] = Arr[i-1]`) → recorre **de derecha a izquierda**.
- Desplazar a la **izquierda** (`Arr[i] = Arr[i+1]`) → recorre **de izquierda a derecha**.
- Intercambios independientes (como en invertir, `aux` mediante) → el sentido da igual, porque
  cada paso toca un par distinto.
