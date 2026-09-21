/* Ejercicio 3 - minmax con referencias (mas limpio que con punteros). */
#include <iostream>
using namespace std;

void minmax(int arr[], int n, int &min, int &max) {
    min = arr[0];
    max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
}

int main() {
    int a[6] = {23, 8, 45, 12, 4, 30};
    int menor, mayor;
    minmax(a, 6, menor, mayor);          // sin & en la llamada
    cout << "min=" << menor << ", max=" << mayor << endl;
    return 0;
}
