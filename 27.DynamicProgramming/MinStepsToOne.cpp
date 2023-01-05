/*
* @Author: Mohit Pathak
* @Date:   2021-09-23 20:01:18
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-24 20:39:37
*/
#include<iostream>
#include <vector>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================
#define inf 1e8


//using top-down dp
int findMinSteps1(int n, vector<int>&dp) {
	if (n == 1 or dp[n] != 0)return dp[n];
	int first = inf, second = inf, third = inf;
	if (n % 2 == 0)first = 1 + findMinSteps1(n / 2, dp);
	if (n % 3 == 0)second = 1 + findMinSteps1(n / 3, dp);
	third = 1 + findMinSteps1(n - 1, dp);
	return dp[n] = min(first, min(second, third));
}

//using bottom-up dp
int findMinSteps2(int n) {
	vector<int>dp(n + 1, 0);
	for (int i = 2; i <= n; i++) {
		int first = inf, second = inf, third = inf;
		if (i % 2 == 0)first = 1 + dp[i / 2];
		if (i % 3 == 0)second = 1 + dp[i / 3];
		third = 1 + dp[i - 1];
		dp[i] = min(first, min(second, third));
	}
	return dp[n];
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
	vector<int>dp(n + 1, 0);
	cout << findMinSteps1(n, dp) << endll;
	cout << findMinSteps2(n) << endll;
	return 0;
}