# Ejercicios — Lección 12

1. **Guardar una lista.** Escribe en un archivo `numeros.txt` los números del 1 al 10, uno por
   línea. → [`soluciones/ej1_guardar.c`](soluciones/ej1_guardar.c)

2. **Sumar desde archivo.** Lee `numeros.txt` (del ejercicio 1) y muestra la suma de todos los
   números. → [`soluciones/ej2_sumar.c`](soluciones/ej2_sumar.c)

3. **Contar líneas.** Lee un archivo (por ejemplo `numeros.txt`) y cuenta cuántas líneas tiene con
   `fgets`. → [`soluciones/ej3_contar_lineas.c`](soluciones/ej3_contar_lineas.c)

4. **Registro (append).** Abre `registro.txt` en modo `"a"` y añade una línea; ejecútalo varias
   veces y observa que no se borra lo anterior.
   → [`soluciones/ej4_registro.c`](soluciones/ej4_registro.c)

5. **Reto — mayúsculas a archivo.** Lee `numeros.txt` carácter a carácter con `fgetc` y escribe en
   `salida.txt` cada carácter, pero convirtiendo letras minúsculas a mayúsculas (pista:
   `<ctype.h>` tiene `toupper`). → [`soluciones/ej5_mayusculas.c`](soluciones/ej5_mayusculas.c)

> Ejecuta cada programa desde una carpeta donde tengas permiso de escritura.
