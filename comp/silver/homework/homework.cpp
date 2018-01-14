/*
ID: rob3rty1
PROB: homework
LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long numQs;

int main(){
    ifstream in ("homework.in");
    ofstream out ("homework.out");
    
    in >> numQs;
    
    long order[numQs], lowest;
    double average = 0, curAverage;
    deque<long> queue;
    long long current;
    
    for(long i = 0; i < numQs; i++){
    	in >> order[i];
    }
    
    lowest = order[numQs - 1];
    current = order[numQs - 1];
    
    for(long i = numQs - 2; i > 0; i--){
    	if(lowest > order[i])
    		lowest = order[i];
    		
    	current += order[i];
    	
    	curAverage = (double)(current - lowest) / (numQs - i - 1);

    	if(curAverage > average){
    		average = curAverage;
    		while(!queue.empty()){
    			queue.pop_back();
    		}
    		queue.push_back(i);
    	}else if(curAverage == average){
    		queue.push_back(i);
		}
    }
    
    while(!queue.empty()){
		out << queue.back() << endl;
		queue.pop_back();
	}
    
    return 0;
}
