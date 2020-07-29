/*************************************************************************
	> File Name: OJ486铺瓷砖.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 29 Jul 2020 11:27:45 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

//递推公式f(n) = f(n - 1) + 2*f(n - 2) 

int main() {
	int n, f[1005] = {0, 1, 3};
	cin >> n;
	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + 2 * f[i - 2];
		f[i] %= 12345;
	}
	cout << f[n] << endl;
	return 0;
} 
