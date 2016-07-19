#include <cmath>
#include <iostream>

using namespace std;

int main(){

	int amountOfDays;
	cin >> amountOfDays;
	int emptyBottles = 0;
	for(int i = 0; i < amountOfDays; ++i){
		int emptyBottles = 0;
		int found;
		int empty;
		int price;
		cin >> found >> empty >> price;
		emptyBottles += found + empty;
		int consumed = 0;
		if(price == 1){
			cout << 0 << endl;
			
		}else{
		int toBuy= 1;
		
		while(emptyBottles/price != 0){
				consumed += emptyBottles/price;
				emptyBottles -= (emptyBottles/price) * price - emptyBottles/price;
		}
		cout << consumed << endl;
		}
	}


}
