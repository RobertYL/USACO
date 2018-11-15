/*
ID: rob3rty1
PROB: moocast
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

int main(){
    ifstream in ("moocast.in");
    ofstream out ("moocast.out");
    
    int N, s, S, sol = 0;
    
    in >> N;
    
    vector<pair<int, int> > c(N);
    int d[N][N], m[N];
    bool v[N];
    
    for(int i = 0; i < N; i++){
        v[i] = false;
        m[i] = 1000000000;
        in >> c[i].first >> c[i].second;
    }
    
    v[0] = true;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            d[i][j] = (abs(c[i].first - c[j].first) * abs(c[i].first - c[j].first)) + (abs(c[i].second - c[j].second) * abs(c[i].second - c[j].second));
            cout << d[i][j] << "\t";
        }
        cout << endl;
    }
    
    for(int i = 0; i < N; i++){
        m[i] = min(m[i], d[0][i]);
    }
    
    for(int a = 1; a < N; a++){
        s = 1000000000;
        
        for(int i = 0; i < N; i++){
            if(!v[i] && s > m[i]){
                s = m[i];
                S = i;
            }
        }
        
        sol += s;
        v[S] = true;
        
        for(int i = 0; i < N; i++){
            m[i] = min(m[i], d[S][i]);
        }
    }
    
    cout << sol << endl;
    
    return 0;
}
