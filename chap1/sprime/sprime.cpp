/*
ID: rob3rty1
PROB: sprime
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int length, currentVec = 2;

vector<long> sprimes1;
vector<long> sprimes2;

void checkPrime(long input){
    if(input == 1){
        return;
    }

    if(input == 2 || input == 3){
        return;
    }

    if(input % 2 == 0){
        return;
    }

    for(long i = 3; i < (input/3) + 3; i+=2){
        if(input % i == 0){
            return;
        }
    }

    if(currentVec == 1){
        sprimes1.push_back (input);
    }else{
        sprimes2.push_back (input);
    }
    return;
}

int main(){
    ifstream in ("sprime.in");
    ofstream out ("sprime.out");

    in >> length;

    sprimes1.push_back (2);
    sprimes1.push_back (3);
    sprimes1.push_back (5);
    sprimes1.push_back (7);

    for(int i = 1; i < length; i++){
        if(i % 2 == 1){
            for(int j = 0; j < sprimes1.size(); j++){
                checkPrime((sprimes1[j] * 10) + 1);
                checkPrime((sprimes1[j] * 10) + 3);
                checkPrime((sprimes1[j] * 10) + 5);
                checkPrime((sprimes1[j] * 10) + 7);
                checkPrime((sprimes1[j] * 10) + 9);
            }
            sprimes1.clear();
            currentVec = 1;
        }else{
            for(int j = 0; j < sprimes2.size(); j++){
                checkPrime((sprimes2[j] * 10) + 1);
                checkPrime((sprimes2[j] * 10) + 3);
                checkPrime((sprimes2[j] * 10) + 5);
                checkPrime((sprimes2[j] * 10) + 7);
                checkPrime((sprimes2[j] * 10) + 9);
 
            }
            sprimes2.clear();
            currentVec = 2;
        }
    }

    if(length % 2 == 1){
        for(int i = 0; i < sprimes1.size(); i++){
            out << sprimes1[i] << endl;
        }
    }else{
       for(int i = 0; i < sprimes2.size(); i++){
            out << sprimes2[i] << endl;
        } 
    }

    return 0;
}
