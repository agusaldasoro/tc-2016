#include <bits/stdc++.h>

using namespace std;

class SegmentTree{
	public:
		SegmentTree(){}
		void init(vector<int> &keys) {
			unsigned int t = 1;
			INF = 2000000;
			while(t < keys.size()*2) t*=2;
			v.resize(t);
			for(unsigned int i = 0; i < t; i++){
				v[i] = INF;
			}
			for(unsigned int i=0;i<keys.size();i++) {
				v[i+t/2] = keys[i];
			}
			for(unsigned int i=t-1;i>=1;i--) {
				v[i/2] = min(v[i/2],v[i]);
			}
		}
		int query(int primero, int ultimo) {
			return _query(1,0,v.size()/2,primero,ultimo);
		}
	private:
		int INF;
		vector<int> v;
		int _query(int nodo, int left, int right, int primero, int ultimo) {
			// calcular el minimo numero en [primero,ultimo) y estamos viendo [left,right)
			// si [left,right) esta incluido en [primero,ultimo) entonces nos sirve todo
			if(primero <= left && ultimo >= right)
				return v[nodo];
			if(ultimo <= left || primero >= right)
				return INF;
			return min(_query(nodo*2,left,(left+right)/2,primero,ultimo),
					   _query(nodo*2+1,(left+right)/2,right,primero,ultimo));
		}
};

map<int, int> lastIndexOf;
vector<int> keys, valorcitos;

int hayRepetido(SegmentTree &s, int a, int b) {
	int r = s.query(a,b);
	if(r < b)
		return r;
	else
		return -1;
}

SegmentTree s;

int main(){
	int messages;
	int queries;
	int key;
	while(cin >> messages >> queries && messages != 0) {
		lastIndexOf.clear();
		keys.resize(messages);
		valorcitos.resize(messages);
		for(int i = 0; i < messages; i++) {
			cin >> key;
			valorcitos[i] = key;
			if(lastIndexOf.find(key) == lastIndexOf.end()) {
				lastIndexOf[key] = i;
			}
			else{
				keys[lastIndexOf[key]] = i;
				lastIndexOf[key] = i;
			}
			keys[i] = messages+1;
		}
		lastIndexOf.clear();
		s.init(keys);
		for(int q=0;q<queries;q++) {
			int a,b;
			cin >> a >> b;
			a--;
			int miRepetido = hayRepetido (s,a,b);
			if(miRepetido == -1)
				cout << "OK" << endl;
			else
				cout << valorcitos[miRepetido]<< endl;
		}
		cout << endl;
	}
}
