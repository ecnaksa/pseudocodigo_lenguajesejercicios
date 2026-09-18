/*
 * Ejercicio 08 - Nivel Intermedio
 * Almacenar 5 numeros, calcular su promedio, determinar cuantos son mayores
 * que el promedio y desplegar esos valores.
 */
#include <iostream>
#include <iomanip>   /* setprecision / fixed para controlar los decimales. */
using namespace std;

void promedioMayores(int arr[], int tam) {
    int suma = 0;
    for (int i = 0; i < tam; i++) {
        suma = suma + arr[i];
    }

    /* static_cast<double> fuerza la division real (con decimales). */
    double promedio = static_cast<double>(suma) / tam;
    cout << fixed << setprecision(2);
    cout << "Promedio: " << promedio << endl;

    int mayores = 0;
    cout << "Valores mayores al promedio:" << endl;
    for (int i = 0; i < tam; i++) {
        if (arr[i] > promedio) {
            mayores = mayores + 1;
            cout << arr[i] << endl;
        }
    }
    cout << "Cantidad de elementos mayores al promedio: " << mayores << endl;
}

int main() {
    int tam = 5;
    int* arr = new int[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Ingrese el elemento " << i << ": ";
        cin >> arr[i];
    }
    promedioMayores(arr, tam);

    delete[] arr;
    return 0;
}
