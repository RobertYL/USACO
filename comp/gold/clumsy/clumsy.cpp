/*
ID: rob3rty1
PROB: clumsy
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
    ifstream in ("clumsy.in");
    ofstream out ("clumsy.out");
    
    string P;
    long count = 0, size, answer = 0;
    
    P.reserve(100000);
    
    in >> P;
    
    size = P.length();
    
    for(int i = 0; i < size; i++){
        if(P[i] == '(')
            count++;
        if(P[i] == ')')
            count--;
            
        if(count < 0){
            count = 1;
            answer++;
        }
    }
    
    answer += count / 2;
    
     out << answer << endl;;
    
    return 0;
}
