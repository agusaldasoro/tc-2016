#include <vector>
#include <iostream>

using namespace std;

void copyVector(vector<int> &v1, vector<int> &v2, int i){
	for(unsigned int iter = 0; iter < v2.size(); iter++){
		v2[iter] = v1[iter+i];
	}
}

int searchCabeza(vector<int> &v){
	for(unsigned int i = 0; i < v.size()-1; i++){
		int n = v[i];
		for(unsigned int j = i+1; j < v.size(); j++){
			if(n == v[j]) return n;
		}
	}
	return -1;
}

int repeated(vector<int> &v){
	if(v.size() <= 1) return -1;
	else{
		int half = v.size()/2;
		vector<int> left(half);
		copyVector(v, left, 0);
		int res = repeated(left);
		if(res >= 0){
			return res;
		}
		else{
			vector<int> right(v.size()-half);
			copyVector(v, right, v.size()-half-1);
			res = repeated(right);
			if(res >= 0) return res;
			else
				return searchCabeza(v);
		}
	}
}

int main(){
	int msgAmount;
	int queriesAmount;
	while(cin >> msgAmount >> queriesAmount){
		if(msgAmount == 0 && queriesAmount == 0) break;
		vector<int> messages(msgAmount,0);
		for(int m = 0; m < msgAmount; m++){
			int msg;
			cin >> msg;
			messages[m] = msg;
		}
		for(int q = 0; q < queriesAmount; q++){
			int i, j, result;
			cin >> i;
			cin >> j;
			vector<int> range(j-i+1, -1);
			copyVector(messages, range, i-1);
			result = repeated(range);
			if(result >= 0){
				cout << result << endl;
			}
			else {
				cout << "OK" << endl;
			}
			
		}
		cout << endl;
	}
	
}
