/*
ID: rob3rty1
PROB: contact
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
    ifstream in ("contact.in");
    ofstream out ("contact.out");
    
    int A, B, N, ;
    vector<bool> sequence;
    string segment;

    in >> A >> B >> N;

    in >> segment;

    while(in.peek() != EOF){
        in >> segment;

        for(int i = 0; i < segment.length(); i++){
            if(segment[i] == '1'){
                sequence.push_back(true);
            }else{
                sequence.push_back(false);
            }
        }
    }

    for(int i = 0; i < sequence.size(); i++){
        for(int j = A; j <= B; j++){
            if(i + j - 1 < sequence.size() - 1){
                for(int k = 0; k < j; k++){
                    
                }
            }
        }
    }

    return 0;
}
