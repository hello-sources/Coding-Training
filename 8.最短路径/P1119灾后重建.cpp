/*************************************************************************
	> File Name: P1119灾后重建.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 10 Jun 2020 08:13:12 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring> 
using namespace std;

int n, m, q, ans[205][205], day[205], now;

int main() {
	memset(ans, 0x3f, sizeof(ans));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> day[i];
		ans[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a++;
		b++;
		ans[a][b] = ans[b][a] = c;
	}
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a++;
		b++;
		while (day[now] <= c && now <= n) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					ans[j][k] = min(ans[j][k], ans[j][now] + ans[now][k]);
				}
			}
			now++;
		}
		if (day[a] > c || day[b] > c || ans[a][b] == 0x3f3f3f3f) {
			cout << -1 << endl;
		} else {
			cout << ans[a][b] << endl;
		}
	}
	return 0;
} 
