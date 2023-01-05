/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-02 22:03:19
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-02 22:13:54
*/

#include<iostream>
#include<stack>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

class MinMaxStack
{
	stack<int>s;
	stack<int>min_stack;
	stack<int>max_stack;
public:
	void push_data(int data) {
		s.push(data);
		if (min_stack.empty() or data <= min_stack.top()) {
			min_stack.push(data);
		} else {
			min_stack.push(min_stack.top());
		}
		if (max_stack.empty() or data >= max_stack.top()) {
			max_stack.push(data);
		} else {
			max_stack.push(max_stack.top());
		}
	}

	void pop_data() {
		s.pop();
		min_stack.pop();
		max_stack.pop();
	}

	int get_top() {
		return s.top();
	}

	int get_min() {
		return min_stack.top();
	}

	int get_max() {
		return max_stack.top();
	}

	bool empty() {
		return s.empty();
	}

};



//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	MinMaxStack st;
	st.push_data(4);
	st.push_data(2);
	st.push_data(1);
	st.push_data(6);
	st.push_data(4);
	st.push_data(9);
	st.push_data(10);
	while (!st.empty()) {
		cout << st.get_top() << " " << st.get_min() << " " << st.get_max() << endll;
		st.pop_data();
	}
	return 0;
}