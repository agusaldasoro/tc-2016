#include <vector>
#include <iostream>
#include <set>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	// Leo la entrada
	int cantidad;
	cin >> cantidad;
	vector<int> numeros(cantidad);
	for (int r = 0; r < cantidad ; r++)
		cin >> numeros[r];

	set<int> solucion;
	solucion.insert(cantidad);
	vector<bool> acumulados(cantidad,false);

    for (int i = cantidad-1; i >= 0; i--){
        // Si el numero cuenta lo que le falta hasta el final
        if (numeros[i] == cantidad-i-1){
            acumulados[i] = true;
            solucion.insert(i);
        } else{
			if (i+numeros[i]+1 < cantidad && acumulados[i+numeros[i]+1]) {
				acumulados[i] = true;
				solucion.insert(i);
            }
        }
    }

    for (auto elem: solucion){
        cout << elem << "\n";
    }
}
