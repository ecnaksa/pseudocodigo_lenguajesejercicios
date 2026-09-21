/* Ejercicio 5 (reto) - Palindromo. */
#include <stdio.h>
#include <string.h>

int main(void) {
    char s[100];
    printf("Palabra: ");
    scanf("%99s", s);

    int largo = (int) strlen(s);
    int esPalindromo = 1;
    for (int i = 0; i < largo / 2; i++) {
        if (s[i] != s[largo - 1 - i]) {
            esPalindromo = 0;
            break;
        }
    }

    if (esPalindromo) printf("Es palindromo\n");
    else printf("No es palindromo\n");
    return 0;
}
