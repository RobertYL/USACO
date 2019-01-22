/*
ID: rob3rty1
PROB: mootube
LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <array>

using namespace std;

struct node{
    vector<int> links;
};

int main(){
    ifstream in ("mootube.in");
    ofstream out ("mootube.out");
    
    int N, Q, a, b;
    long c;

    queue<int> queue;

    in >> N >> Q;
    
    node tree[N + 1];
    long R[N + 1][N + 1];

    for(int i = 1; i < N + 1; i++)
        for(int j = 1; j < N + 1; j++)
            R[i][j] = -1;

    for(int i = 1; i < N + 1; i++)
        R[i][i] = 2147483647;

    for(int i = 0; i < N - 1; i++){
        in >> a >> b >> c;
        R[a][b] = c;
        R[b][a] = c;
        tree[a].links.push_back(b);
        tree[b].links.push_back(a);
    }

    for(int i = 1; i < N + 1; i++){
        for(int j = 0; j < tree[i].links.size(); j++){
            queue.push(tree[i].links[j]);
        }

        while(!queue.empty()){
            a = queue.front();
            queue.pop();

            for(int j = 0; j < tree[a].links.size(); j++){
                if(R[i][tree[a].links[j]] == -1){
                    queue.push(tree[a].links[j]);
                }else{
                    R[i][a] = R[i][tree[a].links[j]];
                    if(R[i][a] > R[a][tree[a].links[j]])
                        R[i][a] = R[a][tree[a].links[j]];
                }
            }
        }
    }

    for(int i = 0; i < Q; i++){
        in >> a >> b;
        c = 0;
        for(int i = 1; i < N + 1; i++){
            if(i != b && R[b][i] >= a){
                c++;
            }
        }
        out << c << endl;
    }


    return 0;
}
