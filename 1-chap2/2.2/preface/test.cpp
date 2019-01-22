#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int generate(int* numeralSum){
	cout << numeralSum[5] << endl;
	numeralSum[5] = 10;
}

int main(){
	int temp[7] = {0, 1, 2, 3, 4, 5, 6};
	
	generate(temp);
	
	cout << temp[5] << endl;

	return 0;
}
