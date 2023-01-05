/*
* @Author: Mohit Pathak
* @Date:   2021-02-14 21:06:52
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-15 01:04:27
*/

#include<iostream>

using namespace std;

class element {
public:
	int coefficient;
	int exponent;
};
class polynomial {
public:
	int elements;
	int length;
	element * arr;

	polynomial(int elements) {
		this->elements = elements;
		length = 0;
		arr = new element[elements];
	}
	~polynomial() {
		delete []arr;
	}
	void set(int coefficient, int exponent);
	void display();
};
void polynomial::set(int coefficient, int exponent) {
	arr[length].coefficient = coefficient;
	arr[length].exponent = exponent;
	length++;
}
void polynomial::display() {
	for (int i = 0; i < length; ++i)
	{
		if (i == length - 1) {
			cout << arr[i].coefficient << "x^" << arr[i].exponent << endl;;

		} else {
			cout << arr[i].coefficient << "x^" << arr[i].exponent << " + ";
		}
	}
}

void polynomialAddition(polynomial *p1, polynomial *p2) {
	polynomial result{p1->length + p2->elements};
	int i = 0, j = 0, k = 0;
	while (i < p1->length && j < p2->length) {
		if (p1->arr[i].exponent < p2->arr[j].exponent) {
			result.arr[k++] = p2->arr[j++];
		} else if (p1->arr[i].exponent > p2->arr[j].exponent) {
			result.arr[k++] = p1->arr[i++];
		} else {
			result.arr[k].exponent = p1->arr[i].exponent;
			result.arr[k].coefficient = p1->arr[i].coefficient + p2->arr[j].coefficient;
			k++;
			j++;
			i++;
		}
	}
	while (i < p1->length)
		result.arr[k++] = p1->arr[i++];
	while (j < p2->length)
		result.arr[k++] = p2->arr[j++];
	result.length = k;
	result.display();
}


int main() {
	polynomial p1{3};
	p1.set(1, 3);
	p1.set(2, 2);
	p1.set(3, 1);
	p1.display();
	polynomial p2{3};
	p2.set(8, 2);
	p2.set(7, 1);
	p2.set(6, 0);
	p2.display();
	polynomialAddition(&p1, &p2);
	return 0;
}