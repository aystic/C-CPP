/*
* @Author: Mohit Pathak
* @Date:   2021-06-25 00:37:25
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-25 02:26:02
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================


int CalculatePages(int pages[], int books, int students, int allowedpages) {
	int maxpages = 0;
	int studentAllocated = 1, currpages = 0;
	int i = 0;
	while (i < books) {
		currpages += pages[i];
		if (currpages >= allowedpages) {
			studentAllocated++;
			maxpages = max(currpages - pages[i], maxpages);
			if (studentAllocated > students)
				return false;
			currpages = pages[i];
		}
		i++;
	}
	return max(currpages, maxpages);
}


bool canallocate(int pages[], int books, int students, int allowedpages) {
	int currpages = 0, studentAllocated = 1;
	int i = 0;
	while (i < books) {
		currpages += pages[i];
		if (currpages >= allowedpages) {
			studentAllocated++;
			if (studentAllocated > students) {
				return false;
			}
			currpages = pages[i];
		}
		i++;
	}
	return true;
}


int findPages(int pages[], int books, int students, int totalpages) {
	int s = pages[books - 1], e = totalpages, mid;
	int answer = -1;
	if (books < students) {
		return answer;
	}
	if (books == students) {
		return pages[books - 1];
	}
	if (students == 1) {
		return totalpages;
	}
	while (s <= e) {
		mid = (s + e) / 2;
		bool ispossible = canallocate(pages, books, students, mid);
		if (ispossible) {
			answer = mid;
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}
	answer = CalculatePages(pages, books, students, answer);
	return answer;
}


//==========================================
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	int t;
	cin >> t;
	while (t--) {
		int books, students;
		cin >> books >> students;
		int pages[books];
		int totalpages = 0;
		for (int i = 0; i < books; ++i)
		{
			cin >> pages[i];
			totalpages += pages[i];
		}
		cout << findPages(pages, books, students, totalpages) << endl;
	}


	return 0;
}