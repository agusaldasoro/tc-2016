#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

string leadingZeroes(unsigned long long num){
	stringstream aStream;
	aStream << num;	
	string orig;
	aStream >> orig;
	int digits = orig.size();
	for(int i = 0; i < 10-digits; i++){
		orig = "0" + orig;
	}
	return orig;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int cantidad;
	cin >> cantidad;
	vector<int> numeros(cantidad);
	int maximo = 0;
	for (int r = 0; r < cantidad ; r++) {
		cin >> numeros[r];
		if (numeros[r]> maximo)
			maximo = numeros[r];
	}
	vector<unsigned long long> listaDePrimos;
	vector<int> arreglo(maximo+1, 0);
	int primosVistos = 0;
	for (int i = 2; i <= maximo; i++) {
		if (arreglo[i]==0) {
            primosVistos++;
            if (i==2){
                listaDePrimos.push_back(i);
            }
            else{
				long long var = i;
                listaDePrimos.push_back((*(--listaDePrimos.end())*(var%10000000000))%10000000000);
            }
			for (int j = 2*i; j <= maximo; j+=i)
				arreglo[j]++;
		}
		arreglo[i] = primosVistos;
	}
    for (unsigned int j=0; j < numeros.size(); j++){
		if (numeros[j]>=31){
			unsigned long long numero = listaDePrimos[arreglo[numeros[j]]-1];
			string zeros = leadingZeroes(numero);
			cout << zeros << "\n";		
		}
        else{
			cout << listaDePrimos[arreglo[numeros[j]]-1] << "\n";
		}
    }
}
