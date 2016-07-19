#include <vector>
#include <iostream>

using namespace std;

int main(){
	int tests;
	int candidates;
	int regions;
	int winner;
	int max;
	cin >> tests;
	for(int i = 0; i < tests; i++){
		cin >> candidates >> regions;
		max = 0;
		winner = 0;
		vector<int> votes(candidates,0);
		for(int r = 0; r < regions; r++){
			for(int v = 0; v < candidates; v++){
				int vote;
				cin >> vote;
				votes[v] += vote;
				if(votes[v] > max){
					max = votes[v];
					winner = v+1;
				}
			}
		}
		cout << winner << endl;
	}
	return 0;		
}
