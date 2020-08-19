/*************************************************************************
	> File Name: OJ238因子和.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 19 Aug 2020 08:59:37 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
typedef long long ll;
ll MOD = 9901;

inline ll FST(ll base, ll times) {
	base %= MOD;
	ll ret = 1;
	while (times) {
		if (times & 1) ret = ret * base % MOD;
		base = base * base % MOD;
		times >>= 1;
	}
	return ret;
}

int main() {
	int a, b;
	cin >> a >> b;
	if (a == 0) {
		cout << 0 << endl;
		return 0;
	} 
	ll ans = 1;
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0) {
			ll c = 0;
			while (a % i == 0) {
				c++;
				a /= i;
			}
			c *= b;
			ans *= 1 * (FST(i, c + 1) - 1) * FST(i - 1, MOD - 2) % MOD;
			ans %= MOD;
		}
	}
	if (a > 1) ans *= 1 * (FST(a, b + 1) - 1) * FST(a - 1, MOD - 2) % MOD;
	ans = (ans % MOD + MOD) % MOD;
	cout << ans << endl;
	return 0;
} 
