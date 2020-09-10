/*************************************************************************
	> File Name: OJ319养牛.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 11 Sep 2020 06:51:17 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

const int MAX_N = 10;
long long a[MAX_N + 5], b[MAX_N + 5], m[MAX_N + 5]; 

long long ex_gcd(long long a, long long b, long long &x, long long &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	long long ret = ex_gcd(b, a % b, y, x);
	y -= a / b * x;
	return ret;
} 

int main() {
	long long n;
	cin >> n;
	m[0] = 1;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		m[0] *= a[i];
	}
	for (long long i = 1; i <= n; i++) m[i] = m[0] / a[i];
	long long ans = 0;
	for (long long i = 1; i <= n; i++) {
		long long x, y;
		ex_gcd(m[i], a[i], x, y);
		x %= a[i];
		ans += x % m[0] * m[i] % m[0] * b[i] % m[0];
		ans %= m[0];
	}
	cout << (ans + m[0]) % m[0] << endl; 
	return 0;
} 
