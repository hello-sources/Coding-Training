/*************************************************************************
	> File Name: OJ314汉克森的趣味题.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 09 Sep 2020 06:08:23 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
long long a0, a1, b0, b1, ans;

long long gcd(long long a, long long b) {
	if (!b) return a;
	return gcd(b, a % b);
}

long long check(long long x) {
	if (gcd(x, a0) - a1) return 0;
	if (x * b0 / gcd(x, b0) - b1) return 0;
	return 1;
}

void solve() {
	ans = 0;
	cin >> a0 >> a1 >> b0 >> b1;
	long long num = b1 / a1;
	for (long long i = 1; i  * i <= num; i++) {
		if (num % i) continue;
		long long k2 = i;
		long long k3 = num / i;
		ans += check(b1 / k3);
		if (k2 != k3) ans += check(b1 / k2); 
	}
	cout << ans << endl; 
	return ;
}

int main() {
	long long tcase;
	cin >> tcase;
	while (tcase--) solve(); 	
	return 0;
} 
