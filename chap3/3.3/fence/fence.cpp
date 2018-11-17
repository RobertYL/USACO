/*
ID: rob3rty1
PROB: fence
LANG: C++11
*/

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>

using namespace std;

multiset<int> *fences = new multiset<int>[501];
stack<int> s;
stack<int> p;

void findCircuit(int node){
    if(fences[node].empty()){
        p.push(node);
    }else{
        while(!fences[node].empty()){
            int nnode = *fences[node].begin();
            
            const auto itr = fences[node].find(nnode);
            if(itr!=fences[node].end()){
                fences[node].erase(itr);
            }
            
            const auto itr2 = fences[nnode].find(node);
            if(itr2!=fences[nnode].end()){
                fences[nnode].erase(itr2);
            }
            
            findCircuit(nnode); 
        }
        p.push(node);
    }
}

int main(){
    ifstream in ("fence.in");
    ofstream out ("fence.out");
    
    int N;
    
    in >> N;
    
    REP(i, 0, N){
        int a, b;
        in >> a >> b;
        fences[a].insert(b);
        fences[b].insert(a);
    }
    
    int start = -1;
    
    for(int i = 1; i < 501; i++){
        if(fences[i].size() % 2 == 1){
            start = i;
            break;
        }
    }
    
    if(start == -1){
        for(int i = 1; i < 501; i++){
            if(fences[i].size() > 0){
                start = i;
                break;
            }
        }
    }
    
    findCircuit(start);
    
    while(!p.empty()){
        out << p.top() << endl;
        p.pop();
    }
    
    return 0;
    
    return 0;
}
