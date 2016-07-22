#include <bits/stdc++.h>

using namespace std;

int digit(int number, int pos){
	return (int) ((number % (int) pow(10,pos+1)) / (pow(10,pos)));
}

int calculateMovements(int number, int prime){
	int digits = 0;
	int maximum = max(number, prime);
	int movements = 0;
	while(maximum > 0){
		maximum = maximum/10;
		digits++;
	}
	cout << digits << endl;
	for(int i = 0; i < digits; i++){
		movements = abs(digit(number,i) - digit(prime,i));
	}
	return movements;
}

int main(){
	int tests;
	cin >> tests;
	for(int i = 0; i < tests; i++){
		short digits;
		string position;
		cin >> digits >> position;
		int dasize = pow(10,digits);
		vector<int> arreglo(dasize, 0);
		int number = atoi(position.c_str());
		int prime = 0;
		for (int i = 3; i <= dasize; i+=2) {
			if (arreglo[i]==0) {
				if(abs(prime-number) <= abs(i-number)) break;
				for(int j = 3*i; j <= dasize; j+=i) arreglo[j]++;
				prime = i;
			}
		}
		cout << calculateMovements(number, prime) << endl;
	}
}
