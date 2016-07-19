#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> primos;
	primos.push_back(2);
	primos.push_back(3);
	primos.push_back(5);
	vector<int> numeros;
	int var;
	bool termine = false;
	while (!termine) {
		cin >> var;
		if (var!=0) {
			numeros.push_back(var);
		}else{
			termine = true;
		}
	}
	int n, j;
	for (int i = 0; i < numeros.size(); i++) {
		n = numeros[i];
		vector<bool> arr(n+1, false);
		arr[1]=arr[2]=arr[3]=arr[5]=true;
		for (j = 0; j < 3; j++) {
			for (int r = 2*primos[j]; r <= n; r+=primos[j]) {
				arr[j]=true;
			}
		}
		int count=0, indice=1;
		bool encontre;
		while(count<n){
			encontre = false;
			while(!encontre){
				indice++;
				encontre = arr[indice];
			}
			count++;
		}
		cout << indice << endl;
	}
	


}
