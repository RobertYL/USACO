/*
ID: rob3rty1
PROB: agrinet
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
    ifstream in ("agrinet.in");
    ofstream out ("agrinet.out");
    
    long N, L = 0;

    in >> N;

    long P[N][N], distance[N], treeSize = 1, treeLength = 0, smallest = -1;
    bool inTree[N];


    for(long i = 0; i < N; i++){
        for(long j = 0; j < N; j++){
            in >> P[i][j];
        }
        inTree[i] = false;
        distance[i] = 2147483647;
    }

    inTree[0] = true;

    for(int i = 1; i < N; i++){
        distance[i] = P[0][i];
    }

    while(treeSize < N){
        for(int i = 0; i < N; i++){
            if(!inTree[i]){
                if(smallest == -1){
                    smallest = i;
                }
                if(distance[smallest] > distance[i]){
                    smallest = i;
                }
            }
        }

        //cout << smallest << endl;

        treeSize++;
        treeLength += distance[smallest];
        inTree[smallest] = true;

        for(int i = 0; i < N; i++)
            if(i != smallest)
                if(distance[i] > P[smallest][i])
                    distance[i] = P[smallest][i];
        
        smallest = -1;
    }

    out << treeLength << endl;

    return 0;
}
