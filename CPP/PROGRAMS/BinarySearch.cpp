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
	int s=0,e=9,mid=(s+e)/2;
	while(s<=e){
		if(arr[mid]>key){
			e=mid-1;
		}else if(arr[mid]<key){
			s=mid+1;
		}else{
			cout<<"The key is at the index "<<mid<<endl;
			return 0;
		}
		mid=(s+e)/2;
	}
	return 0;
}