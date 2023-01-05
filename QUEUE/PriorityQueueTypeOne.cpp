/*
* @Author: Mohit Pathak
* @Date:   2021-02-25 17:15:30
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-26 03:24:05
*/

#include<iostream>
#include "queue.h"
using namespace std;

class pq {
	queue<char> ** arr;
	int no_of_priority;
public:
	pq(int n) {
		no_of_priority = n;
		arr = new queue<char>*[n];
		for (int i = 0; i < n; ++i)
		{
			arr[i] = new queue<char>;
		}
	}
	void insert(char data, int priority);
	void deletedata();
	void create(char *arr, int * priority, int n);

};

void pq::insert(char data, int priority) {
	arr[priority - 1]->enqueue(data);
}
void pq::deletedata() {
	int count = 0;
	while (count < no_of_priority) {
		while (!arr[count]->isempty()) {
			cout << arr[count]->dequeue() << " ";
		}
		count++;
	}
	cout << endl;
}

void pq::create(char *arr, int * priority, int n) {
	for (int i = 0; i < n; ++i)
	{
		insert(arr[i], priority[i]);
	}
}


int main() {
	char arr[] {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'};
	int priority[] {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1};
	pq q{3};
	q.create(arr, priority, 13);
	q.deletedata();
	return 0;
}