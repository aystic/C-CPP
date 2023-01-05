/*
 * @Author: Mohit Pathak
 * @Date: 2021-10-05 11:20:47
 * @Last Modified by: Mohit Pathak
 * @Last Modified time: 2021-10-05 11:42:10
 */
#include <iostream>
#include <vector>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================
#define inf 1e5
int mcm(vector<int>& arr) {
    int n = arr.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    int row = 1, col = 2;
    while (col <= n) {
        int i = row, j = col;
        while (i <= n and j <= n) {
            int temp = i;
            for (int k = i; k < j; k++) {
                int sum = dp[i][k] + dp[k + 1][j];
                sum += (arr[i - 1] * arr[k] * arr[j]);
                if (dp[i][j] != 0)
                    dp[i][j] = min(sum, dp[i][j]);
                else
                    dp[i][j] = sum;
            }
            i++;
            j++;
        }
        col++;
    }
    for (auto v : dp) {
        for (auto it : v) cout << it << " ";
        cout << endll;
    }
    return dp[1][n];
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
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    cout << mcm(arr) << endll;
    return 0;
}