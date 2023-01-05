/*
 * @Author: Mohit Pathak
 * @Date: 2021-10-01 13:33:04
 * @Last Modified by:   Mohit Pathak
 * @Last Modified time: 2021-10-01 13:33:04
 */

#include <iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int findMaxSubarraySum(int arr[], int n) {
    int dp[100];
    dp[0] = arr[0] > 0 ? arr[0] : 0;
    int maxSoFar = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + arr[i];
        if (dp[i] < 0) dp[i] = 0;
        maxSoFar = max(maxSoFar, dp[i]);
    }
    return maxSoFar;
}

int findMaxSubarraySum2(int arr[], int n) {
    int dp = arr[0] > 0 ? arr[0] : 0;
    int maxSoFar = dp;
    for (int i = 1; i < n; i++) {
        dp = dp + arr[i];
        if (dp < 0) dp = 0;
        maxSoFar = max(maxSoFar, dp);
    }
    return maxSoFar;
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
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << findMaxSubarraySum(arr, n) << endll;
    cout << findMaxSubarraySum2(arr, n) << endll;
    return 0;
}