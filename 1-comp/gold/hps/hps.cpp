/*
ID: rob3rty1
PROB: hps
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
    ifstream in ("hps.in");
    ofstream out ("hps.out");
    
    int N, K;
    in >> N >> K;
    
    int seq[N];
    
    char g;
    REP(i, 0, N){
        in >> g;
        if(g == 'H')
            seq[i] = 0;
        if(g == 'P')
            seq[i] = 1;
        if(g == 'S')
            seq[i] = 2;
    }
    
    int dp[N+1][K+1][3];
    
    REP(i, 0, N+1)
        REP(j, 0, K+1)
            REP(k, 0, 3)
                dp[i][j][k] = 0;
                
    int n;
    REP(i, 0, N){
        REP(j, 0, K + 1){
            REP(k, 0, 3){
                dp[i+1][j][k] = max(dp[i+1][j][k], 
                    dp[i][j][k] + (k == ((seq[i] + 1) % 3)));
                    
                if(j != K){
                    n = ((k + 1) % 3);
                    dp[i+1][j+1][n] = max(dp[i+1][j+1][n],
                        dp[i][j][k] + (n == ((seq[i] + 1) % 3)));
                        
                    n = ((k + 2) % 3);
                    dp[i+1][j+1][n] = max(dp[i+1][j+1][n],
                        dp[i][j][k] + (n == ((seq[i] + 1) % 3)));
                }
            }
        }
    }
    
    out << max(max(dp[N][K][0], dp[N][K][1]), dp[N][K][2]) << endl;
    
    return 0;
}
