#include <iostream>
#include <vector>

using namespace std;

int main(){

	int N;
	cin >> N;
	vector<int> numbers;
	int max= 0;
	for(int i = 0; i < N; ++i){
		int aNumber;
		cin >> aNumber;
		numbers.push_back(aNumber);
		if(max < aNumber){
			max = aNumber;
		}
	}
	vector<vector<int> > theMatrix;
	for(int i = 0; i < max+1; ++i){
		vector<int> aVector(max,0);
		theMatrix.push_back(aVector);
	}
	
	for(int i = 0; i < max; ++i){
		theMatrix[0][i] = 1;
		theMatrix[1][i] = i % 10000003;
	}
	
	for(int i = 2; i < max-1; ++i){
		for(int j = i; j < max; ++j){
			theMatrix[i][j] = (theMatrix[i][j-1] + i*theMatrix[i-1][j-1]) % 10000003; 
		}
	}
	for(int j = 0; j < max; ++j){
		int acum = 0;
		for(int i= 0; i < j; ++i){
			acum += theMatrix[i][j] % 10000003;
		}
		theMatrix[max][j] = acum % 10000003;
	}
	for(auto number : numbers){
		cout << theMatrix[max][number] << endl;
	}
}
