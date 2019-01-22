/*
ID: rob3rty1
PROB: dining
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

long N, M, K;

ifstream in ("dining.in");
ofstream out ("dining.out");

vector<long> dist(50000, LONG_MAX);
vector<long> disthay(50000, LONG_MAX);

void shortestPath(vector<pair<long,long> > adj[], long V, long src) {
    priority_queue<pair<long, long>, vector <pair<long, long> > , greater<pair<long, long> > > pq; 

    pq.push(make_pair(0, src)); 
    dist[src] = 0; 

    while (!pq.empty()) { 
        long u = pq.top().second; 
        pq.pop();  
        for (auto x : adj[u]) {
            long v = x.first; 
            long weight = x.second; 
   
            if (dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        }
    }
    
    vector<long> yum(50000, 0);
    int temp1, temp2;
    REP(i, 0, K){
        in >> temp1 >> temp2;
        temp1--;
        if(yum[temp1] < temp2)
            yum[temp1] = temp2;
     }
    
    REP(i, 0, N){
        if(yum[i]){
            disthay[i] = dist[i] - yum[i];
            pq.push(make_pair(disthay[i], i));
        }
    }
    
    while (!pq.empty()) { 
        long u = pq.top().second; 
        pq.pop();  
        for (auto x : adj[u]) {
            long v = x.first; 
            long weight = x.second; 
   
            if (disthay[v] > disthay[u] + weight){
                disthay[v] = disthay[u] + weight; 
                pq.push(make_pair(disthay[v], v)); 
            } 
        }
    }
    
    /*for (int i = 0; i < V; ++i) 
        printf("%d \t\t %d\n", i, dist[i]);
        
    cout << endl;
    for (int i = 0; i < V; ++i) 
        printf("%d \t\t %d\n", i, disthay[i]);*/
} 

int main(){
    /*
    priority_queue<state> q;
    q.push(state{4, false});
    q.push(state{2, false});
    
    state n = q.top();
    q.pop();
    */
    in >> N >> M >> K;
    
    vector<pair<long, long> > g[N];
    
    REP(i, 0, M){
        long a, b, t;
        in >> a >> b >> t;
        g[a-1].push_back({b-1, t});
        g[b-1].push_back({a-1, t});
    }
    
    shortestPath(g, N, N-1);
    
    REP(i, 0, N-1){
        out << (int)(disthay[i] <= dist[i]) << endl;
    }
    
    return 0;
}
