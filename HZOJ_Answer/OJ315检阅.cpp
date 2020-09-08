/*************************************************************************
	> File Name: OJ315检阅.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 09 Sep 2020 06:36:47 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 1000
long long prime[MAX_N + 5];
long long phi[MAX_N + 5];

void init() {
	phi[1] = 1; 
	for (long long i = 2; i <= MAX_N; i++) {
		if (!prime[i]) {
			prime[++prime[0]] = i;
			phi[i] = i - 1;
		}
		for (long long j = 1; j <= prime[0]; j++) {
			if (i * prime[j] > MAX_N) break;
			prime[i * prime[j]] = 1;
			if (i % prime[j]) {
				phi[i * prime[j]] = phi[i] * phi[prime[j]];
			} else {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
		}
	}
	return ;
}

int main() {
	init();
	long long n, ans = 0;
	cin >> n; 
	for (long long i = 2; i < n; i++) {
		ans += 2 * phi[i];
	}
	cout << ans + 3 << endl;
	return 0;
}
