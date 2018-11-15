/*
ID: rob3rty1
PROB: ratios
LANG: C++11
*/

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int goal[3];
int goalf;
int bow[3][3];
int sol[4];

int gcd(int a, int b){
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

int findGCD(int arr[], int n){ 
    int result = arr[0]; 
    for (int i = 1; i < n; i++) 
        result = gcd(arr[i], result); 
  
    return result; 
}

void sum(int a, int b, int c){
    sol[0] = (a * bow[0][0]) + (b * bow[1][0]) + (c * bow[2][0]);
    sol[1] = (a * bow[0][1]) + (b * bow[1][1]) + (c * bow[2][1]);
    sol[2] = (a * bow[0][2]) + (b * bow[1][2]) + (c * bow[2][2]);
    int f = findGCD(sol, 3);

    f /= goalf;
    if(f != 0){
        sol[0] /= f;
        sol[1] /= f;
        sol[2] /= f;
        sol[3] = f;
    }
}

int main(){
    ifstream in ("ratios.in");
    ofstream out ("ratios.out");
    
    for(int i = 0; i < 3; i++)
        in >> goal[i];
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            in >> bow[i][j];

    goalf = findGCD(goal, 3);

    REP(i, 0, 100){
        REP(j, 0, 100){
            REP(k, 0, 100){
                sum(i, j, k);
                if(sol[0] == goal[0] && sol[1] == goal[1] && sol[2] == goal[2]){
                    out << i << " " << j << " " << k << " " << sol[3] << endl;
                    return 0;
                }
            }
        }
    }
    
    out << "NONE" << endl;
    return 0;
}
