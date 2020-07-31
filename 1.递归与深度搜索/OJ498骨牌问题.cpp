/*************************************************************************
	> File Name: OJ498骨牌问题.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 31 Jul 2020 05:39:56 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

//递推公式f[n] = f[n - 1] + f[n - 2] 

int main() {
	int n, f[35] = {0, 1, 2};
	cin >> n;
	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	cout << f[n] << endl;
	return 0;
} 
