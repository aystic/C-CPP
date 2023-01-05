/*
* @Author: Mohit Pathak
* @Date:   2021-02-04 10:23:19
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-04 11:32:03
*/

#include<iostream>
#include<cstring>
using namespace std;




int main() {
	int *p = new int[5];//the default array of size 5
	for (int i = 0; i < 5; ++i)
	{
		p[i] = i + 1;
	}
	int *q = new int[10];//new array of size 10
	cout << p << " " << q << endl;
	for (int i = 0; i < 5; ++i)
	{
		q[i] = p[i];//shifting of elements from the old array to the new array
	}
	delete [] p;
	p = q;//assigning the old name to the new array and deleting the old array and nulling the new array ptr




	for (int i = 5; i < 10; ++i)
	{
		p[i] = i + 1;
	}
	for (int i = 0; i < 10; ++i)
	{
		cout << p[i] << " ";
	}
	cout << endl;
	cout << p << " " << q << endl;
	return 0;
}



//using the memcpy method
int main() {
	int *p, *q;
	p = new int[5];
	q = new int[10];
	for (int i = 0; i < 5; ++i)
	{
		p[i] = i + 1;
	}
	cout << p << " " << q << endl;
	memmove(q, p, sizeof(int) * 5);
	memcpy(q, p, sizeof(int) * 5);
	delete []p;
	p = q;
	q = nullptr;
	for (int i = 0; i < 5; ++i)
	{
		cout << p[i] << " ";
	}
	cout << endl << p << " " << q << endl;
	return 0;
}