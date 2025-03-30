#include <iostream>
#include <stack>  // Para usar la pila (stack)
using namespace std;

void decimalABinario(int num) {
    stack<int> binario;  // Usamos una pila para almacenar los restos

    // Si el n�mero es 0, lo manejamos espec�ficamente
    if (num == 0) {
        cout << "El n�mero en binario es: 0" << endl;
        return;
    }

    // Mientras el n�mero sea mayor que 0, dividimos entre 2
    while (num > 0) {
        binario.push(num % 2);  // Guardamos el resto (0 o 1)
        num = num / 2;  // Dividimos el n�mero entre 2
    }

    // Mostramos el n�mero binario en orden correcto (de arriba a abajo)
    cout << "El n�mero en binario es: ";
    while (!binario.empty()) {
        cout << binario.top();  // Mostrar el valor en la cima de la pila
        binario.pop();  // Eliminar el valor de la pila
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

        // Convertimos el n�mero decimal a binario
        decimalABinario(numero);

        // Preguntar si el usuario quiere realizar otra conversi�n
        cout << "�Quieres convertir otro n�mero? (s/n): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');  // Repite si la opci�n es 's' o 'S'

    cout << "�Hasta luego!" << endl;

    return 0;
}

