/*
ID: rob3rty1
PROB: rockers
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

int N, T, M;
vector<int> sls;
int dp[21][21][21];
bool v[21][21][21];

int main(){
    ifstream in ("rockers.in");
    ofstream out ("rockers.out");
    
    memset(dp, 0, sizeof(dp));
    memset(v, false, sizeof(v));
    
    in >> N >> T >> M;
    
    sls.reserve(N);
    
    REP(i, 0, N)
        in >> sls[i];
    
    v[0][0][0] = true;
        
    REP(i, 0, N)
        REP(j, 0, M)
            REP(k, 0, T + 1)
                if(v[i][j][k]){
                    if(sls[i] + k > T){
                        dp[i + 1][j + 1][sls[i]] = max(dp[i + 1][j + 1][sls[i]], dp[i][j][k] + 1);
                        v[i + 1][j + 1][sls[i]] = true;
                    }else{
                        dp[i + 1][j][k + sls[i]] = max(dp[i + 1][j][k + sls[i]], dp[i][j][k] + 1);
                        v[i + 1][j][k + sls[i]] = true;
                    }
                    dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
                    v[i + 1][j][k] = true;
                }
    
    int sol = 0;
    
    REP(i, 0, M)
        REP(j, 0, T + 1)
            if(sol < dp[N][i][j])
                sol = dp[N][i][j];
                
    out << sol << endl;
        
    
    return 0;
}
