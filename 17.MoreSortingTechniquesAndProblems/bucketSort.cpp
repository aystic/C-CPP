/*
* @Author: MOHIT PATHAK
* @Date:   2021-08-28 09:07:04
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-08-28 09:27:25
*/

#include<iostream>
#include<vector>
#include<string>


using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

class students {
public:
	string name;
	int marks;
};

void bucketSort(students arr[], int n) {
	vector<students> helper[101];
	for (int i = 0; i < n; ++i)
	{
		helper[arr[i].marks].push_back(arr[i]);
	}
	int j = 0;
	for (int i = 100; i >= 0; --i)
	{
		if (helper[i].size() > 0) {
			for (int k = 0; k < helper[i].size(); ++k)
			{
				arr[j++] = helper[i][k];
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i].name << " ";
		cout << arr[i].marks << endll;
	}
	cout << endll;
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
	students arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i].name;
		cin >> arr[i].marks;
	}
	bucketSort(arr, n);
	return 0;
}