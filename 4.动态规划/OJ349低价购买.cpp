/*************************************************************************
	> File Name: OJ349低价购买.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 26 Sep 2020 08:29:20 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 5000
int val[MAX_N + 5];
int dp[MAX_N + 5], f[MAX_N + 5]; 
int n, ans, sum;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> val[i];
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (val[j] <= val[i]) continue;
			dp[i] = max(dp[i], dp[j] + 1);
		}
		if (dp[i] == 1) f[i] = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (dp[j] + 1 != dp[i]) continue;
			if (val[j] <= val[i]) continue;
			f[i] += f[j];
		}
		for (int j = i - 1; j >= 1; j--) {
			if (val[i] == val[j] && dp[i] == dp[j]) f[j] = 0;
		}
		ans = max(dp[i], ans);
	}
	for (int i = 1; i <= n; i++) {
		if (dp[i] == ans) sum += f[i];
	}
	cout << ans << " " << sum << endl;
	return 0;
} 
