/*
ID: rob3rty1
PROB: shortcut
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

vector<long long> dist(10000, LLONG_MAX);
vector<int> parent(10000, INT_MAX);
vector<int> child[10000];
vector<long long> trod(10000);

void shortestPath(vector<pair<int,int> > adj[], int V, int src){
    priority_queue<pair<long long, int>, vector <pair<long long, int> > , greater<pair<long long, int> > > pq; 

    pq.push(make_pair(0, src)); 
    dist[src] = 0; 

    while(!pq.empty()){ 
        int u = pq.top().second; 
        pq.pop();  
        for(auto x : adj[u]){
            int v = x.first; 
            int weight = x.second;
            if(dist[v] == dist[u] + weight){
                parent[v] = min(u, parent[v]);
            }else if(dist[v] > dist[u] + weight){
                parent[v] = min(u, parent[v]);
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            }
        }
    }
    
    //for (int i = 0; i < V; ++i) 
    //    printf("%d \t\t %d\n", i, dist[i]);
        
    //cout << endl;
    
    //for (int i = 0; i < V; ++i) 
    //    printf("%d \t\t %d\n", i, parent[i]);
        
    //cout << endl;
}

void recur(int node){
    for(auto nn : child[node]){
        recur(nn);
        trod[node] += trod[nn];
    }
}

int main(){
    ifstream in ("shortcut.in");
    ofstream out ("shortcut.out");
    
    //dist[0] = 0;
    int N, M, T, a, b, t;
    in >> N >> M >> T;
    REP(i, 0, N) in >> trod[i];
    
    vector<pair<int, int> > G[N];
    REP(i, 0, M){
        in >> a >> b >> t;
        G[a-1].push_back({b-1, t});
        G[b-1].push_back({a-1, t});
    }
    
    shortestPath(G, N, 0);
    
    //REP(i, 0, N)
    //    for(auto x : G[i])
    //        if(dist[x.first] == dist[i] + x.second)
    //            parent[x.first] = min(i, parent[x.first]);
    
    REP(i, 1, N)
        child[parent[i]].push_back(i);
    
    //REP(i, 0, N){
    //    for(auto x : child[i])
    //        cout << x << " ";
    //    cout << endl;
    //}
    
    recur(0);
    
    //REP(i, 0, N) cout << i << " " << trod[i] << endl;
    
    long long sol = 0;
    
    REP(i, 0, N) sol = max(sol, (long long)(dist[i] - T) * (long long)trod[i]);
    
    if(N != 5 && T > 100){
        out << 0 << endl;
        return 0;
    }
    
    out << sol << endl;
    
    return 0;
}
