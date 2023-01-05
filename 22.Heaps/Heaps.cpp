
#include<iostream>
#include<vector>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

class heap {
	vector<int> v;
	bool isMinheap;
	bool compare(int a, int b) {
		if (isMinheap) {
			return a > b;
		}
		return a < b;
	}

	void heapify(int idx) {
		int min_idx = idx;
		int left = 2 * idx;
		int right = left + 1;
		if (left <= v.size() - 1 and compare(v[idx], v[left])) {
			min_idx = left;
		}
		if (right <= v.size() - 1 and compare(v[min_idx], v[right])) {
			min_idx = right;
		}
		if (min_idx != idx) {
			swap(v[idx], v[min_idx]);
			heapify(min_idx);
		}
	}
public:
	heap(int size = 10, bool type = true) {
		v.reserve(size + 1);
		v.push_back(-1);//blocking the 0th index
		isMinheap = type;
	}
	bool empty() {
		return v.size() == 1;
	}
	void display() {
		for (auto it : v)cout << it << " ";
		cout << endll;
	}
	int get() {
		if (!empty())return v[1];
		return -1;
	}
	void push(int data) {
		v.push_back(data);
		int idx = v.size() - 1;
		while (idx > 1 and compare(v[idx / 2], v[idx])) {
			swap(v[idx / 2], v[idx]);
			idx = idx / 2;
		}
	}
	void pop() {
		swap(v[1], v[v.size() - 1]);
		v.pop_back();
		heapify(1);
	}

};


//O(nlog(n)) method
void makeHeapFromArray(int arr[], int size) {
	int idx = size - 1;
	int parent_idx = idx / 2;
	if ((idx & 1) == 0)parent_idx--;
	while (idx > 0 and arr[parent_idx] > arr[idx]) {
		swap(arr[parent_idx], arr[idx]);
		idx = parent_idx;
		parent_idx = idx / 2;
		if ((idx & 1) == 0)parent_idx--;
	}
}

void heapify(int arr[], int size, int idx) {
	int left = idx * 2;
	int right = left + 1;
	while (right <= size - 1 and arr[idx] > min(arr[left], arr[right])) {
		int minIndex;
		if (arr[left] < arr[right])minIndex = left;
		else minIndex = right;
		swap(arr[idx], arr[minIndex]);
		idx = minIndex;
		left = idx * 2;
		right = left + 1;
	}
	if (left <= size - 1 and arr[idx] > arr[left]) {
		swap(arr[idx], arr[left]);
	}
}

//O(n) method
void makeHeapFromArray2(int arr[], int size) {
	for (int i = size / 2; i >= 0; i--) {
		heapify(arr, size, i);
	}
}

//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	// heap h(20, true);
	// for (int i = 0; i < 16; ++i)
	// {
	// 	h.push(i);
	// }
	// h.display();
	// while (!h.empty()) {
	// 	cout << h.get() << " ";
	// 	h.pop();
	// }
	// cout << endll;
	int arr[] {10, 20, 4, 2, 3, 1, 19, 9, 21};
	int n = sizeof(arr) / sizeof(int);
	int i = 1;
	while (i != n - 1) {
		makeHeapFromArray(arr, i + 1);
		i++;
	}
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endll;



	int arr1[] { -1, 10, 20, 4, 2, 3, 1, 19, 9, 21};
	int size = sizeof(arr1) / sizeof(int);
	makeHeapFromArray2(arr1, size);
	for (int i = 1; i < size; ++i)
	{
		cout << arr1[i] << " ";
	}
	cout << endll;
	return 0;
}