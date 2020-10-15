/*************************************************************************
	> File Name: OJ495.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 16 Oct 2020 06:44:15 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int ans[105][45005], p[105];

int main() {
	int n, sum = 0, sum2;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		sum += p[i];
	}
	sum2 = sum / 2;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum2; j++) {
			if (j < p[i]) {
				ans[i][j] = ans[i - 1][j];
			} else {
				ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - p[i]] + p[i]);
			}
		}
	}
	cout << ans[n][sum2] <<  " " << sum - ans[n][sum2] << endl;
	return 0;
}
