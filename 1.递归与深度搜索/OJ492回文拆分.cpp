/*************************************************************************
	> File Name: OJ492回文拆分.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 14 Oct 2020 06:43:41 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
	int f[30] = {0, 0, 1, 1, 3};
	int n;
	cin >> n;
	for (int i = 5; i <= n; i++) {
		if (i % 2 == 0) {
			f[i] = f[i - 1] * 2 + 1;
		} else {
			f[i] = f[i - 1];
		}
	}	
	cout << f[n] << endl;
	return 0;
} 
