/*
* @Author: Mohit Pathak
* @Date:   2021-07-01 22:51:14
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-02 09:49:36
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
	for (int i = 3; i < 1000000; i += 2)sieve[i] = 1;
	for (int i = 3; i < 1000; ++i)
	{
		if (sieve[i] == 1) {
			for (int j = i * i; j < 1000000; j += i)
			{
				sieve[j] = 0;
			}
		}
	}
	sieve[0] = sieve[1] = 0;
	sieve[2] = 1;
}

void printPrimeFactors(int sieve[], int n) {
	int count = 2;
	int m = n;
	while (count * count <= m) {//IF THERE IS NO FACTOR BETWEEN 2-SQRT(N) THEN THERE WILL BE NO FACTOR FROM SQRT(N)-N
		if (sieve[count] == 1 and n % count == 0) {
			cout << count << " ";
			while (n % count == 0)
				n = n / count;
		}
		count++;
	}
	if (n != 1)
		cout << n << endl;
	cout << endl;
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
	printPrimeFactors(sieve, n);
	return 0;
}