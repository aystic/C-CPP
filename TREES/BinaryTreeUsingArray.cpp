/*
* @Author: Mohit Pathak
* @Date:   2021-02-27 05:58:24
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-27 06:02:14
*/

#include<iostream>
#include<cmath>
using namespace std;





int main() {
	int bt[] {1, 2, 3, 4, 5, 6, 7}	;
	int level = 0;
	int j = 0;
	while (j < 7) {
		for (int i = 0; i < pow(2, level); ++i)
		{
			cout << bt[j] << " ";
			j++;
			if (j >= 7)
				break;
		}
		level++;
		cout << endl;

	}

	return 0;
}