/*************************************************************************
	> File Name: OJ356石子合并.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 02 Oct 2020 10:20:35 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 300
#define INF 0x3f3f3f3f
int a[MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5];
int n; 

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
	for (int l = 2; l <= n; l++) {
		for (int i = 1, I = n + 1 - l; i <= I; i++) {
			int j = i + l - 1;
			dp[i][j] = INF;
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + a[j] - a[i - 1]);
			}
		}
	}
	cout << dp[1][n] << endl;
	return 0;
} 
