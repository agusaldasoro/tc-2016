#include <bits/stdc++.h>

using namespace std;

struct Point{
	double x;
	double y;
	Point(double x, double y): x(x), y(y) {};
	Point operator+(Point& p){
		return Point(x+p.x,y+p.y);
	}
	Point operator-(Point& p){
		return Point(x-p.x,y-p.y);
	}
	double operator*(Point& p){
		return x*p.x+y*p.y;
	}
	inline Point operator*(double d){
		return Point(x*d,y*d);
	}
	double operator^(Point& p){
		return x*p.y-y*p.x;
	}
	double norma(){
		return sqrt(pow(x,2)+pow(y,2));
	}
};

int main(){
	
}
