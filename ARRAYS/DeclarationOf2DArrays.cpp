/*
* @Author: Mohit Pathak
* @Date:   2021-02-04 11:51:24
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-04 12:11:40
*/

#include<iostream>

using namespace std;




int main() {
	//Method 1 stack only
	int a[3][4];
	int b[3][4] {{1, 2, 3, 4}, {5, 6, 7, 8}, {0, 0, 0, 0}};
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			a[i][j] = -1;
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << b[i][j] << " ";
		}
		cout << endl;
	}


	//method 2 stack plus heap
	int * arr[3];
	for (int i = 0; i < 3; ++i)
	{
		arr[i]=new int[4];
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			arr[i][j]=99;
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}



	//method 3 heap only
	int** ptr;
	ptr=new int*[3];
	for (int i = 0; i < 3; ++i)
	{
		ptr[i]=new int[4];
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			ptr[i][j]=-99;
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout<<ptr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}