/*
ID: rob3rty1
PROB: measurement
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

long measurements, initialMilk; 

void swap(long* a, long* b)
{
    long t = *a;
    *a = *b;
    *b = t;
}

int partition (long* arr, long* arr1, long* arr2, long low, long high)
{
    long pivot = arr[high];
    long i = (low - 1);
 
    for (long j = low; j <= high- 1; j++){
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
            swap(&arr1[i], &arr1[j]);
            swap(&arr2[i], &arr2[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    swap(&arr1[i + 1], &arr1[high]);
    swap(&arr2[i + 1], &arr2[high]);
    return (i + 1);
}
 
void quickSort(long* arr, long* arr1, long* arr2, long low, long high){
    if (low < high){
        long pi = partition(arr, arr1, arr2, low, high);
        quickSort(arr, arr1, arr2, low, pi - 1);
        quickSort(arr, arr1, arr2, pi + 1, high);
    }
}

int main(){
    ifstream in ("measurement.in");
    ofstream out ("measurement.out");
    
    in >> measurements >> initialMilk;
    
    long days[measurements], IDs[measurements], change[measurements], largest = 0;
    
    unordered_map<long, long> current;
    
    for(long i = 0; i < measurements; i++){
    	in >> days[i] >> IDs[i] >> change[i];
    	current[IDs[i]] = 0;
    }
    
    quickSort(days, IDs, change, 0, measurements - 1);
    
    for(long i = 0; i < measurements, i++){
    	
    }
    
    return 0;
}
