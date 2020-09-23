/*************************************************************************
	> File Name: OJ347乌龟棋.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 24 Sep 2020 07:43:38 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 350
int a[MAX_N + 5];
int cnt[5] = {0};
int dp[35][35][35][35] = {0};

int main() {
	int n, m, b; 
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) {
		cin >> b;
		cnt[b] += 1;
	}
	for (int i = 0; i <= cnt[1]; i++) {
		for (int j = 0; j <= cnt[2]; j++) {
			for (int k = 0; k <= cnt[3]; k++) {
				for (int l = 0; l <= cnt[4]; l++) {
					int t = i + 2 * j + 3 * k + 4 * l, temp = 0;
					dp[i][j][k][l] = a[t];
					if (i) temp = max(temp, dp[i - 1][j][k][l]);
					if (j) temp = max(temp, dp[i][j - 1][k][l]);
					if (k) temp = max(temp, dp[i][j][k - 1][l]);
					if (l) temp = max(temp, dp[i][j][k][l - 1]);
					dp[i][j][k][l] += temp;
				}
			}
		}
	}
	cout << dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << endl; 
	return 0;
}
