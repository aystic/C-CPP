/*
* @Author: Mohit Pathak
* @Date:   2021-02-04 20:28:35
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-06 10:26:00
*/

#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

class array {
public:
	int * arr;
	int size;
	int length;
};


void display(array a) {
	if (a.size == 0) {
		cout << "Array is empty" << endl;
		return;
	}
	for (int i = 0; i < a.length; ++i)
	{
		cout << a.arr[i] << " ";
	}
	cout << endl;
	return;
}

bool issorted(array a) {
	for (int i = a.length - 1; i >= 1; i--) {
		if (a.arr[i] < a.arr[i - 1]) {
			cout << "Array is not sorted." << endl;
			return false;
		}
	}
	cout << "Array is sorted." << endl;
	return true;
}

array * create() {
	array *a;
	a = new array;
	cout << "Enter the size of the array : ";
	cin >> a->size;
	a->arr = new int[a->size];
	cout << "How many elements do you want to insert? : ";
	cin >> a->length;
	cout << "Enter the elements : ";
	for (int i = 0; i < a->length; ++i)
	{
		cin >> a->arr[i];
	}
	cout << endl;
	cout << "Array : ";
	display(*a);
	return a;
}

void check(array a) {
	cout << "Max size is " << a.size << " and length is " << a.length << endl;
	return;
}

void append(array *a, int x) {
	if (a->length == a->size) {
		cout << "Array is full!!!" << endl;
		return;
	} else {
		a->arr[a->length] = x;
		a->length += 1;
	}
	cout << endl;
	cout << "Array : ";
	display(*a);
}

void insert(array * a) {
	if (a->length == a->size) {
		cout << "Array is full!!!" << endl;
		return;
	} else {
		cout << "Enter the element to insert and the index at which to insert the element : ";
		int x, idx;
		cin >> x >> idx;
		if (idx < 0 || (idx >= a->size) || (idx >= a->length + 1)) {
			cout << "Invalid Index" << endl;
			return;
		}
		for (int i = a->length - 1; i >= idx; i--) {
			a->arr[i + 1] = a->arr[i];
		}
		a->arr[idx] = x;
		a->length += 1;
	}
	cout << endl;
	cout << "Array : ";
	display(*a);
}

void deletearray(array *a) {
	delete a;
	a = nullptr;
}

void deleteanelement(array *a) {
	cout << endl << "Array : ";
	display(*a);
	int idx;
	cout << "Enter the element's number which is to be deleted : ";
	cin >> idx;
	idx--;
	if (idx < 0 || idx >= a->length - 1) {
		cout << "Invalid index!" << endl;
		return;
	} else {
		int x;
		x = a->arr[idx];
		for (int i = idx; i < a->length - 1; ++i)
		{
			a->arr[i] = a->arr[i + 1];
		}
		a->length -= 1;
		cout << "Element deleted : ";
		cout << x << endl;
		cout << endl << "Array : ";
		display(*a);
		check(*a);
	}
}

void LinearSearch(array a) {
	cout << "Enter the key to be searched : ";
	int key;
	cin >> key;
	for (int i = 0; i < a.length; i++) {
		if (a.arr[i] == key) {
			cout << "Element " << key << " found at index " << i << endl;
			return;
		}
	}
	cout << "Element not present!" << endl;
}

void TranspositionImprovedLinearSearch(array *a) {
	cout << "Enter the key to be searched : ";
	int key;
	cin >> key;
	for (int i = 0; i < a->length; i++) {
		if (a->arr[i] == key) {
			swap(a->arr[i], a->arr[i - 1]); //Transposition
			cout << "Element " << key << " found at index " << i << endl;
			return;
		}
	}
	cout << "Element not present!" << endl;
}

void MoveTofrontImprovedLinearSearch(array *a) {
	cout << "Enter the key to be searched : ";
	int key;
	cin >> key;
	for (int i = 0; i < a->length; i++) {
		if (a->arr[i] == key) {
			swap(a->arr[i], a->arr[0]);
			cout << "Element " << key << " found at index " << i << endl;
			return;
		}
	}
	cout << "Element not present!" << endl;
}


void BinarySearch(array *a) {
	if (!issorted(*a))
		sort(a->arr, a->arr + a->length);
	cout << "Sorted array :";
	display(*a);
	cout << "Enter the key to be searched : ";
	int key;
	cin >> key;
	int s = 0, e = a->length - 1;
	int mid = (s + e) / 2;
	while (s <= e) {
		if (a->arr[mid] == key) {
			cout << "Element " << key << " found at index " << mid << endl;
			return;
		} else {
			if (a->arr[mid] > key) {
				e = mid - 1;
				mid = (s + e) / 2;
			} else {
				s = mid + 1;
				mid = (s + e) / 2;
			}
		}
	}
	cout << "Element not found!" << endl;
}

void RecursiveBinarySearch(array a, int s, int e, int key) {
	int mid = (s + e) / 2;
	if (s > e) {
		cout << "Element not found!" << endl;
		return;
	}
	if (a.arr[mid] == key) {
		cout << "The element " << key << " found at the index " << mid << endl;
		return;
	} else {
		if (a.arr[mid] < key) {
			return RecursiveBinarySearch(a, mid + 1, e, key);
		} else {
			return RecursiveBinarySearch(a, s, mid - 1, key);
		}
	}
}

void get(array a) {
	cout << "Enter the index at which you wish to find the element stored : ";
	int idx;
	cin >> idx;
	if (idx < 0 || idx > a.length - 1) {
		cout << "Invalid Index!" << endl;
		return;
	} else {
		cout << "Element is " << a.arr[idx] << endl;
		return;
	}
}

void set(array *a) {
	cout << "Enter the index at which you wish to replace the element and the element : ";
	int idx, x;
	cin >> idx >> x;
	if (idx < 0 || idx > a->length - 1) {
		cout << "Invalid Index!" << endl;
		return;
	} else {
		a->arr[idx] = x;
		display(*a);
		return;
	}
}

void findmax(array a) {
	int max = INT_MIN;
	for (int i = 0; i < a.length; ++i)
	{
		if (a.arr[i] > max)
			max = a.arr[i];
	}
	cout << "Maximum element is " << max << endl;
	return;

}

void findmin(array a) {
	int min = INT_MAX;
	for (int i = 0; i < a.length; ++i)
	{
		if (a.arr[i] < min)
			min = a.arr[i];
	}
	cout << "Minimum element is " << min << endl;
	return;

}

void findtotal(array a) {
	int sum = 0;
	for (int i = 0; i < a.length; ++i)
	{
		sum += a.arr[i];
	}
	cout << "The total sum is " << sum << endl;
	return;
}

int findtotalrecursive(array a, int n) {
	if (n == 0) {
		return a.arr[0];
	} else {
		return a.arr[n] + findtotalrecursive(a, n - 1);
	}
}

void reverse(array *a) {
	cout << "Original array : ";
	display(*a);
	for (int i = 0; i < (a->length - 1) / 2; i++) {
		swap(a->arr[i], a->arr[a->length - 1 - i]);
	}
	cout << "Reversed array : ";
	display(*a);
}

void leftshift(array *a) {
	cout << "Original array : ";
	display(*a);
	cout << "Enter the amount by which to left shift the array : ";
	int val;
	cin >> val;
	for (int i = 0; i < a->length; ++i)
	{
		if (i <= a->length - 1 - val)
			swap(a->arr[i], a->arr[i + val]);
		else {
			a->arr[i] = 0;
		}
	}
	cout << "Array Left shifted by " << val << " : ";
	display(*a);
}

void leftrotate(array *a) {
	cout << "Original array : ";
	display(*a);
	cout << "Enter the amount by which to left rotate the array : ";
	int val;
	cin >> val;
	int temp[val];
	for (int i = 0; i < a->length; ++i)
	{
		if (i < val)
			temp[i] = a->arr[i];
		if (i <= a->length - 1 - val)
			swap(a->arr[i], a->arr[i + val]);
		else {
			a->arr[i] = temp[i - (a->length - val)];
		}
	}
	cout << "Array Left rotated by " << val << " : ";
	display(*a);
}

void rightshift(array *a) {
	cout << "Original array : ";
	display(*a);
	cout << "Enter the amount by which to right shift the array : ";
	int val;
	cin >> val;
	for (int i = a->length - 1; i >= 0; --i)
	{
		if (i > val - 1)
			swap(a->arr[i], a->arr[i - val]);
		else {
			a->arr[i] = 0;
		}
	}
	cout << "Array right shifted by " << val << " : ";
	display(*a);
}

void rightrotate(array *a) {
	cout << "Original array : ";
	display(*a);
	cout << "Enter the amount by which to right rotate the array : ";
	int val;
	cin >> val;
	int temp[val];
	int count = 0;
	for (int i = a->length - 1; i >= 0; --i)
	{
		if (i > a->length - 1 - val)
			temp[count++] = a->arr[i];
		if (i > val - 1)
			swap(a->arr[i], a->arr[i - val]);
		else {
			a->arr[i] = 0;
		}
	}
	for (int i = 0; i < val / 2; i++) {
		swap(temp[i], temp[val - 1 - i]);
	}
	for (int i = 0; i < val; ++i)
	{
		a->arr[i] = temp[i];
	}
	cout << "Array right rotated by " << val << " : ";
	display(*a);
}

void insertinsorted(array * a) {
	if (a->length == a->size) {
		cout << "Array is full!" << endl;
		return;
	}
	if (!issorted(*a))
		sort(a->arr, a->arr + a->length);
	cout << "Sorted array : ";
	display(*a);
	cout << "Enter the element to be inserted : ";
	int x;
	cin >> x;
	int n = a->length - 1;
	while (a->arr[n] > x) {
		swap(a->arr[n], a->arr[n + 1]);
		n--;
	}
	a->arr[n + 1] = x;
	a->length++;
	cout << "Final array : ";
	display(*a);

}

void segregate(array *a) {
	cout << "Original array : ";
	display(*a);
	int i = 0, j = a->length - 1;
	while (i <= j) {
		while (a->arr[i] < 0) {
			i++;
			continue;
		}
		while (a->arr[j] >= 0) {
			j--;
			continue;
		}
		swap(a->arr[i], a->arr[j]);
		i++;
		j--;
	}
	cout << "Segregated array : ";
	display(*a);
}

void Clear() {
#if defined _WIN32
	system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
#elif defined (__APPLE__)
	system("clear");
#endif
}

int main() {
	array* a;
	char choice = 'y';
	while (choice == 'y' || choice == 'Y') {
		Clear();
		cout << "===============================ARRAY ADT===============================" << endl;
		cout << "1  ==> Create an Array" << endl;
		cout << "2  ==> Display the Array" << endl;
		cout << "3  ==> Check the size and length of the array" << endl;
		cout << "4  ==> Append an element in the array" << endl;
		cout << "5  ==> Insert an element in the array" << endl;
		cout << "6  ==> Delete an element" << endl;
		cout << "7  ==> Linear Search" << endl;
		cout << "8  ==> Linear Search Improved with transposition" << endl;
		cout << "9  ==> Linear Search Improved with move to front/head" << endl;
		cout << "10 ==> Binary Search" << endl;
		cout << "11 ==> Recursive Binary Search" << endl;
		cout << "12 ==> Get the element at a given index" << endl;
		cout << "13 ==> Replace the element at a given index" << endl;
		cout << "14 ==> Find the maximum element" << endl;
		cout << "15 ==> Find the minimum element" << endl;
		cout << "16 ==> Find the sum of all the elements" << endl;
		cout << "17 ==> Find the sum of all the elements by recursive method" << endl;
		cout << "18 ==> Find the average of all the elements" << endl;
		cout << "19 ==> Reversing the array without using auxilliary array" << endl;
		cout << "20 ==> Left shift the array" << endl;
		cout << "21 ==> Left rotate the array" << endl;
		cout << "22 ==> Right shift the array" << endl;
		cout << "23 ==> Right rotate the array" << endl;
		cout << "24 ==> Inserting an element in sorted array" << endl;
		cout << "25 ==> check if the array is sorted" << endl;
		cout << "26 ==> Put -ve numbers on left and +ve numbers on right" << endl;
		cout << "99 ==> Delete the array" << endl;
		cout << "100 ==> Exit" << endl;
		cout << "========================================================================" << endl;
		cout << "Enter a choice : ";
		int x;
		cin >> x;
		switch (x) {
		case 1:
			a = create();
			break;
		case 2:
			display(*a);
			break;
		case 3:
			check(*a);
			break;
		case 4:
			cout << "Enter the element to append : ";
			int x;
			cin >> x;
			append(a, x);
			break;
		case 5:
			insert(a);
			break;
		case 6:
			deleteanelement(a);
			break;
		case 7:
			LinearSearch(*a);
			break;
		case 8:
			TranspositionImprovedLinearSearch(a);
			break;
		case 9:
			MoveTofrontImprovedLinearSearch(a);
			break;
		case 10:
			BinarySearch(a);
			break;
		case 11:
			if (!issorted(*a))
				sort(a->arr, a->arr + a->length);
			cout << "Sorted array :";
			display(*a);
			cout << "Enter the key to be searched : ";
			int key;
			cin >> key;
			RecursiveBinarySearch(*a, 0, a->length - 1, key);
			break;
		case 12:
			get(*a);
			break;
		case 13:
			set(a);
			break;
		case 14:
			findmax(*a);
			break;
		case 15:
			findmin(*a);
			break;
		case 16:
			findtotal(*a);
			break;
		case 17:
			cout << "The sum is " << findtotalrecursive(*a, a->length - 1) << endl;
			break;
		case 18:
			cout << "The average of all the elements is " << (float)findtotalrecursive(*a, a->length - 1) / a->length << endl;
			break;
		case 19:
			reverse(a);
			break;
		case 20:
			leftshift(a);
			break;
		case 21:
			leftrotate(a);
			break;
		case 22:
			rightshift(a);
			break;
		case 23:
			rightrotate(a);
			break;
		case 24:
			insertinsorted(a);
			break;
		case 25:
			issorted(*a);
			break;
		case 26:
			segregate(a);
			break;
		case 99:
			deletearray(a);
			break;
		case 100:
			return 0;
		default :
			cout << "Invalid choice!" << endl;

		}
		cout << "Do you want to continue (y/n)?" << endl;
		cin.get();
		cin >> choice;
	}
	return 0;
}