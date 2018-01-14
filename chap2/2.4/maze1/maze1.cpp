/*
ID: rob3rty1
PROB: maze1
LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int main(){
    ifstream in ("maze1.in");
    ofstream out ("maze1.out");
    
    int W, H;
    string row;
    
    in >> W >> H;
    
    bool rooms[(2 * H) + 1][(2 * W) + 1];
    int distance[H][W];
    deque<int> entrances;
    char temp;

    for(int i = 0; i < (2 * H) + 1; i++){
        for(int j = 0; j < (2 * W) + 1; j++){
            rooms[i][j] = false;
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            distance[i][j] = 4000;
        }
    }

    getline(in, row);

    for(int i = 0; i < (2 * H) + 1; i++){
        getline(in, row);
        for(int j = 0; j < (2 * W) + 1; j++){
            if(row[j] == ' '){
                rooms[i][j] = true;
                if(i == 0){
                    entrances.push_back((j - 1) / 2);
                    entrances.push_back(i / 2);
                    rooms[i][j] = false;
                    distance[i / 2][(j - 1) / 2] = 1;
                }else if(i == 2 * H){
                    entrances.push_back((j - 1) / 2);
                    entrances.push_back((i / 2) - 1);
                    rooms[i][j] = false;
                    distance[(i / 2) - 1][(j - 1) / 2] = 1;
                }else if(j == 0){
                    entrances.push_back(j / 2);
                    entrances.push_back((i - 1) / 2);
                    rooms[i][j] = false;
                    distance[(i - 1) / 2][j / 2] = 1;
                }else if(j == 2 * W){
                    entrances.push_back((j / 2) - 1);
                    entrances.push_back((i - 1) / 2);
                    rooms[i][j] = false;
                    distance[(i - 1) / 2][(j / 2) - 1] = 1;
                }
            }
        }
    }

    int cX, cY;

    /*for(int i = 0; i < (2 * H) + 1; i++){
        for(int j = 0; j < (2 * W) + 1; j++){
            cout << rooms[i][j];
        }
        cout << endl;
    }*/

    //cout << entrances.size() << endl;

    while(!entrances.empty()){
        cX = entrances.front();
        entrances.pop_front();
        cY = entrances.front();
        entrances.pop_front();

        if(rooms[(2 * cY)][(2 * cX) + 1]){
            if(distance[cY - 1][cX] > distance[cY][cX] + 1){
                distance[cY - 1][cX] = distance[cY][cX] + 1;
                entrances.push_front(cY - 1);
                entrances.push_front(cX);
            }
        }
        
        if(rooms[(2 * cY) + 1][(2 * cX) + 2]){
            if(distance[cY][cX + 1] > distance[cY][cX] + 1){
                distance[cY][cX + 1] = distance[cY][cX] + 1;
                entrances.push_front(cY);
                entrances.push_front(cX + 1);
            }
        }
        
        if(rooms[(2 * cY) + 2][(2 * cX) + 1]){
            if(distance[cY + 1][cX] > distance[cY][cX] + 1){
                distance[cY + 1][cX] = distance[cY][cX] + 1;
                entrances.push_front(cY + 1);
                entrances.push_front(cX);
            }
        }
        
        if(rooms[(2 * cY) + 1][(2 * cX)]){
            if(distance[cY][cX - 1] > distance[cY][cX] + 1){
                distance[cY][cX - 1] = distance[cY][cX] + 1;
                entrances.push_front(cY);
                entrances.push_front(cX - 1);
            }
        }
    }
    
    int max = 0;

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(distance[i][j] > max){
                max = distance[i][j];
            }
        }
    }

    out << max << endl;

    return 0;
}
