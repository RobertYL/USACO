/*
ID: rob3rty1
PROB: fence9
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
    ifstream in ("fence9.in");
    ofstream out ("fence9.out");
    
    int n, m, p;
    
    in >> n >> m >> p;
    
    int total = 0;
    
    REP(i, 1, n + 1){
        total += m * i / n;
        if(m * i % n == 0)
            total--;
    }
    
    if(p > n){
        REP(i, 1, p - n){
            total += m * i / (p - n);
            if(m * i % (p - n) == 0)
                total--;
        }
    }else if(p == n){
        total -= m - 1;
    }else{
        REP(i, 0, n - p + 1){
            total -= m * i / (n - p);
        }
        total++;
    }
    
    out << total << endl;
    
    return 0;
}
