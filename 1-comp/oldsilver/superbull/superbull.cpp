/*
ID: rob3rty1
PROB: superbull
LANG: C++11
*/

//Complete 10/10

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <limits.h>

using namespace std;

int main(){
    ifstream in ("superbull.in");
    ofstream out ("superbull.out");
    
    int N;
    
    in >> N;
    
    int ID[N], W[N][N], node, min, key[N];
    long long sol = 0;
    bool V[N];
    
    for(int i = 0; i < N; i++){
        in >> ID[i];
        V[i] = false;
        key[i] = INT_MAX;
    }
    
    key[0] = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            W[i][j] = -(ID[i] ^ ID[j]);
        }
    }
    
    for(int i = 0; i < N - 1; i++){
        min = INT_MAX;
        
        for(int j = 0; j < N; j++){
            if(key[j] < min && V[j] == false){
                min = key[j];
                node = j;
            }
        }
        
        V[node] = true;
        
        for(int j = 0; j < N; j++)
            if(W[node][j] && V[j] == false && W[node][j] < key[j])
                key[j] = W[node][j];
    }
    
    for(int i = 0; i < N; i++){
        sol -= key[i];
    }
    
    out << sol << endl;
    
    return 0;
}
