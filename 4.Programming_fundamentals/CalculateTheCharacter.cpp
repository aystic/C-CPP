#include<iostream>
using namespace std;

int main(){
	int digits=0;
	int spaces=0;
	int alphabets=0;
	int others=0;
	char c;
	c=cin.get();
	// while(c!='$'){
	// 	if((c>64 && c<91) || (c>96 && c<123))
	// 		alphabets++;
	// 	else if(c>47 && c<58 )
	// 		digits++;
	// 	else if(c==' ')
	// 		spaces++;
	// 	else
	// 		others++;
	// 	c=cin.get();
	// }
	while(c!='$'){
		if((c>='A' && c<='Z') || (c>='a' && c<='z'))
			alphabets++;
		else if(c>='0' && c<='9' )
			digits++;
		else if(c==' '||c=='\n'||c=='\t')
			spaces++;
		else
			others++;
		c=cin.get();
	}
	cout<<"digits "<<digits<<endl;
	cout<<"alphabets "<<alphabets<<endl;
	cout<<"spaces "<<spaces<<endl;
	cout<<"others "<<others<<endl;

	return 0;
}