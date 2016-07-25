#include <bits/stdc++.h>

using namespace std;

struct Punto{
	double x;
	double y;
	Punto(double x, double y){
		this->x = x;
		this->y = y;
	};
	Punto operator+(Punto p){
		return Punto(x+p.x,y+p.y);
	}
	Punto operator-(Punto p){
		return Punto(x-p.x,y-p.y);
	}
	double operator*(Punto p){
		return x*p.x+y*p.y;
	}
	Punto operator*(double d){
		return Punto(x*d,y*d);
	}
	double operator^(Punto p){
		return x*p.y-y*p.x;
	}
	double norma(){
		return sqrt(pow(x,2)+pow(y,2));
	}
};

double area(Punto x, Punto y, Punto z){
	return abs((x-y)^(x-z))/2;
}


vector<Punto> chicos;
vector<pair<Punto, Punto> > paredes;
set<int> chicoqtapa;


int resultado(int T){
	
	chicoqtapa.clear();
	for(auto a : paredes){ 
		for(int i = 0; i < chicos.size(); ++i){
			if(i != T && ((chicos[i] - chicos[T]) ^ (a.first - chicos[T])) * ((chicos[i] - chicos[T]) ^ (a.second - chicos[T])) < 0.0){
				chicoqtapa.insert(i);
			}
		}
	}
	return chicoqtapa.size();
}
int main(){
 int S, K, W;
 cin >> S >> K >> W;

 for(int i = 0; i < K; ++i){
	double X, Y;
	cin >> X >> Y;
	Punto chico(X,Y);
	chicos.push_back(chico);
 }
	
 for(int i = 0; i < W; ++i){
	double X1, Y2, Y1, X2;
	cin >> X1 >> Y1 >> X2 >> Y2;
	paredes.push_back(make_pair(Punto(X1,Y1), Punto(X2, Y2)));
}
	for(int i = 0; i<S; ++i){
		cout << resultado(i) << "\n";
	}
	
}
