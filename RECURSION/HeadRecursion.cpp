/*
* @Author: pmohit
* @Date:   2021-02-02 11:21:51
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-02 11:26:45
*/

#include<iostream>

using namespace std;

//TimeComplexity : O(n) and SpaceComplexity : O(n) there are n+1 calls
void fucntion(int n) {
	if (n > 0) {
		fucntion(n - 1);
		cout << n << " ";
	}

}

//loop counterpart

// void fucntion(n){
// 	int i=1;
// 	while(i<=n){
// 		cout<<i<<" ";
// 		i++;
// 	}

// }


int main() {
	int n = 10;
	fucntion(n);
	cout << endl;
	return 0;
}