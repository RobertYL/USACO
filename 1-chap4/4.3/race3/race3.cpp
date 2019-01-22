/*   
ID: rob3rty1
PROB: race3
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
#include <queue>

using namespace std;

int main(){
    ifstream in ("race3.in");
    ofstream cout ("race3.out");
    
    int a, b, N = -1;
    in >> a;
    
    vector<vector<int> > dg, udg;
    
    while(a != -1){
        vector<int> node;
        while(a != -2){
            node.push_back(a);
            in >> a;
        }
        dg.push_back(node);
        N++;
        in >> a;
    }
    
    REP(i, 0, N + 1){
        vector<int> node;
        udg.push_back(node);
    }
    
    REP(i, 0, N + 1){
        REP(j, 0, dg[i].size()){
            udg[i].push_back(dg[i][j]);
            udg[dg[i][j]].push_back(i);
        }
    }
    
    queue<int> dgSol;
    
    REP(a, 1, N + 1){
        bool v[N + 1];
        REP(i, 0, N + 1)
            v[i] = false;
        
        v[0] = true;
        v[a] = true;
        
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            int n = q.front();
            q.pop();
            REP(i, 0, dg[n].size()){
                if(!v[dg[n][i]]){
                    q.push(dg[n][i]);
                    v[dg[n][i]] = true;
                }
            }
        }
        
        if(!v[N])
            dgSol.push(a);
    }
    
    cout << dgSol.size();
    while(!dgSol.empty()){
        cout << " " << dgSol.front();
        dgSol.pop();
    }
    cout << endl;
    
    
    
    
    queue<int> udgSol;
    
    REP(a, 1, N + 1){
        bool v[N + 1];
        REP(i, 0, N + 1)
            v[i] = false;
        
        v[0] = true;
        v[a] = true;
        
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            int n = q.front();
            q.pop();
            REP(i, 0, udg[n].size()){
                if(!v[udg[n][i]]){
                    q.push(udg[n][i]);
                    v[udg[n][i]] = true;
                }
            }
        }
        
        if(!v[N]){
            REP(i, 0, dg[a].size()){
                if(v[dg[a][i]] && dg[a][i] != a)
                    goto skip;
            }
            udgSol.push(a);
        }
        skip:;
    }
    
    cout << udgSol.size();
    while(!udgSol.empty()){
        cout << " " << udgSol.front();
        udgSol.pop();
    }
    cout << endl;
    
    return 0;
}
