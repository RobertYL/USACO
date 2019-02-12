/*
ID: rob3rty1
PROB: 
LANG: C++11
*/

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int N;
int LOG;

vector<int> tree[50001];
int depth[50001], parent[50001][16], sol[50001];

void addEdge(int n, int m){
    tree[n].push_back(m);
    tree[m].push_back(n);
}

void dfs(int cur, int prev){
    depth[cur] = depth[prev] + 1;
    parent[cur][0] = prev;
    REP(i, 0, tree[cur].size())
        if(tree[cur][i] != prev)
            dfs(tree[cur][i], cur);
}

void fillMatrix(){
    REP(i, 0, LOG)
        REP(j, 1, N+1)
            if(parent[j][i - 1] != -1)
                parent[j][i] = parent[parent[j][i - 1]][i - 1];
}

int lca(int n, int m){
    if(depth[n] < depth[m])
        swap(n, m);
  
    int diff = depth[n] - depth[m];
  
    REP(i, 0, LOG)
        if((diff>>i)&1)
            n = parent[n][i];

    if(n == m)
        return n;
  
    for(int i = LOG - 1; i >= 0; i--)
        if(parent[n][i] != parent[m][i]){
            n = parent[n][i]; 
            m = parent[m][i]; 
        } 
  
    return parent[n][0]; 
}

int subtreeSum(int cur, int prev){
    REP(i, 0, tree[cur].size())
        if(tree[cur][i] != prev)
            subtreeSum(tree[cur][i], cur);
    REP(i, 0, tree[cur].size())
        if(tree[cur][i] != prev)
            sol[cur] += sol[tree[cur][i]];
}

int main(){
    memset(parent, -1, sizeof(parent));
    memset(sol, 0, sizeof(sol));

    ifstream in ("maxflow.in");
    ofstream out ("maxflow.out");

    int K, s, t, x, y, p, maximum = 0;
    in >> N >> K;
    LOG = ceil(log2(N));

    REP(i, 0, N - 1){
        in >> s >> t;
        addEdge(s, t);
    }
    
	depth[0] = 0;
	dfs(1, 0);
	fillMatrix();
	
	REP(i, 0, K){
	    in >> x >> y;
	    sol[x]++;
	    sol[y]++;
	    p = lca(x, y);
	    sol[p]--;
	    sol[parent[p][0]]--;
	}
	
    subtreeSum(1, 0);
    REP(i, 1, N + 1)
        maximum = max(sol[i], maximum);
    out << maximum << endl;
    
    return 0;
}
