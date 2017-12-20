/*
ID: rob3rty1
PROB: preface
LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void generate(int* romanNumerals, int num){
	for(int i = 0; i < 7; i++){
		romanNumerals[i] = 0;
	}
	
	int currentDigit, currentPlace = 0;
	
	while(num != 0){
		currentDigit = num % 10;
		num /= 10;
		
		if(currentDigit > 0 && currentDigit < 4){
			romanNumerals[currentPlace * 2] += currentDigit;
		}else if(currentDigit == 4){
			romanNumerals[currentPlace * 2] += 1;
			romanNumerals[(currentPlace * 2) + 1] += 1;
		}else if(currentDigit > 4 && currentDigit < 9){
			romanNumerals[currentPlace * 2] += currentDigit % 5;
			romanNumerals[(currentPlace * 2) + 1] += 1;
		}else if(currentDigit == 9){
			romanNumerals[currentPlace * 2] += 1;
			romanNumerals[(currentPlace * 2) + 2] += 1;
		}
		
		currentPlace += 1;
	}
}

int main(){
	ifstream in ("preface.in");
	ofstream out ("preface.out");

	int nPages, numeralSum[7] = {0, 0, 0, 0, 0, 0, 0};
	char indexToChar[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

	in >> nPages;

	int romanNumerals[7];

	for(int i = 1; i <= nPages; i++){
		generate(romanNumerals, i);

		for(int j = 0; j < 7; j++){
			numeralSum[j] += romanNumerals[j];
		}
	}
		
		
	//for(int i = 0; i < 7; i++){
	//	cout << numeralSum[i] << " ";
	//}
		
	//cout << endl;
		
	for(int i = 0; i < 7; i++){
		if(numeralSum[i] != 0){
			out << indexToChar[i] << " " << numeralSum[i] << endl;
		}
	}

	return 0;
}
