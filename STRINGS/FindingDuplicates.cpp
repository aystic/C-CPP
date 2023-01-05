/*
* @Author: Mohit Pathak
* @Date:   2021-02-12 02:08:20
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-13 01:33:17
*/

#include<iostream>

using namespace std;

int length;

void DuplicatesByBruteForce(char a[]) {
	cout << "length is " << length << endl;
	char temp = 0;
	char arr[length];
	for (int i = 0; i <= length; ++i)
	{
		arr[i] = a[i];
	}
	for (int i = 0; i != length - 1; ++i)
	{
		for (int j = i + 1; j < length; ++j)
		{
			if (arr[i] == arr[j] && arr[i] != 0)
			{
				if (temp != arr[j]) {
					cout << "Duplicate is " << arr[j] << endl;
				}
				temp = arr[j];
				arr[j] = 0;
			}
		}
	}
}

void DuplicatesByHashtable(char arr[]) {
	int h[26] {0};
	cout << "length is " << length << endl;
	for (int i = 0; arr[i] != '\0'; ++i)
	{
		if (arr[i] >= 65 && arr[i] <= 90)
			h[(int)arr[i] - 65]++;
		else
			h[(int)arr[i] - 97]++;
	}
	for (int i = 0; i < 26; ++i)
	{
		if (h[i] > 1)
			cout << "Duplicate element is " << (char)(i + 65) << endl;
	}
}
int merging(int x, int &h) {
	h = h | x;
	return h;
}

bool masking(int x, int h) {
	return x & h;

}

void DuplicateUsingBits(char arr[]) {
	int h = 0; //we need atleast 26 bits representing 26 alphabets

	for (int i = 0; arr[i] != '\0'; ++i)
	{
		int x = 1;
		if (arr[i] >= 65 && arr[i] <= 90) {
			x = x << ((int)arr[i] - 65);
		}
		else {
			x = x << ((int)arr[i] - 97);
		}
		if (masking(x, h)) {
			cout << "Duplicate element is " << arr[i] << endl;
		} else {
			merging(x, h);
		}
	}
}

int main() {
	char arr[100] {0};
	cin >> arr;
	for (int i = 0; arr[i] != '\0'; ++i)
	{
		length++;
	}
	// DuplicatesByBruteForce(arr);
	// cout << endl;
	// DuplicatesByHashtable(arr);
	cout << endl;
	DuplicateUsingBits(arr);
	return 0;
}