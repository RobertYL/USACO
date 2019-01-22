/*
ID: rob3rty1
PROB: hps
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
    ifstream in ("hps.in");
    ofstream out ("hps.out");
    
    long moves, largest = 0;
    char current;
    
    in >> moves;
    
    long rock[moves], paper[moves], scissors[moves];
    
    for(int i = 0; i < moves; i++){
    	rock[i] = 0;
    	paper[i] = 0;
    	scissors[i] = 0;
    }
    
    in >> current;
    if(current == 'H'){
		rock[0] = 1;
	}else if(current == 'P'){
		paper[0] = 1;
	}else if(current == 'S'){
		scissors[0] = 1;
	}
    
    for(long i = 1; i < moves; i++){
    	in >> current;
    	
    	if(current == 'H'){
    		rock[i] = rock[i - 1] + 1;
    		paper[i] = paper[i - 1];
    		scissors[i] = scissors[i - 1];
    	}else if(current == 'P'){
    		rock[i] = rock[i - 1];
    		paper[i] = paper[i - 1] + 1;
    		scissors[i] = scissors[i - 1];
    	}else if(current == 'S'){
    		rock[i] = rock[i - 1];
    		paper[i] = paper[i - 1];
    		scissors[i] = scissors[i - 1] + 1;
    	}
    }
    
    if(rock[moves - 1] > largest)
    	largest = rock[moves - 1];
    if(paper[moves - 1] > largest)
    	largest = paper[moves - 1];
    if(scissors[moves - 1] > largest)
    	largest = scissors[moves - 1];
    
    for(long i = 0; i < moves; i++){
    	//cout << paper[i] << endl;
    	if(rock[i] + paper[moves - 1] - paper[i] > largest)
    		largest = rock[i] + paper[moves - 1] - paper[i];
		//cout << largest << endl;
    	if(rock[i] + scissors[moves - 1] - scissors[i] > largest)
    		largest = rock[i] + scissors[moves - 1] - scissors[i];
		//cout << largest << endl;
    	if(paper[i] + rock[moves - 1] - rock[i] > largest)
    		largest = paper[i] + rock[moves - 1] - rock[i];
		//cout << largest << endl;
    	if(paper[i] + scissors[moves - 1] - scissors[i] > largest)
    		largest = paper[i] + scissors[moves - 1] - scissors[i];
		//cout << largest << endl;
    	if(scissors[i] + rock[moves - 1] - rock[i] > largest)
    		largest = scissors[i] + rock[moves - 1] - rock[i];
		//cout << largest << endl;
    	if(scissors[i] + paper[moves - 1] - paper[i] > largest)
    		largest = scissors[i] + paper[moves - 1] - paper[i];
		//cout << largest << endl;
    }
    
    out << largest << endl;
    
    return 0;
}
