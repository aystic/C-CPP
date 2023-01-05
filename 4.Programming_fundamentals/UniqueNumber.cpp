#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int unique = 0;
	int a;
	while (n--) {
		cin >> a;
		unique = unique ^ a;
	}
	cout << unique << endl;

	return 0;
}