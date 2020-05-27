/*************************************************************************
    > File Name: P4778单源最短路径.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 27 May 2020 06:50:29 PM CST
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
		ans[a][b] = c;
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
		cout << ans[s][i];
	}
	return 0;
}
