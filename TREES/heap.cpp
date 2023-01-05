/*
* @Author: Mohit Pathak
* @Date:   2021-03-05 03:30:07
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-06 07:13:26
*/

#include<iostream>

using namespace std;

class heap {
	int *maxheap;
	int *minheap;
	int size;
	int length;
public:
	heap(int size) {
		this->size = size;
		maxheap = new int[size];
		minheap = new int[size];
		length = 0;
	}
	void insert(int data);
	void deleteNode();
	void create(int *arr, int n);
	void heapSort();
	void display();
	bool isfull() {return length == size ? true : false; }
	void heapify(int * arr, int n);
};


void heap::heapify(int * arr, int n) {
	int noofelements = n >= size ? size : n;
	//inserting the elements into the minheap and maxheap array
	for (int i = 0; i < noofelements; ++i)
	{
		maxheap[i] = arr[i];
		minheap[i] = arr[i];
		length++;
	}
	for (int i = length - 1; i >= 0; --i)
	{
		//maxheap
		int j = i;
		int temp = maxheap[j];
		while (j < length) {
			int lchild = 2 * j + 1;
			int rchild = 2 * j + 2;
			if (lchild < length) { //if left child exists
				if (rchild < length) {
					//two child
					if (maxheap[lchild] > maxheap[rchild]) {
						//leftchild is bigger
						if (temp < maxheap[lchild]) {
							maxheap[j] = maxheap[lchild];
							j = lchild;
						}
					} else {
						//right child is bigger
						if (temp < maxheap[rchild]) {
							maxheap[j] = maxheap[rchild];
							j = rchild;
						}
					}
				} else {
					//only one child
					if (temp < maxheap[lchild]) {
						maxheap[j] = maxheap[lchild];
						j = lchild;
					}
				}
			}
		}
		maxheap[j] = temp;

		//minheap
		// j = i;
		// temp = minheap[j];
		// while(j<length){
		// 	int lchild=2*j+1;
		// 	int rchild=2*j+2;
		// 	if(lchild<length){//if left child exists
		// 		if(rchild<length){
		// 		}else{
		// 		}
		// 	}
		// }
	}

}

// 0=parent=(i-1)/2 1=lchild=2i+1 2=rchild=2i+2
void heap::create(int *arr, int n) {
	int noofelements = n <= size ? n : size;
	for (int i = 0; i < noofelements; ++i)
	{
		this->maxheap[i] = arr[i];
		this->minheap[i] = arr[i];
		length++;
	}
	for (int i = 1; i < noofelements; ++i)
	{
		int j = i;
		int temp = maxheap[i];
		while (temp > maxheap[(j - 1) / 2]) { //maxheap
			maxheap[j] = maxheap[(j - 1) / 2];
			j = (j - 1) / 2;
			if (j == 0)
				break;
		}
		maxheap[j] = temp;
	}
	for (int i = 0; i < noofelements; ++i)
	{
		int j = i;
		int temp = minheap[i];
		while (j >= 1 && temp < minheap[(j - 1) / 2]) { //minheap
			minheap[j] = minheap[(j - 1) / 2];
			j = (j - 1) / 2;
			if (j == 0)
				break;
		}
		minheap[j] = temp;

	}
}
void heap::display() {
	cout << "Maxheap : " << endl;
	for (int i = 0; i < length; ++i)
	{
		cout << maxheap[i] << " ";
	}
	cout << endl;
	cout << "Minheap : " << endl;
	for (int i = 0; i < length; ++i)
	{
		cout << minheap[i] << " ";
	}
	cout << endl;
}
void heap::insert(int data) {
	if (length == 0) {
		maxheap[length] = data;
		minheap[length] = data;
		length++;
	} else {
		if (!isfull()) {
			maxheap[length] = data;
			minheap[length] = data;
			length++;
			int j = length - 1;
			while (data > maxheap[(j - 1) / 2]) { //insert in maxheap
				maxheap[j] = maxheap[(j - 1) / 2];
				j = (j - 1) / 2;
				if (!j)
					break;
			}
			maxheap[j] = data;
			j = length - 1;
			while (data < minheap[(j - 1) / 2]) { //insert in minheap
				minheap[j] = minheap[(j - 1) / 2];
				j = (j - 1) / 2;
				if (!j)
					break;
			}
			minheap[j] = data;
		} else {
			cout << "No space in heap" << endl;
		}

	}

}

void heap::deleteNode() {
	if (length) {
		swap(maxheap[0], maxheap[length - 1]);
		swap(minheap[0], minheap[length - 1]);
		length--;
		if (length == 0) {
			// cout << "minheap : " << minheap[length] << endl;
			// cout << "maxheap : " << maxheap[length] << endl;
			return ;
		}
		if (length == 1) {
			// cout << "minheap : " << minheap[length] << endl;
			// cout << "maxheap : " << maxheap[length] << endl;
			return ;
		}
		//rearranging the elements in maxheap
		int temp = maxheap[0];
		int j = 0;
		while ((maxheap[2 * j + 1] > temp || maxheap[2 * j + 2] > temp) && (2 * j + 2) < length) {
			if (maxheap[2 * j + 1] >= maxheap[2 * j + 2]) {
				maxheap[j] = maxheap[2 * j + 1];
				j = 2 * j + 1;
			} else {
				maxheap[j] = maxheap[2 * j + 2];
				j = 2 * j + 2;
			}
		}
		maxheap[j] = temp;
		//rearranging the elements in minheap
		temp = minheap[0];
		j = 0;
		while ((minheap[2 * j + 1] < temp || minheap[2 * j + 2] < temp) && (2 * j + 2) < length) {
			if (minheap[2 * j + 1] <= minheap[2 * j + 2]) {
				minheap[j] = minheap[2 * j + 1];
				j = 2 * j + 1;
			} else {
				minheap[j] = minheap[2 * j + 2];
				j = 2 * j + 2;
			}
		}
		minheap[j] = temp;
		// cout << "minheap : " << minheap[length] << endl;
		// cout << "maxheap : " << maxheap[length] << endl;
	} else {
		cout << "heap empty" << endl;
	}
}

void heap::heapSort() {
	int temp = length;
	while (length) {
		deleteNode();
	}
	int i = 0;
	cout << "Maxheap : " << endl;
	while (i < temp) {
		cout << maxheap[i] << " ";
		i++;
	}
	cout << endl;
	i = 0;
	cout << "Maxheap : " << endl;
	while (i < temp) {
		cout << maxheap[i] << " ";
		i++;
	}
	cout << endl;
}


int main() {
	int arr[] {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 10, 12};
	heap h{15};
	h.heapify(arr, 13);
	// h.insert(15);
	// h.insert(-15);
	// h.insert(-75);
	h.display();
	// h.deleteNode();
	h.heapSort();
	// h.display();
	return 0;
}