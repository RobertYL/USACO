/*
ID: rob3rty1
PROB: ratios
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
    ifstream in ("ratios.in");
    ofstream out ("ratios.out");
    
    target[3];
    feeds[3][3];
    total[3];
    
    for(int i = 0; i < 3; i++){
        in >> target[i];
    }
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            in >> feeds[i][j];
        }
    }
    
    for(int i = 0; i < 101; i++){
        for(int i = 0; i < 101; i++){
            for(int i = 0; i < 101; i++){
                total[0] = feeds[0][0] * a;
                total[0] += feeds[1][0] * b;
                total[0] += feeds[2][0] * c;
                
                total[1] = feeds[0][1] * a;
                total[1] += feeds[1][1] * b;
                total[1] += feeds[2][1] * c;
                
                total[2] = feeds[0][2] * a;
                total[2] += feeds[1][2] * b;
                total[2] += feeds[2][2] * c;
            }
        }    
    }
    
    return 0;
}
