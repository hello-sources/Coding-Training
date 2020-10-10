/*************************************************************************
	> File Name: OJ364Naptime_优化.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 10 Oct 2020 08:00:23 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 3830
#define INF 0x3f3f3f3f
int val[MAX_N + 5];
int dp[2][MAX_N + 5][2];

void init_dp() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j <= MAX_N; j++) {
			dp[i][j][0] = dp[i][j][1] = -INF;
		}
		dp[i][0][0] = 0;
	}
	return ;
}

void get_dp(int n) {
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i & 1][j][0] = max(dp[(i - 1) & 1][j][0], dp[(i - 1) & 1][j][1]);
			dp[i & 1][j][1] = max(dp[(i - 1) & 1][j - 1][0], dp[(i - 1) & 1][j - 1][1] + val[i]);
		}
	}
	return ;
}

int main() {
	int n, m, ans;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> val[i];
	init_dp(); 
	dp[1][0][0] = dp[1][1][1] = 0;
	get_dp(n);
	ans = max(dp[n & 1][m][0], dp[n & 1][m][1]);
	init_dp();
	dp[1][0][0] = -INF;
	dp[1][1][1] = val[1];
	get_dp(n);
	cout << max(ans, dp[n & 1][m][1]) << endl;
	return 0;
}
