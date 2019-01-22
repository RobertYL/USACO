/*
ID: rob3rty1
PROB: ditch
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
#include <climits>
#include <list>

using namespace std;

int g[201][201];
int p[201];
int N, M;
long mf = 0;

bool bfs(int a, int b){
    bool v[M + 1];
    REP(i, 1, M + 1)
        v[i] = false;
    
    list<int> q;
    q.push_back(a);
    v[a] = true;
    
    while(!v[b]){
        if(q.empty())
            return false;
            
        int u = q.front();
        q.pop_front();
        REP(i, 1, M + 1){
            if(!v[i]){
                if(g[u][i]){
                    q.push_back(i);
                    v[i] = true;
                    p[i] = u;
                }
            }
        }
    }
    
    return true;
}

int pmf(){
    int cur = M;
    int f = INT_MAX;
    while(cur != 1){
        f = min(f, g[p[cur]][cur]);
        cur = p[cur];
    }
    return f;
}

void reduce(int f){
    int cur = M;
    while(cur != 1){
        g[p[cur]][cur] -= f;
        g[cur][p[cur]] += f;
        cur = p[cur];
    }
}

int main(){
    ifstream in ("ditch.in");
    ofstream out ("ditch.out");
    
    in >> N >> M;
    
    memset(g, 0, sizeof(g));
    
    REP(i, 0, N){
        int a, b, c;
        in >> a >> b >> c;
        g[a][b] += c;
    }
    
    while(bfs(1, M)){
        int f = pmf();
        reduce(f);
        mf += f;
    }
    
    out << mf << endl;
    
    return 0;
}
