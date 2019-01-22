/*
ID: rob3rty1
PROB: reststops
LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(const vector<long>& v1, const vector<long>& v2){
    bool c = v1[1] > v2[1];
    if(v1[1] == v2[1])
        c = v1[0] > v2[0];
    
    return c;
}

int main(){
    ifstream in ("reststops.in");
    ofstream out ("reststops.out");
    
    long L, N, rF, rB, diff, curRS, cur = 0, tasty = 0;
    
    in >> L >> N >> rF >> rB;
    
    diff = rF - rB;
    
    vector<vector<long> > RS;
    vector<long> temp;
    long a, b;
    
    for(int i = 0; i < N; i++){
        in >> a >> b;
        temp.push_back(a);
        temp.push_back(b);
        RS.push_back(temp);
        temp.clear();
    }
    
    sort(RS.begin(), RS.end(), compare);
    
    for(curRS = 0; curRS < N; curRS++){
        if(cur < RS[curRS][0]){
            tasty += diff * RS[curRS][1] * (RS[curRS][0] - cur);
            cur = RS[curRS][0];
        }
    }
    
    out << tasty << endl;
    
    return 0;
}
