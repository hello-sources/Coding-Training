/*************************************************************************
    > File Name: 贝尔曼福德算法.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 03 Jun 2020 06:26:31 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring> 
using namespace std;

int n, m, s, dis[100005][3], ans[10005];

int main() {
	memset(ans, 0x3F, sizeof(ans));
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dis[i][0] = a;
		dis[i][1] = b;
		dis[i][2] = c;
	}
	ans[s] = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			ans[dis[j][1]] = min(ans[dis[j][1]], ans[dis[j][0]] + dis[j][2]);
		}
	} 
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << endl;
	}	
	return 0;
}
