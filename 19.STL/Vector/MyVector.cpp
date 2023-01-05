/*
* @Author: MOHIT PATHAK
* @Date:   2021-08-31 07:47:22
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-08-31 09:42:06
*/

#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

class vector {
	int *arr;
	int cs, ms;
public:
	vector(int defaultSize = 4) {
		ms = defaultSize;
		cs = 1;
		arr = new int[defaultSize];
	}
	void push_back(int data) {
		if (cs < ms) {
			arr[cs - 1] = data;
			cs++;
			if (cs == ms) {
				reallocate(2 * ms);
			}
		} else {
			reallocate(2 * ms);
			arr[cs - 1] = data;
			cs++;
		}
	}
	int pop_back() {
		if (!empty()) {
			cs--;
			if (cs <= ((ms / 4) + 1)) {
				reallocate(ms / 2);
			}
			return arr[cs - 1];
		}
		return -1;

	}
	void reallocate(int size) {
		int *temp = new int[size];
		ms = size;
		for (int i = 0; i < cs; i++) {
			temp[i] = arr[i];
		}
		delete []arr;
		arr = temp;
	}
	int size() {
		return cs - 1;
	}
	int maxsize() {
		return ms;
	}
	void display() {
		for (int i = 0; i < cs - 1; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << endll;
	}
	bool empty() {
		return cs == 1;
	}
	int getIth(int i) {
		if (i >= 0 and i < cs) {
			return arr[i];
		}
		return -1;
	}

	int& operator[](int i) {
		return arr[i];
	}

	~vector() {
		delete[]arr;
	}
};

ostream& operator<<(ostream & cout, vector & v) {
	v.display();
	return cout;
}


//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	vector v1;
	cout << v1.size() << " " << v1.maxsize() << endll;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.display();
	cout << v1.size() << " " << v1.maxsize() << endll;
	cout << endll;
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);
	v1.push_back(9);
	v1.display();
	cout << endll;
	// cout << v1.size() << " " << v1.maxsize() << endll;
	// cout << v1.pop_back() << endll;
	// cout << v1.pop_back() << endll;
	// cout << v1.pop_back() << endll;
	// cout << v1.pop_back() << endll;
	// v1.display();
	// cout << v1.size() << " " << v1.maxsize() << endll;
	// cout << endll;
	// cout << v1.pop_back() << endll;
	// v1.display();
	// cout << v1.size() << " " << v1.maxsize() << endll;

	for (int i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << " ";
		cout << v1.getIth(i) << endll;
	}
	cout << endll;
	cout << v1 << endll;
	v1[0] += 100;
	cout << v1 << endll;
	return 0;
}