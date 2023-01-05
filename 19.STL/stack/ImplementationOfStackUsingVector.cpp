/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-02 16:35:36
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-02 16:51:15
*/

#include<iostream>
#include<vector>


using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

template<class T>
class stack {
	vector<T> v;
public:
	void push(T data) {
		v.push_back(data);
	}
	void pop() {
		if (!v.empty()) {
			v.pop_back();
		}
	}
	T top() {
		return v[v.size() - 1];
	}

	bool empty() {
		return v.empty();
	}
	int size() {
		return v.size();
	}
	void display() {
		for (int i = v.size() - 1; i >= 0; i--) {
			cout << " <- " << v[i];
		}
		cout << endll;
	}
};




//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	stack<char> st;
	st.push('a');
	st.push('b');
	st.push('c');
	st.push('d');
	st.push('e');
	st.push('f');
	st.push('g');
	st.display();
	while (!st.empty()) {
		cout << st.top() << endll;
		st.pop();
	}
	return 0;
}