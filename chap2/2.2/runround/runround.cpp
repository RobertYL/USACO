/*
ID: rob3rty1
PROB: runround
LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool numCheck[10];

bool check(int* num, int size){
	for(int i = 0; i < size; i++){
		numCheck[i] = false;
	}
	
	int index = size - 1;
	int temp = 0;
	
	while(!numCheck[index]){
		numCheck[index] = true;
		temp = num[index] % size;
		index -= temp;
		index += size;
		index %= size;
	}
	
	if(index != size - 1)
		return false;
	
	for(int i = 0; i < size; i++){
		if(!numCheck[i]){
			return false;
		}
	}
	
	return true;
}

int increase(int* num, int size){
	num[0] += 1;
	for(int i = 0; i < 9; i++){
		if(num[i] == 10){
			num[i] = 0;
			num[i + 1] += 1;
			if(i + 1 == size){
				size += 1;
			}
		}
	}
	
	return size;
}

unsigned long exp(int exponent){
	unsigned long num = 1;
	while(exponent != 0){
		num *= 10;
		exponent -= 1;
	}
	
	return num;
}

bool notAllowed(int* num, int size){
	for(int i = 0; i < 10; i++){
		numCheck[i] = false;
	}
	
	for(int i = 0; i < size; i++){
		if(num[i] == 0 || numCheck[num[i]] == true){
			return true;	
		}

		numCheck[num[i]] = true;
	}
	
	return false;
}

int main(){
    ifstream in ("runround.in");
    ofstream out ("runround.out");
    
    unsigned long largerThan;
	int current[10], size = -1;

	in >> largerThan;
	
	for(int i = 0; i < 10; i++){
		current[i] = largerThan % 10;
		largerThan /= 10;
		if(size == -1 && largerThan == 0){
			size = i + 1;
		}
	}
	
	size = increase(current, size);
	while(notAllowed(current, size)){
		size = increase(current, size);
	}
	
	while(!check(current, size)){
		size = increase(current, size);
		while(notAllowed(current, size)){
			size = increase(current, size);
		}
	}

	largerThan = 0;
	for(int i = 0; i < 10; i++){
		largerThan += (unsigned long)current[i] * exp(i);
	}
	
	out << largerThan << endl;
    
    return 0;
}
