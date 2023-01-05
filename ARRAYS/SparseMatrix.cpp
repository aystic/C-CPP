/*
* @Author: Mohit Pathak
* @Date:   2021-02-14 04:01:58
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-14 19:16:21
*/

#include<iostream>

using namespace std;


//defines the type of element that the 1d sparse matrix will contain
class ElementCL {
public:
	int row;
	int column;
	int element;
};

//Creating a sparse matrix in coordinate list notation
class CLrepresentation {
	//every sparse matrix will have these 3 properties
	ElementCL *arr;
	int length;//no of elements currently filled in the array
public:
	CLrepresentation(int size, int row, int column) {
		arr = new ElementCL[size + 1];
		arr[0].row = row;
		arr[0].column = column;
		arr[0].element = size;
		length = 1;
	}
	~CLrepresentation() {
		delete []arr;
	}
	void set(int row, int column, int x);
	void getlength() {
		cout << "length is " << length << endl;
	}
	void display();
	void sum(CLrepresentation *arr2);

};
void CLrepresentation::set(int row, int column, int x) {
	arr[length].row = row;
	arr[length].column = column;
	arr[length].element = x;
	length++;
}
void CLrepresentation::display() {
	int count = 1;
	int r = arr[count].row, c = arr[count].column;
	for (int i = 0; i < arr[0].row; ++i)
	{
		for (int j = 0; j < arr[0].column; ++j)
		{
			if (i == r && j == c) {
				cout << arr[count].element << " ";
				count++;
				r = arr[count].row;
				c = arr[count].column;
			} else {
				cout << "0" << " ";
			}
		}
		cout << endl;
	}
}

void CLrepresentation::sum(CLrepresentation *arr2) {
	CLrepresentation sumarray{arr[0].element + arr2->arr[0].element, arr[0].row, arr[0].column};
	int i = 1, j = 1;
	while (i <= length - 1 && j <= arr2->length - 1) {
		if (arr[i].row < arr2->arr[j].row) {
			sumarray.set(arr[i].row, arr[i].column, arr[i].element);
			i++;
		} else if (arr[i].row > arr2->arr[j].row) {
			sumarray.set(arr2->arr[j].row, arr2->arr[j].column, arr2->arr[j].element);
			j++;
		} else {
			if (arr[i].column < arr2->arr[j].column) {
				sumarray.set(arr[i].row, arr[i].column, arr[i].element);
				i++;
			} else if (arr[i].column > arr2->arr[j].column) {
				sumarray.set(arr2->arr[j].row, arr2->arr[j].column, arr2->arr[j].element);
				j++;
			} else {
				sumarray.set(arr[i].row, arr[i].column, arr[i].element + arr2->arr[j].element);
				i++;
				j++;
			}
		}
	}
	while (i <= length) {
		sumarray.set(arr[i].row, arr[i].column, arr[i].element);
		i++;
	}
	while (j <= arr2->length) {
		sumarray.set(arr2->arr[j].row, arr2->arr[j].column, arr2->arr[j].element);
		j++;
	}
	sumarray.display();
	cout << "Filled length of sum array is " << sumarray.length << endl;
	cout << "Total length of sum array is " << sumarray.arr[0].element << endl;
}

int main() {
	int row, column, nonzero;
	cin >> row >> column >> nonzero;
	CLrepresentation array1{nonzero, row, column};
	array1.set(0, 3, 6);
	array1.set(1, 1, 7);
	array1.set(2, 1, 2);
	array1.set(2, 3, 5);
	array1.set(4, 0, 4);
	array1.display();
	array1.getlength();
	CLrepresentation array2{nonzero + 2, row, column};
	array2.set(0, 1, 9);
	array2.set(0, 3, 6);
	array2.set(1, 1, 7);
	array2.set(1, 4, 9);
	array2.set(2, 1, 2);
	array2.set(2, 3, 5);
	array2.set(4, 0, 4);
	array2.display();
	array2.getlength();
	cout << endl;
	array1.sum(&array2);

	return 0;
}