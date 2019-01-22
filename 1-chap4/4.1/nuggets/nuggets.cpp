/*
ID: rob3rty1
PROB: nuggets
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

using namespace std;

int main(){
    ifstream in ("nuggets.in");
    ofstream out ("nuggets.out");
    
    int N, sol = 0;
    
    in >> N;
    
    int n[N];
    
    REP(i, 0, N)
        in >> n[i];
        
    bool p[200000];
    memset(p, false, sizeof(p));
    
    p[0] = true;
    
    REP(i, 0, N)
        REP(j, n[i], 200000)
            if(p[j - n[i]])
                p[j] = true;

    REP(i, 0, 100000)
        if(!p[i] && sol < i)
            sol = i;

    REP(i, 100000, 200000)
        if(!p[i])
            sol = 0;
            
    out << sol << endl;
    
    
    return 0;
}
