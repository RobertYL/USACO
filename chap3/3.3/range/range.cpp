/*
ID: rob3rty1
PROB: range
LANG: C++11
*/

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ifstream in ("range.in");
    ofstream out ("range.out");
    
    int N;
    
    in >> N;
    
    bool f[N][N];
    string row;
    
    REP(i, 0, N){
        in >> row;
        REP(j, 0, N){
            if(row[j] == '1')
                f[i][j] = true;
            else
                f[i][j] = false;
        }
    }
    
    REP(i, 1, N){
        int count = 0;
        
        REP(j, 0, N - i){
            REP(k, 0, N - i){
                if(f[j][k] && f[j+1][k] && f[j][k+1] && f[j+1][k+1]){
                    count++;
                }else{
                    f[j][k] = false;
                }
            }
        }
        
        if(count == 0)
            return 0;
            
        out << i + 1 << " ";
        out << count << endl;
    }
    
    return 0;
}
