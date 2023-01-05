/*
* @Author: Mohit Pathak
* @Date:   2021-02-01 09:58:22
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-01 10:02:07
*/
#include<iostream>
using namespace std;

class Rect{
	int length;
	int breadth;
public:
	Rect(int l,int b){
		length=l;
		breadth=b;
	}
	int getlength();
	int getbreadth();
	int area();
	int perimeter();
};

int Rect::getlength(){return length;}
int Rect::getbreadth(){return breadth;}
int Rect::area(){return length*breadth;}
int Rect::perimeter(){return 2*(length+breadth);}

int main(){
   Rect r{10,50};
   cout<<r.getlength()<<endl;
   cout<<r.getbreadth()<<endl;
   cout<<r.area()<<" "<<r.perimeter()<<endl;
   return 0;
}	