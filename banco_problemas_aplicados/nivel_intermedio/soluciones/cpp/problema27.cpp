/*
 * Problema 27 - Calculo de Derivada Discreta de Senal
 * dv[i] = v[i+1] - v[i]  (el resultado tiene n-1 elementos).
 */
#include <iostream>
#include <iomanip>
using namespace std;

void derivada(double v[], int n, double dv[]) {
    for (int i = 0; i < n - 1; i++) {
        dv[i] = v[i + 1] - v[i];
    }
}

int main() {
    int n;
    cout << "Ingrese el numero de voltajes: ";
    cin >> n;

    double* v = new double[n];
    for (int i = 0; i < n; i++) {
        cout << "v[" << i << "]: ";
        cin >> v[i];
    }

    if (n < 2) {
        cout << "Se necesitan al menos 2 muestras para la derivada." << endl;
        delete[] v;
        return 0;
    }

    double* dv = new double[n - 1];
    derivada(v, n, dv);

    cout << fixed << setprecision(2);
    cout << "Derivada discreta (delta v): ";
    for (int i = 0; i < n - 1; i++) {
        cout << dv[i] << " ";
    }
    cout << endl;

    delete[] v;
    delete[] dv;
    return 0;
}
