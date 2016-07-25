#include <vector>
#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	// Leo la entrada
	int cantidad;
	cin >> cantidad;
	vector<long long> numeros(cantidad);
	for (int r = 0; r < cantidad ; r++) {
		cin >> numeros[r];
	}
	for (int i = 0; i < cantidad; i++) {
		cout << numeros[i]*numeros[i] - numeros[i] + 2 << "\n";
	}
	return 0;
}
