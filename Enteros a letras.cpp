#include <iostream>
#include <map>
using namespace std;

// Funci�n para convertir n�meros a palabras (versi�n b�sica)
string convertirALetras(int num) {
    map<int, string> numeros = {
        {1, "Uno"}, {2, "Dos"}, {3, "Tres"}, {4, "Cuatro"}, {5, "Cinco"},
        {6, "Seis"}, {7, "Siete"}, {8, "Ocho"}, {9, "Nueve"}, {10, "Diez"},
        {20, "Veinte"}, {30, "Treinta"}, {40, "Cuarenta"}, {50, "Cincuenta"},
        {100, "Cien"}, {200, "Doscientos"}, {500, "Quinientos"}, {1000, "Mil"}
    };

    if (numeros.find(num) != numeros.end()) return numeros[num];

    return "N�mero no soportado";
}

int main() {
    char repetir;

    do {
        int numero;
        cout << "Ingrese un n�mero entero: ";
        cin >> numero;

        cout << "N�mero en letras: " << convertirALetras(numero) << endl;

        // Preguntar si desea realizar otra consulta
        cout << "�Desea realizar otra consulta? (s/n): ";
        cin >> repetir;
    } while (repetir == 's' || repetir == 'S');

    return 0;
}

