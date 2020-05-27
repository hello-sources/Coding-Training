/*************************************************************************
    > File Name: P3771单源最短路径_弱化版.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 27 May 2020 07:03:13 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int n, m, s, ans[1005][1005];

int main() {
	memset(ans, 0x3F, sizeof(ans));
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		ans[a][b] = min(c, ans[a][b]);
	}
	for (int i = 0; i <= n; i++) {
		ans[i][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				ans[j][k] = min(ans[j][k], ans[j][i] + ans[i][k]); 
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (i != 1) cout << " ";
		if (ans[s][i] == 0x3f3f3f3f) {
			cout << 0x7fffffff;
		} else
			cout << ans[s][i];
	}
	return 0;
}
