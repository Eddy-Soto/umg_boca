#include <iostream>
using namespace std;

int main() {
    char operador;
    double num1, num2;
    
    cout << "Ingresa un operador (+, -, *, /): ";
    cin >> operador;
    cout << "Ingresa dos numeros: ";
    cin >> num1 >> num2;
    
    switch(operador) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                cout << num1 << " / " << num2 << " = " << num1 / num2;
            } else {
                cout << "Error: Division por cero.";
            }
            break;
        default:
            cout << "Operador invalido.";
    }
    
    return 0;
}
