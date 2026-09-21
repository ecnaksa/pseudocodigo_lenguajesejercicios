/* Ejercicio 3 (reto) - Numero complejo con +, * y <<. */
#include <iostream>
using namespace std;

class Complejo {
    double re, im;
public:
    Complejo(double r = 0, double i = 0) : re(r), im(i) {}

    Complejo operator+(const Complejo &o) const {
        return Complejo(re + o.re, im + o.im);
    }
    // (a+bi)(c+di) = (ac - bd) + (ad + bc)i
    Complejo operator*(const Complejo &o) const {
        return Complejo(re * o.re - im * o.im, re * o.im + im * o.re);
    }
    friend ostream& operator<<(ostream &os, const Complejo &c);
};

ostream& operator<<(ostream &os, const Complejo &c) {
    os << c.re << " + " << c.im << "i";
    return os;
}

int main() {
    Complejo a(1, 2), b(3, 4);
    cout << "suma:     " << (a + b) << endl;   // 4 + 6i
    cout << "producto: " << (a * b) << endl;   // -5 + 10i
    return 0;
}
