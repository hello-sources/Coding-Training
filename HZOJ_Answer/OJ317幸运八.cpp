/*************************************************************************
	> File Name: OJ317幸运八.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 10 Sep 2020 08:05:36 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
//公式化抽象 

long long  gcd(long long  a, long long  b) {
	if (!b) return a;
	return gcd(b, a % b);
}

long long phi(long long x) {
	long long ans = x, i = 2;
	while (i * i <= x) {
		if (x % i == 0) ans -= ans / i;
		while (x % i == 0) x /= i;
		++i;
	}
	if (x != 1) ans -= ans / x;
	return ans;
}

long long quick_mul(long long a, long long b, long long c) {
	long long temp = a, ans = 0;
	while (b) {
		if (b & 1) ans = (temp + ans) % c;
		temp = temp * 2 % c;
		b >>= 1;
	}
	return ans;
}

long long quick_mod(long long a, long long b, long long c) {
	long long temp = a, ans = 1;
	while (b) {
		if (b & 1) ans = quick_mul(ans, temp, c);
		temp = quick_mul(temp, temp, c);
		b >>= 1;
	}
	return ans;
}

int main() {
	long long n;
	cin >> n;
	n *= 9;
	n /= gcd(n, 8);
	if (gcd(n, 10) != 1) {
		cout << "0" << endl;
		return 0;
	}
	long long  val = phi(n), ans = val;
	for (long long i = 1; i * i <= val; i++) {
		if (val % i) continue;
		long long f1 = i;
		long long f2 = val / i;
		if (quick_mod(10, f1, n) == 1) {
			ans = min(ans, f1);
		}
		if (quick_mod(10, f2, n) == 1) {
			ans = min(ans, f2);
		}
	}
	cout << ans << endl;
	return 0;
} 
