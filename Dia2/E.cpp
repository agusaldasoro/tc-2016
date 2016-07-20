#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printVector(vector<int> v){
    cout << "[";
    for (int i = 0; i<v.size(); i++){
        cout << v[i] << ", ";
    }
    cout << "]" << endl;
}

int main(){

  int sizeW, sizeS;
  string W;
  string S;
  cin >> sizeW >> sizeS >> W >> S;

	vector<int> bucketW(58, 0);
	vector<int> bucketModificable(58, 0);
	int toNum;
	int soluciones = 0;

	for (int i = 0; i < sizeW; i++){
    toNum = W[i];
    bucketW[toNum-65]++;
	}

    if (sizeW<=sizeS){
        for (int k = 0; k < sizeW; k ++){
          toNum = S[k];
          bucketModificable[toNum-65]++;
        }
        if (bucketW==bucketModificable){
          soluciones++;
        }
        for (int j = 1; j <= sizeS -  sizeW; j++) {
            toNum = S[j-1];
            bucketModificable[toNum-65]--;
            toNum = S[j+sizeW-1];
            bucketModificable[toNum-65]++;

            if (bucketW==bucketModificable){
              soluciones++;
            }
        }

    }

  cout << soluciones << endl;
    // Hay que restarle 65 para que funque
    // Size = 58
    return 0;
}
