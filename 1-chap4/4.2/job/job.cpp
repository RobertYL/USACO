/*
ID: rob3rty1
PROB: job
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
#include <list>
#include <climits>

using namespace std;

int solA = 0, solB = 0;

void insert(vector<int>& t, vector<list<int> >& q, int curT, int size){
    int sol, minT = INT_MAX;

    REP(i, 0, size){
        if(curT < q[i].back()){
            if(q[i].back() + t[i] < minT){
                minT = q[i].back() + t[i];
                sol = i;
            }
        }else{
            if(curT + t[i] < minT){
                minT = curT + t[i];
                sol = i;
            }
            
        }
    }
    
    q[sol].push_back(minT);
}

int main(){
    ifstream in ("job.in");
    ofstream out ("job.out");
    
    int N, M1, M2;
    in >> N >> M1 >> M2;
    
    vector<int> At, Bt;
    At.reserve(M1);
    Bt.reserve(M2);
    
    REP(i, 0, M1) in >> At[i];
    REP(i, 0, M2) in >> Bt[i];
        
    vector<list<int> > A, B;
    list<int> temp;
    temp.push_back(0);
    REP(i, 0, M1) A.push_back(temp);
    REP(i, 0, M2) B.push_back(temp);
    
    REP(j, 0, N){
        int sol, minT = INT_MAX;

        REP(i, 0, M1){
            if(0 < A[i].back()){
                if(A[i].back() + At[i] < minT){
                    minT = A[i].back() + At[i];
                    sol = i;
                }
            }else{
                if(0 + At[i] < minT){
                    minT = 0 + At[i];
                    sol = i;
                }
                
            }
        }
        
        A[sol].push_back(minT);
    }
        
    
    vector<int> a2b;
    
    REP(i, 0, N){
        int sol, minT = INT_MAX;
        
        REP(j, 0, M1){
            cout << A[j].front() << endl;
        
            if(minT > A[j].front()){
                minT = A[j].front();
                sol = j;
            }
        }
    
        a2b.push_back(minT);
        //cout << A[sol].size() << endl;
        A[sol].pop_front();
    }
    
    solA = a2b.back();
    
    
    
    return 0;
}
