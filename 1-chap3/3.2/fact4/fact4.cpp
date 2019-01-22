/*
ID: rob3rty1
PROB: fact4
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
    ifstream in ("fact4.in");
    ofstream out ("fact4.out");
    
    int N, D = 1;

    in >> N;

    for(int i = 1; i <= N; i++){
        D *= i;

        D %= 100000;
        
        while(D % 10 == 0){
            D /= 10;
        }
    }

    out << D % 10 << endl;

    return 0;
}
