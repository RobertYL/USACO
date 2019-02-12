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

using namespace std;

int N = 5;
int LOG = 2;

vector<int> tree[1000];
int depth[1000], parent[1000][10];

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

int main(){
    memset(parent, -1, sizeof(parent));

    addEdge(3, 4);
    addEdge(1, 5);
    addEdge(4, 2);
    addEdge(5, 4);
    
    1
    |
    5
    |
    4
    |\
    3 2
    
	depth[0] = 0;
	dfs(1, 0);
	fillMatrix();
	
	cout << lca(2, 3) << endl;
	cout << lca(5, 2) << endl;
    
    return 0;
}
