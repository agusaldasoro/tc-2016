#include <iostream>
#include <queue> 

using namespace std;
int main() {
	
	int R, C, Q;
	while(cin >> R >> C >> Q){
		if(R == 0 && C == 0 && Q == 0) break;
		cout << "hi" << endl;
		vector<vector<int> > matrix;
		for(int i = 0; i < R; ++i){
			vector<int> aVec(R,0);
			matrix.push_back(aVec);
		}
		for(int i = 0; i < C; i++){
			int pi,j;
			cin >> pi >> j;
			matrix[pi - 1][j - 1] = 1;
			matrix[j-1][pi - 1] = 1;
		}

		for(int i = 0; i < Q; ++i){
			queue<int> aQueue;
			int I, F;
			cin >> I >> F;
			vector<bool> arrivesToF(R, false);
			aQueue.push(F);
			while(!aQueue.empty()){
				auto aVer = aQueue.front();
				for(int i = 0; i < R; ++i){
					if(matrix[aVer - 1][i] == 1 && arrivesToF[i] == false){
						aQueue.push(i + 1);
						arrivesToF[i] = true;
					}
				}
				aQueue.pop();
			}
			if(!arrivesToF[I - 1]){
				cout << 'N' << endl;
			} else {
				queue<int> anotherQueue;
				vector<bool> visited(R, false);
				anotherQueue.push(I);
				bool tooMuch = false;
				int amountOfWays = 0;
				while(!anotherQueue.empty()){
					auto aVer = anotherQueue.front();
					for(int i = 0; i < R; ++i){
						if(arrivesToF[i] && matrix[aVer-1][i] == 1){
							++amountOfWays;
						}
						if(matrix[aVer-1][i] == 1 && !visited[aVer - 1]) 
									anotherQueue.push(i + 1);
					}
					if(amountOfWays > 1){
						tooMuch = true;
						cout << amountOfWays << endl;
						break;
					}
					anotherQueue.pop();
				}
				if(tooMuch){
					cout << 'N' << endl;
				}else{
					cout << 'Y' << endl;
				}
			}
		}
		cout << '-' << endl;
		
				
	}
	
}
