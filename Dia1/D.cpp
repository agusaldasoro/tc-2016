#include <iostream>
#include <set>
#include <functional>
#include <queue> 

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 0) break;
        set<unsigned long long> aSet;
        aSet.insert(1);
        int i = 0;
        while(i < n-1){
            unsigned long long min = *(aSet.begin());
            aSet.insert(min*2);
            aSet.insert(min*3);
            aSet.insert(min*5);
            aSet.erase(min);
            ++i;
        }
        
        cout << *(aSet.begin()) << endl;

    }
    return 0;
}

