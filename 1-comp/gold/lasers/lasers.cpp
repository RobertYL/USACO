/*
ID: rob3rty1
PROB: lasers
LANG: C++11
*/

//Complete 11/11

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int main(){
    ifstream in ("lasers.in");
    ofstream out ("lasers.out");
    
    int N, xl, yl, xb, yb, x, y, f, d;
    
    in >> N >> xl >> yl >> xb >> yb;
    
    N += 2;
    vector<pair<pair<int, int>, int> > Px(N), Py(N);
    vector<vector<int> > G(N);
    
    Px[0] = {{xl, yl}, 0};
    Py[0] = {{yl, xl}, 0};
    Px[1] = {{xb, yb}, 1};
    Py[1] = {{yb, xb}, 1};
    
    for(int i = 2; i < N; i++){
        in >> x >> y;
        Px[i] = {{x, y}, i};
        Py[i] = {{y, x}, i};
    }
    
    sort(Px.begin(), Px.end());
    sort(Py.begin(), Py.end());
    
    /*for(int i = 0; i < N; i++){
        cout << Py[i].first.first << "\t" << Py[i].first.second << "\t" << Py[i].second << endl;
    }*/

    for(int i = 0; i < N - 1; i++){
        if(Px[i].first.first == Px[i+1].first.first)
            G[Px[i].second].push_back(Px[i+1].second);
        else
            G[Px[i].second].push_back(-1);
    }
    G[Px[N-1].second].push_back(-1);
    
    for(int i = 0; i < N-1; i++){
        if(Py[i].first.first == Py[i+1].first.first)
            G[Py[i].second].push_back(Py[i+1].second);
        else
            G[Py[i].second].push_back(-1);
    }
    G[Py[N-1].second].push_back(-1);
    
    for(int i = 1; i < N; i++){
        if(Px[i].first.first == Px[i-1].first.first)
            G[Px[i].second].push_back(Px[i-1].second);
        else
            G[Px[i].second].push_back(-1);
    }
    G[Px[0].second].push_back(-1);
    
    for(int i = 1; i < N; i++){
        if(Py[i].first.first == Py[i-1].first.first)
            G[Py[i].second].push_back(Py[i-1].second);
        else
            G[Py[i].second].push_back(-1);
    }
    G[Py[0].second].push_back(-1);

    deque<int> q;
    
    q.push_back(0);
    q.push_back(1000000);
    q.push_back(2000000);
    q.push_back(3000000);
    q.push_back(-1);
    int m = 0;
    bool found = false;
    
    while(!q.empty()){
        f = q.front();
        q.pop_front();
        
        if(f == -1){
            m++;
            q.push_back(-1);
            if(q.size() == 1){
                break;
            }
            continue;
        }
        
        d = f / 1000000;
        f %= 1000000;
        
        if(G[f][d] == 1){
            found = true;
            break;
        }
        
        if(G[f][d] != -1){
            for(int i = 0; i < 4; i++){
                if((d + 2) % 4 == i){
                    continue;
                }
                    
                if(d == i){
                    q.push_front((d * 1000000) + G[f][d]);
                }else{
                    q.push_back((i * 1000000) + G[f][d]);
                }
            }
        }
    }
    
    if(found){
        out << m << endl;
    }else{
        out << -1 << endl;
    }
    
    return 0;
}
