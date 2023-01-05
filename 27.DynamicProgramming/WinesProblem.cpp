/*
 * @Author: Mohit Pathak
 * @Date:   2021-09-30 07:58:18
 * @Last Modified by:   Mohit Pathak
 * @Last Modified time: 2021-10-05 14:57:56
 */
#include <iostream>
#include <vector>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================
#define minf -1e5

int findMaxProfit(int firstBottle, int lastBottle, int year,
                  vector<int>& price) {
    if (firstBottle > lastBottle) return 0;
    int case1 = (year * price[firstBottle]) +
                findMaxProfit(firstBottle + 1, lastBottle, year + 1, price);
    int case2 = (year * price[lastBottle]) +
                findMaxProfit(firstBottle, lastBottle - 1, year + 1, price);
    int answer = max(case1, case2);
    return answer;
}

// using memoization
int findMaxProfit2(int firstBottle, int lastBottle, int year,
                   vector<int>& price, vector<vector<int>>& dp) {
    if (firstBottle > lastBottle) return 0;
    if (dp[firstBottle][lastBottle] != -1) return dp[firstBottle][lastBottle];
    int case1 =
        (year * price[firstBottle]) +
        findMaxProfit2(firstBottle + 1, lastBottle, year + 1, price, dp);
    int case2 =
        (year * price[lastBottle]) +
        findMaxProfit2(firstBottle, lastBottle - 1, year + 1, price, dp);
    int answer = max(case1, case2);
    return dp[firstBottle][lastBottle] = answer;
}

// usin bottom up approach
int findMaxProfit3(vector<int>& price) {
    vector<vector<int>> dp(price.size(), vector<int>(price.size(), 0));
    for (int i = 0, j = 0; i < price.size() and j < price.size();) {
        dp[i][j] = price.size() * price[i];
        i++;
        j++;
    }
    int s = 0, e = 1;
    while (e < price.size()) {
        int i = s, j = e;
        while (i < price.size() and j < price.size()) {
            int year = price.size() - j + i;
            int case1 = price[i] * year + dp[i + 1][j];
            int case2 = price[j] * year + dp[i][j - 1];
            dp[i][j] = max(case1, case2);
            i++;
            j++;
        }
        e++;
    }
    return dp[0][price.size() - 1];
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
    vector<int> arr;
    arr.reserve(n);
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int i = 0;
    for (auto it : arr) {
        dp[i][i] = n * it;
        i++;
    }
    cout << findMaxProfit(0, n - 1, 1, arr) << endll;
    cout << findMaxProfit2(0, n - 1, 1, arr, dp) << endll;
    cout << findMaxProfit3(arr) << endll;
    return 0;
}