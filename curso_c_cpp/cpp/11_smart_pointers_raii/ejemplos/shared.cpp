/*
 * shared_ptr: propiedad compartida con contador de referencias.
 */
#include <iostream>
#include <memory>
using namespace std;

int main() {
    shared_ptr<int> a = make_shared<int>(100);
    cout << "Duenos: " << a.use_count() << endl;   // 1

    {
        shared_ptr<int> b = a;                      // a y b comparten
        cout << "Duenos: " << a.use_count() << endl;   // 2
        cout << "*b = " << *b << endl;
    }   // b sale de ambito: queda un solo dueno

    cout << "Duenos: " << a.use_count() << endl;   // 1
    return 0;                                       // aqui se libera el int
}
