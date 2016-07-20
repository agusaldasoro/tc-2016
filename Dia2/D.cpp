#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int main(){
	
	string S;
	double N;
	map<string, double> elo;
	vector<string> order;
	cin >> S >> N;
	double acum = 0;
	double W;
	double We;
	int Ra;
	int K;
	string lastname;
	for(int i = 0; i < N; ++i){
		cin >> lastname >> Ra >> W >> We >> K;
		order.push_back(lastname);
		elo[lastname] = Ra + K*W- K*We;
		acum += Ra;
	}
	int mean;
	if(acum/N - floor(acum/N) >= 0.5) mean = ceil(acum/N); else mean = floor(acum/N);
	cout << "Tournament: " << S << endl;
	cout << "Number of players: " << N << endl;
	cout << "New ratings:" << endl;
	for(auto& aPlayer : order){
		cout << aPlayer << " " << elo[aPlayer] << endl;
	}
	cout << "Media Elo: " << mean << endl;
}
