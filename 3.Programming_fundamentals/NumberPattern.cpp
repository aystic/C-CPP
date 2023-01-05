#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int value=i;
		for(int j=1;j<=n-1+i;j++){
			if(j<=n-i)
				cout<<" "<<"\t";
			else if (j<=n){
				cout<<value<<"\t";
				value++;
			}else{
				if(j==n+1){
					value=value-1;
				}
				value--;
				cout<<value<<"\t";
			}
		}
		cout<<endl;
	}



	return 0;
}