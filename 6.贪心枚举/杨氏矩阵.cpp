/*************************************************************************
    > File Name: 杨氏矩阵.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 20 May 2020 08:30:17 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int n, m, t, num[3005][3005];

int main() {
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &num[i][j]);
		}
	}
	int x = n, y = 1;
	while (x > 0 && y <= m) {
		if (num[x][y] == t) {
			printf("%d %d\n", x, y);
			return 0;
		}
		if (num[x][y] > t) {
			x--;
		} else {
			y++;
		}
	}
	return 0;
}
