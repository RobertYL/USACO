/*
ID: rob3rty1
PROB: cownav
LANG: C++11
*/

// HOLY CRAP I CAN"T GET THIS TO WORK SO I"M SKIPPING IT
// basically just bfs for all states, each state has 3 or less
// edges to traverse so within time theoretically.

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N;
bool M[20][20];
int D[20][20][4][20][20][4];
int step[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct state{
    int R, C, F;
    int r, c, f;
    
    int dist(){
        return D[R][C][F][r][c][f];
    }
    
    void dist(int x){
        D[R][C][F][r][c][f] = x;
    }
    
    state tR(){
        int nF = (R==2&&C==2)?F:(F+1)%4;
        int nf = (r==2&&c==2)?f:(f+1)%4;
        return state{R,C,nF,r,c,nf};
    }
    
    state tL(){
        int nF = (R==2&&C==2)?F:(F+3)%4;
        int nf = (r==2&&c==2)?f:(f+3)%4;
        return state{R,C,nF,r,c,nf};
    }
    
    state mF(){
        int nR = min(max(R + step[F][0], 0), N-1);
        int nC = min(max(C + step[F][1], 0), N-1);
        if(M[nR][nC] || (R == 2 && C == 2)){
            nR = R;
            nC = C;
        }
        int nr = min(max(r + step[f][0], 0), N-1);
        int nc = min(max(c + step[f][1], 0), N-1);
        if(M[nr][nc] || (r == 2 && c == 2)){
            nr = r;
            nc = c;
        }
        return state{nR,nC,F,nr,nc,f};
    }
};

int main(){
    ifstream in ("cownav.in");
    ofstream out ("cownav.out");
    
    in >> N;

    string row;
    for(int i = N-1; i >= 0; i--){
        in >> row;
        REP(j, 0, N)
            M[i][j] = (row[j] == 'H');
    }
    
    REP(a, 0, N)
    REP(b, 0, N)
    REP(c, 0, 4)
    REP(d, 0, N)
    REP(e, 0, N)
    REP(f, 0, 4)
        D[a][b][c][d][e][f] = INT_MAX;
    D[0][0][0][0][0][1] = 0;
    //0 - Up
    //1 - Right
    //2 - Down
    //3 - Left
    
    queue<state> q;
    q.push(state{0, 0, 0, 0, 0, 1});
    
    state n;
    
    while(!q.empty()){
        state cur = q.front();
        q.pop();
        
        n = cur.tR();
        if(n.dist() != INT_MAX){
            n.dist(cur.dist()+1);
            q.push(n);
        }
        
        n = cur.tL();
        if(n.dist() != INT_MAX){
            n.dist(cur.dist()+1);
            q.push(n);
        }
        
        n = cur.mF();
        if(n.dist() != INT_MAX){
            n.dist(cur.dist()+1);
            q.push(n);
        }
    }
    
    int sol = INT_MAX;
    REP(i, 0, 4)
        REP(j, 0, 4)
            sol = min(sol, D[N-1][N-1][i][N-1][N-1][j]);
    cout << sol << endl;
    
    return 0;
}
