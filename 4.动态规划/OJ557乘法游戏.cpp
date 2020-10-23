/*************************************************************************
	> File Name: OJ557乘法游戏.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 24 Oct 2020 06:48:20 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100
int val[MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> val[i];
	for (int i = 1; i < n; i++) dp[i][i + 1] = 0;
	for (int l = 3; l <= n; l++) {
		for (int i = 1, I = n + 1 - l; i <= I; i++) {
			int j = i + l - 1;
			dp[i][j] = dp[i + 1][j] + val[i + 1] * val[i] * val[j];
			for (int k = i + 1; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + val[i] * val[j] * val[k]);
			}
		}
	}
	cout << dp[1][n] << endl;
	return 0;
} 
