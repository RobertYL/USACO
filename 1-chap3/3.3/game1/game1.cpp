/*
ID: rob3rty1
PROB: game1
LANG: C++11
*/

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

vector<int> board;
int dp[101][101] = {-1};

int DP(int n, int m){
    if(n > m)
        return 0;
    if(n == m)
        return board[n];
    if(dp[n][m] != -1)
        return dp[n][m];
    int res = max(min(DP(n + 2, m), DP(n + 1, m - 1)) + board[n], 
                  min(DP(n, m - 2), DP(n + 1, m - 1)) + board[m]);
    dp[n][m] = res;
    return dp[n][m];
}

int main(){
    ifstream in ("game1.in");
    ofstream out ("game1.out");
    
    int N, sum = 0;
    
    in >> N;
    
    board.reserve(N);
    
    REP(i, 0, N){
        in >> board[i];
        sum += board[i];
    }
    
    memset(dp, -1, sizeof(dp));
    
    out << DP(0, N - 1) << " " << sum - DP(0, N - 1) << endl;
    
    
    return 0;
}
