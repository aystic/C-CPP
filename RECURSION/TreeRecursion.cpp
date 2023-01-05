/*
* @Author: Mohit Pathak
* @Date:   2021-02-02 11:30:17
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-02 15:43:19
*/

#include<iostream>

using namespace std;

//T : O(2^n) and S : O(n)

void function(int n) {
	if (n > 0) {
		cout << n << " ";
		function(n - 1);
		function(n - 1);
		cout << n << " ";

	}

}


int main() {
	int n = 3;
	function(n);
	cout << endl;
	return 0;
}