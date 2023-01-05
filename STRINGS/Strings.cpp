/*
* @Author: Mohit Pathak
* @Date:   2021-02-12 00:38:08
* @Last Modified by:   pmohit
* @Last Modified time: 2021-02-12 01:12:53
*/

#include<iostream>

using namespace std;
int main() {
	char name1[10] = {'J', 'O', 'H', 'N'};
	cout << sizeof(name1) << endl;//Output : 10
	char name2[10] = {'J', 'O', 'H', 'N', '\0'};
	cout << sizeof(name2) << endl;//Output : 10
	char name3[] = "JOHN";
	cout << sizeof(name3) << endl;//Output : 5
	// char *n = "JOHN"; //Memory is allocated inside heap
	// cout << sizeof(n) << endl;
	char * ptr = new char[10];//Dynamic memory allocation
	ptr[0] = {'J'};
	ptr[1] = {'O'};
	ptr[2] = {'H'};
	ptr[3] = {'N'};

	string s = "MohitPathakMohitPathakMohitPathakMohitPathakMohitPathakMohitPathakMohitPathakMohitPathakMohitPathak";
	cout << sizeof(s) << endl;
	cout << s << endl;
	return 0;
}