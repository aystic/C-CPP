#include<iostream>
using namespace std;

int main(){
	int row;
	cin>>row;
	int a=0;
	for(int i=1;i<=row;i++){
		if(i%2==0)
			a=0;
		else
			a=1;
		for (int j = 1; j <=i; ++j){

			cout<<a<<"\t";
			// if(a==0){
			// 	a=1;
			// }else{
			// 	a=0;
			// }
			a=1-a;
		}
		cout<<endl;
	}


	return 0;
}