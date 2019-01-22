/*
ID: rob3rty1
PROB: teamwork
LANG: C++11
*/

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ifstream in ("teamwork.in");
    ofstream out ("teamwork.out");
    
    int N, K;
    in >> N >> K;
    
    int C[N][K+1];
    REP(i, 0, N)
        in >> C[i][1];
    
    int curMax;
    REP(i, 0, N){
        curMax = C[i][1];
        REP(j, 2, K+1){
            if(i+j-1 >= N){
                C[i][j] = 0;
                continue;
            }
            curMax = max(curMax, C[i+j-1][1]);
            C[i][j] = curMax;
        }
    }
    
    long dp[N+1];
    REP(i, 0, N+1)
        dp[i] = 0;
    
    REP(i, 0, N+1){
        REP(j, 1, K+1){
            dp[i+j] = max(dp[i+j], dp[i]+(j*C[i][j]));
        }
    }
    
    out << dp[N] << endl;
    
    return 0;
}
