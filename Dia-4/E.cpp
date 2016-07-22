#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int tests;
	cin >> tests;
	int n;
	for(int i = 0; i < tests; i++){
		cin >> n;
		n = 0;
		cout << "number is " << n << cout;
		int prime = n;
		bool notPrime = true;
		while(notPrime){
			for(int num = 2; num <= (int) sqrt(prime); num++){
				if(prime % num == 0){
					notPrime = false;
				}
			}
			if(notPrime) prime++;
		}
		cout << prime << endl;	
	}
	
}
