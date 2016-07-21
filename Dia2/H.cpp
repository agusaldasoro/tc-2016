#include <iostream> 
#include <vector>
#include <set>

using namespace std;

int gcd(int a, int b){
	return (a == 0) ? b : gcd(b % a, a);
}


long long potMod(int base,int  exp ,int  M){
	if(exp == 0) return 1;
	auto val = potMod(base, exp/2, M);
	auto val2 = (exp % 2 == 1) ? ((val*val*base) % M) : (((val*val) % M));
	return val2;
}


int main(){
	int n;
	cin >> n;
	vector<int> permutation(n);
	set<int> aSet;
	for(int i = 0; i < n; ++i){
		int y;
		cin >> y;
		permutation[i] = y-1;
		aSet.insert(i);
	}
	vector<int> cycleSizes;
	while(!aSet.empty()){
		int first = *aSet.begin();
		aSet.erase(first);
		int last = permutation[first];
		int cycleSize = 1;
		while(first != last){
			++cycleSize;
			aSet.erase(last);
			last = permutation[last];
		}
		
		cycleSizes.push_back(cycleSize);
	};
	
	for(auto i : cycleSizes){
		if(i % 2 == 0){
			cout << 0 << endl;
			return 0;
		}
	}
	
	int acum = 0;
	
	for(int i = 0; i < cycleSizes.size(); ++i){
		acum += cycleSizes[i]/2;
		for(int j = i + 1; j < cycleSizes.size() ;++j){
			acum += gcd(cycleSizes[i], cycleSizes[j]);
		}
	}
	
	cout << potMod(2, acum, 1000) << endl;
	return 0;
	
}
