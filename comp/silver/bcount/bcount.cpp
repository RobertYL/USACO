/*
ID: rob3rty1
PROB: bcount
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
    ifstream in ("bcount.in");
    ofstream out ("bcount.out");
    
    long N, Q, a, b;

    in >> N >> Q;

    int cows[3][N + 1];

    cows[0][0] = 0;
    cows[1][0] = 0;
    cows[2][0] = 0;

    for(long i = 1; i <= N; i++){
        cows[0][i] = cows[0][i - 1];
        cows[1][i] = cows[1][i - 1];
        cows[2][i] = cows[2][i - 1];

        in >> a;
        cows[a - 1][i]++;
    }

    for(long i = 0; i < Q; i++){
        in >> a >> b;

        out << cows[0][b] - cows[0][a - 1] << " ";
        out << cows[1][b] - cows[1][a - 1] << " ";
        out << cows[2][b] - cows[2][a - 1] << endl;
    }

    return 0;
}
