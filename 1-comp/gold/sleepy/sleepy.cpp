/*
ID: rob3rty1
PROB: sleepy
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

using namespace std;

int getSum(int fw[], int i){
   int sum = 0;
   i++;  
   while(i > 0){
      sum += fw[i];
      i -= i & (-i);
   }
   return sum;   
}  

void update(int fw[], int n, int i, int newVal){
   i++;
   while (i <= n){
      fw[i] += newVal;
      i += i & (-i);
   } 
}

int *construct(int a[], int n){ 
    int *fw = new int [n+1];
    for (int i = 0; i <= n; i++)
        fw[i] = 0;
    for (int i=0; i<n; i++)
        update(fw, n, i, a[i]);
    return fw;
}

int main(){
    ifstream in ("sleepy.in");
    ofstream cout ("sleepy.out");
    
    int N, n, K;
    in >> N;
    
    vector<int> line;
    REP(i, 0, N){
        in >> n;
        line.push_back(n-1);
    }
    
    int a[N];
    memset(a, 0, sizeof(a));
    int *fw = construct(a, N);
    
    update(fw, N, line[N-1], 1);
    
    for(int i = N-2; i >= 0; i--){
        if(line[i] > line[i+1])
            break;
        update(fw, N, line[i], 1);
    }
    
    K = N - getSum(fw, N);
    
    cout << K << endl;
    
    REP(i, 0, K){
        cout << (K - i - 1) + getSum(fw, line[i]);
        update(fw, N, line[i], 1);
        if(K - 1 != i)
            cout << " ";
        else
            cout << endl;
    }
    
    return 0;
}
