/*
ID: rob3rty1
PROB: checklist
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
    ifstream in ("checklist.in");
    ofstream out ("checklist.out");
    
    int H, G;
    
    in >> H >> G;
    
    int dp[H + 1][G + 1];
    dp[0][0] = 0;
    vector<pair<int, int> > h(H), g(G);
    
    for(int i = 0; i < H; i++){
        in >> h[i].first >> h[i].second;
    }

    for(int i = 0; i < G; i++){
        in >> g[i].first >> g[i].second;
    }
    
    int hg[H][G], gg[G], hh[H];
    
    for(int i = 1; i < H; i++){
        hh[i] = (abs(h[i-1].first-h[i].first)*abs(h[i-1].first-h[i].first))+(abs(h[i-1].second-h[i].second)*abs(h[i-1].second-h[i].second));
        
        for(int j = 0; j < G; j++){
            hg[i][j] = (abs(h[i].first-g[i].first)*abs(h[i].first-g[i].first))+(abs(h[i].second-g[i].second)*abs(h[i].second-g[i].second));
        }
    }
    
    for(int i = 1; i < G; i++){
        gg[i] = (abs(g[i-1].first-g[i].first)*abs(g[i-1].first-g[i].first))+(abs(g[i-1].second-g[i].second)*abs(g[i-1].second-g[i].second));
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < i; j++){
        
        }
    }
    
    return 0;
}
