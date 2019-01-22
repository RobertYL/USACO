/*
ID: rob3rty1
PROB: feast
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
    ifstream in ("feast.in");
    ofstream out ("feast.out");
    
    int T, A, B;
    
    in >> T >> A >> B;
    
    bool P[T + 1][2];
    
    for(int i = 0; i < T + 1; i++){
        P[i][0] = false;
        P[i][1] = false;
    }
    
    P[0][0] = true;
    
    for(int i = 1; i < T + 1; i++){
        if(i - A > -1){
            if(P[i - A][0]){
                P[i][0] = true;
            }
        }
        
        if(i - B > -1){
            if(P[i - B][0]){
                P[i][0] = true;
            }
        }
    }
    
    for(int i = 0; i < T + 1; i++){
        if(P[i][0]){
            P[i/2][1] = true;
        }
    }
    
    for(int i = 1; i < T + 1; i++){
        if(i - A > -1){
            if(P[i - A][1]){
                P[i][1] = true;
            }
        }
        
        if(i - B > -1){
            if(P[i - B][1]){
                P[i][1] = true;
            }
        }
    }

    for(int i = T; i > 0; i--){
        if(P[i][0] || P[i][1]){
            out << i << endl;
            break;
        }
    }
    
    return 0;
}
