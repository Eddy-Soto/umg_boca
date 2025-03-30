#include <iostream>
using namespace std;

void multiplicacionGrafica(int num1, int num2) {
    for (int i = 0; i < num1; i++) {
        for (int j = 0; j < num2; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

int main() {
    int num1, num2;

    cout << "Ingrese el primer número: ";
    cin >> num1;

    cout << "Ingrese el segundo número: ";
    cin >> num2;

    cout << "La multiplicación de " << num1 << " y " << num2 << " es:" << endl;
    multiplicacionGrafica(num1, num2);

    return 0;
}

