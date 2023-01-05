#include<iostream>
using namespace std;

int sum(int a,int b){
	return a+b;
}

void display(int sum){
	cout<<sum<<endl;
}
int main(){
	int (*fpsum)(int, int);
	fpsum=sum;
	void (*fpdisplay)(int);
	fpdisplay=display;
	fpdisplay(fpsum(8,10));


	return 0;
}