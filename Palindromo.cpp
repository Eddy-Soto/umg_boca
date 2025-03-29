#include <iostream>
#include <algorithm>  // Librer�a para manipulaci�n de strings
using namespace std;

// Funci�n para verificar si una cadena es pal�ndromo
bool esPalindromo(string str) {
    string original = str;
    reverse(str.begin(), str.end());  // Invertir la cadena
    return original == str;  // Comparar original con invertida
}

int main() {
    char repetir;

    do {
        string texto;
        cout << "Ingrese una palabra o n�mero: ";
        cin >> texto;

        // Verificar si es un pal�ndromo
        if (esPalindromo(texto))
            cout << "Es un pal�ndromo." << endl;
        else
            cout << "No es un pal�ndromo." << endl;

        // Preguntar si desea realizar otra consulta
        cout << "�Desea realizar otra consulta? (s/n): ";
        cin >> repetir;
    } while (repetir == 's' || repetir == 'S');

    return 0;
}

