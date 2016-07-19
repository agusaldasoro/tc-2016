#include <iostream> 
#include <vector>
#include <set>
using namespace std;
int main(){

	int m;
	int n;
	cin >> n >> m;
	vector<bool> used(n,false);
	vector< vector<int> > adjMatrix;
	for(int i = 0; i < n; ++i){
		vector<int> aRow(n, 1);
		adjMatrix.push_back(aRow);
	}
	for(int i = 0; i < m; ++i){
		int x,y;
		cin >> x >> y;
		adjMatrix[x-1][y-1] = 0;
		adjMatrix[y-1][x-1] = 0;
	}
	
	set<int> set1;
	set<int> set2;
	set<int> set3;
	for(int i = 0; i < n; ++i){
		if(adjMatrix[0][i] == 0){
			set1.insert(i);
			used[i] = true;
		}
		if(adjMatrix[1][i] == 0){
			set2.insert(i);
			used[i] = true;
		}
	}
	bool usado = true;
	int i = 0;
	while(usado == true){
		usado = used[i];
		++i;
	}
	for(int j = 0; j < n; ++j){
		if(adjMatrix[i][j] == 0){
			set3.insert(j);
			used[j] = true;
		}
	}
	if(set1.size() + set2.size() + set3.size() == n){
		cout << "possible" << endl;
	} else{
		cout << "impossible" << endl;
	}
}
