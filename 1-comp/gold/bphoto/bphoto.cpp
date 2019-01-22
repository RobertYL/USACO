/*
ID: rob3rty1
PROB: bphoto
LANG: C++11
*/

//Incomplete 2/10

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <bits/stdc++.h>

using namespace std;

/* Updates element at index 'i' of BIT. */
void update(int i, int add, vector<int>& BIT)
{
    while (i > 0 && i < BIT.size())
    {
        BIT[i] += add;
        i = i + (i & (-i));
    }
}
 
/* Returns cumulative sum of all elements of
   fenwick tree/BIT from start upto and
   including element at index 'i'. */
int sum(int i, vector<int>& BIT)
{
    int ans = 0;
    while (i > 0)
    {
        ans += BIT[i];
        i = i - (i & (-i));
    }
 
    return ans;
}

// Insert x into BIT. We masically increment
// rank of all elements greater than x.
void insertElement(int x, vector<int> &BIT)
{
    update(x, 1, BIT);
}

int findRank(int x, vector<int> &BIT)
{
    return sum(x, BIT);
}

int main(){
    ifstream in ("bphoto.in");
    ofstream out ("bphoto.out");
    
    int N, t, sol = 0, a, b;
    vector<int> BIT(1000002);
    
    in >> N;
    
    vector<pair<int, int> > h(N);
    
    for(int i = 0; i < N; i++){
        in >> t;
        h[i] = {t, i + 1};
    }
    
    sort(h.begin(), h.end());
    
    for(int i = N - 1; i >= 0; i--){
        insertElement(h[i].second, BIT);
        
        b = findRank(h[i].second, BIT);
        t = N - b - i;
        
        a = min(b, t);
        b = max(b, t);
                
        if(a * 2 < b){
            sol++;
        }
    }
    
    cout << sol << endl;
    
    return 0;
}
