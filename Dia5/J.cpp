#include <bits/stdc++.h>

using namespace std;

vector<int> primos;
vector<int> criba;

int main(){
	int n;
	cin >> n;
	primos.clear();
	criba.resize(min(n,3000), 0);
	int elegidos = 0;
	criba.resize(n+1,0);
	primos.push_back(2);
	for (int i = 3; i < n; i+=2) {
		if (criba[i]==0) {
			primos.push_back(i);
			for(int j = 3*i; j <= n; j+=i*2) criba[j]++;
		}
	}
	for(int i = 6; i <= n; i++){
		int primeDiv = 0;
		for(int j = 0; j < primos.size(); j++){
			int num = i;
			if(num % primos[j] == 0) primeDiv++;
		}
		if(primeDiv == 2) elegidos++;
	}
	cout << elegidos << endl;
}
