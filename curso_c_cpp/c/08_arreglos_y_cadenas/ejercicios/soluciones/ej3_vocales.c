/* Ejercicio 3 - Contar vocales de una palabra. */
#include <stdio.h>

int main(void) {
    char palabra[100];
    printf("Palabra: ");
    scanf("%99s", palabra);

    int vocales = 0;
    for (int i = 0; palabra[i] != '\0'; i++) {   // recorrer hasta el nulo
        char c = palabra[i];
        if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
            c=='A'||c=='E'||c=='I'||c=='O'||c=='U') {
            vocales++;
        }
    }
    printf("Vocales: %d\n", vocales);
    return 0;
}
