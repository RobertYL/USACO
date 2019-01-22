/*
ID: rob3rty1
PROB: concom
LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int entries, controls[101][101] = {0}, ownership[101] = {0}, beenThere[101] = {0}, a, b, maximum = 0;

void dfs(int x){
    beenThere[x] = 1;
    for(int i = 1; i <= maximum; i++)
        ownership[i] += controls[x][i];  
    for(int i = 1; i <= maximum; i++)
        if(ownership[i] >= 50 && beenThere[i] != 1 && i != x)
            dfs(i);
}

int main(){
    ifstream in ("concom.in");
    ofstream out ("concom.out");
    
    in >> entries;
    
    for(int i = 0; i < entries; i++){
        in >> a >> b;
        in >> controls[a][b];
        
        if(a > maximum){
            maximum = a;
        }
        if(b > maximum){
            maximum = b;
        }
    }
    
    for(int i = 0; i <= maximum; i++){
        for(int j = 0; j <= maximum; j++){
            ownership[j] = 0;
            beenThere[j] = 0;
        }
        
        dfs(i);
        
        for(int j = 1; j <= maximum; j++){
            if(ownership[j] >= 50 && i != j){
                out << i << " " << j << endl;
            }
        }
    }
    
    return 0;
}
