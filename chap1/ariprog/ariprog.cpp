/*
ID: rob3rty1
PROG: ariprog
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int length, bisquareSize;
vector<int> bisquares;
bool bisquareNum[250000] = {false};

int main(){
    ofstream out ("ariprog.out");
    ifstream in ("ariprog.in");
    
    in >> length;
    in >> bisquareSize;

    //cout << length << " " << bisquareSize << endl;

    for(int i = 0; i <= bisquareSize; i++){
        for(int j = i; j <= bisquareSize; j++){
            int bisquare = (i*i) + (j*j);
            if(!bisquareNum[bisquare]){
                bisquares.push_back (bisquare);
                bisquareNum[bisquare] = true;
            }
        }
    }

    //cout << "Finished bisquare calculations" << endl;

    sort (bisquares.begin(), bisquares.end());

    bisquares.erase( unique( bisquares.begin(), bisquares.end() ), bisquares.end() );

/*    for(int i = 0; i < bisquares.size(); i++){
        cout << bisquares[i] << ":";
    }*/

    int maxCount = bisquares.size();
    int maxDiff = bisquares[bisquares.size() - 1]/(length - 1);
    int diffNum, temp = 0;

    for(int diff = 1; diff <= maxDiff; diff++){
        for(int start = 0; start < maxCount - length; start++){
            for(diffNum = 1; diffNum <= length - 1; diffNum++){
                
                if(!bisquareNum[bisquares[start] + (diff * diffNum)])
                    break;

                if(diffNum == length - 1){
                    temp = 1;
                    out << bisquares[start] << " " << diff << endl;
                }
            }
        }
    }

    if(temp == 0)
        out << "NONE" << endl;

    return 0;
}
