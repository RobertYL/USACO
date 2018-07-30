/*
ID: rob3rty1
PROB: angry
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

using namespace std;

int main(){
    ifstream in ("angry.in");
    ofstream out ("angry.out");
    
    int N, t, a, b, aR, bR, aN, bN, R;
    
    in >> N;
    
    vector<int> x(N);
    
    for(int i = 0; i < N; i++){
        in >> x[i];
    }
    
    sort(x.begin(), x.end());
    
    a = 0;
    b = N - 1;
    aR = x[a + 1] - x[a];
    bR = x[b] - x[b - 1];
    t = min(aR, bR);
    
    for(R = t; R < 1000000000; R++){
        if(b - a <= 1)
            break;

        aN = a;
        bN = b;
        
        while(x[aN + 1] - x[a] < R){
            aN++;
        }
        
        while(x[b] - x[bN - 1] < R){
            bN--;
        }
        
        if(aN != a){
            a = aN;
        }
        
        if(bN != b){
            b = bN;
        }
        
        if(b - a <= 1)
            break;
    }
    
    if(a == b){
        out << R - 1 << ".0" << endl;
        return 0;
    }
    
    if(abs(-x[a - 1] + x[a] + x[a] - x[b]) == 1){
        out << R - 1 << ".5" << endl;
        return 0;
    }
    
    out << max(R, ((x[b] - x[a]) / 2));
    
    if(R < ((x[b] - x[a]) / 2) && (x[b] - x[a]) % 2){
        out << ".5" << endl;
    }else{
        out << ".0" << endl;
    }
    
    
    
    return 0;
}
