/*
ID: rob3rty1
PROB: hamming
LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string toBinaryString(int a, int size){
    string binary = "";
    int mask = 1;
    
    for(int i = 0; i < size; i++){
        if((mask&a) >= 1){
            binary = "1"+binary;
        }else{
            binary = "0"+binary;
        }
        mask <<= 1;
    }
    return binary;
}

int hammingDistance(string num1, string num2){
    int count = 0, temp1 = 0, temp2 = 0;
    
    for(int i = 0; i < num1.length(); i++){
        temp1 = num1[i] - '0';
        temp2 = num2[i] - '0';
        
        if(temp1 + temp2 == 1){
            count++;
        }
    }
    
    return count;
}

int main(){
    ifstream in ("hamming.in");
    ofstream out ("hamming.out");
    
    int nCodewords, bitLength, distance;
    
    in >> nCodewords >> bitLength >> distance;
    
    int maxSize = 2;
    
    for(int i = 0; i < bitLength - 1; i++){
        maxSize *= 2;
    }
    
    if(bitLength == 1)
        maxSize = 1;
    
    int codewords[nCodewords];
    codewords[0] = 0;
    int arrayAmount = 1;
    string current;
    
    for(int i = 1; i < maxSize; i++){
        current = toBinaryString(i, bitLength);
        
        for(int j = 0; j < arrayAmount; j++){
            if(hammingDistance(current, toBinaryString(codewords[j], bitLength)) < distance){
                goto contin;
            }
        }
        
        if(arrayAmount == nCodewords)
            break;
        
        codewords[arrayAmount] = i;
        arrayAmount++;
        
        contin:;
    }
    
    for(int i = 0; i < nCodewords; i++){
        out << codewords[i];
        
        if((i + 1) % 10 == 0){
            out << endl;
        }else if(i != nCodewords - 1){
            out << " ";
        }
    }
    
    if(nCodewords % 10 != 0)
        out << endl;
    
    return 0;
}
