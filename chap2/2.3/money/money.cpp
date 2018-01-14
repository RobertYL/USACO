/*
ID: rob3rty1
PROB: money
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
    ifstream in ("money.in");
    ofstream out ("money.out");
    
    int num, target;
    long long combinations[10001] = {0};
    combinations[0] = 1;
    
    in >> num >> target;
    
    int values[num];
    
    for(int i = 0; i < num; i++){
        in >> values[i];
    }
    
    for(int i = 0; i < num; i++){
        for(int j = values[i]; j <= target; j++){
            combinations[j] += combinations[j - values[i]];
        }
    }
    
    out << combinations[target] << endl;;
    
    return 0;
}
