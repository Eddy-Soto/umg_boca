#include <iostream>
using namespace std;

int main() {
    char repetir;

    do {
        int num;  // Variable para el n�mero ingresado
        cout << "Ingrese un n�mero: ";
        cin >> num;

        // Verificar si el n�mero es par o impar usando el operador m�dulo
        if (num % 2 == 0)
            cout << "El n�mero es par." << endl;
        else
            cout << "El n�mero es impar." << endl;

        // Preguntar si desea realizar otra consulta
        cout << "�Desea realizar otra consulta? (s/n): ";
        cin >> repetir;
    } while (repetir == 's' || repetir == 'S');

    return 0;
}



