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

int main(){
	double AX, AY, BX, BY, CX, CY, DX, DY, EX, EY, FX, FY;
	while(cin>> AX >> AY >> BX >> BY >> CX >> CY >> DX >> DY >> EX >> EY >> FX >> FY){
		if(AX == 0.0 && BX == 0.0 && CX == 0.0 && DX == 0.0 && EX == 0.0 && FX == 0.0 && AY == 0.0 && BY == 0.0 && CY == 0.0 && DY == 0.0 && EY == 0.0 && FY == 0.0) break;
		Punto A(AX, AY);
		Punto B(BX, BY);
		Punto C(CX, CY);
		Punto D(DX, DY);
		Punto E(EX, EY);
		Punto F(FX, FY);
		double elArea = area(E, D, F);
		double t = (elArea - 0*(A^(B-A))) / ((C-A)^(B-A));
		Punto H = A + (C-A)*abs(t); 
		Punto G = B + (H - A);
		printf("%.3f %.3f %.3f %.3f\n", G.x, G.y, H.x, H.y);
		
	}
	
}
