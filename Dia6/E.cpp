#include <bits/stdc++.h>

using namespace std;

struct Door{
	int boss;
	int superBoss;
	bool isSuperBoss;
	Door(int x, int y, bool boss) : boss(x), superBoss(y), isSuperBoss(boss){}
	bool operator<(const Door d) const{
		return this->cost() > d.cost();
	}
	int cost() const{
		if(isSuperBoss){
			return superBoss;
		}else{
			return boss;
		}
	}
};

priority_queue<Door> listOfDoors;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for(int i = 0; i < tests; i++){
		int doors;
		int obtained = 0;
		int traded = 0;
		cin >> doors;
		for(int j = 0; j < doors; j++){
			int boss, superboss;
			cin >> boss >> superboss;
			Door door(boss, superboss, false);
			listOfDoors.push(door);
		}
		while(!listOfDoors.empty()){
			Door d = listOfDoors.top();			
			listOfDoors.pop();
			if(obtained < d.cost()){
				traded += d.cost() - obtained;
				obtained = d.cost();
			}
			if(d.isSuperBoss){
				obtained+=2;
			}
			else{
				obtained++;
				d.isSuperBoss = true;
				listOfDoors.push(d);
			}
		}
		cout << traded << "\n";
	}
}
