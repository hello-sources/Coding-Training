/*************************************************************************
	> File Name: OJ487发愤涂墙.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 29 Jul 2020 11:33:14 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

//递推公式f(n) = f(n - 1) + f(n - 2) 

int main() {
	long long n, f[50] = {0, 2, 2};
	cin >> n;
	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
	} 
	cout << f[n] << endl;
	return 0;
}
