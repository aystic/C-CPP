/*
* @Author: Mohit Pathak
* @Date:   2021-02-13 01:41:19
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-14 00:27:30
*/

#include<iostream>

using namespace std;

void checkForAnagram(string s1, string s2) {
	int h[26] {0};
	for (int i = 0; s1[i] != '\0'; ++i)
	{
		if (s1[i] >= 65 && s1[i] <= 90)
			h[(int)s1[i] - 65]++;
		else
			h[(int)s1[i] - 97]++;
	}
	for (int i = 0; s2[i] != '\0'; ++i)
	{
		if (s2[i] >= 65 && s2[i] <= 90) {
			if (h[(int)s2[i] - 65] == 0) {
				cout << "Not anagrams" << endl;
				return;
			}
			h[(int)s2[i] - 65]--;
		}
		else {
			if (h[(int)s2[i] - 97] == 0) {
				cout << "Not anagrams" << endl;
				return;
			}
			h[(int)s2[i] - 97]--;
		}
	}
	for (int i = 0; i < 26; ++i)
	{
		if (h[i] != 0) {
			cout << "Not anagrams" << endl;
			break;
		}
	}
	cout << "anagrams" << endl;
	return ;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	checkForAnagram(s1, s2);
	return 0;
}