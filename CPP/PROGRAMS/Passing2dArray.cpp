#include<iostream>
using namespace std;

const int size=15;

// void display(int arr[][10],int r,int c){
void display(int arr[][size],int r,int c){
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}


}

int main(){
	int arr[size][size];
	int val=1;
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			arr[i][j]=val;
			val++;
		}
	}
	// display(arr,10,10);
	display(arr,10,10);


	return 0;
}