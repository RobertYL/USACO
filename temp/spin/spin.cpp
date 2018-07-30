/*
ID: rob3rty1
PROB: spin
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
    ifstream in ("spin.in");
    ofstream out ("spin.out");

    int S[5], a, b, c;
    bool W[5][360];

    for(int i = 0; i < 360; i++){
        for(int j = 0; j < 5; j++){
            W[j][i] = false;
        }
    }

    for(int i = 0; i < 5; i++){
        in >> S[i] >> a;

        for(int j = 0; j < a; j++){
            in >> b >> c;

            for(int k = 0; k < c + 1; k++){
                W[i][(b + k) % 360] = true;
            }
        }
    }

    for(int i = 0; i < 5; i++){
        cout << S[i] << ": ";

        for(int j = 0; j < 360; j++){
            cout << W[i][j];
        }

        cout << endl;
    }

    return 0;
}
