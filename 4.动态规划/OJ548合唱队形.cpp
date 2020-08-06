/*************************************************************************
	> File Name: OJ548合唱队形.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 06 Aug 2020 06:06:58 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

//三维数组0维表示从前往后，1维表示从后往前，2维表示两个之间的差值 
int n, h[1005], dp[1005][3]; 

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		dp[i][0] = dp[i][1] = 1;
	} 
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (h[j] < h[i]) {
				dp[i][0] = max(dp[i][0], dp[j][0] + 1);
			}
		}
	}
	for (int i = n - 1; i >= 1; i--) {
		for (int j = n; j > i; j--) {
			if (h[j] < h[i]) {
				dp[i][1] = max(dp[i][1], dp[j][1] + 1);
			}
		}
	}
	int ans = 9999999;
	for (int i = 1; i <= n; i++) {
		dp[i][2] = (dp[i][0] + dp[i][1] - 1);
		ans = min(ans, n - dp[i][2]);
	}
	cout << ans << endl;
	return 0;
}
