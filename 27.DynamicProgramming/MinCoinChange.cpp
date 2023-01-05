/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-24 21:30:43
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-24 23:17:27
*/
#include<iostream>
#include <vector>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

#define inf 1e5
//using top-down approach


// int findMinCoins(int n, vector<int>&dp) {
// 	if (dp[n] != inf)return dp[n];
// 	int first, second, third;
// 	first = second = third = inf;
// 	if (n > 1)first = 1 + findMinCoins(n - 1, dp);
// 	if (n > 7)second = 1 + findMinCoins(n - 7, dp);
// 	if (n > 10)third = 1 + findMinCoins(n - 10, dp);
// 	return dp[n] = min(first, min(second, third));
// }

int findMinCoins(int n, vector<int>&dp, vector<int>&coins) {
	if (dp[n] != inf)return dp[n];
	vector<int>temp(coins.size(), inf);
	for (int i = 0; i < coins.size(); i++) {
		if (n >= coins[i])
			temp[i] = 1 + findMinCoins(n - coins[i], dp, coins);
	}
	int ans = inf;
	for (auto it : temp) {
		ans = min(it, ans);
	}
	return ans;
}

//using bottom-up approach
int findMinCoins(int n, vector<int>&coins) {
	if (n == 0)return 0;
	vector<int>dp(n + 1, inf);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		vector<int>temp(coins.size(), inf);
		for (int j = 0; j < coins.size(); j++) {
			if (i >= coins[j])
				temp[j] = 1 + dp[i - coins[j]];
		}
		int ans = inf;
		for (auto it : temp) {
			ans = min(it, ans);
		}
		dp[i] = ans;
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
	vector<int>dp(n + 1, inf);
	vector<int>coins{1, 7, 10};
	dp[0] = 0;
	dp[1] = 1;
	cout << findMinCoins(n, dp, coins) << endll;
	cout << findMinCoins(n, coins) << endll;
	return 0;
}