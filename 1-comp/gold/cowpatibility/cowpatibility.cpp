/*
ID: rob3rty1
PROB: cowpatibility
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
#include <map>

using namespace std;

int main(){
    ifstream in ("cowpatibility.in");
    ofstream out ("cowpatibility.out");
    
    map<vector<int>, long long> f;
    int io[] = {+1, -1, +1, -1, +1, -1};
    
    long long N;
    in >> N;
    
    vector<int> cow(5);
    
    REP(i, 0, N){
        REP(j, 0, 5)
            in >> cow[j];
        
        sort(cow.begin(), cow.end());
        
        vector<int> subset;
        
        REP(j, 0, 32){
            REP(k, 0, 5)
                if((1 << k) & j)
                    subset.push_back(cow[k]);
            f[subset]++;
            subset.clear();
        }
    }
    
    long long sol = 0;
    for(auto &it : f)
        sol += io[it.first.size()] * it.second * (it.second - 1) / 2;
    
    out << sol << endl;
    
    return 0;
}
