#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main(){

	// Leo la entrada
	int cantidad;
	cin >> cantidad;
	vector<long long> numeros(cantidad);
	long long maximo = 0;
	for (int r = 0; r < cantidad ; r++) {
		cin >> numeros[r];
		if (numeros[r]> maximo)
			maximo = numeros[r];
	}

	// Calculo todos los primos hasta raiz de maximo
	long long mucho = 10000000;
    int cota = min(maximo, mucho);
	vector<long long> listaDePrimos;
	vector<int> arreglo(cota+1, 0);
	for (int i = 2; i <= cota; i++) {
		if (arreglo[i]==0) {
			listaDePrimos.push_back(i);
			for (long long j = 2*i; j <= cota; j+=i) {
				if (arreglo[j]==0)
					arreglo[j]=i;
			}
		}
	}
	int cantidadDePrimos = listaDePrimos.size();
    int k, w;
    long long n, divisorPrimo1, divisorPrimo2, dividido1, dividido2;

    // Recorro cada una de las entradas
	for (int r = 0; r < cantidad; r++) {
		n = numeros[r];
		// La entrada es muy grande
		if (n > cota) {
			for (k = 0; k < cantidadDePrimos; k++){
                if(n%listaDePrimos[k] == 0){
                    divisorPrimo1 = listaDePrimos[k];
                    dividido1 = n / divisorPrimo1;
                    for (w = k; w < cantidadDePrimos; w++){
                        if (dividido1%listaDePrimos[w] == 0){
                            divisorPrimo2 = listaDePrimos[w];
                            dividido2 = dividido1 / divisorPrimo2;
                            if (dividido2 > 1) {
                                cout << "Vasha" << endl << divisorPrimo1*divisorPrimo2 << endl;
                                break;
                            } else {
                                cout << "Molek" << endl;
                                break;
                            }
                        }
                    }
                    if (w == cantidadDePrimos){
                        cout << "Molek" << endl;
                    }
                    break;
                }
			}
			if (k == cantidadDePrimos){
				cout << "Vasha" << endl << 0 << endl;
			}
		}else {
			divisorPrimo1 = arreglo[n];
			if (divisorPrimo1 > 0) {
				divisorPrimo2 = arreglo[n/divisorPrimo1];
				// Tiene 3 divisores
				if (divisorPrimo2 > 0)
					cout << "Vasha" << endl << divisorPrimo1*divisorPrimo2 << endl;
				else
					cout << "Molek" << endl;
			}else
				cout << "Vasha" << endl << 0 << endl;
		}
	}
}
