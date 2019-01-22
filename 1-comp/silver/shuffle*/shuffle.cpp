/*
ID: rob3rty1
PROB: 
LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long cowNum;

int main(){
    ifstream in ("shuffle.in");
    ofstream out ("shuffle.out");
    
    in >> cowNum;
    
    long shuffle[cowNum], currentLoc;
    bool loop[cowNum], testing[cowNum], shuffles;
    
    for(long i = 0; i < cowNum; i++){
    	in >> shuffle[i];
    	shuffle[i] -= 1;
    	loop[i] = 0;
    	testing[i] = 0;
    }
    
    for(long i = 0; i < cowNum; i++){
    	shuffles = false;
    	currentLoc = i;
    
    	while(true){
    		if(loop[currentLoc]){
    			goto nothing;
    		}else if(testing[currentLoc]){
    			goto foundLoop;
    		}
    		
    		testing[currentLoc] = 1;
    		currentLoc = shuffle[currentLoc];
    		if(!shuffles)
    			shuffles = true;
    	}
    	foundLoop:
    	
    	while(!loop[currentLoc]){
    		loop[currentLoc] = 1;
    		currentLoc = shuffle[currentLoc];
    	}
    	
    	nothing:
    	
    	if(shuffles){
			for(long j = 0; j < cowNum; j++){
    			testing[j] = 0;
    		}
		}
    }
    
    currentLoc = 0;
    
    for(long i = 0; i < cowNum; i++){
		currentLoc += loop[i];
    }
    
    out << currentLoc << endl;
    
    return 0;
}
