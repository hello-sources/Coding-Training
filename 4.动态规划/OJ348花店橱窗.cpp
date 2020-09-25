/*************************************************************************
	> File Name: OJ348花店橱窗.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 25 Sep 2020 02:10:06 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100
#define INF 0x3f3f3f3f 
int val[MAX_N + 5][MAX_N + 5];
int n, m;
int dp[MAX_N + 5][MAX_N + 5];   
int pos[MAX_N + 5][MAX_N + 5]; 
int ans[MAX_N + 5]; 

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = -INF;
		for (int j = 1; j <= m; j++) {
			cin >> val[i][j];
			dp[i][j] = -INF;
		}
	}
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= m; j++) {
			int val1 = dp[i - 1][j - 1] + val[i][j];
			int val2 = dp[i][j - 1];
			if (val1 > val2) {
				dp[i][j] = val1;
				pos[i][j] = j;
			} else {
				dp[i][j] = val2;
				pos[i][j] = pos[i][j - 1];
			}
			
		}
	}
	cout << dp[n][m] << endl;
	int p = pos[n][m];
	for (int i = n, p = pos[n][m]; i >= 1; i--, p = pos[i][p - 1]) {
		ans[i] = p;
	}
	for (int i = 1; i <= n; i++) {
		i == 1 || cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
} 
