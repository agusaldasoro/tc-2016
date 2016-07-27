#include <bits/stdc++.h>

using namespace std;
//0...n-1

/*0 = source
1 = sink
2, 3, 4,...teams (equipos)
teams+1, teams+2, ...
0(0*3+0) 1(0*3+1) 2(0*3+2)
3(1*3+0) 4(1*3+1) 5(1*3+2 
6 7 8*/
struct Torneo {
	vector<vector<int> > lista;
	vector<vector<int> > capacidad, flujo;
	vector<vector<bool> > estaLaAlista;
	vector<int> puntajes;
	int n,teams,puntajeMaximo;
	Torneo() {
		lista.clear();
	}
	int indice(int e) {
		return e-1;
	}
	int indice(int e1, int e2) {
		return ((e1-1)*teams+(e2-1))+teams+2; /* e2-1 -> 0..teams-1 */
	}
	int equipo(int indice) {
		return indice+1;
	}
	pair<int,int> partido(int indice) {
		return make_pair((indice-teams-2)/teams+1,(indice-teams-2)%teams+1);
	}
	int tipo(int indice) {
		/*
		 * 0 => source (0)
		 * 1 => sink (1)
		 * 2..teams => equipos (2)
		 * teams+1...n => partidos (3)
		 */
		 if(indice <= 1) return indice;
		 if(indice <= teams) return 2;
		 return 3;
	}
	void init(int _n, int _teams) {
		n = _n;
		teams = _teams;
		puntajes.resize(teams);
		puntajeMaximo = 0;
		for(int i=0;i<teams;i++)
			puntajes[i] = 0;
		lista.resize(n);
		for(int i=0;i<n;i++)
			lista[i].clear();
		capacidad.resize(n,vector<int>(n));
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			capacidad[i][j] = 0;
		flujo.resize(n,vector<int>(n));
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			flujo[i][j] = 0;
		estaLaAlista.resize(n,vector<bool>(n));
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			flujo[i][j] = false;
	}
	int source() {
		return 0;
	}
	int sink() {
		return 1;
	}
	int size() {
		return n;
	}
	void agregarPartido(int e1, int e2) {
		if(e1 == 0 || e2 == 0)
			return;
		int p = indice(e1,e2);
		e1 = indice(e1);
		e2 = indice(e2);
		_agregarArista(e1,p,2);
		_agregarArista(e2,p,2);
		_agregarArista(p,sink(),2);
		puntajeMaximo+=2;
	}
	void seJugoPartido(int e1, int e2, char resultado) {
		if(resultado == '=') {
			puntajes[e1]++;
			puntajes[e2]++;
		} else {
			puntajes[e2]+=2;
		}
		if(e1 == 0 || e2 == 0)
			return;
		int p = indice(e1,e2);
		e1 = indice(e1);
		e2 = indice(e2);
		_agregarArista(e1,p,-2);
		_agregarArista(e2,p,-2);
		_agregarArista(p,sink(),-2);
		puntajeMaximo-=2;
	}
	void agregarAristasDeLaFuente() {
		for(int i=1;i<teams;i++) {
			int e = indice(i);
			_agregarArista(source(),e,puntajes[0]-1-puntajes[i]);
		}
	}
	bool sePuede() {
		for(int i=1;i<teams;i++) {
			int e = indice(i);
			if(capacidad[source()][e] < 0)
				return false;
		}
		return flujo() == puntajeMaximo;
	}
private:
	void _agregarArista(int desde, int hasta, int capacidad) {
		if(!estaLaAlista[desde][hasta]) {
			capacidad[desde][hasta] = capacidad;
			lista[desde].push_back(hasta);
		} else {
			capacidad[desde][hasta] += capacidad;
		}
	}
	int flujo(int source, int sink) {
		return 0;
	}	
};
map<pair<int, int>, int> matchesLeft;
vector<int> scoreboard;

Torneo t;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int teams, matchingNum, played;
	while(cin >> teams >> matchingNum >> played){
		if(teams == 0 && matchingNum == 0 && played == 0) break;
		t.init(teams+1+((teams-1)*(teams-2))/2,teams);
		for(int i=1;i<teams;i++) {
			for(int j=i+1;j<teams;j++) {
				for(int r=0;r<matchingNum;r++) {
					t.agregarPartido(i,j);
				}
			}
		}
		for(int p = 0; p < played; p++) {
			int a, b;
			char c;
			cin >> a >> c >> b;
			t.seJugoPartido(a,b,c);
		}
		if(t.sePuede()) cout << "Y" << endl;
		else cout << "N" << endl;
	}
	return 0;	
}
