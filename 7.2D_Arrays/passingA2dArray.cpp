#include <iostream>
using namespace std;

void display(int a[][5], int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int a[5][5] = {0};
    display(a, 5, 5);

    return 0;
}