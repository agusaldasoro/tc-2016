#include <iostream>
#include <vector>
using namespace std;

vector<long long> memo(1000100, -1);

int main(){
	memo[1] = 1;
	for(int a = 2; a < 1000100; ++a) memo[a] = ((memo[a-1]*a +1) % 1000003);
	
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int n;
		cin >> n;
		cout << memo[n] << endl;
	}

}
