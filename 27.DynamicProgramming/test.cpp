/*
 * @Author: Mohit Pathak
 * @Date: 2021-10-05 19:34:55
 * @Last Modified by: Mohit Pathak
 * @Last Modified time: 2021-10-05 19:35:49
 */
#include <iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

//==========================================
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //==========================================
    pair<int, int> p(0, 0);
    cout << p.first << " " << p.second << endl;
    if (p < make_pair(0, 20)) cout << "True" << endll;
    return 0;
}