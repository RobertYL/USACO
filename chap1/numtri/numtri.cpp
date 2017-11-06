/*
ID: rob3rty1
PROB: numtri
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int triangle[1001][1001] = {0};
int size;

int consolidate(int row){
    for(int i = 0; i < row + 1; i++){
        if(triangle[row + 1][i] > triangle[row + 1][i + 1]){
            triangle[row][i] += triangle[row + 1][i];
        }else{
            triangle[row][i] += triangle[row + 1][i + 1];
        }
    }
}

int main(){
    ofstream out ("numtri.out");
    ifstream in ("numtri.in");

    in >> size;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < i + 1; j++){
            in >> triangle[i][j];
        }
    }

    /*size = 5;
    triangle[0][0] = 7;
    triangle[1][0] = 3;
    triangle[1][1] = 8;
    triangle[2][0] = 8;
    triangle[2][1] = 1;
    triangle[2][2] = 0;
    triangle[3][0] = 2;
    triangle[3][1] = 7;
    triangle[3][2] = 4;
    triangle[3][3] = 4;
    triangle[4][0] = 4;
    triangle[4][1] = 5;
    triangle[4][2] = 2;
    triangle[4][3] = 6;
    triangle[4][4] = 5;*/

    for(int i = size - 1; i >= 0; i--){
        consolidate(i);
    }

    out << triangle[0][0] << endl;

    return 0;
}
