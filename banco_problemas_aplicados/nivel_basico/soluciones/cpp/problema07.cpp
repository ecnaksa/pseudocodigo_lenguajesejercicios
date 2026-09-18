/*
 * Problema 07 - Clasificador de Polaridad AC
 * 10 lecturas: contar ceros/positivos/negativos y sumar positivos y negativos.
 */
#include <iostream>
#include <iomanip>
using namespace std;

void clasificaPolaridad(double arr[], int tam) {
    int ceros = 0, pos = 0, neg = 0;
    double spos = 0.0, sneg = 0.0;
    for (int i = 0; i < tam; i++) {
        if (arr[i] == 0.0) {
            ceros = ceros + 1;
        } else if (arr[i] > 0.0) {
            pos = pos + 1;
            spos = spos + arr[i];
        } else {
            neg = neg + 1;
            sneg = sneg + arr[i];
        }
    }
    cout << fixed << setprecision(2);
    cout << "Ceros exactos: " << ceros << endl;
    cout << "Positivos: " << pos << "  (suma = " << spos << ")" << endl;
    cout << "Negativos: " << neg << "  (suma = " << sneg << ")" << endl;
}

int main() {
    int tam = 10;
    double* arr = new double[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Lectura de tension " << i << " (V): ";
        cin >> arr[i];
    }
    clasificaPolaridad(arr, tam);

    delete[] arr;
    return 0;
}
