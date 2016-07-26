#include <bits/stdc++.h>

using namespace std;

int main(){
	string input;
	cin >> input;
	int regions = 0;
	for(int i = 0; i < input.size(); i++){
		char letter = input[i];
		if(letter == 'A') regions++;
		if(letter == 'B') regions+=2;
		if(letter == 'D') regions++;
		if(letter == 'O') regions++;
		if(letter == 'P') regions++;
		if(letter == 'Q') regions++;
		if(letter == 'R') regions++;
	}
	cout << regions << endl;
}
