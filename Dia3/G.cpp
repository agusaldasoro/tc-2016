#include <iostream>

using namespace std;

int main(){
	int bags;
	while(cin >> bags){
		int apples;
		int evens = 0;
		int unevens = 0;
		for(int i = 0; i < bags; i++){
			cin >> apples;
			if(apples % 2 == 0) evens++;
			else unevens++;
		}
		if(unevens % 2 == 0){
			cout << evens << endl;
		}
		else {
			cout << unevens << endl;
		}
	}
	return 0;
}

