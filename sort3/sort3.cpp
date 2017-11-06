/*
ID: rob3rty1
PROB: sort3
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct section{
    int size = 0;
    int ones = 0;
    int twos = 0;
    int threes = 0;
};

int length, changes = 0;
int numbers[1000];
section one, two, three;

int main(){
    ifstream in ("sort3.in");
    ofstream out ("sort3.out");

    in >> length;

    for(int i = 0; i < length; i++){
        in >> numbers[i];
        if(numbers[i] == 1)
            one.size++;
        if(numbers[i] == 2)
            two.size++;
        if(numbers[i] == 3)
            three.size++;
    }

    for(int i = 0; i < one.size; i++){
        if(numbers[i] == 1)
            one.ones++;
        if(numbers[i] == 2)
            one.twos++;
        if(numbers[i] == 3)
            one.threes++;
    }

    for(int i = one.size; i < one.size + two.size; i++){
        if(numbers[i] == 1)
            two.ones++;
        if(numbers[i] == 2)
            two.twos++;
        if(numbers[i] == 3)
            two.threes++;
    }

    for(int i = one.size + two.size; i < length; i++){
        if(numbers[i] == 1)
            three.ones++;
        if(numbers[i] == 2)
            three.twos++;
        if(numbers[i] == 3)
            three.threes++;
    }

    //cout << one.size << " " << one.ones << " " << one.twos << " " << one.threes << endl;
    //cout << two.size << " " << two.ones << " " << two.twos << " " << two.threes << endl;
    //cout << three.size << " " << three.ones << " " << three.twos << " " << three.threes << endl;

    while(one.twos > 0 && two.ones > 0){
        one.twos--;
        one.ones++;
        two.ones--;
        two.twos++;
        changes++;
    }

    while(one.threes > 0 && three.ones > 0){
        one.threes--;
        one.ones++;
        three.ones--;
        three.threes++;
        changes++;
    }

    while(one.threes > 0 && two.ones > 0){
        one.threes--;
        one.ones++;
        two.ones--;
        two.threes++;
        changes++;
    }

    while(one.twos > 0 && three.ones > 0){
        one.twos--;
        one.ones++;
        three.ones--;
        three.twos++;
        changes++;
    }

    changes += two.threes;

    out << changes << endl;

    return 0;
}
