#include <bits/stdc++.h>

using namespace std;

int calculateMovements(string position, string required){
	int movements = 0;
	cout << position << endl;
	cout << required << endl;
	for(int i = required.size()-1; i >= 0; i--){
		if(position.size() < i){
			movements += required[i] + '0';
		}
		else{
			movements += abs(required[i] - position[i]);
		}
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
		int prime = -1;
		for (int i = 2; i <= dasize; i++) {
			if (arreglo[i]==0) {
				if(prime == -1) prime = i; 
				else if(abs(prime-number) <= abs(i-number)) break;
				for(int j = 2*i; j <= dasize; j+=i) arreglo[j]++;
			}
		}
		stringstream aStream;
		aStream << prime;	
		string required;
		aStream >> required;
		cout << calculateMovements(position, required) << endl;
	}
}
