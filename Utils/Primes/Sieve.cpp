#include <bits/stdc++.h>

using namespace std;

vector<int> primes;
vector<int> sieve;

void calculate(int size){
	sieve.resize(size+1,0);
	primes.push_back(2);
	for (int i = 3; i < size; i+=2) {
		if (sieve[i]==0) {
			primes.push_back(i);
			for(int j = 3*i; j <= size; j+=i*2) sieve[j]++;
		}
	}
}

int main(){
	
}
