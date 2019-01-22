/*
ID: rob3rty1
PROB: holstein
LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <queue>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int trailingZeros(unsigned int num) {
    int bits = 0;

    if (num) {
        while ((num & 1) == 0) {
            bits++;
            num >>= 1;
        }
    }
    return bits;
}

bool isBitSet(unsigned int num, int bit){
    return 1 == ( (num >> bit) & 1);
}

int main(){
    ifstream in ("holstein.in");
    ofstream out ("holstein.out");

    int nTypes = 0;

    in >> nTypes;
    
    int nTarget[nTypes];

    for(int i = 0; i < nTypes; i++)
        in >> nTarget[i];

    int nFeed = 0;

    in >> nFeed;
    
    int nFeeds[nFeed][nTypes];

    for(int i = 0; i < nFeed; i++)
        for(int j = 0; j < nTypes; j++)
            in >> nFeeds[i][j];
            
    queue<unsigned int> queue;
    unsigned int temp = 0;
    
    for(int i = 0; i < nFeed; i++){
        temp |= (1u << nFeed - i - 1);
        queue.push(temp);
        temp = 0;
    }
    
    unsigned int current;
    int testArea[nTypes];
    int numOfFeed = 0;
    
    while (!queue.empty()){
        current = queue.front();
        
        numOfFeed = 0;
        for(int i = 0; i < nTypes; i++)
            testArea[i] = 0;
        
        for(int i = nFeed - 1; i >= 0; i--){
            if(isBitSet(current, i)){
                numOfFeed++;
                for(int j = 0; j < nTypes; j++){
                    testArea[j] += nFeeds[nFeed - i - 1][j];
                }                
            }
        }
        
        for(int i = 0; i < nTypes; i++){
            if(testArea[i] < nTarget[i])
                goto contin;
        }      
        
        out << numOfFeed;
        
        for(int i = nFeed - 1; i >= 0; i--)
            if(isBitSet(current, i))
                out << ' ' << nFeed - i;
                
        break; 
        
        contin:
        
        unsigned int temp1 = 0;
        
        for(int i = 0; i < trailingZeros(current); i++){
            temp1 = current;
            temp1 |= (1u << trailingZeros(current) - i - 1);
            queue.push(temp1);
            temp1 = 0;
        }
        
        queue.pop();
    }
    
    out << endl;

    return 0;
}
