#include <iostream>
#include <vector>
using namespace std;

int main(){


	int maximum = 1000000;
//	vector<vector<int> > factorizados(maximum);
//	for (int i = 2; i < maximum; i++) {
//		if (factorizados[i].empty()){
//		// Si estoy en un primo
//			for (int j = 2*i; j <= maximum; j+=i) {
//				factorizados[j].push_back(i);
//				cout << i << endl;
//				// Lo agrego a su factorizacion
//			}
//		}
//	}

    	vector<vector<long> > factorizados;
    	for(int i=0; i<maximum+1; i++){
            vector<long> aInsertar;
            factorizados.push_back(aInsertar);
    	}
        for (int i = 2; i < maximum; i++) {
            if (factorizados[i].empty()){
            // Si estoy en un primo
                for (int j = 2*i; j <= maximum; j+=i) {

                    factorizados[j].push_back(i);
                    // Lo agrego a su factorizacion
                }
            }
        }



	int n;

	while(cin >> n) {

		vector<bool> arreglo(n+1, false);
		int suma = 0;

		for (int i = 0; i < factorizados[n].size(); i++)
		{
			for (int k = factorizados[n][i]; i < factorizados[n].size(); i++)
			{
				if (arreglo[factorizados[n][i]]== false){
					arreglo[factorizados[n][i]]== true;
					suma += factorizados[n][i];
				}
			}
		}
		cout << suma%1000000007 << endl;

	}
	return 0;
}


