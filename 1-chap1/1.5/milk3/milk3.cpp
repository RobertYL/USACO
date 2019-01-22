/*
ID:rob3rty1
PROG: milk3
LANG: C++11                                                                                                                                                                                       
*/
 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

int aMax, bMax, cMax;
bool reached[21][21][21] = {false};
bool possibleC[21] = {false};

struct buckets{
    int bukA;
    int bukB;
    int bukC;
};

buckets pour(buckets input, char from, char to){
    if(from == 'a'){
        if(to == 'b'){
            while(input.bukB != bMax && input.bukA != 0){
                input.bukB++;
                input.bukA--;
            }
        }if(to == 'c'){
            while(input.bukC != cMax && input.bukA != 0){
                input.bukC++;
                input.bukA--;
            } 
        }
    }if(from == 'b'){
        if(to == 'a'){
            while(input.bukA != aMax && input.bukB != 0){
                input.bukA++;
                input.bukB--;
            }
        }if(to == 'c'){
            while(input.bukC != cMax && input.bukB != 0){
                input.bukC++;
                input.bukB--;
            }
        }
    }if(from == 'c'){
        if(to == 'a'){
            while(input.bukA != aMax && input.bukC != 0){
                input.bukA++;
                input.bukC--;
            }
        }if(to == 'b'){
            while(input.bukB != bMax && input.bukC != 0){
                input.bukB++;
                input.bukC--;
            }
        }
    }

    //cout << "Current bucket amounts in pour are: " << input.bukA << ":" << input.bukB << ":" << input.bukC << endl;

    //cout << "Pouring from " << from << " to " << to << endl;

    return input;
}

void cycle(buckets input){

    //cout << "Current bucket amounts in cycle are: " << input.bukA << ":" << input.bukB << ":" << input.bukC << endl;

    if(reached[input.bukA][input.bukB][input.bukC])
        return;

    reached[input.bukA][input.bukB][input.bukC] = true;

    if(input.bukA == 0)
        possibleC[input.bukC] = true;

    cycle(pour(input, 'a', 'b'));
    cycle(pour(input, 'a', 'c'));
    cycle(pour(input, 'b', 'a'));
    cycle(pour(input, 'b', 'c'));
    cycle(pour(input, 'c', 'a'));
    cycle(pour(input, 'c', 'b'));
}

int main(){
    
    ofstream out ("milk3.out");
    ifstream in ("milk3.in");
    in >> aMax >> bMax >> cMax;
    
    /*
    aMax = 2;
    bMax = 5;
    cMax = 10;
*/
    buckets input;
    input.bukA = 0;
    input.bukB = 0;
    input.bukC = cMax;

    cycle(input);

    int count = 0, count2 = 0;

    for(int i = 0; i < 21; i++){
        if(possibleC[i])
            count++;
    }

    for(int i = 0; i < 21; i++){
        if(possibleC[i]){
            out << i;
            if(count > count2 + 1){
                out << " ";
                count2++;
            }
        }
    }

    out << endl;
}
