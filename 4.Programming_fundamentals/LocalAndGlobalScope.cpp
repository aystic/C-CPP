#include<iostream>
using namespace std;

int i;
char c;
int j=9;
char d='9';
int main(){
	cout<<"Global uninitialized int i = "<<i<<endl;
	cout<<"Global initialized int j = "<<j<<endl;
	cout<<"Global uninitialized char c = "<<c<<endl;
	if(c=='\0'){
		cout<<"c carries a null character!"<<endl;
	}
	cout<<"Global initialized char d = "<<d<<endl;
	int i=10;
	cout<<"Local i = "<<i<<endl;
	cout<<"Global i using ::i operator "<<::i<<endl;


	return 0;
}