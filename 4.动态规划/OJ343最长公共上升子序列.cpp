/*************************************************************************
	> File Name: OJ343最长公共上升子序列.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 20 Sep 2020 07:08:14 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 3000
#define ll long long

ll a[3005], b[3005];
int dp[3005][3005];

int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i - 1][j];
			if (a[i] > b[j] && ans < dp[i - 1][j]) {
				ans = dp[i - 1][j];
			} else if (a[i] == b[j]) dp[i][j] = ans + 1;
		} 
	}
	int ans1 = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[n][i] > ans1) ans1 = dp[n][i];
	}
	cout << ans1 << endl;
	return 0;
} 
