/*************************************************************************
	> File Name: OJ308推箱子游戏2.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Wed 15 Jul 2020 09:41:15 AM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
	int x, y, z;
};

char c[2];
int x, y, d[205][205][3], ans;
int v[205][205][3];
int nx[3][4] = {
    -2, 1, 0, 0,
    -1, 1, 0, 0,
    -1, 2, 0, 0
};
int ny[3][4] = {
    0, 0, -2, 1,
    0, 0, -1, 2,
    0, 0, -1, 1
};
int nz[3][4] = {
    2, 2, 1, 1,
    1, 1, 0, 0,
    0, 0, 2, 2
};
node temp, next;
queue<node> q;

int calc(int x, int y) {
	int num = 0;
	if (x < 0 || x > 200 || y < 0 || y > 200) {
		if (x > 200) {
			int k = (x - 200) / 3 + 2;
			num += k * 2;
			x -= k * 3;
		}
		if (y > 200) {
			int k = (y - 200) / 3 + 2;
			num += k * 2;
			y -= k * 3;
		}
	}
	return num + d[x][y][0];
}

int main() {
	v[100][100][0] = 1;
	q.push({100, 100, 0});
	while (!q.empty()) {
		node temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = temp.x + nx[temp.z][i];
			int y = temp.y + ny[temp.z][i];
			if (x < 0 || x > 200 || y < 0 || y > 200) continue;
			if (v[x][y][nz[temp.z][i]]) continue;
			q.push({x, y, nz[temp.z][i]});
			v[x][y][nz[temp.z][i]] = 1;
			d[x][y][nz[temp.z][i]] = d[temp.x][temp.y][temp.z] + 1;
		}
	}
	while (cin >> c >> x >> y) {
		x += 100;
		y += 100;
		ans = (c[0] == 'U' ? calc(x, y) : 2100000000);
		if (c[0] == 'H') {
			for (int i = -2; i <= 2; i++) {
				ans = min(ans, calc(x + i, y - 1) + abs(i) + 1);
				ans = min(ans, calc(x + i, y + 2) + abs(i) + 1);
			}
		} else if (c[0] == 'V') {
			for (int i = -2; i <= 2; i++) {
				ans = min(ans, calc(x - 1, y + i) + abs(i) + 1);
				ans = min(ans, calc(x + 2, y + i) + abs(i) + 1);
			}
        }
		cout << ans << endl;
	}
	return 0;
}
