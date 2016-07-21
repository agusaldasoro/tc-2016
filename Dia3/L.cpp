#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int maximum = 31623;
    vector<int> listaDePrimos;
    vector<int> factorizados(maximum, 0);
    for (int i = 2; i < maximum; i++) {
        if (factorizados[i] == 0){
        // Si estoy en un primo
            listaDePrimos.push_back(i);
            for (int j = 2*i; j <= maximum; j+=i) {
                factorizados[j] = 1;
            }
        }
    }

	int n, n2, k, w, z, parcial, tamanioInicial;
	long long multiplicador, finale, sumando, suma;
	while(cin >> n) {
        vector<int> descomposicion;
        n2 = n;
        for(z=0; z < listaDePrimos.size(); z++){
            if (n2 < listaDePrimos[z]*listaDePrimos[z] && n2!=1) {
                descomposicion.push_back(n2);
                break;
            }
            else if (n2%listaDePrimos[z] == 0){
                descomposicion.push_back(listaDePrimos[z]);
                while(n2%listaDePrimos[z] == 0){
                    n2 = n2 / listaDePrimos[z];
                }
            }
        }
        vector<pair<int, long long> > partes(1, make_pair(-1, 0));
        for (k = 0; k < descomposicion.size(); k++){
            tamanioInicial = partes.size();
            for (w = 0; w < tamanioInicial; w++){
                multiplicador = abs(partes[w].first*descomposicion[k]);
                finale = n/multiplicador;
                sumando = finale*(finale-1)/2;
                partes.push_back(make_pair((-1)*partes[w].first*descomposicion[k], sumando));
            }
        }
        suma = 0;
        for (k = 1; k < partes.size(); k++){
            suma += partes[k].first*partes[k].second;
        }
        cout << suma%1000000007 << endl;
	}
	return 0;
}


