#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for(int i = 0; i < tests; i++){
		int x, y;
		cin >> x >> y;
		for(int j = max(x,2); j <= y; j++){
			bool isPrime = true;
			for(int num = 2; num <= (int) sqrt(j); num++){
				if(j % num == 0){
					isPrime = false;
					break;
				}
			}
			if(isPrime){
				cout << j << "\n";
			}
		}
		cout << endl;	
	}
	
}
