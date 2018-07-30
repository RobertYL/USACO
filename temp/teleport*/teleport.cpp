/*
ID: rob3rty1
PROB: teleport
LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main(){
    ifstream in ("teleport.in");
    ofstream out ("teleport.out");
    
    int N;
    long long solution = 0;
    
    in >> N;
    
    vector<long> optimalLoc, save;
    long a2b[N][2], a, b;
    
    for(int i = 0; i < N; i++){
        in >> a >> b;
        if(a > b){
            a2b[i][0] = a;
            a2b[i][1] = b;
            solution += a - b;
        }else{
            a2b[i][0] = b;
            a2b[i][1] = a;
            solution += b - a;
        }
        
        if(a2b[i][0] >= 0 && a2b[i][1] >= 0){
            if(a2b[i][0] - a2b[i][1] > a2b[i][1]){
                optimalLoc.push_back(a2b[i][1]);
                save.push_back(a2b[i][0] - (2*a2b[i][1]));
            }
        }else if(a2b[i][0] <= 0 && a2b[i][1] <= 0){
            if(a2b[i][1] - a2b[i][0] > -a2b[i][0]){
                optimalLoc.push_back(a2b[i][1]);
                save.push_back(-a2b[i][1]);
            }
        }else{
            optimalLoc.push_back(a2b[i][0]);
            save.push_back(a2b[i][0]);
            
            optimalLoc.push_back(a2b[i][1]);
            save.push_back(-a2b[i][1]);
        }
    }
    
    map<long, unsigned long> road;
    
    for(int i = 0; i < optimalLoc.size(); i++){
        for(int j = 1; j < save[i]; j++){
            if(road.count(optimalLoc[i] - j) == 0)
                road[optimalLoc[i] - j] = 0;
            road[optimalLoc[i] - j] += save[i] - j;
            if(road.count(optimalLoc[i] + j) == 0)
                road[optimalLoc[i] + j] = 0;
            road[optimalLoc[i] + j] += save[i] - j;
        }
        if(road.count(optimalLoc[i]) == 0)
            road[optimalLoc[i]] = 0;
        road[optimalLoc[i]] += save[i];
    }
    
    a = 0;
    
    for(map<long, unsigned long>::iterator x=road.begin(); x != road.end(); x++){
        if(x->second > a)
            a = x->second;
    }
    
    out << solution - a << endl;
    
    return 0;
}
