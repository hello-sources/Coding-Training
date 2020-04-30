/*************************************************************************
    > File Name: 最长上升子序列.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Thu 30 Apr 2020 07:36:17 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 1000000

int dp[MAX_N + 5];
int a[MAX_N + 5];

int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[j] >= a[i]) continue;
			dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}
 
