#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int numeroSecreto = rand() % 100 + 1;
    int intento, contador = 0;
    
    cout << "Adivina el numero (1-100):" << endl;
    
    do {
        cout << "Ingresa tu intento: ";
        cin >> intento;
        contador++;
        
        if (intento < numeroSecreto) {
            cout << "El numero es mayor." << endl;
        } else if (intento > numeroSecreto) {
            cout << "El numero es menor." << endl;
        } else {
            cout << "Correcto! Lo lograste en " << contador << " intentos." << endl;
        }
    } while (intento != numeroSecreto);
    
    return 0;
}
