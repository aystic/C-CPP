/*
* @Author: Mohit Pathak
* @Date:   2021-01-31 14:03:07
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-01-31 14:07:27
*/
#include<iostream>
using namespace std;

class rectangle{
public:
	int length;
	int breadth;
	int area(){ return length*breadth;}
	int perimeter(){ return 2*(length+breadth);}
};

int main(){
	rectangle r1;
	rectangle *r2;
	r2=&r1;
	r2->length=10;
	r2->breadth=50;
	cout<<(r2->area())<<endl;
	cout<<(r2->perimeter())<<endl;
	return 0;
}