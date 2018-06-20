/*
ID: rob3rty1
PROB: lightson
LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

struct room{
    vector<int> switchX;
    vector<int> switchY;
};

int main(){
    ifstream in ("lightson.in");
    ofstream out ("lightson.out");
    
    int N, M, x, y, a, b;

    in >> N >> M;

    room barn[N][N];
    bool lit[N][N], visited[N][N];
    queue<int> flickX, flickY;

    for(int i = 0; i < M; i++){
        in >> x >> y >> a >> b;

        barn[y - 1][x - 1].switchX.push_back(a - 1);
        barn[y - 1][x - 1].switchY.push_back(b - 1);
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            lit[i][j] = false;
            visited[i][j] = false;
        }
    }

    lit[0][0] = true;
    visited[0][0] = true;
    a = 0;

    flickX.push(0);
    flickY.push(0);

    while(!flickX.empty()){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << lit[i][j];
            //visited[i][j] = false;
        }
        cout << endl;
    }

    cout << endl;
        while(!flickX.empty()){
            x = flickX.front();
            flickX.pop();
            y = flickY.front();
            flickY.pop();

            for(int i = 0; i < barn[y][x].switchX.size(); i++){
                lit[barn[y][x].switchY[i]][barn[y][x].switchX[i]] = true;
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(visited[i][j]){
                    if(j != 0){
                        if(lit[i][j - 1] && !visited[i][j - 1]){
                            flickX.push(j - 1);
                            flickY.push(i);
                            visited[i][j - 1] = true;
                        }
                    }
                    if(i != 0){
                        if(lit[i - 1][j] && !visited[i - 1][j]){
                            flickX.push(j);
                            flickY.push(i - 1);
                            visited[i - 1][j] = true;
                        }
                    }
                    if(j != N - 1){
                        if(lit[i][j + 1] && !visited[i][j + 1]){
                            flickX.push(j + 1);
                            flickY.push(i);
                            visited[i][j + 1] = true;
                        }
                    }
                    if(i != N - 1){
                        if(lit[i + 1][j] && !visited[i + 1][j]){
                            flickX.push(j);
                            flickY.push(i + 1);
                            visited[i + 1][j] = true;
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << lit[i][j];
            //visited[i][j] = false;
        }
        cout << endl;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(lit[i][j]){
                a++;
            }
        }
    }

    out << a << endl;

    return 0;
}
