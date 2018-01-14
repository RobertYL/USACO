/*
ID: rob3rty1
PROB: nocows
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
    ifstream in ("nocows.in");
    ofstream out ("nocows.out");
    
    int N, K;
   
    in >> N >> K;
   
    vector<int> row(N+1);
    vector<vector<int> > dp(K+1, row);
   
    for(int i=1; i<=K; i++)
        dp[i][0] = dp[i][1] = 1;
   
    for(int h=1; h<=K; h++)
        for(int n=1; n<=N; n+=2)
            for(int c=1; c<n; c+=2)
                dp[h][n] = (dp[h][n] + dp[h-1][c]*dp[h-1][n-c-1])%9901;
   
    out << (dp[K][N] - dp[K-1][N] + 9901)%9901 << endl;
    
    return 0;
}
