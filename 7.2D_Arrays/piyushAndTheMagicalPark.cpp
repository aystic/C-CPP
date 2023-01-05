#include<iostream>
using namespace std;

int main() {
	int n, m, k, s;
	cin >> n >> m >> k >> s;
	char a[n][m];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (s < k) {
				cout << "No" << endl;
				return 0;
			}
			if (a[i][j] == '.') {
				s -= 2;
			} else if (a[i][j] == '*') {
				s += 5;
			} else {
				break;
			}
			if (j != m - 1) {
				s--;
			}
		}
	}
	cout << "Yes" << endl;
	cout << s << endl;
	return 0;
}