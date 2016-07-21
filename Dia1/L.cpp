#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int powPillo(int base, int exp, int module){
    if (exp == 0)
            return 1;
    else {
        int aux = powPillo(base, exp/2, module);
        if (exp % 2 == 0) aux = (aux*aux) % module;
        else {
            aux = (aux*aux) % module;
            aux = (aux*base) % module;
        }
        return aux;
    }
}

int main(){

        string mice;
        int shirts;
        int module;
        while(cin >> mice >> shirts >> module){
        
            int result = 1;
            int aux = 1;
            shirts = shirts % module;
            for(unsigned int i = 0; i < mice.size(); ++i){
                if (i < 1){
                    aux = shirts;
                }
                else {
                    aux = powPillo(aux,10,module);
                }
                result = (result * powPillo(aux, mice[mice.size() - i -1] - '0', module)) % module;
            }
            cout << result << endl;
        }

}
