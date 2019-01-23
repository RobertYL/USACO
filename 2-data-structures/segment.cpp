#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <climits>
#include <iostream>

using namespace std;

const int N = 1e5;  // STree max
int n;  // Actual STree size
int STree[2 * N]; // Range Sum STree
int STreeMin[2 * N]; // Range Minimum STree

int getSum(int l, int r){
    // Query for Range Sum
    int res = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l&1) res += STree[l++];
        if(r&1) res += STree[--r];
    }
    return res;
}

int getMin(int l, int r){
    // Query for Range Minimum
    int res = INT_MAX;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l&1) res = min(res, STreeMin[l++]);
        if(r&1) res = min(res, STreeMin[--r]);
    }
    return res;
}

void update(int i, int value){
    // Update Range Sum STree
    int j = i + n;
    for(STree[i + n] = value; j > 1; j >>= 1) STree[j>>1] = STree[j] + STree[j^1];
    
    // Update Range Minimum STree
    STreeMin[i + n] = STree[i + n];
    for(j = (i + n) >> 1; j > 0; j >>= 1) STreeMin[j] = min(STreeMin[j<<1], STreeMin[j<<1|1]);
} 

void construct(){
    // Construct Range Sum STree
    for(int i = n - 1; i > 0; i--) STree[i] = STree[i<<1] + STree[i<<1|1];
    
    // Construct Range Minimum STree
    for(int i = n; i < 2 * n; i++) STreeMin[i] = STree[i];
    for(int i = n - 1; i > 0; i--) STreeMin[i] = min(STreeMin[i<<1], STreeMin[i<<1|1]);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", STree + n + i);
    construct();
    update(0, 1);
    printf("%d\n", getMin(0, 4));
    return 0;
}
