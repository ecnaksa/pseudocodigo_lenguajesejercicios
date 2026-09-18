/*
 * Problema 35 - Remocion de Valores Anomalos (Outliers)
 * Reemplaza por la media local (vecinos) las lecturas que excedan 2 desviaciones estandar.
 */
#include <iostream>
#include <iomanip>
#include <cmath>          // sqrt, fabs
using namespace std;

void removeOutliers(double arr[], int n, double res[]) {
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        suma = suma + arr[i];
    }
    double media = suma / n;

    double sumaCuad = 0.0;
    for (int i = 0; i < n; i++) {
        sumaCuad = sumaCuad + (arr[i] - media) * (arr[i] - media);
    }
    double desv = sqrt(sumaCuad / n);

    for (int i = 0; i < n; i++) {
        if (fabs(arr[i] - media) > 2.0 * desv) {
            if (i == 0) {
                res[i] = arr[i + 1];
            } else if (i == n - 1) {
                res[i] = arr[i - 1];
            } else {
                res[i] = (arr[i - 1] + arr[i + 1]) / 2.0;
            }
        } else {
            res[i] = arr[i];
        }
    }
}

int main() {
    int n;
    cout << "Ingrese el numero de lecturas: ";
    cin >> n;

    double* arr = new double[n];
    double* res = new double[n];
    for (int i = 0; i < n; i++) {
        cout << "Lectura " << i << ": ";
        cin >> arr[i];
    }

    removeOutliers(arr, n, res);

    cout << fixed << setprecision(2);
    cout << "Vector depurado: ";
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] res;
    return 0;
}
