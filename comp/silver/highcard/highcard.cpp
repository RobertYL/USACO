/*
ID: rob3rty1
PROB: highcard
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
    ifstream in ("highcard.in");
    ofstream out ("highcard.out");
    
    int N, T, a = 0, b = 1, A = 0;

    in >> N;

    bool hand[N * 2], used[N * 2];

    for(int i = 0; i < 2 * N; i++){
        hand[i] = false;
        used[i] = false;
    }

    for(int i = 0; i < N; i++){
        in >> T;

        hand[T - 1] = true;
    }

    while(true){
    
        while(!hand[a] || used[a]){
            a++;
        }

        //cout << a << " ";

        while(true){
            if(b >= (N * 2)){
                goto finish;
            }

            if(!hand[b] && !used[b] && b > a){
                //cout << b << endl;
                used[b] = true;
                used[a] = true;
                A++;
                break;
            }

            b++;
        }
    }

    finish:;

    out << A << endl;

    return 0;
}
