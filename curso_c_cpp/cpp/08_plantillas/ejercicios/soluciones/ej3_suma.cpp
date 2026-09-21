/* Ejercicio 3 - sumaArreglo generico. */
#include <iostream>
using namespace std;

template <typename T>
T sumaArreglo(T arr[], int n) {
    T total = T();               // valor "cero" del tipo (0, 0.0, "", ...)
    for (int i = 0; i < n; i++) total += arr[i];
    return total;
}

int main() {
    int ai[] = {1, 2, 3, 4};
    double ad[] = {1.5, 2.5, 3.0};
    cout << "int:    " << sumaArreglo(ai, 4) << endl;   // 10
    cout << "double: " << sumaArreglo(ad, 3) << endl;   // 7
    return 0;
}
