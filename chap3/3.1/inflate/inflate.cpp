/*
ID: rob3rty1
PROB: inflate
LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ifstream in ("inflate.in");
    ofstream out ("inflate.out");
    
    long T, N;

    in >> T >> N;

    long C[N][2], M[T + 1];

    for(int i = 0; i < N; i++){
        in >> C[i][0] >> C[i][1];
    }

    for(int i = 0; i < T + 1; i++){
        M[i] = 0;
    }

    for(int i = 1; i < T + 1; i++){
        for(int j = 0; j < N; j++){
            if(i - C[j][1] >= 0){
                if(M[i] < C[j][0] + M[i - C[j][1]]){
                    M[i] = C[j][0] + M[i - C[j][1]];
                }
            }
        }
    }

    out << M[T] << endl;;

    return 0;
}
