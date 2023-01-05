#include<iostream>
#include<stack>
#include<string>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int precedence(char ch){
	return ch=='^'?3:(ch=='/' || ch=='*')?2:(ch=='+'||ch=='-')?1:-1;
}


void infixToPostfix(string& s){
	stack<char>st;
	for(int i=0;s[i]!='\0';i++){
		char ch=s[i];
		if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9')){
			cout<<ch;
		}else{
			int currentPrecedence=precedence(ch);
			if(ch=='(')st.push(ch);
			if(ch==')'){
				while(st.top()!='('){
					cout<<st.top();
					st.pop();
				}
				st.pop();
			}
			if(precedence(st.top())<=currentPrecedence){
				if(ch=='^' && st.top()=='^'){
					//right associative
					st.push(ch);
				}else{
					//left associative
					while(!st.empty() || precedence(st.top())<currentPrecedence){
						cout<<st.top();
						st.pop();
					}
				}
			}else{
				while(!st.empty() || precedence(st.top())<currentPrecedence){
						cout<<st.top();
						st.pop();
					}
			}
		}
	}
}


//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================
	string s;
	cin>>s;
	infixToPostfix(s);
	return 0;
}