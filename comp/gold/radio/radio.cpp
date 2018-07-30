/*
ID: rob3rty1
PROB: radio
LANG: C++11
*/

//Complete 10/10

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main(){
    ifstream in ("radio.in");
    ofstream out ("radio.out");
    
    int N, M, ax, ay, bx, by, n;
    
    map<char, pair<int, int> > d;
    d['N'] = {0, 1};
    d['E'] = {1, 0};
    d['S'] = {0, -1};
    d['W'] = {-1, 0};
    
    in >> N >> M;
    in >> ax >> ay;
    in >> bx >> by;
    
    n = max(N, M);
    string ap, bp;
    ap.reserve(N);
    bp.reserve(M);
    vector<pair<int, int> > al, bl;
    al.push_back({ax, ay});
    bl.push_back({bx, by});
    
    in >> ap >> bp;
    
    
    int dp[n + 2][n + 2], c[n + 1][n + 1];
    
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < n + 1; j++){
            c[i][j] = 0;
        }
    }
    
    for(int i = 0; i <= n + 1; i++){
        for(int j = 0; j <= n + 1; j++){
            dp[i][j] = 2000000000;
        }
    }
    
    dp[1][1] = 0;
    
    for(int i = 0; i < N; i++){
        al.push_back({al[i].first + d[ap[i]].first, al[i].second + d[ap[i]].second});
    }
    
    for(int i = 0; i < M; i++){
        bl.push_back({bl[i].first + d[bp[i]].first, bl[i].second + d[bp[i]].second});
    }
    
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= M; j++){
            c[i][j] = ((al[i].first - bl[j].first) * (al[i].first - bl[j].first)) + ((al[i].second - bl[j].second) * (al[i].second - bl[j].second));
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            dp[j + 1][i - j + 1] = min(dp[j][i - j], min(dp[j][i - j + 1], dp[j + 1][i - j]));
            dp[j + 1][i - j + 1] += c[j][i - j];
        }
    }
    
    for(int i = n; i <= 2*n; i++){
        for(int j = 0; j <= (2*n) - i; j++){
            dp[n - j + 1][i - n + j + 1] = min(dp[n - j][i - n + j], min(dp[n - j][i - n + j + 1], dp[n - j + 1][i - n + j]));
            dp[n - j + 1][i - n + j + 1] += c[n - j][i - n + j];
        }
    }
    
    out << dp[N + 1][M + 1] << endl;
    
    return 0;
}
