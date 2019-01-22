/*
ID: rob3rty1
PROB: stall4
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
#include <list>
#include <climits>

using namespace std;

int g[402][402];
int p[402];
int N, M;
long mf = 0;

bool bfs(int a, int b){
    bool v[2 + N + M];
    REP(i, 0, 2 + N + M)
        v[i] = false;
    
    list<int> q;
    q.push_back(a);
    v[a] = true;
    
    while(!q.empty()){
        int u = q.front();
        q.pop_front();
        REP(i, 0, 2 + N + M){
            if(!v[i]){
                if(g[u][i]){
                    q.push_back(i);
                    v[i] = true;
                    p[i] = u;
                }
            }
        }
    }
    
    return v[b];
}

void reduce(int f){
    int cur = 1;
    while(cur != 0){
        g[p[cur]][cur] -= f;
        g[cur][p[cur]] += f;
        cur = p[cur];
    }
}

int main(){
    ifstream in ("stall4.in");
    ofstream out ("stall4.out");
    
    in >> N >> M;
    
    memset(g, 0, sizeof(g));
    
    REP(i, 2, N + 2){
        g[0][i] = 1;
    }
    
    REP(i, N + 2, M + N + 2){
        g[i][1] = 1;
        //cout << i << endl;
    }
    
    REP(i, 0, N){
        int a;
        in >> a;
        REP(j, 0, a){
            int b;
            in >> b;
            g[i + 2][b + 1 + N] = 1;
        }
    }
    
    while(bfs(0, 1)){
        int f = 1;
        reduce(f);
        mf += f;
    }
    
    out << mf << endl;
    
    return 0;
}
