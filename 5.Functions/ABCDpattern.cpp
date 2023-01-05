#include<iostream>
using namespace std;

void printpattern(int n){

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n+1-i;j++){
			cout<<(char)('A'+j-1);
		}
		cout<<endl;
	}

}

int main(){
	int n;
	cin>>n;
	printpattern(n);
	return 0;
}