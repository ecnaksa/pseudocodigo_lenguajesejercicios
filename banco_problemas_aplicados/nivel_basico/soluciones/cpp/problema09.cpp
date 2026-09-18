/*
 * Problema 09 - Superposicion Lineal de Dos Canales (A + B)
 * C[i] = A[i] + B[i]  (vectores de 5)
 */
#include <iostream>
#include <iomanip>
using namespace std;

void superpone(double A[], double B[], double C[], int tam) {
    for (int i = 0; i < tam; i++) {
        C[i] = A[i] + B[i];
    }
    cout << fixed << setprecision(2);
    cout << "Vector resultante C (A + B):" << endl;
    for (int i = 0; i < tam; i++) {
        cout << "C[" << i << "] = " << C[i] << endl;
    }
}

int main() {
    int tam = 5;
    double* A = new double[tam];
    double* B = new double[tam];
    double* C = new double[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Canal A, muestra " << i << ": ";
        cin >> A[i];
        cout << "Canal B, muestra " << i << ": ";
        cin >> B[i];
    }
    superpone(A, B, C, tam);

    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}
