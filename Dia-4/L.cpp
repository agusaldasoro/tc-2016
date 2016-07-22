#include <bits/stdc++.h>

using namespace std;

set<int> primes;
vector<int> numbers;
vector<int> criba;

int main(){
	int number;
	int maximum = 6;
	int caca = 0;
	while(cin >> number){
		if(number == 0) break;
		numbers.push_back(number);
		if(number >= maximum) maximum = number;
	}
	criba.resize(maximum+1,0);
	for (int i = 3; i < maximum; i+=2) {
		if (criba[i]==0) {
			primes.insert(i);
			for(int j = 3*i; j <= maximum; j+=i*2) criba[j]++;
		}
	}
	for(unsigned int i = 0; i < numbers.size(); i++){
		auto it = primes.begin();
		while(it != primes.end()){
			auto iprime = primes.find(numbers[i]-*it);
			if(iprime != primes.end()){
				cout << numbers[i] << " = " << *it << " + " << *iprime << "\n";
				break;
			}
			it++;
		}
		if(it == primes.end()) cout << "Goldbach's conjecture is wrong." << "\n";
	}
}
