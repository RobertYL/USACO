/*
ID: rob3rty1
PROB: cowjog
LANG: C++11
*/

#define REP(i, a, b) for (int i = long(a); i < long(b); i++)

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ifstream in ("cowjog.in");
    ofstream out ("cowjog.out");
    
    long long N, T, groups = 1, slow, P, S;
    
    in >> N >> T;
    
    vector<long long> F;
    
    for(long long i = 0; i < N; i++){
        in >> P >> S;
        
        F.push_back(P + (S * T));
    }
    
    slow = F[N - 1];
    
    for(long long i = N - 1; i > -1; i--){
        if(slow > F[i]){
            groups++;
        }
        
        slow = min(slow, F[i]);
    }
    
    out << groups << endl;
    
    return 0;
}
