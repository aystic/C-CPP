/*
* @Author: Mohit Pathak
* @Date:   2021-07-03 01:10:43
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-03 02:05:31
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void makeSieve(int arr[], int size) {
	for (int i = 3; i < size; i += 2)
	{
		arr[i] = 1;
	}
	for (int i = 3; i <= 1000; ++i)
	{
		if (arr[i]) {
			for (int j = i * i; j < size; j += i)
			{
				arr[j] = 0;
			}
		}
	}
	arr[0] = arr[1] = 0;
	arr[2] = 1;
}

bool checkPrime(int sieve[], ll n) {
	if (n < 1000000) {
		return sieve[n] == 1 ? true : false;
	} else {
		ll i = 0;
		for (; i * i <= n; i++)
		{
			if (sieve[i]) {
				if (n % i == 0)
					return false;
			}
		}
		return true;
	}
	return true;
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
	int size = 1000005;
	int sieve[size] {};
	makeSieve(sieve, size);
	ll n;
	cin >> n;
	if (checkPrime(sieve, n)) {
		cout << "Is prime" << endl;
	} else {
		cout << "Not prime" << endl;
	}
	return 0;
}