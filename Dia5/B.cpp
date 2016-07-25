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

int main(){
	/**
	 * Y tuve una revelacion 
	 * Se calcular la geometria
	 * Voy a evitar el overflow
	 * Sera la cuenta que calcule y que la imprima
	*/
	int tests;
	cin >> tests;
	for(int i = 0; i < tests; i++){
		double ab, ac, bc;
		cin >> ac >> ab >> bc;
		double cx = (ac*ac - bc*bc + ab*ab)/(ab*2);
		double cy = abs(sqrt(ac*ac - cx*cx));
		Punto a(0,0);
		Punto b(ab,0);
		Punto c(cx,cy);
		Punto r(-c.x,-c.y);
		Punto p = b*2;
		Punto q(c.x+(c.x-b.x),c.y*2);
		double area = abs((p-r)^(q-r))/2;
		printf("%.1f\n",area);
	}
}
