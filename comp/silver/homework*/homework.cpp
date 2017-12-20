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

long long numQs;

int main(){
    ifstream in ("homework.in");
    ofstream out ("homework.out");
    
    in >> numQs;
    
    long long order[numQs], highest = 0, currentLowest = 10000;
    deque<long long> queue;
    long long totalScore = 0, average = 0, currentAverage;
    
    for(long long i = 0; i < numQs; i++){
    	in >> order[i];
    	totalScore += order[i];
    	if(order[i] > highest)
    		highest = order[i];
    	if(order[i] < currentLowest)
    		currentLowest = order[i];
    }
    
    long long amounts[highest + 1];
    
    for(long long i = 0; i < numQs; i++){
    	amounts[order[i]] += 1;
    }
    
    for(long long i = 0; i < numQs - 2; i++){
    	totalScore -= order[i];
    	amounts[order[i]] -= 1;
    	
    	while(amounts[currentLowest] == 0)
    		currentLowest += 1;
    	
    	currentAverage = (totalScore - currentLowest) / (numQs - i - 1);

    	if(currentAverage > average){
    		average = currentAverage;
    		while(!queue.empty()){
    			queue.pop_back();
    		}
    		queue.push_back(i + 1);
    	}else if(currentAverage == average){
    		queue.push_back(i + 1);
		}
    }
    
    while(!queue.empty()){
		out << queue.back() << endl;
		queue.pop_back();
	}
    
    return 0;
}
