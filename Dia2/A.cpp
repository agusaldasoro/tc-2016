#include <string>
#include <cmath>
#include <iostream>

using namespace std;

int main(){
	
	long long a;
	long long b;
	int p;
	long long k;
	while(cin >> a >> b >> p){
		k = 0;
		unsigned long long numer = 0;
		unsigned long long denom = 0;
		for(int i = 1; i <= b; i++){
			unsigned long long value = log(i)/log(p);
			if(i <= a) denom += value;
			numer += value;
		}
		k = numer/denom;
		cout << oct << k << endl;
	}
}
