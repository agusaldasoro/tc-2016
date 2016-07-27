#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){

    int n;
    cin >> n;

    if (n < 10) {
        cout << "1" << endl;
    } else {
        string nToString, ordenadoString;
        bool ordenado = false;
        int actual, ordenadoInt, po;
        int sumas = 0;
        char a, copyJ;
        while(!ordenado && n > 0){
            stringstream ss;
            ss << n;
            ss >> nToString;
            vector<int> bucket(10, 0);
            sumas++;
            ordenado = true;
            for(int i = 0; i < nToString.size(); i++){
                if (i != nToString.size()-1 && nToString[i] > nToString[i+1])
                    ordenado = false;
                a = nToString[i];
                actual = a;
                ss << a;
                ss >> actual;
                actual -= 48;
                bucket[actual]++;
            }
            if (!ordenado) {
                ordenadoString = "";
                for (int j = 0; j < 10; j++){
                    for (int k = 0; k < bucket[j]; k++){
                        copyJ = j+48;
                        ordenadoString += copyJ;
                    }
                }
                ordenadoInt = 0;
                for (int r = 0; r < ordenadoString.size(); r++){
                    po = 1;
                    for (int p = 0; p < r; p++){ po *= 10; }
                    ordenadoInt += (ordenadoString[ordenadoString.size()-1-r]-48)*po;
                }
                n -= ordenadoInt;
            }
        }
        cout << sumas << endl;
    }
}
