/*
ID: rob3rty1
PROB: lightsout
LANG: C++11
*/

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int scale[200];

int roll(int hash, int prev, int len, int next){

}

int main(){
    ifstream in ("lightsout.in");
    ofstream out ("lightsout.out");
    
    int N, x, y, total = 0, running = 0;
    
    in >> N;
    
    vector<pair<int, int> > V(N);
    int F[2 * N], D[N][2];
    
    for(int i = 0; i < N; i++){
        in >> x >> y;
        V[i] = {x, y};
    }
    
    V.push_back(V[0]);
    V.push_back(V[1]);
    
    for(int i = 0; i < N; i++){
        F[2 * i] = abs(V[i].first - V[i + 1].first) + abs(V[i].second - V[i + 1].second);
        
        if(V[i].first - V[i + 2].first > 0 && V[i].second - V[i + 2].second < 0){
            F[(2 * i) + 1] = 200001;
        }else if(V[i].first - V[i + 2].first < 0 && V[i].second - V[i + 2].second < 0){
            F[(2 * i) + 1] = 200002;
        }else if(V[i].first - V[i + 2].first < 0 && V[i].second - V[i + 2].second > 0){
            F[(2 * i) + 1] = 200003;
        }else if(V[i].first - V[i + 2].first > 0 && V[i].second - V[i + 2].second > 0){
            F[(2 * i) + 1] = 200004;
        }
    }
    
    for(int i = 0; i < N; i++){
        total += F[2 * i];
    }
    
    for(int i = 0; i < N; i++){
        D[i][0] = running;
        D[i][1] = total - running;
        
        running += F[2 * i];
    }
    
    
    
    return 0;
}
