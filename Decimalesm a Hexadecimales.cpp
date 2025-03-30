#include <iostream>
#include <stack>  // Para usar la pila (stack)
#include <iomanip>  // Para formateo de salida
using namespace std;

void decimalAHexadecimal(int num) {
    stack<char> hexadecimal;  // Usamos una pila para almacenar los restos (en formato hexadecimal)

    // Si el n�mero es 0, lo manejamos espec�ficamente
    if (num == 0) {
        cout << "El n�mero en hexadecimal es: 0" << endl;
        return;
    }

    // Mientras el n�mero sea mayor que 0, dividimos entre 16
    while (num > 0) {
        int resto = num % 16;  // Obtenemos el resto de la divisi�n entre 16
        if (resto < 10) {
            hexadecimal.push('0' + resto);  // Para restos menores que 10, usamos 0-9
        } else {
            hexadecimal.push('A' + (resto - 10));  // Para restos mayores o iguales a 10, usamos A-F
        }
        num = num / 16;  // Dividimos el n�mero entre 16
    }

    // Mostramos el n�mero hexadecimal en orden correcto (de arriba a abajo)
    cout << "El n�mero en hexadecimal es: ";
    while (!hexadecimal.empty()) {
        cout << hexadecimal.top();  // Mostrar el valor en la cima de la pila
        hexadecimal.pop();  // Eliminar el valor de la pila
    }
    cout << endl;
}

int main() {
    int numero;
    char opcion;

    do {
        // Pedimos al usuario que ingrese un n�mero decimal
        cout << "Introduce un n�mero decimal: ";
        cin >> numero;

        // Convertimos el n�mero decimal a hexadecimal
        decimalAHexadecimal(numero);

        // Preguntar si el usuario quiere realizar otra conversi�n
        cout << "�Quieres convertir otro n�mero? (s/n): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');  // Repite si la opci�n es 's' o 'S'

    cout << "�Hasta luego!" << endl;

    return 0;
}

