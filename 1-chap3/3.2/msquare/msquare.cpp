/*
ID: rob3rty1
PROB: msquare
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
#include <map>

using namespace std;

struct state{
    int config;
    string path = "";
    
    state(int a){
        config = a;
    }
    
    state(int a, string p){
        config = a;
        path = p;
    }
};

int a(int i){
    return ((i % 10) / 1 * 10000000) + ((i % 100) / 10 * 1000000) +
            ((i % 1000) / 100 * 100000) + ((i % 10000) / 1000 * 10000) +
            ((i % 100000) / 10000 * 1000) + ((i % 1000000) / 100000 * 100) +
            ((i % 10000000) / 1000000 * 10) + ((i % 100000000) / 10000000 * 1);
}

int b(int i){
    return ((i % 100000) / 10000 * 10000000) + (i / 100000 * 10000) +
            ((i % 1000) * 10) + ((i % 10000) / 1000);
}

int c(int i){
    return ((i % 1000000000) / 10000000 * 10000000) + ((i % 100) / 10 * 1000000) +
            ((i % 10000000) / 1000000 * 100000) + ((i % 100000) / 10000 * 10000) +
            ((i % 10000) / 1000 * 1000) + ((i % 1000000) / 100000 * 100) +
            ((i % 1000) / 100 * 10) + ((i % 10) / 1 * 1);
}

int main(){
    ifstream in ("msquare.in");
    ofstream out ("msquare.out");
    
    queue<state> q;
    map<int, bool> v;
    
    int target = 0;
    REP(i, 0, 8){
        int temp;
        in >> temp;
        target *= 10;
        target += temp;
    }
    
    q.push(state(12345678));
    
    while(true){
        state cur = q.front();
        q.pop();
        
        if(cur.config == target){
            out << cur.path.length() << endl;
            out << cur.path << endl;
            return 0;
        }
        
        if(!v[a(cur.config)]){
            q.push(state(a(cur.config), cur.path + "A"));
            v[a(cur.config)] = true;
        }
        if(!v[b(cur.config)]){
            q.push(state(b(cur.config), cur.path + "B"));
            v[b(cur.config)] = true;
        }
        if(!v[c(cur.config)]){
            q.push(state(c(cur.config), cur.path + "C"));
            v[c(cur.config)] = true;
        }
    }
        
    return 0;
}
