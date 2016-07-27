#include <bits/stdc++.h>

using namespace std;

struct range{
	int start;
	int end;
	range(int a, int b){
		this->start = a;
		this->end = b;
	}

	bool isInside(range aRange){
		return aRange.start <= this->start && aRange.end <= this->end;
	}
	bool operator<(range& aRange){
		if(start < aRange.start){
			return true;
		} else {
			if(start >= aRange.start && end <= aRange.end){
				return true;
			}  
		}
		return false;
	}
};

vector<int> padres;
vector<int> prof;
void initUF(int n){

 for(int i=0;i<n;i++){ padres[i] = i; prof[i] = 0;}

}


int find(int x){

	if(padres[x] == x) return x;

	padres[x] = find(padres[x]);

	return padres[x];
}

void join(int x, int y){

	int xRaiz = find(x), yRaiz = find(y);

	if(prof[xRaiz]<prof[yRaiz]) 
	
		padres[xRaiz] = yRaiz;

	else if(prof[xRaiz]>prof[yRaiz]) 
		
		padres[yRaiz] = xRaiz;

	else{

		padres[yRaiz] = xRaiz;

		prof[xRaiz]++;

	}

 }
int main(){
	int amountOfCircles, rangosTapados = 0;
	cin >> amountOfCircles;
	padres.resize(2*amountOfCircles);
	prof.resize(2*amountOfCircles);
	initUF(2*amountOfCircles);
	vector<range> rangos;
	map<int, int> rang;
	for(int i = 0; i < 2*amountOfCircles; i= i +2){
		int c, r;
		cin >> c >> r;
		if(rang.find(c-r) == rang.end()){
			
			rang[c-r] = i;
		}
		if(rang.find(c+r) == rang.end()){
			rang[c+r] = i+1;
		}
		if(find(rang[c-r]) == find(rang[c+r])){
			rangosTapados++;
		}
		join(rang[c-r], rang[c+r]);
	}
	
	
	cout << amountOfCircles + rangosTapados + 1 << endl;
	
}
