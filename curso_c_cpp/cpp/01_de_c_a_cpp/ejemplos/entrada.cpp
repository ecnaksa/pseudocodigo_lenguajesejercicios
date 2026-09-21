/*
 * Entrada con cin (sin & ni especificadores) y salida encadenada con cout.
 * Prueba: printf "25\n" | ./prog
 */
#include <iostream>
using namespace std;

int main() {
    int edad;
    cout << "Tu edad: ";
    cin >> edad;                       // sin & ; cin deduce el tipo

    cout << "El proximo anio tendras " << edad + 1 << " anios." << endl;

    bool mayor = (edad >= 18);         // bool nativo
    cout << "Mayor de edad: " << (mayor ? "si" : "no") << endl;
    return 0;
}
