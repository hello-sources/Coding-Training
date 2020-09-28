/*************************************************************************
	> File Name: OJ353自然数拆分.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Tue 29 Sep 2020 07:28:45 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 4000
#define MOD_NUM 2147483648
int f[MAX_N + 5][MAX_N + 5];
//表示把N分成M份，其中有1的和没有1的方案数 
//递推公式f(n, m) = f(n - 1, m - 1) + f(n - m, m)

int main() {
	int n;
	cin >> n; 
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			f[i][j] = f[i - 1][j - 1] + f[i - j][j];
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += f[n][i];
		ans %= MOD_NUM;
	}
	cout << ans - 1 << endl;
	return 0;
} 
