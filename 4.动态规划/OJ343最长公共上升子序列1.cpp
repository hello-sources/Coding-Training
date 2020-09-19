/*************************************************************************
	> File Name: OJ343最长公共上升子序列1.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 20 Sep 2020 07:09:57 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 3000
int a[MAX_N + 5], b[MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5];
int n, ans;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i][j - 1];
			if (a[i] - b[j]) continue;
			dp[i][j] = max(1, dp[i][j]);
			for (int k = 1; k < i; k++) {
				if (a[k] >= a[i]) continue;
				dp[i][j] = max(dp[i][j], dp[k][j - 1] + 1);
			}
			ans = max(ans, dp[i][j]);
		}
	} 
	cout << ans << endl;
	return 0;
}
