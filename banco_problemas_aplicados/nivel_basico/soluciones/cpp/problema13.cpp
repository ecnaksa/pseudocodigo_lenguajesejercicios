/*
 * Problema 13 - Calculo de Potencia Aparente Promedio
 * double potenciaPromedio(double V[], double I[], int n)  -> (suma de V[i]*I[i]) / n
 */
#include <iostream>
#include <iomanip>
using namespace std;

double potenciaPromedio(double V[], double I[], int n) {
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        suma = suma + V[i] * I[i];
    }
    return suma / n;
}

int main() {
    int n;
    cout << "Ingrese el numero de muestras: ";
    cin >> n;

    double* V = new double[n];
    double* I = new double[n];
    for (int i = 0; i < n; i++) {
        cout << "V[" << i << "] (V): ";
        cin >> V[i];
        cout << "I[" << i << "] (A): ";
        cin >> I[i];
    }

    cout << fixed << setprecision(2);
    cout << "Potencia aparente promedio: " << potenciaPromedio(V, I, n) << endl;

    delete[] V;
    delete[] I;
    return 0;
}
