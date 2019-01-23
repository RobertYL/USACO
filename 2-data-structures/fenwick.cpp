#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <cstring>

using namespace std;

int getSum(int BITree[], int index){
    int sum = 0;
    index = index + 1;
    while(index>0){
        sum += BITree[index];
        index -= index & -index;
    }
    return sum;
}

void updateBIT(int BITree[], int n, int index, int val){
    index = index + 1;
    while(index <= n){
        BITree[index] += val;
        index += index & -index;
    } 
} 

int *constructBITree(int arr[], int n){
    int *BITree = new int[n+1];
    memset(BITree, 0, sizeof(BITree));
    
    REP(i, 0, n) updateBIT(BITree, n, i, arr[i]);
    return BITree;
} 

int main(){
    
    return 0;
}
