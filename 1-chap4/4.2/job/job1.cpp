/*
ID: rob3rty1
PROB: job
LANG: C++
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
#include <bits/stdc++.h>

using namespace std;

int n, a, b;

int A[35], B[35];

map<int, vector<int> > M;
int test[35];
int r1 = 0 , r2 = 0;
int solve() {
 int tmp = n;
 vector<int> outing , outing2;
 while (tmp) {
  memset(test, 0, sizeof test);
  for (int i = 0; i < a; i++) {
   int t = 0;
   if (M.find(i) != M.end()) {
    vector<int>&v = M[i];
    int len = v.size();
    t = v[len - 1];
   }
   test[i] = t + A[i];
  }

  int id = 0, mn = 1 << 30;
  for (int i = 0; i < a; i++) {
   if (test[i] < mn) {
    mn = test[i];
    id = i;
   }
  }
  tmp--;
  M[id].push_back(mn);
  r1 = max(r1, mn);
  outing.push_back(mn);
 }
 M.clear();
 sort(outing.begin() , outing.end());
 for (tmp = 0; tmp < n; tmp++) {
  memset(test, 0, sizeof test);
  for (int i = 0; i < b; i++) {
   int t = 0;
   if (M.find(i) != M.end()) {
    vector<int>&v = M[i];
    int len = v.size();
    t = v[len - 1];
   }
   test[i] = t + B[i];
  }
  int id = 0, mn = 1 << 30;
  for (int i = 0; i < b; i++) {
   if (test[i] < mn) {
    mn = test[i];
    id = i;
   }
  }
  M[id].push_back(mn);
  r2 =mn =max(mn , r2);
  outing2.push_back(mn);
 }

 sort(outing2.rbegin() , outing2.rend());
 for(int i=0 ; i < int(outing.size()) ; i++){
  r2 = max(r2 , outing[i] + outing2[i] ) ;
 }
 cout<<r1<<" " << r2 <<endl;
 return 0;
}

int main() {
 freopen("job.in","r",stdin);
 freopen("job.out","w",stdout);
 cin >> n >> a >> b;
 for (int i = 0; i < a; i++)
  cin >> A[i];
 for (int j = 0; j < b; j++)
  cin >> B[j];
 sort(A, A + a);
 sort(B, B + b);
 solve();

}
