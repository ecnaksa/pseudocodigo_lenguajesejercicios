/*
 * Problema 37 - Calculo del Producto Punto de Vectores
 * double productoPunto(double A[], double B[], int n)  -> escalar = suma de A[i]*B[i].
 */
#include <iostream>
#include <iomanip>
using namespace std;

double productoPunto(double A[], double B[], int n) {
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        suma = suma + A[i] * B[i];
    }
    return suma;
}

int main() {
    int n;
    cout << "Ingrese el tamano de los vectores: ";
    cin >> n;

    double* A = new double[n];
    double* B = new double[n];
    for (int i = 0; i < n; i++) {
        cout << "A[" << i << "]: ";
        cin >> A[i];
        cout << "B[" << i << "]: ";
        cin >> B[i];
    }

    cout << fixed << setprecision(2);
    cout << "Producto punto A . B = " << productoPunto(A, B, n) << endl;

    delete[] A;
    delete[] B;
    return 0;
}
