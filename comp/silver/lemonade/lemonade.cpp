/*
ID: rob3rty1
PROB: lemonade
LANG: C++11
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

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
        if (arr[j] >= pivot){
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
    ifstream in ("lemonade.in");
    ofstream out ("lemonade.out");
    
    long N;
    
    in >> N;
    
    long w[N];
    
    for(long i = 0; i < N; i++){
        in >> w[i];
    }
    
    quickSort(w, 0, N - 1);
    
    for(long i = 0; i < N; i++){
        if(w[i] < i){
            out << i << endl;
            break;
        }
        
        if(i == N - 1){
            out << N;
        }
    }

    return 0;
}
