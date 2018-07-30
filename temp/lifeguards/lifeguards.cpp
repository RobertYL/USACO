/*
ID: rob3rty1
PROB: lifeguards
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
    ifstream in ("lifeguards.in");
    ofstream out ("lifeguards.out");
    
    long N, largest = 0, smallest = 1000000000, temp, size;

    in >> N;

    long timeSheet[N][2];

    for(int i = 0; i < N; i++){
        in >> timeSheet[i][0] >> timeSheet[i][1];

        if(timeSheet[i][1] > largest)
            largest = timeSheet[i][1];

        if(timeSheet[i][0] < smallest)
            smallest = timeSheet[i][0];
    }

    bool log[largest - smallest + 1];
    size = largest - smallest + 1;

    for(int i = 0; i < N; i++){
        timeSheet[i][0] -= smallest;
        timeSheet[i][1] -= smallest;
    }

    largest = 0;

    for(int i = 0; i < N; i++){
        temp = 0;
        for(int j = 0; j < size; j++){
            log[j] = false;
        }

        for(int j = 0; j < N; j++){
            if(j != i){
                for(int k = timeSheet[j][0]; k < timeSheet[j][1]; k++){
                    log[k] = true;
                }
            }
        }

        for(int j = 0; j < size; j++){
            if(log[j])
                temp++;
        }

        if(temp > largest)
            largest = temp;
    }

    out << largest << endl;;

    return 0;
}
