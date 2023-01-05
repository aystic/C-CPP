/*
 * @Author: Mohit Pathak
 * @Date: 2021-10-02 00:16:41
 * @Last Modified by: Mohit Pathak
 * @Last Modified time: 2021-10-02 12:58:44
 */
#include <iostream>
#include <vector>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

// using top down dp
int findMaxWays(int n, int k, vector<int>& dp) {
    if (dp[n] != 0) return dp[n];
    int answer = 0;
    for (int i = 1; i <= k; i++) {
        if (n - i >= 0) {
            dp[n - i] = findMaxWays(n - i, k, dp);
            answer += dp[n - i];
        }
    }
    return dp[n] = answer;
}

// using bottom up dp
int findMaxWays2(int n, int k) {
    int dp[n + 1];
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) sum += dp[i - j];
        }
        dp[i] = sum;
    }
    return dp[n];
}

// using bottom up dp optimised
int findMaxWays3(int n, int k) {
    int dp[n + 1];
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = 2 * dp[i - 1];
        if (i - k - 1 >= 0) {
            dp[i] -= dp[i - k - 1];
        }
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
    int k;
    cin >> k;
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    cout << findMaxWays(n, k, dp) << endll;
    cout << findMaxWays2(n, k) << endll;
    cout << findMaxWays3(n, k) << endll;
    return 0;
}