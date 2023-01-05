#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	int sum;
	cin >> sum;
	int start = 0, end = n - 1;
	while (start <= end) {
		int temp = arr[start] + arr[end];
		if (temp == sum) {
			cout << arr[start] << " " << arr[end] << endl;
			start++;
			end--;
		} else if (temp < sum) {
			start++;
		} else {
			end--;
		}
	}
	return 0;
}