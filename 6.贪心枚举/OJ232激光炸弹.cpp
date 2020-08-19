/*************************************************************************
	> File Name: OJ232激光炸弹.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 19 Aug 2020 08:32:51 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio> 
using namespace std;
//二维前缀和 
const int MAX_N = 5005;
int G[MAX_N][MAX_N];
int M[MAX_N][MAX_N];

int main() {
	int n, r, max_x = 0, max_y = 0;
	scanf("%d%d", &n, &r);
	for (int i = 1; i <= n; i++) {
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		++x, ++y;
		max_x = std::max(x, max_x);
		max_y = std::max(y, max_y);
		M[x][y] = std::max(M[x][y], w);
	}
	for (int i = 1; i <= max_x; i++) {
		for (int j = 1; j <= max_y; j++) {
			G[i][j] = G[i - 1][j]+ G[i][j - 1] + M[i][j] - G[i - 1][j - 1];
		}
	}
	int ans = 0;
	for (int x = 1; x <= max_x; x++) {
		for (int y = 1; y <= max_y; y++) {
			int x2 = std::min(max_x, x + r - 1);
			int y2 = std::min(max_y, y + r - 1);
			ans = std::max(ans, G[x2][y2] - G[x - 1][y2] - G[x2][y - 1] + G[x - 1][y - 1]);
		}
	}
	std::cout << ans << endl;
	return 0;
}
