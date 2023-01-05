/*
* @Author: Mohit Pathak
* @Date:   2021-02-02 11:26:55
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-02 11:29:32
*/

#include<iostream>

using namespace std;

//T: O(n) and S: O(n)
void function(int n) {

	if (n > 0) {
		cout << n << " ";
		function(n - 1);
	}
}

//loop counterpart of the above function

// void function(int n){
// 	while(n>0){
// 		cout<<n<<" ";
// 		n--;
// 	}

// }

int main() {
	int n = 10;
	function(n);
	cout << endl;
	return 0;
}