/*
ID: rob3rty1
PROB: bgm
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
    ifstream in ("bgm.in");
    ofstream out ("bgm.out");
    
    long long ans = 0, count[256][7];
    int N, val;
    char var;
    
    in >> N;
    
    for(int i = 0; i < 256; i++)
        for(int j = 0; j < 7; j++)
            count[i][j] = 0;
    
    for(int i = 0; i < N; i++){
        in >> var >> val;
        count[var][(val % 7 + 7) % 7]++;
    }
    
    for(int B = 0; B < 7; B++){
        for(int E = 0; E < 7; E++){
            for(int S = 0; S < 7; S++){
                for(int I = 0; I < 7; I++){
                    for(int G = 0; G < 7; G++){
                        for(int O = 0; O < 7; O++){
                            for(int M = 0; M < 7; M++){
                                if(((B + E + S + S + I + E) * (G + O + E + S) * (M + O + O)) % 7 == 0){
                                    ans += count['B'][B] * count['E'][E] * count['S'][S] * count['I'][I] * count['G'][G] * count['O'][O] * count['M'][M];
                                }
                            }
                        }
                    }
                }
            }
        }    
    }
    
    out << ans << endl;
    
    return 0;
}
