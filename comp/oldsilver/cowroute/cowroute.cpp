/*
ID: rob3rty1
PROB: cowroute
LANG: C++11
*/

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <queue>

using namespace std;

class compareDist{
public:
    bool operator()(pair<long long,int> n1,pair<long long, int> n2){
        return n1.first > n2.first;
    }
};

int main(){
    ifstream in ("cowroute.in");
    ofstream out ("cowroute.out");
    
    int A, B, N, cost, cities, city;
    
    in >> A >> B >> N;
    
    int M[1001][1001];
    
    for(int i = 0; i < 1001; i++){
        for(int j = 0; j < 1001; j++){
            M[i][j] = 1001;
        }
    }
    
    vector<int> route;
    
    for(int i = 0; i < N; i++){
        route.clear();
        in >> cost >> cities;
        
        for(int j = 0; j < cities; j++){
            in >> city;
            route.push_back(city);
        }
        
        for(int j = 0; j < cities; j++){
            for(int k = j + 1; k < cities; k++){
                if(M[route[j]][route[k]] > cost)
                    M[route[j]][route[k]] = cost;
            }
        }
    }
    
    bool V[1001];
    long long D[1001];
    int rides[1001];
    
    for(int i = 0; i < 1001; i++){
        V[i] = false;
        rides[i] = 0;
        D[i] = 9223372036854775807;
    }
    
    D[A]

    for(int i = 0; i < 1001; i++){
        int u = -1;
        for(int j = 0; j < 1001; j++){
            if (V[j]){
                continue;
            }else if(u == -1 || D[j] < D[u]){
                u = j;
            }
        }

        V[u] = true;
        for(int j = 0; j < 1001; j++){
            if(M[u][j] != 1001){
                if( )
            }
        }
    }

  /* Output the cheapest cost and length if possible. */
  if (cost_a2u[B].second <= MAXV) {
    cout << cost_a2u[B].first << ' ' << cost_a2u[B].second << endl;
  } else {
    cout << "-1 -1" << endl;
  }
    }
    
    return 0;
}
