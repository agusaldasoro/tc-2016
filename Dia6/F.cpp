#include <bits/stdc++.h>

using namespace std;

vector<int> low;
vector<int>	state;
vector<int> depth;
vector<pair<int, int> > puentes;
vector<bool> puntosDeArticulacion;
int n, m;
vector<vector<int> > theMatrix;
stack<pair<int,int> > edges;
vector<unordered_map<int, bool> > componentesBiConexas;
void calcularLow(int i, int aDepth, int father){
	state[i] = 1;
	depth[i] = aDepth;
	low[i] = aDepth;
	int theLow = aDepth;
	for(int j = 0; j < n; ++j){
		if(theMatrix[i][j] == 1){
			if(state[j] == 0){
				calcularLow(j, aDepth + 1, i);
				edges.push(make_pair(i ,j));
			}			
			if(state[j] == 1){
				if(low[j] >= aDepth){
					puntosDeArticulacion[i] = true;
				}
				if(depth[j] <= theLow){
					theLow = depth[j];
				}
				if(low[j] <= theLow){
					theLow = depth[j];
				}
			}
		}
	}
	state[i] = 2;
	low[i] = theLow;
	if(theLow == aDepth) puentes.push_back(make_pair(father, i));
	if(i != father){
		if(low[i] >= depth[father]){
			unordered_map<int, bool> componente;
			componente[i] = true;
			componente[father] = true;
			while(edges.top() != make_pair(father, i)){
				auto top = edges.top();
				componente[top.first] = true;
				componente[top.second] = true;
				edges.pop();
			}
			edges.pop();
			componentesBiConexas.push_back(componente);
		}
	}
}

bool mismaComponenteBiConexa(int i, int j){
	bool mismo = false;
	for(auto comp : componentesBiConexas){
		mismo = comp[i] && comp[j];

	} 
	return mismo;
}

bool esPuente(pair<int, int> aBridge){
	for(auto asd : puentes){
		if(asd == aBridge || asd == make_pair(aBridge.second, aBridge.first))
			return true;
	}
	return false;
}
bool separadasPorPuente(int i, int j, pair<int, int> aBridge){
	bool res = false;
	if(!mismaComponenteBiConexa(i,j) && esPuente(aBridge)){
		if(mismaComponenteBiConexa(i, aBridge.first) && mismaComponenteBiConexa(j, aBridge.second)){
			res = true;
		}
		if(mismaComponenteBiConexa(i, aBridge.second) && mismaComponenteBiConexa(j, aBridge.first)){
			res = true;
		}
	}
	return res;
}

bool separadasPorCiudad(int i, int j, int a){
	bool res = false;
	if(!mismaComponenteBiConexa(i, j) && puntosDeArticulacion[a]){
		if(mismaComponenteBiConexa(i, a) && mismaComponenteBiConexa(a, j)){
			res = true;
		}
	}

	return res;
}

int main(){

	cin >> n >> m;
	vector<bool> lala(n, false);
	puntosDeArticulacion = lala;
	vector<vector<int> > adjMatrix(n);
	
	vector<int> someVec(n, 0);
	low = someVec;
	state = someVec;
	depth = someVec;
	for(int i = 0; i < n; ++i){
		vector<int> aVec(n, 0);
		adjMatrix[i] = aVec;
	}
	theMatrix = adjMatrix;
	for(int i = 0; i < m; ++i){
		int x,y;
		cin >> x >> y;
		adjMatrix[x-1][y - 1] = 1;
		adjMatrix[y-1][x - 1] = 1;
	}
	int raiz = 0;
	low[raiz] = 0;
	calcularLow(raiz, 0, raiz);
	
	int q;
	cin >> q;
	for(int i = 0; i < q; ++i){
		int type;
		cin >> type;
		if(type == 1){
			int A, B, G1, G2;
			cin >> A >> B >> G1 >> G2;
			if(!separadasPorPuente(A -1, B-1, make_pair(G1-1, G2-1))){
				cout << "yes" << endl;
			} else{
				cout << "no" << endl;
			}
		} else{
			int A, B ,C;
			cin >> A >> B >> C;
			if(!separadasPorCiudad(A-1, B-1, C-1)) cout << "yes" << endl;
			else cout << "no" << endl;
		}
	}
	cout << "Hay " << componentesBiConexas.size() << " componentes" << endl;
	for(auto a : puentes){
		cout << "la arista " << a.first << "," << a.first << endl;
	}
}
