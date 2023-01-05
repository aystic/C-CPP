#include <iostream>
using namespace std;

void rotate(int a[][1000], int n) {
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n; ++j) {
            swap(a[i][j], a[n - 1 - i][j]);
        }
    }
    int count = 0;
    while (count <= n - 1) {
        swap(a[0][n - 1 - count], a[0 + count][n - 1]);
        swap(a[n - 1][0 + count], a[n - 1 - count][0]);
        count++;
    }
    swap(a[0][0], a[n - 1][n - 1]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 4;
    // cin >> n;
    // int a[1000][1000];
    int a[1000][1000]{
        {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         cin >> a[i][j];
    //     }
    // }
    rotate(a, n);
    return 0;
}