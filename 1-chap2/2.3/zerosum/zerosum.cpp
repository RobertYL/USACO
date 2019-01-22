/*
ID: rob3rty1
PROB: zerosum
LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

ofstream out ("zerosum.out");

void increase(int* num, int length){
    num[length - 1]++;
    
    for(int i = length - 1; i > 0; i--){
        if(num[i] == 3){
            num[i] = 0;
            num[i - 1]++;
        }
    }
}

long tenToThe(int power){
    int mul = 1;
    
    while(power != 0){
        mul *= 10;
        power--;
    }
    
    return mul;
}

bool check(int* num, int length){
    long sum = 0, current = 0;
    int spaceCount = 0;
    
    for(int i = length - 1; i >= 0; i--){
        if(num[i] == 0){
            current += (i + 1) * tenToThe(spaceCount);
            spaceCount++;
        }else if(num[i] == 1){
            if(spaceCount != 0){
                current += (i + 1) * tenToThe(spaceCount);
                sum += current;
                current = 0;
                spaceCount = 0;
            }else{
                sum += i + 1;
            }
        }else if(num[i] == 2){
            if(spaceCount != 0){
                current += (i + 1) * tenToThe(spaceCount);
                sum -= current;
                current = 0;
                spaceCount = 0;
            }else{
                sum -= i + 1;
            }
        }
    }
    
    if(sum == 0){
        return true;
    }
        
    return false;
}

void print(int* num, int length){
    out << 1;

    for(int i = 1; i < length; i++){
        if(num[i] == 0){
            out << " ";
        }else if(num[i] == 1){
            out << "+";
        }else if(num[i] == 2){
            out << "-";
        }
        
        out << i + 1;
    }
    
    out << endl;
}

int main(){
    ifstream in ("zerosum.in");
    
    int length;
    
    in >> length;
    
    int current[length] = {0};
    current[0] = 1;
    
    while(current[0] == 1){
        increase(current, length);
        if(check(current, length)){
                print(current, length);
        }
    }
    
    return 0;
}
