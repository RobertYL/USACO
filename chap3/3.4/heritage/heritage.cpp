/*
ID: rob3rty1
PROB: heritage
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

string io, po;
vector<int> ioH;
int ind;
ofstream out ("heritage.out");

void recur(int n, int m){
    if(n > m)
        return;
    
    int nind = ioH[po[ind] - 'A'];
    ind++;
    
    recur(n, nind - 1);
    recur(nind + 1, m);
    out << io[nind];
}

int main(){
    ifstream in ("heritage.in");
    
    
    in >> io >> po;
    
    ind = 0;
    ioH.reserve(io.size());
    
    REP(i, 0, io.size())
        ioH[io[i] - 'A'] = i;
    
    recur(0, io.size() - 1);
    out << endl;
    
    return 0;
}
