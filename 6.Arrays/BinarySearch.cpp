#include<iostream>
using namespace std;

int BinarySearch(int* a,int i,int l,int key){
	while(i<=l){
		int mid=(i+l)/2;
		if(a[mid]>key){
			l=mid-1;
		}else if(a[mid]<key){
			i=mid+1;
		}else{
			return mid;
		}
	}
	return -1;
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int key;
	cout<<"Enter the element to be searched :"<<endl;
	cin>>key;
	int i=0,l=n-1;
	if(BinarySearch(a,i,l,key)==-1){
		cout<<"Element not present"<<endl;
	}else{
		cout<<"Element present at index "<<BinarySearch(a,i,l,key)<<endl;
	}

	return 0;
}