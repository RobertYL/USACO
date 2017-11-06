/*
ID: rob3rty1
PROB: frac1
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int maxDen;

struct fraction{
    int top;
    int bot;
    float real;
};

fraction initFrac(int top, int bot){
    fraction temp;
    temp.top = top;
    temp.bot = bot;
    temp.real = (float)(top)/(float)(bot);
    return temp;
}

bool larger(const fraction &a, const fraction &b){
    return a.real < b.real;
}

bool equiv(const fraction &a, const fraction &b){
    return a.real == b.real;
}

int reducible(const fraction &input){
    for(int i = input.top; i > 1; i--){
        if(input.top % i == 0 && input.bot % i == 0)
            return i;
    }

    return 1;
}

vector<fraction> fractions;

int main(){
    ifstream in ("frac1.in");
    ofstream out ("frac1.out");

    in >> maxDen;

    

    for(int i = 1; i <= maxDen; i++){
        for(int j = 1; j < i; j++){
            fractions.push_back (initFrac(j, i));
        }
    }

    sort (fractions.begin(), fractions.end(), larger);

    fractions.erase (unique(fractions.begin(), fractions.end(), equiv), fractions.end());

    out << "0/1" << endl;

    int temp;

    for(int i = 0; i < fractions.size(); i++){
        temp = reducible(fractions[i]);
        fractions[i].top /= temp;
        fractions[i].bot /= temp;
        out << fractions[i].top << "/" << fractions[i].bot << endl;
    }

    out << "1/1" << endl;

    return 0;
}
