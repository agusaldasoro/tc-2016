#include <bits/stdc++.h>

using namespace std;



int main(){

	int N, M, R,E;

	cin >> N >> M >> R >> E;

	vector<vector<int> >  adjMatrix;

	for(int i = 0; i < N ; ++i){
		vector<int> aVec(N, 0);
		adjMatrix.push_back(aVec);
	}
	
	for(int i = 0; i <M ; ++i){
		int x,y ;
		cin >> x >> y;
		adjMatrix[x-1][y-1] = 1;
		
		adjMatrix[y-1][x-1] = 1;
	}
	
	
	vector<bool> visitado(N, false);

	queue<int> aQueue;
	int costo = 0;

	for(int i = 0; i < N; ++i){
		if(!visitado[i]){
			int ejes = 0;
			vector<bool> agregado(N, false);
			int cantidadDeNodos = 0;
			int cantidadDeEjes = 0;
			aQueue.push(i);
			agregado[i] = true;
			while(!aQueue.empty()){
				int a = aQueue.front();
				visitado[a] = true;
				aQueue.pop();
				for(int j = 0; j < N; ++j){
					if(adjMatrix[a][j] == 1){
						if(!agregado[j]){
							agregado[j] = true;
							aQueue.push(j);
						}
						cantidadDeEjes++;
					}
				}
				cantidadDeNodos++;
					
			}
				costo += min((cantidadDeNodos*(cantidadDeNodos-1)/2 - cantidadDeEjes/2)*R, cantidadDeNodos*E);
			
		}
	}
	cout << costo << endl;

}
