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
#include <unordered_map>

using namespace std;

void swap(long* a, long* b){
    long t = *a;
    *a = *b;
    *b = t;
}

long partition (long arr[], long low, long high){
    int pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high- 1; j++){
        if (arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(long arr[], long low, long high)
{
    if (low < high){
        long pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    ifstream in ("sort.in");
    ofstream out ("sort.out");
    
    long N, solution = 0, tempLow, tempHigh, temp;
    
    in >> N;
    
    vector<long> A;
    A.reserve(100000);
    unordered_map<long, long> low, high;
    
    for(long i = 0; i < N; i++){
        in >> temp;
        A.push_back(temp);
    }
    
    for(long i = 0; i < N; i++){
        if(low.count(A[i]) <= 0)
            low[A[i]] = i;
        
        if(high.count(A[N - i - 1]) <= 0)
            high[A[N - i - 1]] = N - i - 1;
    }
    
    sort(A.begin(), A.end());
    
    //for(int i = 0; i < A.size(); i++)
        //cout << A[i] << endl;
    
    for(long i = 0; i < N; i++){
        if(A[i] != A[i - 1]){
            tempLow = low[A[i]] - i;
            
            if(tempLow < 0)
                -tempLow;
                
            if(tempLow > solution)
                solution = tempLow;
        }
        
        if(A[i] != A[i + 1]){
            tempHigh = high[A[i]] - i;
            
            if(tempHigh < 0)
                -tempHigh;
            
            if(tempHigh > solution)
                solution = tempHigh;
        }
    }
    
    out << solution + 1 << endl;
        
    return 0;
}
