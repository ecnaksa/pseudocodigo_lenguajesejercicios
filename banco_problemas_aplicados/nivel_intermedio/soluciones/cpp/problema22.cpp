/*
 * Problema 22 - Conteo Avanzado de Codigos de Falla
 * int contarFalla(int Arr[], int tam, int codigo)
 */
#include <iostream>
using namespace std;

int contarFalla(int arr[], int tam, int codigo) {
    int contador = 0;
    for (int i = 0; i < tam; i++) {
        if (arr[i] == codigo) {
            contador = contador + 1;
        }
    }
    return contador;
}

int main() {
    int tam, codigo;
    cout << "Ingrese el numero de fallas registradas: ";
    cin >> tam;

    int* arr = new int[tam];
    for (int i = 0; i < tam; i++) {
        cout << "Falla " << i << ": ";
        cin >> arr[i];
    }

    cout << "Ingrese el codigo a cuantificar: ";
    cin >> codigo;

    cout << "El codigo " << codigo << " aparece " << contarFalla(arr, tam, codigo) << " veces." << endl;

    delete[] arr;
    return 0;
}
