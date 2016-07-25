#include <vector>
#include <iostream>

using namespace std;

int main(){

	// Leo la entrada
	int cantidadDeTests, tamanio, actual, medio, cuarto, suma;
	cin >> cantidadDeTests ;
	
	for (int r = 0; r < cantidadDeTests ; r++) {
		cin >> tamanio;
		vector<int> vectorActual(4, 0);
		for (int i = 0; i < tamanio; i++) {
			cin >> actual;
			vectorActual[actual-1]++;	 
		}
		// Caso grupos de a 4
		suma = vectorActual[3];
		// Caso grupos de a 3
		vectorActual[0] -= vectorActual[2];
		suma += vectorActual[2];
		// Caso grupos de a 2
		medio = vectorActual[1] / 2;
		suma += medio;
		vectorActual[1] -= medio*2;
		vectorActual[0] -= 2*vectorActual[1];
		suma += vectorActual[1];
		// Caso grupos de a 1
		if (vectorActual[0] > 0) {
			cuarto = vectorActual[0] / 4;
			vectorActual[0] -= cuarto*4;
			suma += cuarto;
			if (vectorActual[0]>0) 
				suma ++;
		}
		cout << suma << endl;		
	}
	return 0;
}
