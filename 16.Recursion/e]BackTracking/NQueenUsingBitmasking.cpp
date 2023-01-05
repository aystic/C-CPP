/*
* @Author: Mohit Pathak
* @Date:   2021-08-26 16:01:44
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-08-26 17:42:43
*/


#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================
int DONE;
void display(int arr[][20], int n) {
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (arr[i][j] == 1)cout << "Q ";
			else cout << "_ ";
		}
		cout << endll;
	}
	cout << endll;
}

// bool solveNQueen(int rw, int l, int r, int n, int arr[][20]) {
// 	if (rw == DONE) {
// 		display(arr, n);
// 		return true;
// 	}
// 	int safe = DONE & (~(rw | l | r));
// 	for (int i = 0; i < n; ++i)
// 	{
// 		l = rw << 1;
// 		r = rw >> 1;
// 		safe = ~(rw | l | r);


// 	}
// }


//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	int n;
	cin >> n;
	int arr[20][20] {};
	int rw = 1, l = 0, r = 0;
	DONE = (1 << n) - 1;
	// solveNQueen(rw, l, r);
	return 0;
}
