/*
ID: rob3rty1
PROB: snowboots
LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ifstream in ("snowboots.in");
    ofstream out ("snowboots.out");
    
    int N, B, cur, startB, curB;
    
    in >> N >> B;
    
    long f[N], s[B];
    int d[B];
    
    for(int i = 0; i < N; i++){
        in >> f[i];
    }
    
    for(int i = 0; i < B; i++){
        in >> s[i] >> d[i];
    }
    
    for(startB = 0; startB < B; startB++){
        cur = N - 1;
        curB = startB;
        while(cur != 0){
            for(int stride = d[curB]; stride > 0; stride--){
                if(stride <= cur){
                    if(f[cur - stride] <= s[curB]){
                        cur -= stride;
                        if(cur == 0){
                            goto works;
                        }
                        goto jump;
                    }
                }
                if(stride == 1){
                    if(curB != 0){
                        curB--;
                    }else{
                        goto nowork;
                    }
                }
            }
            jump:;
        }
        
        nowork:;
        
    }
    
    works:
    
    out << startB << endl;
    
    return 0;
}

