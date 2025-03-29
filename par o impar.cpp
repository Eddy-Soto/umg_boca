#include <iostream>
using namespace std;

int main() {
    char repetir;

    do {
        int num;  // Variable para el número ingresado
        cout << "Ingrese un número: ";
        cin >> num;

        // Verificar si el número es par o impar usando el operador módulo
        if (num % 2 == 0)
            cout << "El número es par." << endl;
        else
            cout << "El número es impar." << endl;

        // Preguntar si desea realizar otra consulta
        cout << "¿Desea realizar otra consulta? (s/n): ";
        cin >> repetir;
    } while (repetir == 's' || repetir == 'S');

    return 0;
}



