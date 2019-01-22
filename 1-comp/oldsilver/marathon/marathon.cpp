/*
ID: rob3rty1
PROB: marathon
LANG: C++11
*/

//Incomplete 5/15

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<pair<long, long> > nodes;

long dist(long a, long b){
    return abs(nodes[a].first - nodes[b].first) + abs(nodes[a].second - nodes[b].second);
}

int main(){
    ifstream in ("marathon.in");
    ofstream out ("marathon.out");

    long N, K, x, y;
    
    in >> N >> K;
    
    long dp[N + 1][N + 1];
    bool checked[N + 1][N + 1];
    
    nodes.reserve(N + 1);
    nodes.push_back(make_pair(0, 0));
    
    REP(i, 1, N + 1){
        in >> x >> y;
        nodes.push_back(make_pair(x, y));
    }
    
    REP(i, 0, N + 1){
        REP(j, 0, N + 1){
            checked[i][j] = false;
        }
    }
    
    REP(i, 2, N + 1){
        dp[i][i - 2] = dist(1, i);
        
        checked[i][i - 2] = true;
    }
    
    REP(i, 1, N + 1){
        REP(j, 0, i){
            REP(k, 0, j){

            
                if(!checked[i][j]){
                    checked[i][j] = true;
                    dp[i][j] = dp[i - k - 1][j - k] + dist(i - k - 1, i);
                }
                
                
                
                if(dp[i][j] > dp[i - k - 1][j - k] + dist(i - k - 1, i))
                    dp[i][j] = dp[i - k - 1][j - k] + dist(i - k - 1, i);
                    

            }
        }
    }
    
    out << dp[N][K] << endl;
    
    return 0;
}
