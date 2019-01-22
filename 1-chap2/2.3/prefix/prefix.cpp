/*
ID: rob3rty1
PROB: prefix
LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main(){
    ifstream in ("prefix.in");
    ofstream out ("prefix.out");
    
    string strings[201];
    int count = 0;
    
    in >> strings[count];
    
    while(strings[count] != "."){
        count++;
        in >> strings[count];
    }
    
    string sequence = "", segment;
    
    in >> segment;
    
    while(!in.eof()){
        sequence += segment;
        in >> segment;
    }
    
    long length = sequence.length(), current;
    
    bool beenThere[length + 1];
    
    for(int i = 0; i < length + 1; i++){
        beenThere[i] = false;
    }
    
    queue<long> queue;
    
    queue.push(0);
    
    while(!queue.empty()){
        current = queue.front();
        queue.pop();
        
        if(current == length){
            break;
        }
        
        for(int i = 0; i < count; i++){
            if(current + strings[i].length() > length){
                goto stop;
            }
            
            if(beenThere[current + strings[i].length()]){
                goto stop;
            }
            
            for(int j = 0; j < strings[i].length(); j++){
                if(strings[i][j] != sequence[current + j]){
                    goto stop;
                }
            }
            
            queue.push(current + strings[i].length());
            beenThere[current + strings[i].length() - 1] = true;
            
            stop:;
        }
    }
    
    bool temp = false;
    
    
    
    /*for(int i = 0; i < length; i++){
        cout << " " << beenThere[i] << endl;
    }*/
    
    for(int i = length - 1; i >= 0; i--){
        if(beenThere[i]){
            out << i + 1 << endl;
            temp = true;
            break;
        }
    }
    
    if(!temp){
        out << 0 << endl;
    }
    
    return 0;
}
