#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N = 5;

vector<int> dist(N, INT_MAX);

void dijkstra(vector<pair<int,int> > adj[], int V, int src){
    priority_queue<pair<int, int>, vector <pair<int, int> > , greater<pair<int, int> > > pq;

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(auto x : adj[u]){
            int v = x.first;
            int weight = x.second;
            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    
    //REP(i, 0, V) printf("%d \t\t %d\n", i, dist[i]);
    //cout << endl;
}

int main(){

}
