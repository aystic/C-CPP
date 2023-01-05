/*
* @Author: MOHIT PATHAK
* @Date:   2021-08-31 13:34:49
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-08-31 13:54:29
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

class book {
public:
	string name;
	int price;
};





template <typename iterator, typename T>
iterator search(iterator start, iterator end, T n) {
	while (start != end) {
		if (*(start) == n) {
			return start;
		}
		start++;
	}
	return end;
}

template <typename iterator, typename T, typename compare>
iterator search(iterator start, iterator end, T n, compare cmp) {
	while (start != end) {
		if (cmp(*start, n)) {
			return start;
		}
		start++;
	}
	return end;
}

class booksCompare {
public:
	bool operator()(book& b1, book& b2) {
		if (b1.name == b2.name and b1.price == b2.price) {
			return true;
		}
		return false;
	}
};


//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	// vector<int> arr;
	// arr.push_back(4);
	// arr.push_back(5);
	// arr.push_back(2);
	// arr.push_back(1);
	// arr.push_back(9);
	// arr.push_back(0);
	// auto it = search(arr.begin(), arr.end(), 4);
	// if (it == arr.end())cout << "Element not found" << endll;
	// else cout << "Element present at index " << (it - arr.begin()) << endll;

	vector<book> books;
	books.push_back({"c++", 100});
	books.push_back({"python", 120});
	books.push_back({"java", 200});
	for (auto it : books) {
		cout << it.name << " " << it.price << endll;
	}
	book key({"java", 200});
	booksCompare compare;
	auto it = search(books.begin(), books.end(), key, compare);
	if (it == books.end()) {
		cout << "Book not found" << endll;
	} else {
		cout << "Book found at index " << (it - books.begin()) << endll;
	}
	return 0;
}