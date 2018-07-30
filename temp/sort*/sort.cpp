/*
ID: rob3rty1
PROB: sort
LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ifstream in ("sort.in");
    ofstream out ("sort.out");
    
    long N, temp, count = 0;
    
    in >> N;

    vector<long> A;
    A.reserve(100000);
    
    for(long i = 0; i < N; i++){
        in >> temp;
        A.push_back(temp);
    }
    
    bool sorted = false;
    while(!sorted){
        count++;
        sorted = true;
        for(long i = 0; i < N - 1; i++)
            if(A[i + 1] < A[i])
                swap(A[i + 1], A[i]);
                
        for(long i = N - 2; i < -1; i--)
            if(A[i + 1] < A[i])
                swap(A[i + 1], A[i]);
                
        for(long i = 0; i < N - 1; i++)
            if(A[i + 1] < A[i])
                sorted = false;
                
        for(long i = 0; i < N; i++)
            cout << A[i] << " ";
            
        cout << endl;
    }
    
    cout << count << endl;
    
    return 0;
}
