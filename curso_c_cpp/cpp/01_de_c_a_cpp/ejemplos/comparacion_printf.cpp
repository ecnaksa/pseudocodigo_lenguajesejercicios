/*
 * Comparacion: la misma salida con printf (estilo C) y con cout (estilo C++).
 * Ambos funcionan en C++, pero lo idiomatico es cout.
 */
#include <iostream>   // cout
#include <cstdio>     // printf (version C++ de stdio.h)
using namespace std;

int main() {
    int x = 7;
    double y = 3.5;

    // Estilo C:
    printf("Estilo C:   x=%d, y=%.2f\n", x, y);

    // Estilo C++:
    cout << "Estilo C++: x=" << x << ", y=" << y << endl;
    return 0;
}
