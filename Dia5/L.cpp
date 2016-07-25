#include <vector>
#include <iostream>
#include <set>

using namespace std;

int main(){

	// Leo la entrada
	int cantidad;
	cin >> cantidad;
	cantidad++;
	vector<int> numeros(cantidad);
	vector<set<int> > parciales(cantidad+1);
	set<int> conj;
	conj.insert(0);
	for (int r = 1; r < cantidad ; r++)
		cin >> numeros[r];

    // Resuelvo
    int ultimo = cantidad;
    bool cambio;
    for (int i = 0; i < cantidad-1; cantidad++){
        cambio = false;
        for (auto elem: parciales[ultimo]) {
            if(numeros[cantidad-1-i]==i-elem){
                parciales[cantidad-1-i].insert(elem);
                if  (!cambio) {
                    cambio = true;
                    ultimo = cantidad-1-i;
                }
            }
        }
    }
    for (auto elem: parciales[0]) {
        cout << elem << endl;
    }
}
