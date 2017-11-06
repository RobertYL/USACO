/*
ID: rob3rty1
PROB: holstein
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

int nutrientNumber, feedNumber;
int targetNutrients[25];
bool tested[]

struct feed{
    int nutrients[25];
};

feed feeds[15];

struct feedCom{
    bool works;
    bool Cfeed[15] = {0};
};

feedCom optimal;

feed combineFeed(feedCom comp){
    
}

void rec(int count, feedCom comp){
    int combinedNutrients[25] = {0};
    
    for(int i = 0; i < feedNumber; i++){
        if(comp.Cfeed[i]){
            for(int j = 0; j < nutrientNumber; j++){
                combinedNutrients[j] += feeds[i].nutrients[j];
            }
        }
    }

    for(int i = 0; i < nutrientNumber; i++){
        if(combinedNutrients[i] < targetNutrients[i]){
            comp.works = 0;
            break;
        }
        comp.works = 1;
    }

    if(count == feedNumber)
        return comp;

    if(comp.works)
        return comp;



}

//Grabs data points and run recursive function
//Outputs best possible feed composition
int main(){
    ifstream in ("holstein.in");
    ofstream out ("holstein.out");

    in >> nutrientNumber;

    for(int i = 0; i < nutrientNumber; i++)
        in >> targetNutrients[i];

    in >> feedNumber;

    for(int i = 0; i < feedNumber; i++)
        for(int j = 0; j < nutrientNumber; j++)
            in >> feeds[i].nutrients[j];



    return 0;
}
