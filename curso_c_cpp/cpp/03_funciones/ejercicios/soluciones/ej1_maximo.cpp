/* Ejercicio 1 - maximo sobrecargado. */
#include <iostream>
using namespace std;

int maximo(int a, int b) {
    return (a > b) ? a : b;
}
double maximo(double a, double b) {
    return (a > b) ? a : b;
}

int main() {
    cout << maximo(3, 7) << endl;        // 7 (enteros)
    cout << maximo(2.5, 1.8) << endl;    // 2.5 (doubles)
    return 0;
}
