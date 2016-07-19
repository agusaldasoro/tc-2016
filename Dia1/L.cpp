#include <cmath>
#include <iostream>

using namespace std;

int digit(string number, int position){
	return number[number.size()-1-position] - '0';
}

int potenciasDe10[123450];
int potenciasDeShirts[123450];

int pot10(int exp, int m) {
	if(exp == 0)
		potenciasDe10[exp] = 1;
	else {
		potenciasDe10[exp] = 1;
		for(int i=0;i<10;i++) {
			potenciasDe10[exp] = (potenciasDe10[exp] * potenciasDe10[exp-1])%m;
		}
	}
	return potenciasDe10[exp];
}

int potShirts(int base, int exp, int m) {
	if(exp == 0)
		potenciasDeShirts[exp] = 1;
	else if(exp == 1)
		potenciasDeShirts[exp] = base;
	else {
		potenciasDeShirts[exp] = 1;
		for(int i=0;i<10;i++) {
			potenciasDeShirts[exp] = (potenciasDeShirts[exp] * potenciasDeShirts[exp-1])%m;
		}
	}
	return potenciasDeShirts[exp];
}

int main(){
	string mice;
	int shirts;
	int module;
	int result;
	while(cin >> mice >> shirts >> module){
		shirts = shirts % module;
		long aux = shirts;
		for(long long i = 0; i < mice.size(); i++) {
			aux = (potShirts(aux, i,module) * digit(mice, i))%module;
			if(aux != 0){
				result *= aux;
				result = result % module;
			}
		}
		cout << (result % module) << endl;
	}
	
	return 0;
}
