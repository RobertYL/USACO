/*
ID: rob3rty1
PROB: lamps
LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int cycles[8][6] = {{0,0,0,0,0,0},
                    {0,0,1,1,1,0},
                    {0,1,0,1,0,1},
                    {0,1,1,0,1,1},
                    {1,0,0,1,0,0},
                    {1,0,1,0,1,0},
                    {1,1,0,0,0,1},
                    {1,1,1,1,1,1}};

int main(){
    ifstream in ("lamps.in");
    ofstream out ("lamps.out");
    
    int lampNum, changes, temp;
    
    in >> lampNum >> changes;
    
    int mandatory[6];
    
    for(int i = 0; i < 6; i++){
        mandatory[i] = -1;
    }
    
    while(true){
        in >> temp;
        if(temp == -1){
            break;
        }
        
        mandatory[(temp - 1) % 6] = 1;
    }
    
    while(true){
        in >> temp;
        if(temp == -1){
            break;
        }
        
        if(mandatory[(temp - 1) % 6] == 1){
            goto fail;
        }
        
        mandatory[(temp - 1) % 6] = 0;
    }
    
    temp = 0;
    
    if(changes == 0){
        for(int i = 0; i < 6; i++){
            if(mandatory[i] == 0){
                goto fail;
            }
        }
        
        for(int i = 0; i < lampNum; i++){
            out << 1;
        }
        
        out << endl;
    }else if(changes == 1){
        int smth[4] = {0,2,3,5};
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 6; j++){
                if(mandatory[j] != -1 && mandatory[j] != cycles[smth[i]][j]){
                    goto no;
                }
            }
            
            temp = 1;
            
            for(int j = 0; j < lampNum; j++){
                out << cycles[smth[i]][j % 6];
            }
            
            out << endl;
            
            no:;
        }
        
        if(temp == 0){
            goto fail;
        }
    }else{
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 6; j++){
                if(mandatory[j] != -1 && mandatory[j] != cycles[i][j]){
                    goto no1;
                }
            }
            
            temp = 1;
            
            for(int j = 0; j < lampNum; j++){
                out << cycles[i][j % 6];
            }
            
            out << endl;
            
            no1:;
        }
        
        if(temp == 0){
            goto fail;
        }
    }
    
    if(false){
        fail:
        out << "IMPOSSIBLE" << endl;
    }
    
    return 0;
}
