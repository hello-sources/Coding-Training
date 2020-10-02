/*************************************************************************
	> File Name: OJ357多边形.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 03 Oct 2020 06:47:07 AM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 100
#define INF 0x3f3f3f3f
int val[MAX_N + 5], op[MAX_N + 5];
int n;
int dp[MAX_N + 5][MAX_N + 5][2];
int ans[MAX_N + 5];

void get_dp(int *val, int *op) {
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		dp[i][i][0] = val[i];
		dp[i][i][1] = val[i];
	}
	for (int l = 2; l <= n; l++) {
		for (int i = 1, I = n + 1 - l; i <= I; i++) {
			int j = i + l - 1;
			dp[i][j][0] = -INF;
			dp[i][j][1] = INF;
			for (int k = i; k < j; k++) {
				if (op[k + 1] == 1) {
					dp[i][j][0] = max(dp[i][k][0] + dp[k + 1][j][0], dp[i][j][0]);
					dp[i][j][1] = min(dp[i][k][1] + dp[k + 1][j][1], dp[i][j][1]);
				} else {
					int val1 = dp[i][k][0] * dp[k + 1][j][0];
					int val2 = dp[i][k][1] * dp[k + 1][j][0];
					int val3 = dp[i][k][0] * dp[k + 1][j][1];
					int val4 = dp[i][k][1] * dp[k + 1][j][1];
					dp[i][j][0] = max(dp[i][j][0], max(val1, max(val2, max(val3, val4))));
					dp[i][j][1] = min(dp[i][j][1], min(val1, min(val2, min(val3, val4))));
				}
			}
		}
	}
	return ;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		char str[10];
		cin >> str >> a;
		val[i] = val[i + n] = a;
		op[i] = op[i + n] = (str[0] - 't' ? 2 : 1);
	} 
	int max_num = -INF;
	for (int t = 0; t < n; t++) {
		get_dp(val + t - 1, op + t - 1);
		ans[t] = dp[1][n][0];
		max_num = max(max_num, ans[t]);
	}
	cout << max_num << endl;
	for (int i = 1, flag = 0; i <= n; i++) {
		if (ans[i] - max_num) continue;
		flag && cout << " ";
		flag += 1;
		cout << i;
	}
	cout << endl;
	return 0;
}
