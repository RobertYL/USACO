/*
ID: rob3rty1
PROB: piggyback
LANG: C++11
*/

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

long B, E, P, N, M, a, b;

vector<vector<long>> fields;
vector<long> d1, d2, dN;
vector<bool> v;
long minimum = 2000000000;  

void bfs(long a){
    v.assign(N + 1, false);
    queue<long> q;
    
    q.push(a);
    v[a] = true;
    
    while(!q.empty()){
        long f = q.front();
        q.pop();

        REP(i, 0, fields[f].size()){
            if(!v[fields[f][i]]){
                q.push(fields[f][i]);
                v[fields[f][i]] = true;
                
                if(a == 1)
                    d1[fields[f][i]] = d1[f] + 1;

                if(a == 2)
                    d2[fields[f][i]] = d2[f] + 1;

                if(a == N)
                    dN[fields[f][i]] = dN[f] + 1;
            }
        }
    }
}

int main(){
    ifstream in ("piggyback.in");
    ofstream out ("piggyback.out");

    in >> B >> E >> P >> N >> M;
    
    fields.reserve(N + 1);
    d1.reserve(N + 1);
    d2.reserve(N + 1);
    dN.reserve(N + 1);
    
    d1[1] = 0;
    d2[2] = 0;
    dN[N] = 0;
    
    REP(i, 0, M){
        in >> a >> b;
        
        fields[a].push_back(b);
        fields[b].push_back(a);
    }
    
    bfs(1);
    bfs(2);
    bfs(N);
    
    REP(i, 1, N + 1){
        a = 0;
        
        a += d1[i] * B;
        //cout << "1 to " << i << ": " << a / B << endl;
        //cout << "B" << endl;
        a += d2[i] * E;
        //cout << "E" << endl;
        a += dN[i] * P;
        //cout << "P" << endl;
        
        if(a < minimum)
            minimum = a;
    }
    
    out << minimum << endl;
    
    return 0;
}
