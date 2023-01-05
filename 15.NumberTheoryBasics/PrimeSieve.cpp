/*
* @Author: pmohit
* @Date:   2021-07-01 11:29:41
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-01 11:56:43
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void createSieve(int sieve[]) {
	//REMOVE ALL EVEN NUMBERS FROM THE LIST OF PRIME NUMBERS
	for (int i = 3; i < 1000000; i += 2)
	{
		sieve[i] = 1;
	}
	for (int i = 3; i <= 1000; ++i)
	{
		if (sieve[i] == 1) { //IF THE NUMBER IS 1 THEN MARKING ALL ITS MULTIPLE AS NON PRIME
			for (int j = i * i; j < 1000000; j += i)
			{
				sieve[j] = 0;
			}
		}
	}
	sieve[0] = sieve[1] = 0;
	sieve[2] = 1;
}

void printPrimes(int sieve[], int n) {
	for (int i = 0; i <= n; ++i)
	{
		if (sieve[i] == 1) {
			cout << i << " ";
		}
	}
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

	int sieve[1000000] {};
	createSieve(sieve);
	int n;
	cin >> n;
	printPrimes(sieve, n);
	return 0;
}