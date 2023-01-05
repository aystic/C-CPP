/*
 * @Author: Mohit Pathak
 * @Date: 2021-10-04 10:30:35
 * @Last Modified by: Mohit Pathak
 * @Last Modified time: 2021-10-04 12:03:06
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

// method 1
int lis1(vector<int>& arr) {
    vector<int> dp(arr.size(), 0);
    for (int i = 0; i < arr.size(); i++) {
        int temp = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                temp = max(dp[j], temp);
            }
        }
        dp[i] = 1 + temp;
    }
    int answer = 0;
    for (auto it : dp) {
        cout << it << " ";
        answer = max(answer, it);
    }
    cout << endll;
    return answer;
}

// method 2
int lis2(vector<int>& arr) {
    const int inf = 1e8, minf = -1e8;
    vector<int> dp(arr.size() + 1, inf);
    dp[0] = minf;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 1; j < dp.size(); j++) {
            if (arr[i] > dp[j - 1] and arr[i] < dp[j]) {
                dp[j] = arr[i];
                break;
            }
        }
    }
    for (int i = dp.size() - 1; i >= 0; i--) {
        if (dp[i] != inf and i > 0) {
            return i;
        }
    }
    return 0;
}

// method 3
int lis3(vector<int>& arr) {
    const int inf = 1e8, minf = -1e8;
    vector<int> dp(arr.size() + 1, inf);
    dp[0] = minf;
    for (int i = 0; i < arr.size(); i++) {
        int idx = upper_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        dp[idx] = arr[i];
    }
    for (int i = dp.size() - 1; i >= 0; i--) {
        if (dp[i] != inf and i > 0) {
            return i;
        }
    }
    return 0;
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
    cout << lis1(arr) << endll;
    cout << lis2(arr) << endll;
    cout << lis3(arr) << endll;
    return 0;
}