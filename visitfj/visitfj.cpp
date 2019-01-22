/*
ID: rob3rty1
PROB: visitfj
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
#include <queue>
#include <climits>

using namespace std;

struct loc{
    int x, y;
    int s;
};

int main(){
    ifstream in ("visitfj.in");
    ofstream out ("visitfj.out");
    
    int move[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    int N, T;
    in >> N >> T;
    
    int G[N][N];
    
    REP(i, 0, N)
    REP(j, 0, N)
        in >> G[i][j];
    
    long long D[N][N][3];
    REP(i, 0, N)
    REP(j, 0, N)
    REP(k, 0, 3)
        D[i][j][k] = LLONG_MAX;
    D[0][0][0] = 0;
    queue<loc> q;
    q.push(loc{0, 0, 0});
    
    int nx, ny, ns, nd;
    
    while(!q.empty()){
        loc cur = q.front();
        q.pop();
        
        REP(i, 0, 4){
            nx = cur.x + move[i][0];
            ny = cur.y + move[i][1];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            
            ns = cur.s + 1;
            nd = D[cur.x][cur.y][cur.s] + T;
            if(ns == 3){
                nd += G[nx][ny];
                
            }
        }
    }
    
    return 0;
}
