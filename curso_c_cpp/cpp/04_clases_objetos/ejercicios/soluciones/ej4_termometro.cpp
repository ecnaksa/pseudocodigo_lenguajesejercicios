/* Ejercicio 4 (reto) - Termometro con conversion. */
#include <iostream>
using namespace std;

class Termometro {
private:
    double celsius = 0;

public:
    void set(double c) { celsius = c; }
    double getCelsius() { return celsius; }
    double getFahrenheit() { return celsius * 9.0 / 5.0 + 32.0; }
};

int main() {
    Termometro t;
    t.set(25);
    cout << t.getCelsius() << " C = " << t.getFahrenheit() << " F" << endl;
    return 0;
}
