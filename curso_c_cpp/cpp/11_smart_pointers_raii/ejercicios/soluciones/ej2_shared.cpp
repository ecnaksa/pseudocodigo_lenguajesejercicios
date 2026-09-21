/* Ejercicio 2 - Contador de referencias de shared_ptr. */
#include <iostream>
#include <memory>
using namespace std;

int main() {
    shared_ptr<int> a = make_shared<int>(7);
    cout << "1) duenos = " << a.use_count() << endl;   // 1

    shared_ptr<int> b = a;
    cout << "2) duenos = " << a.use_count() << endl;   // 2

    {
        shared_ptr<int> c = a;
        cout << "3) duenos = " << a.use_count() << endl;   // 3
    }
    cout << "4) duenos = " << a.use_count() << endl;   // 2
    return 0;
}
