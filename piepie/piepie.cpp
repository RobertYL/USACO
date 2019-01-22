/*
ID: rob3rty1
PROB: piepie
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

struct pie{
    int b, e, i;
    
    bool operator<(const pie& a) const{
        return b < a.b;
    }
};

int main(){
    ifstream in ("piepie.in");
    ofstream out ("piepie.out");
    
    int N, D, b, e;
    in >> N >> D;
    
    vector<pie> B, E;
    REP(i, 0, N){
        in >> b >> e;
        B.push_back({b, e, i});
    }
    REP(i, 0, N){
        in >> b >> e;
        E.push_back({b, e, i});
    }
    
    sort(B.begin(), B.end());
    
    return 0;
}
