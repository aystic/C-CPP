/*
* @Author: Mohit Pathak
* @Date:   2021-07-02 10:20:37
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-02 10:28:46
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void printPrimeFactors(int n) {
	/*APPROACH : WE DIVIDE THE GIVEN NUMBER FROM 2 TO N AND FOR EACH NUMBER IF N IS DIVISIBLE BY THAT NUMBER THEN WE DIVIVE THE NUMBER N UNTIL IT IS NOT DIVISIBLE AND THEN WE MOVE ON TO NEXT ITERATION*/
	for (int i = 2; i <= n; ++i)
	{
		if (!(n % i)) {
			cout << i << " ";
			while (!(n % i)) {
				n = n / i;
			}
		}
	}
	cout << endl;
}

void printPrimeFactorsOptimised(int n) {
	/*APPROACH : WE DIVIDE THE GIVEN NUMBER FROM 2 TO SQRT(N) FOR EACH REDUCED VALUE OF N, REDUCED VALUE REFERS TO THE VALUE OBTAINED AFTER REPEATEDLY DIVIDING BY A NUMBER UNTIL THE OTHER NUMBER IS NOT DIVISIBLE*/
	int i = 2;
	while (i * i <= n) {
		if (!(n % i)) {
			cout << i << " ";
			while (!(n % i)) {
				n = n / i;
			}
		}
		i++;
	}
	if (n != 1)
		cout << n << endl;
}




//==========================================
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	int n;
	cin >> n;
	printPrimeFactors(n);
	printPrimeFactorsOptimised(n);
	return 0;
}