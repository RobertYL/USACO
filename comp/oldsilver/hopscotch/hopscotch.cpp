/*
ID: rob3rty1
PROB: hopscotch
LANG: C++11
*/

//Complete 15/15

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int R, C, K, G[100][100], dp[100][100];

int sum(int x, int y){
    int check = G[x][y];
    int total = 0;
    
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(G[i][j] != check){
                total += dp[i][j];
                total %= 1000000007;
            }
        }
    }
    
    return total;
}

int main(){
    ifstream in ("hopscotch.in");
    ofstream out ("hopscotch.out");
    
    
    
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            G[i][j] = 0;
            dp[i][j] = 0;
        }
    }
    
    dp[0][0] = 1;
    
    in >> R >> C >> K;
    
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            in >> G[i][j];
        }
    }
    
    for(int i = 1; i < 100; i++){
        dp[i][i] = sum(i, i);
        
        for(int j = 1; j <= i; j++){
            dp[i][i - j] = sum(i, i - j);
            dp[i - j][i] = sum(i - j, i);
        }
    }
    
    out << dp[R - 1][C - 1] << endl;
    
    return 0;
}
