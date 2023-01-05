/*
* @Author: Mohit Pathak
* @Date:   2021-05-03 10:44:36
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-05-04 01:36:24
*/

//#include <bits/stdc++.h>
#include <iostream>
// #include<limits>

using namespace std;
#define endll "\n"
//======================================





//=======================================
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//=======================================

	cout << "Char data types : " << endll;
	cout << "Size of char " << sizeof(char) << " bytes" << endll;
	cout << "Size of char16_t " << sizeof(char16_t) << " bytes" << endll;
	cout << "Size of char32_t " << sizeof(char32_t) << " bytes" << endll;
	cout << "Size of wchar_t " << sizeof(wchar_t) << " bytes" << endll;
	cout << endll;
	cout << "Size of Signed Int data types : " << endll;
	cout << "Size of signed char " << sizeof(signed char) << " bytes" << endll;
	cout << "Size of signed short int / short " << sizeof( short) << " bytes" << endll;
	cout << "Size of signed int / int " << sizeof(int) << " bytes" << endll;
	cout << "Size of signed long int / long " << sizeof( long) << " bytes" << endll;
	cout << "Size of singed long long int / long long  " << sizeof( long long) << " bytes" << endll;
	cout << endll;
	cout << "Size of Unsigned Int data types :" << endll;
	cout << "Size of unsigned char " << sizeof(unsigned char) << " bytes" << endll;
	cout << "Size of unsigned short int / unsigned short " << sizeof(unsigned short) << " bytes" << endll;
	cout << "Size of unsigned int / unsigned " << sizeof(unsigned ) << " bytes" << endll;
	cout << "Size of unsigned long int / long " << sizeof(unsigned long) << " bytes" << endll;
	cout << "Size of unsigned long long int / long long " << sizeof(unsigned long long) << " bytes" << endll;
	cout << endll;
	cout << "Size of Floating-point data types : " << endll;
	cout << "Size of float " << sizeof(float) << " bytes" << endll;
	cout << "Size of double " << sizeof(double) << " bytes" << endll;
	cout << "Size of long double " << sizeof(long double) << " bytes" << endll;
	cout << endll;
	cout << "Size of boolean data type : " << endll;
	cout << "Size of bool " << sizeof(bool) << " bytes" << endll;
	cout << endll;
	cout << "Size of void type " << endll;
	cout << "Size of void " << sizeof(void) << " bytes" << endll;
	cout << endll;
	cout << "Size of decltype(nullptr) : " << endll;
	cout << "Size of decltype(nullptr) " << sizeof(decltype(nullptr)) << " bytes" << endll;
	cout << endll << endll << endll;
	cout << CHAR_MIN << " " << CHAR_MAX << endll;
	cout << SCHAR_MIN << " " << SCHAR_MAX << endll;
	cout << UCHAR_MAX << endll;
	cout << SHRT_MIN << " " << SHRT_MAX << endll;
	cout << INT_MIN << " " << INT_MAX << endll;
	cout << LONG_MIN << " " << LONG_MAX << endll;
	return 0;
}