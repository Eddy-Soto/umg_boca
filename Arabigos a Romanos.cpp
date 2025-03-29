#include <iostream>
using namespace std;

// Funci�n para convertir un n�mero entero a n�meros romanos
string convertirARomano(int num) {
    string romano[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int valores[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string resultado = "";

    // Conversi�n al formato romano
    for (int i = 0; i < 13; i++) {
        while (num >= valores[i]) {
            resultado += romano[i];
            num -= valores[i];
        }
    }
    return resultado;
}

int main() {
    char repetir;

    do {
        int numero;
        cout << "Ingrese un n�mero (m�nimo 1000): ";
        cin >> numero;

        if (numero >= 1000)
            cout << "N�mero en romano: " << convertirARomano(numero) << endl;
        else
            cout << "El n�mero debe ser mayor o igual a 1000." << endl;

        // Preguntar si desea realizar otra consulta
        cout << "�Desea realizar otra consulta? (s/n): ";
        cin >> repetir;
    } while (repetir == 's' || repetir == 'S');

    return 0;
}

