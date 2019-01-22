/*
ID: rob3rty1
PROB: pairup
LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int numTypes;

int 

int main(){
    ifstream in ("pairup.in");
    ofstream out ("pairup.out");
    
    in >> numTypes;
    
    long cows[numTypes][2];
    
    for(int i = 0; i < numTypes; i++){
    	in >> cows[i][0] >> cows[i][1];
    }
    
    
    
    return 0;
}
