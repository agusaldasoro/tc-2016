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
    int primosEnN;
    long long n, divisorPrimo1, divisorPrimo2;

    // Recorro cada una de las entradas
	for(int r = 0; r < cantidad; r++) {
		n = numeros[r];
		primosEnN = 0;
		// La entrada es muy grande
		for(int k = cantidadDePrimos - 1; k >= 0; k--){
            while((n % listaDePrimos[k] == 0) && n>1){
                primosEnN++;
                if(k % 2 == 0) divisorPrimo1 = listaDePrimos[k];
                else divisorPrimo2 = listaDePrimos[k];
                n = n/listaDePrimos[k];
            }
            if(n == 1) break;
		}
		if(primosEnN == 1){
            cout << "Vasha" << endl << 0 << endl;
		}
        else if(primosEnN == 2){
            cout << "Molek" << endl;
		}
		else {
            cout << "Vasha" << endl << divisorPrimo1*divisorPrimo2 << endl;
		}
	}
}
