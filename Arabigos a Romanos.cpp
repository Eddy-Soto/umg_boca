#include <iostream>
using namespace std;

// Función para convertir un número entero a números romanos
string convertirARomano(int num) {
    string romano[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int valores[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string resultado = "";

    // Conversión al formato romano
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
        cout << "Ingrese un número (mínimo 1000): ";
        cin >> numero;

        if (numero >= 1000)
            cout << "Número en romano: " << convertirARomano(numero) << endl;
        else
            cout << "El número debe ser mayor o igual a 1000." << endl;

        // Preguntar si desea realizar otra consulta
        cout << "¿Desea realizar otra consulta? (s/n): ";
        cin >> repetir;
    } while (repetir == 's' || repetir == 'S');

    return 0;
}

