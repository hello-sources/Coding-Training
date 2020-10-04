/*************************************************************************
	> File Name: OJ359能量项链.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 05 Oct 2020 07:25:53 AM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 200 
int n; 
int val[MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5];

void get_dp(int *val) {
	memset(dp, 0, sizeof(dp));
	for (int l = 2; l <= n; l++) {
		for (int i = 1, I = n + 1 - l; i <= I; i++) {
			int j = i + l - 1;
			for (int k = i; k < j; k++) {
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + val[i] * val[k + 1] * val[j + 1]);
			}
		}
	}
	return ;
} 

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> val[i];
		val[i + n] = val[i];
	}
	int ans = 0;
	for (int t = 1; t <= n; t++) {
		get_dp(val + t - 1);
		ans = max(ans, dp[1][n]);
	}
	cout << ans << endl;
	return 0;
} 
