#include<iostream>
using namespace std;

int main(){
	cout<<"Enter -1 to end"<<endl;
	int n;
	while(1){
		cin>>n;
		if(n%7==0){
			continue;
		}
		if(n==-1){
			break;
		}
		cout<<n<<endl;
	}

	return 0;
}