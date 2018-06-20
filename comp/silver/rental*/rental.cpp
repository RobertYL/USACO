/*
ID: rob3rty1
PROB: rental
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
    int t = *a;
    *a = *b;
    *b = t;
}

long partition(long arr[], long low, long high){
    long pivot = arr[high];
    long i = (low - 1);
 
    for (long j = low; j <= high- 1; j++){
        if (arr[j] >= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
void quickSort(long arr[], long low, long high){
    if (low < high){
        long pi = partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

long partition2(long arr[], long low, long high, long arr2[]){
    long pivot = arr[high];
    long i = (low - 1);
 
    for (long j = low; j <= high - 1; j++){
        if (arr[j] >= pivot){
            i++;
            swap(&arr[i], &arr[j]);
            swap(&arr2[i], &arr2[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    swap(&arr2[i + 1], &arr2[high]);
    return (i + 1);
}
 
void quickSort2(long arr[], long low, long high, long arr2[]){
    if (low < high){
        long pi = partition2(arr, low, high, arr2);
 
        quickSort2(arr, low, pi - 1, arr2);
        quickSort2(arr, pi + 1, high, arr2);
    }
}

int main(){
    ifstream in ("rental.in");
    ofstream out ("rental.out");
    
    long N, store, rent, a, b, c;
    long long cur = 0, prev = 0;
    long curCow;
    long curStore = 0, gal = 0;
    long curRent = 0;

    in >> N >> store >> rent;

    long milk[N];

    for(int i = 0; i < N; i++){
        in >> milk[i];
    }

	quickSort(milk, 0, N - 1);

    long storeR[store];
    long storeA[store];

	for(int i = 0; i < store; i++){
        in >> a >> b;
        storeR[i] = b;
        storeA[i] = a;
	}

    quickSort2(storeR, 0, store - 1, storeA);

    long rentA[rent];

    for(int i = 0; i < rent; i++){
        in >> rentA[i];
    }

    quickSort(rentA, 0, rent - 1);

    for(int i = 0; i < rent; i++){
        prev += rentA[i];
        
        curRent = i;

        if(i == N - 1)
            break;
    }

    curCow = N - rent;

    if(curCow < 0)
        curCow = 0;

    for(int i = 0; i < N - rent; i++){
        a = milk[i];

        while(a != 0){
            a--;
            gal++;
            prev += storeR[curStore];
            if(gal == storeA[curStore]){
                curStore++;
                if(curStore == store)
                    goto finished;
            }
        }
    }

    finished:

    cur = prev;

    while(curCow != N - 1 && curStore != store){
        cur -= rentA[curRent];
        curRent--;

        a = milk[curCow];

        while(a != 0){
            a--;
            gal++;
            cur += storeR[curStore];
            if(gal == storeA[curStore]){
                curStore++;
                if(curStore == store)
                    goto done;
                gal = 0;
            }
        }

        done:

        if(cur > prev)
            prev = cur;

        curCow++;

    }

    out << prev << endl;

    return 0;
}
