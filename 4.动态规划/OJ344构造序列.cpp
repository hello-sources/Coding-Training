/*************************************************************************
	> File Name: OJ344构造序列.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 21 Sep 2020 06:06:16 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 2000
int a[MAX_N + 5], ind[MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5];
int n, ans;

bool cmp1(int i, int j) {
	return a[i] < a[j];
}

bool cmp2(int i, int j) {
	return a[i] > a[j];
}

void get_dp() {
	for (int i = 1; i <= n; i++) {
		dp[i][1] = dp[i - 1][1] + abs(a[ind[1]] - a[i]);
		for (int j = 2; j <= n; j++) {
			dp[i][j] = dp[i- 1][j] + abs(a[ind[j]] - a[i]);
			dp[i][j] = min(dp[i][j], dp[i][j - 1]);
		}
	}
}


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], ind[i] = i; 
	sort(ind + 1, ind + 1 + n, cmp1);
	get_dp();
	ans = dp[n][n];
	sort(ind + 1, ind + 1 + n, cmp1);
	get_dp();
	ans = min(ans, dp[n][n]);
	cout << ans << endl;
	return 0;
} 
