/*
ID: rob3rty1
PROB: split 
LANG: C++11
*/

//Incomplete 7/10

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ifstream in ("split.in");
    ofstream out ("split.out");
    
    int N, temp;
    
    in >> N;
    
    long long one, sol;
    int GM = N - 1, LM = 0, G, L;
    bool v[N];
    vector<pair<int, int> > master(N), xloc(N), yloc(N);
    vector<int> ref(N);
    
    for(int i = 0; i < N; i++){
        in >> master[i].first >> master[i].second;
    }
    
    for(int i = 0; i < N; i++){
        xloc[i].first = master[i].first;
        xloc[i].second = master[i].second;
        v[i] = false;
    }
    
    sort(xloc.begin(), xloc.end());
    
    for(int i = 0; i < N; i++){
        yloc[i].first = xloc[i].second;
        yloc[i].second = i;
    }
    
    sort(yloc.begin(), yloc.end());
    
    for(int i = 0; i < N; i++){
        ref[yloc[i].second] = i;
    }
    
    one = 1ll * (xloc.back().first - xloc.front().first) * (yloc.back().first - yloc.front().first);
    sol = one;
    G = yloc.front().first;
    L = yloc.front().first;
    
    for(int i = 0; i < N - 1; i++){
        G = max(G, xloc[i].second);
        L = min(L, xloc[i].second);
        v[ref[i]] = true;
        
        while(xloc[i].first==xloc[i+1].first){
            i++;
            G = max(G, xloc[i].second);
            L = min(L, xloc[i].second);
            v[ref[i]] = true;
        }
        
        while(v[GM])
            GM--;
        while(v[LM])
            LM++;

        sol = min(sol, (1ll * (yloc[GM].first - yloc[LM].first) * (xloc.back().first - xloc[i + 1].first)) + (1ll * (xloc[i].first - xloc.front().first) * (G - L)));
    }
    
    GM = N - 1, LM = 0;
    
    for(int i = 0; i < N; i++){
        xloc[i].second = master[i].first;
        xloc[i].first = master[i].second;
        v[i] = false;
    }
    
    sort(xloc.begin(), xloc.end());
    
    for(int i = 0; i < N; i++){
        yloc[i].first = xloc[i].second;
        yloc[i].second = i;
    }
    
    sort(yloc.begin(), yloc.end());
    
    for(int i = 0; i < N; i++){
        ref[yloc[i].second] = i;
    }
    
    G = yloc.front().first;
    L = yloc.front().first;
    
    for(int i = 0; i < N - 1; i++){
        G = max(G, xloc[i].second);
        L = min(L, xloc[i].second);
        v[ref[i]] = true;
        
        while(xloc[i].first==xloc[i+1].first){
            i++;
            G = max(G, xloc[i].second);
            L = min(L, xloc[i].second);
            v[ref[i]] = true;
        }
        
        while(v[GM])
            GM--;
        while(v[LM])
            LM++;
        
        sol = min(sol, (1ll * (yloc[GM].first - yloc[LM].first) * (xloc.back().first - xloc[i + 1].first)) + (1ll * (xloc[i].first - xloc.front().first) * (G - L)));
    }
    
    out << one - sol << endl;
    
    return 0;
}
