/*************************************************************************
	> File Name: OJ311素数GCD对.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 06 Sep 2020 10:54:39 AM CST
 ************************************************************************/

#include <iostream>
#define MAX_N 10000000 
long long phi[MAX_N + 5];
long long prime[MAX_N + 5];
long long f[MAX_N + 5];

void init() {
	prime[0] = prime[1] = 1;
	phi[1] = 1;
	for (long long i = 2; i * 2 <= MAX_N; i++) {
		if (!prime[i]) {
			f[++f[0]] = i;
			phi[i] = i - 1;
		}
		for (long long j = 1; j <= f[0]; j++) {
			if (f[j] * i > MAX_N) break;
			prime[f[j] * i] = 1;
			if (i % f[j]) {
				phi[f[j] * i] = (f[j] - 1) * phi[i];
			} else {
				phi[f[j] * i] = f[j] * phi[i];
				break;
			}
		}
	}
	f[0] = 0;
	for (long long i = 1; i <= MAX_N; i++) {
		f[i] = f[i - 1] + !prime[i];
	}
	return ;
}

int main() {
	init();
	long long n, ans = 0;
	cin >> n; 
	ans = phi[1] * f[n];
	for (long long y = 2; y <= n; y++) {
		ans += 2 * phi[y] * f[n / y];
	}
	cout << ans << endl;
	return 0;
} 
