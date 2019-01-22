/*
ID: rob3rty1
PROB: buylow
LANG: C++11
*/

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int longSeq = 0, numSeq = 0, N;
int S[5000], dp[5000];

void recur(int x){
    if(dp[x] == 1)
        numSeq++;
    
    set<int> s;
    
    for(int i = x - 1; i >= 0; i--)
        if(dp[i] + 1 == dp[x] && S[i] > S[x] && s.find(S[x]) == s.end()){
            s.insert(S[i]);
            recur(i);
        }
}


int main(){
    ifstream in ("buylow.in");
    ofstream out ("buylow.out");
    
    in >> N;
    
    REP(i, 0, N)
        in >> S[i];
        
    
    REP(i, 0, N)
        dp[i] = 1;

    REP(i, 0, N)
        REP(j, i+1, N)
            if(S[i] > S[j])
                dp[j] = max(dp[j], dp[i] + 1);
    
    REP(i, 0, N)
        cout << S[i] << "\t" << dp[i] << endl;
                
    REP(i, 0, N)
        longSeq = max(longSeq, dp[i]);
    
    set<int> s;
    
    for(int i = N - 1; i >= 0; i--)
        if(dp[i] == longSeq && s.find(S[i]) == s.end()){
            s.insert(S[i]);
            recur(i);
        }
            
    cout << longSeq << " " << numSeq << endl;
    
    return 0;
}
