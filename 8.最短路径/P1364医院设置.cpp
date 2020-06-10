/*************************************************************************
	> File Name: P1364医院设置.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 10 Jun 2020 07:50:38 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring> 
using namespace std;

int n, ans[105][105], num[105];

int main() {
	memset(ans, 0x3F, sizeof(ans));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ans[i][i] = 0;
		int a, b;
		cin >> num[i] >> a >> b;
		if (a) {
			ans[i][a] = ans[a][i] = 1;
		} 
		if (b) {
			ans[i][b] = ans[b][i] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				ans[j][k] = min(ans[j][k], ans[j][i] + ans[i][k]);
			}
		}
	}
	int mmin = 999999999;
	for (int i = 1; i <= n; i++) {
		int t = 0;
		for (int j = 1; j <= n; j++) {
			t += ans[i][j] * num[j];
		}
		mmin = min(mmin, t);
	}
	cout << mmin << endl;
	return 0;
} 
