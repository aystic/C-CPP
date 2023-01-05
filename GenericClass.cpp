/*
* @Author: Mohit Pathak
* @Date:   2021-02-01 14:04:24
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-01 14:37:38
*/

#include<iostream>

using namespace std;

template <class t>
class rectangle{
	t length;
	t breadth;
public:
	rectangle(t l,t b);
	t getlength();
	t getbreadth();
	t area();
};

template <class t>
rectangle <t>::rectangle(t l,t b){
	this->length=l;
	this->breadth=b;
}

template <class t>
t rectangle<t>::getbreadth(){
	return this->breadth;
}

template <class t>
t rectangle<t>::getlength(){
	return this->length;
}

template<class t>
t rectangle<t>::area(){
	return this->length*this->breadth;

}

int main(){
	rectangle<float> r {2.5f,4.0f};
	cout<<r.getlength()<<" "<<r.getbreadth()<<endl;
	cout<<r.area()<<endl;
	rectangle<char> r1{4,64};
	cout<<r1.getlength()<<" "<<r1.getbreadth()<<endl;
	cout<<(int)r1.area()<<endl;//output should be 0
	return 0;
}
