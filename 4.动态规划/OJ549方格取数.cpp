/*************************************************************************
	> File Name: OJ549方格取数.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 19 Oct 2020 07:24:57 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 10
int dp[MAX_N + 5][MAX_N + 5][MAX_N + 5][MAX_N + 5] = {0};
int val[MAX_N + 5][MAX_N + 5];

int main() {
	int n, a, b, c;
	cin >> n;
	while (cin >> a >> b >> c) {
		if (a + b + c == 0) break;
		val[a][b] = c;
	}
	dp[1][1][1][1] = val[1][1];
	for (int t = 3; t <= 2 * n; t++) {
		for (int i = 1, I = min(t, n); i <= I; i++) {
			int j = t - i;
			if (j <= 0 || j > n) continue;
			for (int k = 1, K = min(t, n); k <= K; k++) {
				int l = t - k;
				if (l <= 0 || l > n) continue;
				int val1 = dp[i - 1][j][k - 1][l];
				int val2 = dp[i][j - 1][k - 1][l];
				int val3 = dp[i - 1][j][k][l - 1];
				int val4 = dp[i][j - 1][k][l - 1];
				dp[i][j][k][l] = max(val1, max(val2, max(val3, val4)));
				dp[i][j][k][l] += val[i][j] + val[k][l];
				if (i == k && j == l) dp[i][j][k][l] -= val[i][j];
			}
		}
	}
	cout << dp[n][n][n][n] << endl;
	return 0;
}
