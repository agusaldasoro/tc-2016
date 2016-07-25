#include <bits/stdc++.h>

using namespace std;

set<unsigned long long> primes;
vector<unsigned long long> numbers;
vector<unsigned long long> criba;

int main(){
	unsigned long long number;
	int maximum = -1;
	int tests;
	cin >> tests;
	for(int i = 0; i < tests; i++){
		cin >> number;
		numbers.push_back(number);
	}
	criba.resize(671200,0);
	primes.insert(2);
	for (unsigned long long i = 3; i < criba.size(); i+=2) {
		if (criba[i]==0) {
			primes.insert(i);
			for(int j = 3*i; j <= criba.size(); j+=i*2){
				criba[j]++;
			}
		}
	}
	for(unsigned int i = 0; i < numbers.size(); i++){
		unsigned long long minPrime = numbers[i];
		if(minPrime < 2) minPrime = 2;
		while(true){
			auto it = primes.begin();
			bool isPrime = true;
			while(it != primes.end() && (*it) < minPrime){
				if(minPrime % (*it)  == 0){
					isPrime = false;
					break;
				}
				else it++;
			}
			if(isPrime) break;
			else minPrime++;
		}
		cout << minPrime << "\n";
	}
}
