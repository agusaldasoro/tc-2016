#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main(){

	// Leo la entrad
	vector<long long> numeros;
	long long maximo = 0;
	long long actual;
	while(true){
		cin >> actual;
		if (actual < 1){ break; }
		numeros.push_back(actual);
		if (actual > maximo)
			maximo = actual;
	}

	// Calculo todos los primos hasta raiz de maximo
    int cota = sqrt(maximo);
	vector<long long> listaDePrimos;
	vector<int> arreglo(cota+1, 0);
	for (int i = 2; i <= cota; i++) {
		if (arreglo[i] == 0) {
			listaDePrimos.push_back(i);
			for (long long j = 2*i; j <= cota; j+=i) {
                if (arreglo[j] == 0)
                    arreglo[j] = i;
			}
		}
	}

	int cantidadDePrimos = listaDePrimos.size();
    int k, w;
    long long n, orig, divisorPrimo1, divisorPrimo2, dividido1, dividido2;

    // Recorro cada una de las entradas
	for (int r = 0; r < numeros.size(); r++) {
        vector<long long> divisores;
		n = numeros[r];
		// La entrada es muy grande
		if (n > cota) {
			for (k = 0; k < cantidadDePrimos; k++){
			    while (n%listaDePrimos[k] == 0){
                    divisores.push_back(listaDePrimos[k]);
                    n = n / listaDePrimos[k];
                }
			}
            if (n > 1) {
                divisores.push_back(n);
            }
		}else {

			while (n > 1){
                if (arreglo[n] > 0) {
                    divisores.push_back(arreglo[n]);
                    n = n / arreglo[n];
                } else{
                    divisores.push_back(n);
                    n = n / n;
                }
			}

		}
		for (int j = 0; j < divisores.size(); j++){
            cout << divisores[j] << "\n" ;
		}
		cout << "\n";
	}
}

