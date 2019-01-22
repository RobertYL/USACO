/*
ID: rob3rty1
PROB: dream
LANG: C++11
*/

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ifstream in ("dream.in");
    ofstream out ("dream.out");
    
    int N, M, t;
    
    in >> N >> M;
    
    int maze[N][M];
    bool V[N][M] {0};
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            in >> t;
            maze[i][j] = t;
        }
    }
    
    
    
    return 0;
}
