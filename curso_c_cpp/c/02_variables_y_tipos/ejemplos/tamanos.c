/*
 * Tamanos (sizeof) y rangos (limits.h / float.h).
 */
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
    printf("Tamanos en bytes:\n");
    printf("  char:      %zu\n", sizeof(char));
    printf("  int:       %zu\n", sizeof(int));
    printf("  long:      %zu\n", sizeof(long));
    printf("  double:    %zu\n", sizeof(double));

    printf("\nRangos de int:\n");
    printf("  INT_MIN = %d\n", INT_MIN);
    printf("  INT_MAX = %d\n", INT_MAX);

    printf("\nMayor double aproximado: %e\n", DBL_MAX);
    return 0;
}
