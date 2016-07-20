#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	while(cin >> N){
		
		if(N == 0) break;
		vector<int> primes;
		for(int i = 0; i < N; ++i){
			int aPrime;
			cin >> aPrime;
			primes.push_back(aPrime);
		}
		int X;
		int Y;
		cin >> X;
		cin >> Y;
		set<int> uglyNumber;
		uglyNumber.insert(1);
		int aCounter = 0;
		vector<int> toBePrinted;
		while(!uglyNumber.empty() && *(uglyNumber.begin()) <= Y){
			int min = *(uglyNumber.begin());
			if(min >= X){
				toBePrinted.push_back(min);
				++aCounter;
			}
			for(auto aPrime : primes){
				if(aPrime <= Y/min) {
					uglyNumber.insert(min*aPrime);
				}
			}
			uglyNumber.erase(min);
		}
		if(aCounter != 0){
			cout << toBePrinted[0];
			for(auto it = ++(toBePrinted.begin()); it != toBePrinted.end(); ++it){
				cout<< ',' << *it ;
			}				
			cout << "\n";
		}else{
			cout << "none" << "\n";
		}	
	}
}
