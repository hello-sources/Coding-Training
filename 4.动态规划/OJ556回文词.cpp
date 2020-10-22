/*************************************************************************
	> File Name: OJ556回文词.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 22 Oct 2020 11:15:38 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

char s1[5005], s2[5005]; 
int dp[5005][5005] = {0};

int main() {
	int n;
	cin >> n >> s1;
	for (int i = 0; s1[i]; i++) {
		s2[n - i - 1] = s1[i];
	}
	for (int i = 1; i <= n; i++) dp[i][0] = dp[0][i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (s1[i - 1] - s2[j - 1]) {
				dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
			} else {
				dp[i][j] = dp[i - 1][j - 1];
			}
		}
	}
	cout << dp[n][n] / 2 << endl;
	return 0;
} 
