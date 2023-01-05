#include<iostream>
using namespace std;

int main(){
	char arr[]={65,66,67,68,69,70,71,72,73,74,75};
	/*No change in the value of the original array*/
	cout<<"No change in the value of the original array\n";
	for(int i:arr){//i is used;
		i++;
	}
	cout<<endl;
	for(int i:arr){
		cout<<i<<" ";
	}
	cout<<endl;

	/*Change in the value of the original array*/
	cout<<"Change in the value of the original array\n";
	for(char &i:arr){//&i is used
		i++;
	}
	cout<<endl;
	for(int i:arr){
		cout<<i<<" ";
	}
	cout<<endl;


	cout<<"Printing the corresponding ascii characters\n";
	for(char i:arr){//char i is used
		cout<<i<<" ";
	}
	cout<<endl;

	cout<<"Using auto\n";
	for(auto i:arr){//auto i is used
		cout<<i<<" ";
	}
	cout<<endl;

	return 0;
}