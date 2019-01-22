/*
ID: rob3rty1
PROB: kimbits
LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

double sizeofset[33][33];
ofstream out ("kimbits.out");

void initsizeofset(){
	int i, j;

	for(j=0; j<=32; j++)
		sizeofset[0][j] = 1;

	for(i=1; i<=32; i++){
	    for(j=0; j<=32; j++){
		    if(j == 0){
			    sizeofset[i][j] = 1;
		    }else{
			    sizeofset[i][j] = sizeofset[i-1][j-1] + sizeofset[i-1][j];
		    }
	    }
    }
}

void printbits(int nbits, int nones, double index){
	double s;

	if(nbits == 0)
		return;

	s = sizeofset[nbits-1][nones];
	if(s <= index){
		out << 1;
		printbits(nbits-1, nones-1, index-s);
	}else{
		out << 0;
		printbits(nbits-1, nones, index);
	}
}

int main(){
    ifstream in ("kimbits.in");
    
    int nbits, nones;
	double index;
    
	initsizeofset();
	
	in >> nbits >> nones >> index;
	
	printbits(nbits, nones, index-1);
	
	out << endl;

    return 0;
}
