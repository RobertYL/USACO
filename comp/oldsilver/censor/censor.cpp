/*
ID: rob3rty1
PROB: censor
LANG: C++11
*/

//Complete 15/15

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int hnext(int pow, int re, int hash, int ch){
    return ((((1ll * hash) - ((1ll * pow * re) % 1000000007) + 1000000007) * 100000007) + ch) % 1000000007;
}

int main(){
    ifstream in ("censor.in");
    ofstream out ("censor.out");
    
    string S, T;
    S.reserve(1000000);
    T.reserve(1000000);
    in >> S >> T;
    
    int size = S.length(), sizeT = T.length(), hashT = 0, pow = 1;
    vector<char> M;
    vector<int> rHash;
    M.reserve(1000000);

    rHash.push_back(0);
    
    for(int i = 0; i < sizeT - 1; i++){
        pow = (1ll * pow * 100000007) % 1000000007;
    }
    
    
    for(int i = 0; i < sizeT; i++){
        hashT = hnext(0, 0, hashT, T[i] - 'a' + 1);
        M.push_back('`');
    }
    
    for(int i = 0; i < size; i++){
        M.push_back(S[i]);
        
        rHash.push_back(hnext(pow, M[M.size() - sizeT - 1] - 'a' + 1, rHash.back(), M.back() - 'a' + 1));
        
        if(rHash.back() == hashT){
            M.resize(M.size() - sizeT);
            rHash.resize(rHash.size() - sizeT);
        }
    }
    
    for(int i = sizeT; i < M.size(); i++){
        out << M[i];
    }
    
    out << endl;
    
    return 0;
}
