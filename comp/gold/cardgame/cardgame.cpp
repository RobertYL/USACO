/*
ID: rob3rty1
PROB: cardgame
LANG: C++11
*/

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ifstream in ("cardgame.in");
    ofstream out ("cardgame.out");
    
    int N, t, sol = 0;
    
    in >> N;
    
    vector<int> high(N/2), low(N/2), highB, lowB;
    bool E[2*N];
    
    for(int i = 0; i < 2*N; i++){
        E[i] = false;
    }
    
    for(int i = 0; i < N/2; i++){
        in >> t;
        high[i] = t;
        E[t - 1] = true;
    }
    
    for(int i = 0; i < N/2; i++){
        in >> t;
        low[i] = t;
        E[t - 1] = true;
    }
    
    for(int i = 0; i < 2*N; i++){
        if(!E[i]){
            if(lowB.size() < N/2){
                lowB.push_back(i + 1);
            }else{
                highB.push_back(i + 1);
            }
        }
    }
    
    sort(high.begin(), high.end());
    sort(low.begin(), low.end());
    
    t = 0;
    
    for(int i = 0; i < N/2; i++){
        while(highB[t] < high[i]){
            t++;
            if(t == N/2)
                goto finish;
        }
        sol++;
        t++;
        if(t == N/2)
            goto finish;
    }
    
    finish:;
    
    t = (N/2) - 1;
    
    for(int i = (N/2) - 1; i > -1; i--){
        while(lowB[t] > low[i]){
            t--;
            if(t == -1)
                goto finish2;
        }
        sol++;
        t--;
        if(t == -1)
            goto finish2;
    }
    
    finish2:;
    
    out << sol << endl;
    
    return 0;
}
