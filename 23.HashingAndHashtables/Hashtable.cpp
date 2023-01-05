/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-07 19:04:54
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-07 21:26:26
*/

#include<iostream>
#include<string>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

class node {
public:
	string key;
	int value;
	node* next;
	node(string s, int n) {
		key = s;
		value = n;
		next = nullptr;
	}
	~node() {
		// cout << "Deleting (" << key << "," << value << ")" << endll;
		if (next) {
			delete next;
		}
	}
};

class hashtable {
	node** table;
	int current_size;
	int max_size;
	int hashFunction(string s) {
		int idx = 0;
		int p = 1;
		for (int i = 0; i < s.length(); ++i)
		{
			idx += (s[i] * p) % max_size;
			idx = idx % max_size;
			p = (p * 27) % max_size;
		}
		return idx;
	}
	void rehash() {
		node**old_table = table;
		max_size = 2 * max_size;
		current_size = 0;
		table = new node*[max_size];
		for (int i = 0; i < max_size; ++i)
		{
			table[i] = nullptr;
		}
		for (int i = 0; i < max_size / 2; ++i)
		{
			node*temp = old_table[i];
			while (temp) {
				insert(temp->key, temp->value);
				temp = temp->next;
			}
			if (old_table[i]) {
				delete old_table[i];
			}
		}
		delete [] old_table;
	}


public:
	hashtable(int size = 7) {
		table = new node*[size];
		current_size = 0;
		max_size = size;
		for (int i = 0; i < size; ++i)
		{
			table[i] = nullptr;
		}
	}

	void insert(string key, int value) {
		int idx = hashFunction(key);
		node* temp = new node(key, value);
		temp->next = table[idx];
		table[idx] = temp;
		current_size++;

		//REHASHING
		float LF = current_size / (1.0 * max_size);
		if (LF > 0.7) {
			rehash();
		}
	}

	void display() {
		for (int i = 0; i < max_size; ++i)
		{
			cout << "Bucket " << i << ":";
			node*temp = table[i];
			while (temp) {
				cout << "(" << temp->key << "," << temp->value << ")" << "=>";
				temp = temp->next;
			}
			cout << endll;
		}
	}

	int search(string key) {
		int idx = hashFunction(key);
		node*temp = table[idx];
		while (temp and temp->key != key) {
			temp = temp->next;
		}
		if (!temp)return -1;
		return temp->value;
	}

	void erase(string key) {
		int idx = hashFunction(key);
		node*temp = table[idx];
		node*temp2 = temp;
		while (temp and temp->key != key) {
			temp2 = temp;
			temp = temp->next;
		}
		if (!temp)return;
		if (table[idx] == temp) {
			table[idx] = temp->next;
			temp->next = nullptr;
			delete temp;
			return;
		}
		temp2->next = temp->next;
		temp->next = nullptr;
		delete temp;
	}
	int& operator[](string key) {
		int idx = hashFunction(key);
		node*temp = table[idx];
		node*temp2 = temp;
		while (temp and temp->key != key) {
			temp2 = temp;
			temp = temp->next;
		}
		if (!temp) {
			insert(key, -1);
			return table[idx]->value;
		}
		return temp->value;
	}
};



//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================


	hashtable h;
	h.insert("Burger", 100);
	h.insert("Pepsi", 20);
	h.insert("Noodles", 20);
	h.insert("Coke", 40);
	// h.display();
	h.insert("Chips", 20);
	// h.display();
	// h.erase("Coke");
	// h.display();
	cout << endll;
	// cout << "Price of Coke is : " << h.search("Coke") << endll;
	// cout << "Price of Pepsi is : " << h.search("Pepsi") << endll;
	// cout << "Price of Burger is : " << h.search("Burger") << endll;
	// cout << "Price of Noodles is : " << h.search("Noodles") << endll;

	//overloading [] operator
	h["Coke"] = 100;//updation of an already present element
	h["Dosa"] = 50;//insertion of an element
	h["Coke"] += 10;//updation
	h["Dosa"] += 20;//updation
	//searching
	cout << "Updated price of Coke is " << h["Coke"] << endll;
	cout << "Price of dosa is " << h["Dosa"] << endll;
	h.erase("Dosa");
	h.display();
	return 0;
}