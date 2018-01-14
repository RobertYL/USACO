/*
ID: rob3rty1
PROB: comehome
LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int main(){
    ifstream in ("comehome.in");
    ofstream out ("comehome.out");
    
    long paths, pathLength[52][52], distance[52], A, B, C;
    char a, b;
    deque<long> pasture;

    in >> paths;

    for(int i = 0; i < 52; i++){
        for(int j = 0; j < 52; j++){
            pathLength[i][j] = -1;
        }
        distance[i] = -1;
    }

    distance[25] = 0;

    for(int i = 0; i < paths; i++){
        in >> a >> b;

        if(a >= 'A' && a <= 'Z')
            A = (int)(a - 'A');
        if(a >= 'a' && a <= 'z')
            A = (int)(a - 'a' + 26);
        if(b >= 'A' && b <= 'Z')
            B = (int)(b - 'A');
        if(b >= 'a' && b <= 'z')
            B = (int)(b - 'a' + 26);

        in >> C;

        if(pathLength[A][B] == -1){
            pathLength[A][B] = C;
            pathLength[B][A] = C;
        }

        if(C < pathLength[A][B]){
            pathLength[A][B] = C;
            pathLength[B][A] = C;
        }
    }

    pasture.push_back(25);

    while(!pasture.empty()){
        A = pasture.front();
        pasture.pop_front();

        for(int i = 0; i < 52; i++){
            if(pathLength[A][i] != -1){
                if(distance[i] == -1){
                    distance[i] = distance[A] + pathLength[A][i];
                    pasture.push_back(i);
                }
                if(distance[i] > distance[A] + pathLength[A][i]){
                    distance[i] = distance[A] + pathLength[A][i];
                    pasture.push_back(i);
                }
            }
        }
    }

    A = 2147483647;

    for(int i = 0; i < 25; i++){
        if(distance[i] != -1 && distance[i] < A){
            A = distance[i];
            a = i + 'A';
        }
    }

    out << a << " " << A << endl;

    return 0;
}
