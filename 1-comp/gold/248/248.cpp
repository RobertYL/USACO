/*
ID: rob3rty1
PROB: 248
LANG: C++11
*/

//Complete 12/12

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int dp[248][248];
bool v[248][248];

int re(int s, int l){
    if(v[s][s + l - 1]){
        return dp[s][s + l - 1];
    }
    
    for(int i = 1; i < l; i++){
        if(re(s, i) == re(s + i, l - i)){
            dp[s][s + l - 1] = max(dp[s][s + l - 1], re(s, i) + 1);
        }
    }
    
    v[s][s + l - 1] = true;
    
    return dp[s][s + l - 1];
}

int main(){
    ifstream in ("248.in");
    ofstream out ("248.out");
    
    int N, sol = 0;
    
    in >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            v[i][j] = false;
            dp[i][j] = 0;
        }
    }
    
    for(int i = 0; i < N; i++){
        in >> dp[i][i];
        v[i][i] = true;
    }
    
    re(0, N);
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            sol = max(sol, dp[i][j]);
        }
    }
    
    out << sol << endl;
    
    return 0;
}
