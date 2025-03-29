#include <iostream>
#include <algorithm>  // Librería para manipulación de strings
using namespace std;

// Función para verificar si una cadena es palíndromo
bool esPalindromo(string str) {
    string original = str;
    reverse(str.begin(), str.end());  // Invertir la cadena
    return original == str;  // Comparar original con invertida
}

int main() {
    char repetir;

    do {
        string texto;
        cout << "Ingrese una palabra o número: ";
        cin >> texto;

        // Verificar si es un palíndromo
        if (esPalindromo(texto))
            cout << "Es un palíndromo." << endl;
        else
            cout << "No es un palíndromo." << endl;

        // Preguntar si desea realizar otra consulta
        cout << "¿Desea realizar otra consulta? (s/n): ";
        cin >> repetir;
    } while (repetir == 's' || repetir == 'S');

    return 0;
}

