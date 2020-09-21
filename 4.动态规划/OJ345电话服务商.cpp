/*************************************************************************
	> File Name: OJ345电话服务商.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Tue 22 Sep 2020 07:46:38 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm> 
#include <cstring>
using namespace std;
#define MAX_N 1000
#define MAX_L 200
#define INF 0x3f3f3f3f
int p[MAX_N + 5];
int c[MAX_L + 5][MAX_L + 5];
int l, n;
int dp[2][MAX_L + 5][MAX_L + 5];

int main() {
	cin >> l >> n;
	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= l; j++) {
			cin >> c[i][j];
		}
	}
	for (int i = 1; i <= n; i++) cin >> p[i];
	memset(dp[0], 0x3f, sizeof(dp[0]));
	dp[0][1][2] = 0, p[0] = 3;
	for (int i = 0; i < n; i++) {
		memset(dp[(i + 1) & 1], 0x3f, sizeof(dp[(i + 1) & 1]));
		for (int j = 1; j <= l; j++) {
			for (int k = 1; k <= l; k++) {
				if (dp[i & 1][j][k] == INF) continue;
				int p1 = p[i], p2 = p[i + 1];
				if (j - p2 && k - p2) {
					dp[(i + 1) & 1][j][k] = 
						min(dp[(i + 1) & 1][j][k], dp[i & 1][j][k] + c[p1][p2]);
				}
				if (k - p2 && p1 - p2) {
					dp[(i + 1) & 1][k][p1] = 
						min(dp[(i + 1) & 1][k][p1], dp[i & 1][j][k] + c[j][p2]);	
				}
				if (j - p2 && p1 - p2) {
					dp[(i + 1) & 1][j][p1] = 
						min(dp[(i + 1) & 1][j][p1], dp[i & 1][j][k] + c[k][p2]);
				}
			}
		}
	}
	int ans = INF;
	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= l; j++) {
			ans = min(ans, dp[n & 1][i][j]);
		}
	}
	cout  << ans << endl;
	return 0;
} 
