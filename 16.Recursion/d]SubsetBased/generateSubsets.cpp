/*
* @Author: Mohit Pathak
* @Date:   2021-07-10 22:33:09
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-10 23:23:23
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
using namespace std;
//==========================================

void generateSubsets(char input[], char output[], int i, int j) {
	//IF THE INPUT ARRAY REACHES END THEN END THE OUTPUT ARRAY AND PRINT IT
	if (input[i] == '\0') {
		output[j] = '\0';
		cout << "\"" << output << "\"" << endl;
		return ;
	}

	output[j] = input[i];

	//CALL WHILE INCLUDING THE CURRENT ELEMENT OF INPUT IN THE OUTPUT
	generateSubsets(input, output, i + 1, j + 1);

	//CALL WHILE EXCLUDING THE CURRENT ELEMENT OF INPUT IN THE OUTPUT
	generateSubsets(input, output, i + 1, j);

	return ;

}


//==========================================
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
//==========================================

	char input[100];
	char output[100];
	cin >> input;
	generateSubsets(input, output, 0, 0);
	return 0;
}