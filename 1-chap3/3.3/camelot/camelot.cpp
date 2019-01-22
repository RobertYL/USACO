/*
ID: rob3rty1
PROB: camelot
LANG: C++11
*/

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main(){
    ifstream in ("camelot.in");
    ofstream out ("camelot.out");
    
    int R, C;
    
    in >> R >> C;
    
    int sol = 1000000;
    int kd[R][C];
    int ktd[R][C];
    memset(ktd, 0, sizeof(ktd));
    bool ktv[R][C][R][C];
    memset(ktv, 0, sizeof(ktv));
    
    int km[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    
    pair<int, int> king;
    char t;
    int u;
    in >> t >> king.first;
    king.first -= 1;
    king.second = t - 'A';
    
    vector<pair<int, int> > knights;
    
    while(in >> t >> u)
        knights.push_back({u - 1, t - 'A'});
    
    queue<pair<int, int> > q;
    
    REP(i, 0, R){
        REP(j, 0, C){
            ktv[i][j][i][j] = true;
            memset(kd, -1, sizeof(kd));
            kd[i][j] = 0;
            
            q.push({i, j});
            
            while(!q.empty()){
                REP(a, 0, 8){
                    int nr = q.front().first + km[a][0], nc = q.front().second + km[a][1];
                    if(nr >= 0 && nr < R && nc >= 0 && nc < C){
                        if(kd[nr][nc] == -1){
                            kd[nr][nc] = kd[q.front().first][q.front().second] + 1;
                            q.push({nr, nc});
                        }
                    }
                }
                q.pop();
            }
            
            /*REP(a, 0, R){
                REP(b, 0, C){
                    cout << kd[a][b] << " ";
                }
                cout << endl;
            }
            cout << endl;*/
            
            REP(k, 0, knights.size())
                ktd[i][j] += kd[knights[k].first][knights[k].second];
                
            REP(k, 0, knights.size()){
                q.push({knights[k].first, knights[k].second});
                
                while(!q.empty()){
                    ktv[i][j][q.front().first][q.front().second] = true;
                    REP(a, 0, 8){
                        int nr = q.front().first + km[a][0], nc = q.front().second + km[a][1];
                        if(nr >= 0 && nr < R && nc >= 0 && nc < C){
                            if(kd[nr][nc] + 1 == kd[q.front().first][q.front().second]){
                                q.push({nr, nc});
                            }
                        }
                    }
                    q.pop();
                }
            }
        }
    }
    
    REP(i, 0, R){
        REP(j, 0, C){
            int ks = 100000;
            REP(a, 0, R){
                REP(b, 0, C){
                    if(ktv[i][j][a][b])
                        if(ks > abs(a - king.first) + abs(b - king.second))
                            ks = abs(a - king.first) + abs(b - king.second);
                }
            }
            
            if(ktd[i][j] + ks < sol)
                sol = ktd[i][j] + ks;
        }
    }
    
    out << sol << endl;
    
    return 0;
}
