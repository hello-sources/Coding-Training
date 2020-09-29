/*************************************************************************
	> File Name: OJ354硬币.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 30 Sep 2020 07:26:34 AM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 1000
#define MAX_M 100000
int f[MAX_M + 5];
int val[MAX_N + 5], cnt = 0; 
int a[MAX_N + 5], b[MAX_N + 5];

int solve() {
	memset(f, 0, sizeof(f));
	cnt = 0;
	int n, m;
	cin >> n >> m;
	if (n == 0 && m == 0) return 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= b[i]; j <<= 1) {
			val[cnt++] = a[i] * j;
			b[i] -= j;
		}
		if (b[i]) val[cnt++] = a[i] * b[i]; 
	}
	f[0] = 1;
	for (int i = 0; i < cnt; i++) {
		for (int j = m; j >= val[i]; j--) {
			f[j] += f[j - val[i]]; 
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) ans += (f[i] != 0);
	cout << ans << endl;
	return 1;
}

int main() {
	while (solve()) ;
	return 0;
} 
