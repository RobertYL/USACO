/*
ID: rob3rty1
PROB: multimoo
LANG: C++11
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;    

int N, size, maxSolo = 0, maxDuo = 0;
long board[250][250];
bool visited[250][250], visited2[250][250];
set<long> touching;
unordered_map<long, set<long> > done;

bool check(int i, int j, long a){
    if(i < 0 || j < 0 || i >= N || j >= N)
        return false;
    
    if(board[i][j] != a){
        touching.insert(board[i][j]);
        return false;
    }
    
    if(visited[i][j])
        return false;

    return true;
}

void dfs(int i, int j){
    if(check(i + 1, j, board[i][j])){
        size++;
        visited[i + 1][j] = 1;
        dfs(i + 1, j);
    }
        
    if(check(i - 1, j, board[i][j])){
        size++;
        visited[i - 1][j] = 1;
        dfs(i - 1, j);
    }
    
    if(check(i, j + 1, board[i][j])){
        size++;
        visited[i][j + 1] = 1;
        dfs(i, j + 1);
    }
    
    if(check(i, j - 1, board[i][j])){
        size++;
        visited[i][j - 1] = 1;
        dfs(i, j - 1);
    }
}

bool check2(int i, int j, long a, long b){
    if(i < 0 || j < 0 || i >= N || j >= N)
        return false;
    
    if(board[i][j] != a && board[i][j] != b){
        return false;
    }
    
    if(visited2[i][j])
        return false;

    return true;
}

void dfs2(int i, int j, long a, long b){
    if(check2(i + 1, j, a, b)){
        size++;
        visited2[i + 1][j] = 1;
        dfs2(i + 1, j, a, b);
    }
        
    if(check2(i - 1, j, a, b)){
        size++;
        visited2[i - 1][j] = 1;
        dfs2(i - 1, j, a, b);
    }
    
    if(check2(i, j + 1, a, b)){
        size++;
        visited2[i][j + 1] = 1;
        dfs2(i, j + 1, a, b);
    }
    
    if(check2(i, j - 1, a, b)){
        size++;
        visited2[i][j - 1] = 1;
        dfs2(i, j - 1, a, b);
    }
}

bool notdone(long a, long b){
    if(done.count(b) <= 0){
        return true;
    }else{
        if(done[b].count(a) <= 0){
            return true;
        }
    }
    
    return false;
}

int main(){
    ifstream in ("multimoo.in");
    ofstream out ("multimoo.out");
    
    in >> N;
    
    memset(visited, 0, sizeof(visited));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            in >> board[i][j];
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j]){

                size = 1;
                visited[i][j] = true;
                
                dfs(i, j);
                
                if(size > maxSolo)
                    maxSolo = size;
                    
                for(auto elem: touching){
                    if(notdone(board[i][j], elem)){
                        memset(visited2, 0, sizeof(visited2));
                        size = 1;
                        visited2[i][j] = true;
                        
                        dfs2(i, j, board[i][j], elem);
                        
                        if(size > maxDuo)
                            maxDuo = size;
                    }
                    done[board[i][j]].insert(elem);
                }
                touching.clear();
            }
        }
    }
    
    out << maxSolo << endl;
    out << maxDuo << endl;
    
    return 0;
}
