/*
ID: rob3rty1
PROG: subset
LANG: C++11
 */
 
// @BEGIN_OF_SOURCE_CODE
 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
 
#define Inf 2147483647
#define Pi acos(-1.0)
#define N 1000000
#define LL long long
 
inline LL Power(int b, int p) { LL ret = 1; for ( int i = 1; i <= p; i++ ) ret *= b; return ret; }
const int dr [] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dc [] = {0, 1, 1, 1, 0, -1, -1, -1};
 
#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(i, x) for(typeof (x.begin()) i = x.begin(); i != x.end (); i++)
#define Set(a, s) memset(a, s, sizeof (a))
#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)
 
using namespace std;
 
long long dp [1600];
 
int main () {
 
    freopen ("subset.in", "r", stdin);
    freopen ("subset.out", "w", stdout);
 
    int n; scanf ("%d", &n);
 
    if ( ((n * (n + 1)) / 2) % 2 ) {
        printf ("0\n"); return 0;
    }
 
    Set (dp, 0);
 
    dp [0] = 1;     // we can make zero in 1 ways
 
    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1599; j >= 0; j-- ) {
            if ( dp [j] && j + i < 1600 )
                dp [j + i] += dp [j];
        }
    }
 
    //printf ("%d\n", ((n * (n + 1)) / 2));
 
 
    cout << dp [(n * (n + 1) / 2) / 2] / 2 << endl;
 
    return 0;
}
