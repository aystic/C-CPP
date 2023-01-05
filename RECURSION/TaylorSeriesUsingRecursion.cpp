/*
* @Author: pmohit
* @Date:   2021-02-03 09:27:57
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-03 12:25:05
*/

#include<iostream>

using namespace std;


/* Method one : Using Recursion only*/

//Taylor Series : e^x = 1 + x + x^2/2! + x^3/3! + ....
// int factorial(int n) {
// 	if (n == 0)
// 		return 0;
// 	else
// 		return n * factorial(n - 1);
// }

// int power(int n, int m) {
// 	if (m == 0)
// 		return 1;
// 	else {
// 		if (m % 2 == 0) {
// 			return power(n * n, m / 2);
// 		} else {
// 			return n * power(n * n, (m - 1) / 2);
// 		}
// 	}

// }

// int taylor(int x, int n) {
// 	if (n == 1)
// 		return 1;
// 	else
// 		return power(x, n - 1) / factorial(n - 1) + taylor(x, n - 1);
// }



/* Method two : Using Static Variables and recursion*/

// float term(float, float);

// float taylor(float x, float n) {
// 	if (n == 1)
// 		return 1.0f;
// 	else
// 		return (float)(taylor(x, n - 1) + term(x, n - 1));

// }

// float term(float x, float n) {
// 	static float fact = 1;
// 	static float power = 1;
// 	power *= x;
// 	fact *= n;
// 	return (power / fact);

// }


/* Method three : Using loops and Recursion by Simplifying the series*/
/* e^x : 1+ x/1 [ 1+ x/2 [ 1 + x/3 [ 1+x/4] ]] */

//using loops

// float taylor(int x, int n) {
// 	float s = 1.0f;
// 	while (n > 0) {
// 		s *=(x /(float) n);
// 		s++;
// 		n--;
// 	}
// 	return s;
// }


//using recursion

float taylor (int x, int n){
	static float s=1.0f;
	if(n==0){
		return s;
	}else{
		s*=(float)x/n;
		s+=1;
		return taylor(x,n-1);
	}

}

int main() {
	cout << "Enter x and n in taylor series e^x and n termms :";
	int x, n;
	cin >> x >> n;
	cout << taylor(x, n-1) << endl;
	return 0;
}