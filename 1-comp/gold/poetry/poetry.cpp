/*
ID: rob3rty1
PROB: poetry
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

using namespace std;

long long pow(long long x, long long y, long long p){ 
    long long res = 1;
    x = x % p;
    while(y > 0){
        if(y & 1)
            res = (res * x) % p; 
        y = y >> 1;
        x = (x * x) % p;   
    }
    return res;
}

int main(){
    ifstream in ("poetry.in");
    ofstream cout ("poetry.out");   
    
    long long sol = 1, temp;
    
    int N, M, K, s, c;
    long long P[5000], endP[5000], lines[26];
    char e;
    in >> N >> M >> K;
    
    vector<pair<int, int> > W;
    
    REP(i, 0, N){
        in >> s >> c;
        W.push_back({s, c-1});
    }
    
    //sort(W.begin(), W.end());
    
    memset(P, 0, sizeof(P));
    P[0] = 1;
    REP(i, 0, K){
        REP(j, 0, N){
            if(i + W[j].first < K){
                P[i + W[j].first] += P[i];
                P[i + W[j].first] %= 1000000007;
            }
        }
    }
    
    //REP(i, 0, K)
    //    cout << i << " : " << P[i] << endl;
    
    memset(endP, 0, sizeof(endP));
    REP(j, 0, N){
        endP[W[j].second] += P[K - W[j].first];
        endP[W[j].second] %= 1000000007;
    }
        
    //REP(i, 0, N)
    //    cout << i << " : " << endP[i] << endl;
        
    memset(lines, 0, sizeof(lines));
    REP(i, 0, M){
        in >> e;
        lines[e - 'A']++;
    }
    
    //REP(i, 0, 26)
    //    cout << i << " : " << lines[i] << endl;
    
    //cout << pow(3, 2, 10) << endl;
    
    REP(i, 0, 26){
        if(lines[i] == 0)
            continue;
        //cout << sol << endl;
        temp = 0;
        REP(j, 0, N){
            temp += pow(endP[j], lines[i], 1000000007);
            //cout << j << " : " << temp << endl;
            //cout << "\t" << endP[j] << " : " << lines[i] << " : " << pow(endP[j], lines[i]) << endl;
            temp %= 1000000007;
        }
        if(temp == 0)
            continue;
        sol *= temp;
        sol %= 1000000007;
    }
    
    cout << sol << endl;
    
    return 0;
}
