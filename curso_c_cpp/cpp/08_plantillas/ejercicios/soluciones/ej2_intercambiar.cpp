/* Ejercicio 2 - intercambiar generico (por referencia). */
#include <iostream>
#include <string>
using namespace std;

template <typename T>
void intercambiar(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 1, y = 2;
    intercambiar(x, y);
    cout << x << " " << y << endl;      // 2 1

    string s = "hola", t = "mundo";
    intercambiar(s, t);
    cout << s << " " << t << endl;      // mundo hola
    return 0;
}
