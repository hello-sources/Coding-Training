/*************************************************************************
	> File Name: OJ346传纸条.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 23 Sep 2020 06:34:45 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 50
int val[MAX_N + 5][MAX_N + 5];
int n, m; 
int dp[(MAX_N + 5) >> 1][MAX_N + 5][MAX_N + 5];

void trans(int i, int k, int j, int l, int &ans) {
	if (k < 1 || k > m) return ;
	if (l < 1 || l > m) return ;
	if (i == j) return ;
	ans = max(ans, dp[i + k][i][j]);
	return ;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> val[i][j];
		}
	}
	dp[3][1][2] = val[1][2] + val[2][1]; 
	for (int t = 4; t <= n + m - 1; t++) {
		for (int i = 1, I = min(n - 1, t - 1); i <= I; i++) {
			for (int j = i + 1, J = min(n, t - 1); j <= J; j++) {
				int k = t - i, l = t - j;
				if (k < 1 || k > m) continue;
				if (l < 1 || l > m) continue;
				trans(i - 1, k, j - 1, l, dp[t][i][j]);
				trans(i, k - 1, j - 1, l, dp[t][i][j]);
				trans(i - 1, k, j, l - 1, dp[t][i][j]);
				trans(i, k - 1, j, l - 1, dp[t][i][j]);
				dp[t][i][j] += val[i][k] + val[j][l];
			}
		}
	}
	cout << dp[n + m - 1][n - 1][n] << endl;
	return 0;
} 
