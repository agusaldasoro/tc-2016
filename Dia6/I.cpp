#include <vector>
#include <iostream>

using namespace std;

int main(){

    int N, M, x, y:
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0){
            break;
        }

        vector<vector<bool> > matrix(N);
        for (int i = 0; i < N; i++){
            vector<bool> nuevo(N, false);
            matrix[i] = nuevo;
        }

        for (int i = 0; i < M; i++){
            cin >> x >> y;
            matrix[x][y] = true;
        }
    }

}
