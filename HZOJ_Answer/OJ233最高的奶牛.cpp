/*************************************************************************
	> File Name: OJ233最高的奶牛.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 09 Jul 2020 08:13:15 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int n, p, h, m, ans[10005];

int main() {
	cin >> n >> p >> h >> m;
	for (int i = 1; i <= n; i++) {
		ans[i] = h;
	}
	for (int i = 0; i < m; i++) {
		int a, b, f = 0;
		cin >> a >> b;
		if (a > b) {
			swap(a, b);
		}
		for (int j = a + 1; j < b; j++) {
			if (ans[j] >= ans[a] || ans[j] > ans[b]) {
				f = 1;
				break;
			}
		}
		if (f == 1) {
			for (int j = a + 1; j < b; j++) {
				ans[j]--;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << endl;
	}
	
	return 0;
} 
