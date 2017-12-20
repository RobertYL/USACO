/*
ID: rob3rty1
PROB: div7
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
    ifstream in ("div7.in");
    ofstream out ("div7.out");
    
    long numCows, maxCows = 0, cow[7] = {0, 0, 0, 0, 0, 0, 0}, temp;
    
    in >> numCows;
    
    for(int i = 0; i < numCows; i++){
    	in >> temp;
    	cow[temp % 7] += 1;
    }
    
    /*for(int i = 0; i < 7; i++){
    	cout << cow[i] << " ";
    }*/
    
    maxCows = cow[0];
    
    for(int i = 1; i < 7; i++){
    	temp = cow[i] / 7;
    	
    	maxCows += temp * 7;
    	
    	cow[i] -= temp * 7;
    }
    
    for(int i = 1; i < 4; i++){
    	if(cow[i] > cow[7 - i]){
    		maxCows += 2 * cow[7 - i];
    	}else{
    		maxCows += 2 * cow[i];
    	}
    }
    
    out << maxCows << endl;
    
    return 0;
}
