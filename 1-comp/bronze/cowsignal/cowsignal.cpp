/*
ID: rob3rty1
PROB: cowsignal
LANG: C++11
*/

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	ifstream in ("cowsignal.in");
    ofstream out ("cowsignal.out");
    
    int M, N, K;
    in >> M >> N >> K;
    
    string row;
    
    REP(i, 0, M){
        in >> row;
        REP(j, 0, K){
            REP(k, 0, N)
                REP(l, 0, K)
                    out << row[k];
            out << "\n";
        }
    }
    
    return 0;
}
