#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, hipotenusa;
    
    cout << "Ingrese el valor del cateto a: ";
    cin >> a;
    cout << "Ingrese el valor del cateto b: ";
    cin >> b;
    
    if (a > 0 && b > 0) {
        hipotenusa = sqrt(pow(a, 2) + pow(b, 2));
        cout << "La hipotenusa es: " << hipotenusa << endl;
    } else {
        cout << "Los catetos deben ser positivos." << endl;
    }
    
    return 0;
}
