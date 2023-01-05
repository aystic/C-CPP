/*
* @Author: pmohit
* @Date:   2021-09-23 11:53:46
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-09-23 19:53:24
*/
#include<iostream>
#include <vector>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

//O(2^n)
int fib(int n) {
	return (n == 0 or n == 1) ? n : (fib(n - 1) + fib(n - 2));
}

//O(n)=n+n-1 using top down approach
int fib1(int n, vector<int>&dp) {
	return (n == 0 or n == 1) ? n : (dp[n] == -1 ? (dp[n] = fib1(n - 1, dp) + fib1(n - 2, dp)) : dp[n]);
}

//O(n) using bottom up approach
int fib2(int n) {
	vector<int>dp(n + 1, 0);
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}
//bottom up with space optimization
int fib3(int n) {
	vector<int>dp(3, 0);
	dp[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		dp[2] = dp[1] + dp[0];
		dp[0] = dp[1];
		dp[1] = dp[2];
	}
	return dp[2];
}




//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================
	int n;
	cin >> n;
	vector<int>dp(n + 1, -1);
	cout << fib2(n) << endll;
	return 0;
}