/*
ID: rob3rty1
PROB: fracdec
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
    ifstream in ("fracdec.in");
    ofstream cout ("fracdec.out");
    
    long N, D, l = 0, cl = 0, i, counter = 0;
    int r[100000], d[100000];

    in >> N >> D;

    for(int i = 0; i < 100000; i++){
        r[i] = -1;
        d[i] = 0;
    }

    i = N / D;

    N -= i * D;

    while(N != 0){
        if(r[N] != -1){
            cl = l - r[N];
            break;
        }
        r[N] = l;
        
        N *= 10;
        d[l] = N / D;
        N -= d[l] * D;

        l++;
    }

    cout << i << ".";

    if(i == 0)
        counter++;

    for(; i != 0; i /= 10, counter++);

    if(l == 0){
        cout << 0;
    }

    for(int i = 0; i < l - cl; i++){
        counter++;

        if(counter % 76 == 0)
            cout << endl;
        
        cout << d[i];
    }

    for(int i = l - cl; i < l; i++){
        if(i == l - cl){
            counter++;
            cout << "(";
        }

        counter++;

        if(counter % 76 == 0)
            cout << endl;

        cout << d[i];

        if(i == l - 1){
            counter++;
            cout << ")";
        }
    }

    cout << endl;

    return 0;
}
