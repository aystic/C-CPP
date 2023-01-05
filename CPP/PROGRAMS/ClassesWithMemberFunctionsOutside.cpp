/*
* @Author: Mohit Pathak
* @Date:   2021-02-01 08:42:11
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-01 09:59:51
*/
#include<iostream>
using namespace std;

class rectangle{
	int length;
	int breadth;
public:
	rectangle(int,int);
	int getlength();
	int getbreadth();
	int area();
	int perimeter();
};

rectangle::rectangle(int l=0,int b=0): length(l), breadth(b){}
int rectangle::getlength(){return length;}
int rectangle::getbreadth(){return breadth;}
int rectangle::area(){return length*breadth;}
int rectangle::perimeter(){return 2*(length+breadth);}

int main(){
   rectangle r{10,50};
   cout<<r.getlength()<<" "<<r.getbreadth()<<endl;
   cout<<r.area()<<" "<<r.perimeter()<<endl;   
   return 0;
}	