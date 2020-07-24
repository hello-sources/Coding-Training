/*************************************************************************
	> File Name: OJ473方法.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 24 Jul 2020 12:03:05 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
	double a;
	while (cin >> a) {
		if (a == 0) break;
		double sum = 0;
		for (int i = 2; 1; i++) {
			sum += 1.0 / i;
			if (sum >= a) {
				cout << i - 1 << endl;
				break;
			}
		}
	}	
	return 0;
} 
