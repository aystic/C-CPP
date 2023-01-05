#include<iostream>

using namespace std;

int main(){
	char a[100];
	string b;

	cout<<"using the cin.getline which doesn't leaves a \\n in the input buffer\n";
	cin.getline(a,100);
	cout<<a<<endl;
	cout<<endl;


	cout<<"using the cin.get which leaves a \\n in the input buffer \n";
	cin.get(a,100);// leaves \n in the input buffer
	cout<<a<<endl;
	cout<<endl;

	// cout<<"using another cin.get to consume the \\n in the input buffer \n";
	// cin.get();
	// cin>>ws;
	// cout<<endl;

	cout<<"using the getline by passing ! as delimeter\n";
	cin>>ws;
	getline(cin,b,'!');
	cout<<b<<endl;
	cout<<endl;

	cout<<"using plain cin\n";
	cin>>b;
	cout<<b<<endl;
	return 0;
}