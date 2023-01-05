/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-08 12:19:01
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-08 23:48:06
*/
#include<iostream>
#include<unordered_map>
#include<cstring>
#include<string>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

class node {
public:
	char ch;
	unordered_map<char, node*> um;
	bool isTerminal;
	node(char ch) {
		this->ch = ch;
		isTerminal = false;
	}
};

class Trie {
	node*root;
	int size;
public:
	Trie() {
		root = new node('\0');
		size = 0;
	}
	bool empty() {
		return size == 0;
	}
	void insert(char* word) {
		if (word[0] == '\0')return;
		node*temp = root;
		for (int i = 0; word[i] != '\0'; ++i)
		{
			char ch = word[i];
			//if the char is present then check for next char else insert the char
			if (temp->um.count(ch) == 0) {
				node* newNode = new node(ch);
				temp->um[ch] = newNode;
			}
			if (word[i + 1] == '\0') {
				temp->isTerminal = true;
				size++;
				return;
			} else {
				temp = temp->um[ch];
			}
		}
	}
	bool find(char word[]) {
		node*temp = root;
		if (word[0] == '\0')return false;
		for (int i = 0; word[i] != '\0'; ++i)
		{
			char ch = word[i];
			if (temp->um.count(ch) == 0) {
				return false;
			} else {
				if (word[i + 1] == '\0') {
					return temp->isTerminal;
				}
				temp = temp->um[ch];
			}
		}
	}
	int getSize() {
		return size;
	}
};



//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================
	char words[][20] {"no", "not", "new", "apple", "ape", "pizza"};
	Trie t;
	for (int i = 0; i < 6; ++i)
	{
		t.insert(words[i]);
	}
	for (int i = 0; i < 6; ++i)
	{
		cout << t.find(words[i]) << endll;
	}
	// for (int i = 0; i < 8; ++i)
	// {
	// 	char key[20]	;
	// 	cin >> key;
	// 	cout << t.find(key) << endll;
	// }
	cout << "size is " << t.getSize() << endll;
	return 0;
}