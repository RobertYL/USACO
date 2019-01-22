/*
ID: rob3rty1
PROB: stamps
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
    ifstream in ("stamps.in");
    ofstream out ("stamps.out");
    
    int K, N, cur = 0, actual = 0, largest = 0;
    deque<int> dp;

    in >> K >> N;

    int stamps[N];

    for(int i = 0; i < N; i++){
        in >> stamps[i];

        if(stamps[i] > largest)
            largest = stamps[i];
    }

    dp.push_back(0);

    while(true){
        cur++;
        actual++;
        dp.push_back(K + 1);

        for(int i = 0; i < N; i++){
            if(cur - stamps[i] < 0){
                continue;
            }

            if(dp[cur - stamps[i]] + 1 < dp[cur]){
                dp[cur] = dp[cur - stamps[i]] + 1;
            }
        }

        if(dp.size() > largest + 1){
            dp.pop_front();
            cur--;
        }

        if(dp[cur] > K){
            break;
        }
    }

    out << actual - 1 << endl;
    
    return 0;
}
