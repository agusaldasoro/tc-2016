#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main(){

	// Leo la entrada
	int cantidad;
	cin >> cantidad;
	vector<int> numeros(cantidad);
	int maximo = 0;
	for (int r = 0; r < cantidad ; r++) {
		cin >> numeros[r];
		if (numeros[r]> maximo)
			maximo = numeros[r];
	}

	// Calculo todos los primos hasta raiz de maximo
    int cota = min(maximo, 10000000);
	vector<int> listaDePrimos;
	vector<int> arreglo(cota+1, 0);
	arreglo[0] = 0;
	arreglo[1] = 0;
	for (int i = 2; i <= cota; i++) {
		if (arreglo[i]==0) {
			listaDePrimos.push_back(i);
			for (int j = 2*i; j <= cota; j+=i) {
				if (arreglo[j]==0)
					arreglo[j]=i;
			}
		}
	}
	int cantidadDePrimos = listaDePrimos.size();
    int n, n2, dividido1, dividido2, k, q, q2, w;
    int divisorPrimo1, divisorPrimo2;

    // Recorro cada una de las entradas
	for (int r = 0; r < cantidad; r++) {
		n = numeros[r];
		// La entrada es muy grande
		if (n > cota) {
			for (k = 0; k < cantidadDePrimos; k++) {
				if (n%listaDePrimos[k] == 0) {
                    cout << "el k es " << listaDePrimos[k] << endl;
                    // El primo actual lo divide
                    // divisorPrimo1 es el primer divisor
					divisorPrimo1 = listaDePrimos[k];
					// Lo que queda despues de dividir
					dividido1 = n/divisorPrimo1;
					if (dividido1 > cota) {
						for (w = k; w < cantidadDePrimos; w++) {
							if (dividido1%listaDePrimos[w] == 0) {
                                // n tiene dos divisores primos
                                dividido2 = dividido1/listaDePrimos[w];
                                if(dividido2 > cota) {
                                    cout << "kb" << endl;
                                    break;
                                }else {
                                    divisorPrimo2 = arreglo[dividido2];
                                    cout << divisorPrimo2 << endl;
                                    if (divisorPrimo2 > 0) {
                                        // Tiene tres o mas divisores primos
                                        cout << "Vasha" << endl << divisorPrimo1*divisorPrimo2 << endl;
                                    } else{
                                        cout << "Molek" << endl;
                                    }
                                    break;
                                }
							}
						}
						if(w == cantidadDePrimos) {
							cout << "Molek" << endl;
						}
						break;
					}else {
						divisorPrimo2 = arreglo[dividido1];
						if (divisorPrimo2 > 0)
							cout << "Vasha" << endl << listaDePrimos[k]*divisorPrimo2 << endl;
						else
							cout << "Molek" << endl;
                        break;
					}
				}
			}
			// Ningun primo menor a raiz de si mismo lo divide, entonces es primo
			if(k == cantidadDePrimos) {
				cout << "Vasha" << endl << 0 << endl;
			}
		}else {
			q = arreglo[n];
			if (q > 0) {
				q2 = arreglo[n/q];
				if (q2 > 0)
					cout << "Vasha" << endl << q*q2 << endl;
				else
					cout << "Molek" << endl;
			}else
				cout << "Vasha" << endl << 0 << endl;
		}
	}
}
