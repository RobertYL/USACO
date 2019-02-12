/*
ID: rob3rty1
PROB: cardgame
LANG: C++11
*/

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	ifstream in ("cardgame.in");
    ofstream out ("cardgame.out");
    
    int N, score = 0;
    in >> N;
    
    int EC[2*N];
    bool bc[2*N];
    memset(bc, 1, sizeof(bc));
    
    REP(i, 0, N){
        in >> EC[i];
        EC[i]--;
        bc[EC[i]] = 0;
    }
    
    int prefix[N + 1], suffix[N + 1];
    set<int> BC;
    
    REP(i, 0, 2*N){
        if(bc[i])
            BC.insert(i);
    }
    
    set<int>::iterator it;
    
    prefix[0] = 0;
    REP(i, 1, N + 1){
        it = BC.lower_bound(EC[i - 1]);
        
        if(it != BC.end()){
            BC.erase(it);
            score++;
        }
        prefix[i] = score;
    }

    
    
    BC.clear();
    
    REP(i, 0, 2*N){
        if(bc[i])
            BC.insert(i);
    }
    
    score = 0;

    suffix[N] = 0;
    REP(i, 0, N){
        it = BC.lower_bound(EC[N - i - 1]);
        it--;
        if(it != BC.end()){
            //cout << i << " : \t" << *it << endl;
            BC.erase(it);
            score++;
        }
        suffix[N - i - 1] = score;
    }
    
    //REP(i, 0, N + 1)
    //    cout << i << " : \t" << prefix[i] << "\t" << suffix[i] << endl; 
    
    score = 0;
    REP(i, 0, N + 1)
        score = max(score, prefix[i] + suffix[i]);
    
    out << score << endl;
    
    return 0;
}
