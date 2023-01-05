#include<iostream>

using namespace std;

int main(){
	int arr[10];
	cout<<"Enter 10 numbers\n ";
	for (int i = 0; i < 10; ++i)
	{
		cin>>arr[i];
	}
	cout<<"Enter the key to be searched :";
	int key;
	cin>>key;
	for(int i:arr){
		if(i==key)
			cout<<"key found at index "<<i<<endl;
	}
	return 0;
}