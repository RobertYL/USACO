/*
ID: rob3rty1
PROB: distant
LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ifstream in ("distant.in");
    ofstream out ("distant.out");
    
    long N, A, B, max = 0;
    string row;
    char grass;

    in >> N >> A >> B;

    char pasture[N][N];
    long dist[N * N][N * N];

    for(int i = 0; i < N; i++){
        in >> row;

        for(int j = 0; j < N; j++){
            pasture[i][j] = row[j];
        }
    }

    for(int i = 0; i < N * N; i++){
        for(int j = 0; j < N * N; j++){
            dist[i][j] = 2000000000;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            grass = pasture[i][j];
            
            if(i != 0){
                if(pasture[i - 1][j] == grass){
                    dist[(N * (i - 1)) + j][(N * i) + j] = A;
                    dist[(N * i) + j][(N * (i - 1)) + j] = A;
                }else{
                    dist[(N * (i - 1)) + j][(N * i) + j] = B;
                    dist[(N * i) + j][(N * (i - 1)) + j] = B;
                }
            }

            if(i != N - 1){
                if(pasture[i + 1][j] == grass){
                    dist[(N * (i + 1)) + j][(N * i) + j] = A;
                    dist[(N * i) + j][(N * (i + 1)) + j] = A;
                }else{
                    dist[(N * (i + 1)) + j][(N * i) + j] = B;
                    dist[(N * i) + j][(N * (i + 1)) + j] = B;
                }
            }

            if(j != 0){
                if(pasture[i][j - 1] == grass){
                    dist[(N * i) + j - 1][(N * i) + j] = A;
                    dist[(N * i) + j][(N * i) + j - 1] = A;
                }else{
                    dist[(N * i) + j - 1][(N * i) + j] = B;
                    dist[(N * i) + j][(N * i) + j - 1] = B;
                }
            }

            if(j != N - 1){
                if(pasture[i][j + 1] == grass){
                    dist[(N * i) + j + 1][(N * i) + j] = A;
                    dist[(N * i) + j][(N * i) + j + 1] = A;
                }else{
                    dist[(N * i) + j + 1][(N * i) + j] = B;
                    dist[(N * i) + j][(N * i) + j + 1] = B;
                }
            }
        }
    }
    
    for(int i = 0; i < N * N; i++){
        for(int j = 0; j < N * N; j++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    
    for(int i = 0; i < N * N; i++)
        dist[i][i] = 0;

    for(int k = 0; k < N * N; k++){
        for(int i = 0; i < N * N; i++){
            for(int j = 0; j < N * N; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    for(int i = 0; i < N * N; i++)
        for(int j = 0; j < N * N; j++)
            if(max < dist[i][j])
                max = dist[i][j];
                
    out << max << endl;

    return 0;
}
