/* Ejercicio 2 - Dinero en centavos con +, < y << formateado. */
#include <iostream>
#include <iomanip>
using namespace std;

class Dinero {
    long centavos;
public:
    Dinero(long c = 0) : centavos(c) {}
    Dinero operator+(const Dinero &o) const { return Dinero(centavos + o.centavos); }
    bool operator<(const Dinero &o) const { return centavos < o.centavos; }
    friend ostream& operator<<(ostream &os, const Dinero &d);
};

ostream& operator<<(ostream &os, const Dinero &d) {
    os << "$" << d.centavos / 100 << "." << setw(2) << setfill('0') << d.centavos % 100;
    return os;
}

int main() {
    Dinero a(1050);   // $10.50
    Dinero b(375);    // $3.75
    cout << a << " + " << b << " = " << (a + b) << endl;    // $14.25
    cout << "b < a: " << (b < a ? "si" : "no") << endl;     // si
    return 0;
}
